parser grammar C2105133Parser;

options {
	tokenVocab = C2105133Lexer;
}

@parser::header {
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
    #include <functional>
    #include <sstream>
    #include "C8086Lexer.h"
    #include "2105133_SymbolTable.h"

    using namespace std;

    extern ofstream parserLogFile;
    extern ofstream errorFile;
    extern SymbolTable Table;
    extern int syntaxErrorCount;
}

@parser::members {
    void writeIntoparserLogFile(const string message) {
        if (!parserLogFile) {
            cout << "Error opening parserLogFile.txt" << endl;
            return;
        }

        parserLogFile << message << endl;
        parserLogFile.flush();
    }

    void writeIntoErrorFile(const string message) {
        if (!errorFile) {
            cout << "Error opening errorFile.txt" << endl;
            return;
        }
        syntaxErrorCount++;
        errorFile << message << endl;
        errorFile.flush();
    }

    vector<string> extractParamTypes(const string& paramListText, bool definition, bool insert=false, int line = 0 ) {
        vector<string> paramTypes;
        istringstream ss(paramListText);
        string param;

        while (getline(ss, param, ',')) {
            istringstream wordStream(param);
            string type;
            wordStream >> type; 
            if (!type.empty()) {
                paramTypes.push_back(type);
                if(definition)
                {
                    string name;
                    wordStream >> name;
                    if(insert)
                    {
                        if(!Table.insert(name, type))
                        {
                            writeIntoErrorFile("Error at line " + to_string(line) + ": Multiple declaration of " + name + " in parameter\n");
                            writeIntoparserLogFile("Error at line " + to_string(line) + ": Multiple declaration of " + name + " in parameter\n");
                        }
                    }
                        
                }
            }
        }

        return paramTypes;
    }

    void insertFunctionDeclaration( string funcName, string returnType, string paramListText="", bool definition = false) {

        bool success = Table.insert(funcName, "ID");

        if (!success) {
            cerr << "Semantic Error: Function '" << funcName << "' already declared in current scope." << endl;
            return;
        }

        
        SymbolInfo* funcSymbol = Table.lookup(funcName);
        if (!funcSymbol) {
            cerr << "Internal Error: Inserted function not found during lookup." << endl;
            return;
        }

        
        //Table.enterScope();
        
        
        vector<string> paramTypes = extractParamTypes(paramListText, definition);

        
        funcSymbol->setIsFunction(true);
        funcSymbol->setReturnType(returnType);
        funcSymbol->setParamTypes(paramTypes); 
        if(!definition)
            funcSymbol->setIsDeclared(true);
        else
            funcSymbol->setIsDefined(true);
    }


    void insertVarDeclarations(string &type, const string &declListText) {
        stringstream ss(declListText);
        string name;

        while (getline(ss, name, ',')) {
            
            int bracketPos = name.find('[');
            string temp = type;
            if (bracketPos != string::npos) {
                name = name.substr(0, bracketPos);
                type += " array";
            }

            bool success = Table.insert(name, type);
            type = temp;
            if (!success) {
               // writeIntoErrorFile("Error at line " + line + ": Multiple declaration of " + name);
            }
        }
    }

}

start:
	p = program {
        writeIntoparserLogFile(
            "Line " + to_string($p.stop->getLine()) +
            ": start : program \n\n" + "\n"
        );
        Table.printAllScopeTable(parserLogFile);
        writeIntoparserLogFile("Total lines: " + to_string($p.stop->getLine()) +
        "\nTotal errors: " + to_string(syntaxErrorCount) + "\n");
    };

program
	returns[string act_text]:
	p = program u = unit {
        $act_text = $p.act_text + $u.act_text;
        writeIntoparserLogFile(
            "Line " + to_string($u.stop->getLine()) +
            ": program : program unit\n\n" + $act_text + "\n"
        );
    }
	| u = unit {
        $act_text = $u.act_text;
        writeIntoparserLogFile(
            "Line " + to_string($u.stop->getLine()) +
            ": program : unit\n\n" + $act_text + "\n"
        );
    };

unit
	returns[string act_text]:
	vd = var_declaration {
        $act_text = $vd.act_text;
        writeIntoparserLogFile(
            "Line " + to_string($ctx->getStart()->getLine()) +
            ": unit : var_declaration\n\n" + $act_text + "\n"
        );
    }
	| fd = func_declaration {
        $act_text = $fd.act_text;
        writeIntoparserLogFile(
            "Line " + to_string($ctx->getStart()->getLine()) +
            ": unit : func_declaration\n\n" + $act_text + "\n"
        );
    }
	| f = func_definition {
        $act_text = $f.act_text + "\n";
        writeIntoparserLogFile(
            "Line " + to_string($f.stop->getLine()) +
            ": unit : func_definition\n\n" + $act_text + "\n"
        );
    };

func_declaration
	returns[string act_text]:
	t = type_specifier ID LPAREN p = parameter_list RPAREN SEMICOLON {
        $act_text = $t.act_text + " " + $ID->getText() + "(" + $p.act_text + ")" + ";\n";
        writeIntoparserLogFile(
            "Line " + to_string($ctx->getStart()->getLine()) +
            ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n" +
            $act_text + "\n"
        );
        insertFunctionDeclaration($ID->getText(),$t.act_text,$p.act_text);
        Table.enterScope();
        vector <string> store = extractParamTypes($p.act_text, true, true, $ctx->getStart()->getLine());
        Table.exitScope();
    }
	| t = type_specifier ID LPAREN RPAREN SEMICOLON {
         $act_text = $t.act_text + " " + $ID->getText() + "(" + ")" + ";\n";
        writeIntoparserLogFile(
            "Line " + to_string($ctx->getStart()->getLine()) +
            ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n" +
            $act_text + "\n"
        );
        insertFunctionDeclaration($ID->getText(),$t.act_text);
        Table.enterScope();
        Table.exitScope();
    };

func_definition
	returns[string act_text, int Line]:
	t = type_specifier ID LPAREN p = parameter_list RPAREN {
    SymbolInfo* temp = Table.lookup($ID->getText());
        if(temp!=nullptr){
            if(!temp->getIsDeclared())
            {
                //insertFunctionDeclaration($ID->getText(),$t.act_text,$p.act_text,true);
                writeIntoErrorFile("Error at line " + to_string($ID->getLine()) + ": Multiple declaration of " + $ID->getText() + "\n");
                writeIntoparserLogFile("Error at line " + to_string($ID->getLine()) + ": Multiple declaration of " + $ID->getText() + "\n"); 
            }
            else{
                if($t.act_text != temp->getReturnType())
                {
                    writeIntoErrorFile("Error at line " + to_string($ID->getLine()) + ": Return type mismatch with function declaration in function " + $ID->getText() + "\n");
                    writeIntoparserLogFile("Error at line " + to_string($ID->getLine()) + ": Return type mismatch with function declaration in function " + $ID->getText() + "\n");   
                }
                vector <string> param = extractParamTypes($p.act_text, false);
                if(param.size() != temp->getParamTypes().size())
                {
                    writeIntoErrorFile("Error at line " + to_string($ID->getLine()) + ": Total number of arguments mismatch with declaration in function " + $ID->getText() + "\n");
                    writeIntoparserLogFile("Error at line " + to_string($ID->getLine()) + ": Total number of arguments mismatch with declaration in function " + $ID->getText() + "\n"); 
                }
            }
            Table.enterScope();
            vector <string> store = extractParamTypes($p.act_text, true, true, $ctx->getStart()->getLine());
        }else
        {
            insertFunctionDeclaration($ID->getText(),$t.act_text,$p.act_text,true);
            Table.enterScope();
            vector <string> store = extractParamTypes($p.act_text, true, true, $ctx->getStart()->getLine());
        }
    }
    c = compound_statement[false] {
        $act_text = $t.act_text + " " + $ID->getText() + "(" + $p.act_text + ")" + $c.act_text;
        $Line = $c.Line;
        writeIntoparserLogFile(
            "Line " + to_string($c.stop->getLine()) +
            ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n" +
            $act_text + "\n"
        );
        Table.exitScope();
    }
	| t = type_specifier ID LPAREN RPAREN
    {
        SymbolInfo* temp = Table.lookup($ID->getText());
        if(temp!=nullptr){
            if(!temp->getIsDeclared())
                 insertFunctionDeclaration($ID->getText(),$t.act_text,"",true);
            Table.enterScope();
        }else
        {
            insertFunctionDeclaration($ID->getText(),$t.act_text,"",true);
            Table.enterScope();
        }
    } c = compound_statement[false] {
        $act_text =  $t.act_text + " " + $ID->getText() + "(" + ")" + $c.act_text;
        $Line = $c.Line;
        writeIntoparserLogFile(
            "Line " + to_string($c.stop->getLine()) +
            ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n" +
            $act_text + "\n"
        );
        Table.exitScope();
    }
    | t = type_specifier ID LPAREN pe = parameter_list_err RPAREN {
        // This block handles error in parameter list
        writeIntoErrorFile("Error at line " + to_string($ID->getLine()) + ": Syntax error in parameter list of function " + $ID->getText() + "\n");
        writeIntoparserLogFile("Error at line " + to_string($ID->getLine()) + ": Syntax error in parameter list of function " + $ID->getText() + "\n");
        Table.enterScope();  // still enter scope to allow compound_statement parsing
    } c = compound_statement[false] {
        $act_text = $t.act_text + " " + $ID->getText() + "(" + $pe.act_text + ")" + $c.act_text;
        $Line = $c.Line;
        writeIntoparserLogFile("Line " + to_string($c.stop->getLine()) + ": func_definition : type_specifier ID LPAREN parameter_list_err RPAREN compound_statement\n\n" + $act_text + "\n");
        Table.exitScope();
    }
    ; 

parameter_list_err returns [string act_text] : (.)+? {
    $act_text = $ctx->getText();
}
;
parameter_list
	returns[string act_text]:
	p = parameter_list COMMA t = type_specifier ID {
        $act_text = $p.act_text + "," + $t.act_text + " " + $ID->getText();
        writeIntoparserLogFile(
            "Line " + to_string($ctx->getStart()->getLine()) +
            ": parameter_list : parameter_list COMMA type_specifier ID\n\n" +
            $act_text + "\n"
        );
    }
	| p = parameter_list COMMA t = type_specifier {
        $act_text = $p.act_text + "," + $t.act_text;
        writeIntoparserLogFile(
            "Line " + to_string($ctx->getStart()->getLine()) +
            ": parameter_list : parameter_list COMMA type_specifier\n\n" +
            $act_text + "\n"
        );
    }
	| t = type_specifier ID {
        $act_text = $t.act_text + " " + $ID->getText();
        writeIntoparserLogFile(
            "Line " + to_string($ctx->getStart()->getLine()) +
            ": parameter_list : type_specifier ID\n\n" +
            $act_text + "\n"
        );
    }
	| t = type_specifier {
        $act_text = $t.act_text ;
        writeIntoparserLogFile(
            "Line " + to_string($ctx->getStart()->getLine()) +
            ": parameter_list : type_specifier\n\n" +
            $act_text + "\n"
        );
    };


compound_statement [bool flagScope]
	returns[string act_text, int Line]:
	LCURL {if (flagScope) Table.enterScope();}
    s = statements RCURL {
        $act_text = "{\n" + $s.act_text + "}\n" ;
        $Line = $RCURL->getLine();
        writeIntoparserLogFile(
            "Line " + to_string($RCURL->getLine()) +
            ": compound_statement : LCURL statements RCURL\n\n" +
            $act_text + "\n\n\n"
        );
        Table.printAllScopeTable(parserLogFile);
        if (flagScope) Table.exitScope();
    }
	| LCURL {if (flagScope) Table.enterScope();}
     RCURL {
        $act_text = $ctx->getText();
        $Line = $RCURL->getLine();
        writeIntoparserLogFile(
            "Line " + to_string($RCURL->getLine()) +
            ": compound_statement : LCURL RCURL\n\n" +
            $act_text + "\n\n\n"
        );
        Table.printAllScopeTable(parserLogFile);
        if (flagScope) Table.exitScope();
    };

var_declaration
	returns[string act_text,int line ]:
	t = type_specifier dl = declaration_list sm = SEMICOLON {
        $act_text = $t.act_text + " " + $dl.act_text + ";\n" ;
        $line = $sm->getLine();
        writeIntoparserLogFile("Line " + to_string($sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON \n");
        if($t.act_text == "void")
        {
            writeIntoErrorFile("Error at line " + to_string($sm->getLine()) + ": Variable type cannot be void " + "\n");
            writeIntoparserLogFile("Error at line " + to_string($sm->getLine()) + ": Variable type cannot be void " + "\n"); 
            
        }else
            insertVarDeclarations($t.act_text, $dl.act_text);
        writeIntoparserLogFile($act_text);
      }
	| t = type_specifier de = declaration_list_err sm = SEMICOLON {
        writeIntoErrorFile(
            string("Line# ") + to_string($sm->getLine()) +
            " with error name: " + $de.error_name +
            " - Syntax error at declaration list of variable declaration"
        );

        syntaxErrorCount++;
      };

declaration_list_err
	returns[string error_name]: 
	{
        $error_name = "Error in declaration list";
    };

type_specifier
	returns[string act_text]:
	INT {
            $act_text = $ctx->getText();
            writeIntoparserLogFile("Line " + to_string($INT->getLine()) + ": type_specifier : INT \n\nint \n");
        }
	| FLOAT {
            $act_text = $ctx->getText();
             writeIntoparserLogFile("Line " + to_string($FLOAT->getLine()) + ": type_specifier : FLOAT \n\nfloat \n");
        }
	| VOID {
            $act_text = $ctx->getText();
            writeIntoparserLogFile("Line " + to_string($VOID->getLine()) + ": type_specifier : VOID \n\nvoid \n");
        };

declaration_list
	returns[string act_text]:
	dl=declaration_list COMMA ID { 
        $act_text = $dl.act_text + "," + $ID->getText()  ;
        if(Table.getCurrentScopeTable()->lookup($ID->getText()))
        {
            writeIntoErrorFile("Error at line " + to_string($ID->getLine()) + ": Multiple declaration of " + $ID->getText() + "\n");
            writeIntoparserLogFile("Error at line " + to_string($ID->getLine()) + ": Multiple declaration of " + $ID->getText() + "\n");
        }
        writeIntoparserLogFile("Line " + to_string($ID->getLine()) + ": declaration_list : declaration_list COMMA ID \n\n" + $act_text + "\n");
	}
	| dl=declaration_list COMMA ID LTHIRD CONST_INT RTHIRD { 
        $act_text = $dl.act_text + "," + $ID->getText() + "[" + $CONST_INT->getText() + "]" ;
        if(Table.getCurrentScopeTable()->lookup($ID->getText()))
        {
            writeIntoErrorFile("Error at line " + to_string($ID->getLine()) + ": Multiple declaration of " + $ID->getText() + "\n");
            writeIntoparserLogFile("Error at line " + to_string($ID->getLine()) + ": Multiple declaration of " + $ID->getText() + "\n");
        } 
        writeIntoparserLogFile("Line " + to_string($ID->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD \n\n" + $act_text + "\n");
	}
	| ID { 
        $act_text = $ctx->getText(); 
        if(Table.getCurrentScopeTable()->lookup($ID->getText()))
        {
            writeIntoErrorFile("Error at line " + to_string($ID->getLine()) + ": Multiple declaration of " + $ID->getText() + "\n");
            writeIntoparserLogFile("Error at line " + to_string($ID->getLine()) + ": Multiple declaration of " + $ID->getText() + "\n");
        }
        writeIntoparserLogFile("Line " + to_string($ID->getLine()) + ": declaration_list : ID \n\n" + $ctx->getText() + "\n");
	}
	| ID LTHIRD CONST_INT RTHIRD { 
        $act_text = $ctx->getText();
        if(Table.getCurrentScopeTable()->lookup($ID->getText()))
        {
            writeIntoErrorFile("Error at line " + to_string($ID->getLine()) + ": Multiple declaration of " + $ID->getText() + "\n");
            writeIntoparserLogFile("Error at line " + to_string($ID->getLine()) + ": Multiple declaration of " + $ID->getText() + "\n");
        }
        writeIntoparserLogFile("Line " + to_string($ID->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD \n\n" + $ctx->getText() + "\n");
	}
    | dl=declaration_list ADDOP {$act_text = $dl.act_text;
        writeIntoErrorFile("Error at line " + to_string($ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON");
        writeIntoparserLogFile("Error at line " + to_string($ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON");
      }
    | dl=declaration_list ID {$act_text = $dl.act_text;
        writeIntoErrorFile("Error at line " + to_string($ID->getLine()) + ": syntax error, unexpected ID, expecting COMMA or SEMICOLON");
        writeIntoparserLogFile("Error at line " + to_string($ID->getLine()) + ": syntax error, unexpected ID, expecting COMMA or SEMICOLON");
      }
    | dl=declaration_list SUBOP {$act_text = $dl.act_text;
        writeIntoErrorFile("Error at line " + to_string($SUBOP->getLine()) + ": syntax error, unexpected SUBOP, expecting COMMA or SEMICOLON");
        writeIntoparserLogFile("Error at line " + to_string($SUBOP->getLine()) + ": syntax error, unexpected SUBOP, expecting COMMA or SEMICOLON");
      }
    | dl=declaration_list MULOP {$act_text = $dl.act_text;
        writeIntoErrorFile("Error at line " + to_string($MULOP->getLine()) + ": syntax error, unexpected MULOP, expecting COMMA or SEMICOLON");
        writeIntoparserLogFile("Error at line " + to_string($MULOP->getLine()) + ": syntax error, unexpected MULOP, expecting COMMA or SEMICOLON");
      }
    | dl=declaration_list INCOP {$act_text = $dl.act_text;
        writeIntoErrorFile("Error at line " + to_string($INCOP->getLine()) + ": syntax error, unexpected INCOP, expecting COMMA or SEMICOLON");
        writeIntoparserLogFile("Error at line " + to_string($INCOP->getLine()) + ": syntax error, unexpected INCOP, expecting COMMA or SEMICOLON");
      }
    | dl=declaration_list DECOP {$act_text = $dl.act_text;
        writeIntoErrorFile("Error at line " + to_string($DECOP->getLine()) + ": syntax error, unexpected DECOP, expecting COMMA or SEMICOLON");
        writeIntoparserLogFile("Error at line " + to_string($DECOP->getLine()) + ": syntax error, unexpected DECOP, expecting COMMA or SEMICOLON");
      }
    | dl=declaration_list NOT {$act_text = $dl.act_text;
        writeIntoErrorFile("Error at line " + to_string($NOT->getLine()) + ": syntax error, unexpected NOT, expecting COMMA or SEMICOLON");
        writeIntoparserLogFile("Error at line " + to_string($NOT->getLine()) + ": syntax error, unexpected NOT, expecting COMMA or SEMICOLON");
      }
    | dl=declaration_list RELOP {$act_text = $dl.act_text;
        writeIntoErrorFile("Error at line " + to_string($RELOP->getLine()) + ": syntax error, unexpected RELOP, expecting COMMA or SEMICOLON");
        writeIntoparserLogFile("Error at line " + to_string($RELOP->getLine()) + ": syntax error, unexpected RELOP, expecting COMMA or SEMICOLON");
      }
    | dl=declaration_list LOGICOP {$act_text = $dl.act_text;
        writeIntoErrorFile("Error at line " + to_string($LOGICOP->getLine()) + ": syntax error, unexpected LOGICOP, expecting COMMA or SEMICOLON");
        writeIntoparserLogFile("Error at line " + to_string($LOGICOP->getLine()) + ": syntax error, unexpected LOGICOP, expecting COMMA or SEMICOLON");
      }
    | dl=declaration_list ASSIGNOP {$act_text = $dl.act_text;
        writeIntoErrorFile("Error at line " + to_string($ASSIGNOP->getLine()) + ": syntax error, unexpected ASSIGNOP, expecting COMMA or SEMICOLON");
        writeIntoparserLogFile("Error at line " + to_string($ASSIGNOP->getLine()) + ": syntax error, unexpected ASSIGNOP, expecting COMMA or SEMICOLON");
      }

    ;

statements
	returns[string act_text]:
	s = statement {
        $act_text = $s.act_text;
        writeIntoparserLogFile("Line " + to_string($s.stop->getLine()) + ": statements : statement\n\n" + $act_text + "\n");
    }
	| ss = statements s = statement {
        $act_text = $ss.act_text + $s.act_text;
        writeIntoparserLogFile("Line " + to_string($s.stop->getLine()) + ": statements : statements statement\n\n" + $act_text + "\n");
    };

statement
	returns[string act_text, int line]:
	vd = var_declaration {
        $act_text = $vd.act_text;
        $line = $vd.line;
        writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": statement : var_declaration\n\n" + $act_text + "\n");
    }
	| es = expression_statement {
        $act_text = $es.act_text +"\n";
        $line = $es.line;
        writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": statement : expression_statement\n\n" + $act_text + "\n");
    }
	| cs = compound_statement[true] {
        $act_text = $cs.act_text;
        writeIntoparserLogFile("Line " + to_string($cs.stop->getLine()) + ": statement : compound_statement\n\n" + $act_text + "\n");
    }
	| FOR LPAREN es1 = expression_statement es2 = expression_statement e1 = expression RPAREN s1 =
		statement {
        $act_text = "for(" + $es1.act_text + $es2.act_text + $e1.act_text + ")" + $s1.act_text ;
        writeIntoparserLogFile("Line " + to_string($s1.stop->getLine()) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" + $act_text + "\n");
    }
	| IF LPAREN e = expression RPAREN s = statement {
        $act_text = "if (" + $e.act_text + ")" + $s.act_text ;
        writeIntoparserLogFile("Line " + to_string($s.stop->getLine()) + ": statement : IF LPAREN expression RPAREN statement\n\n" + $act_text + "\n");
    }
	| IF LPAREN e = expression RPAREN s = statement ELSE s1 = statement {
        $act_text = "if (" + $e.act_text + ")" + $s.act_text + "else\n" + $s1.act_text;
        writeIntoparserLogFile("Line " + to_string($s1.stop->getLine()) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" + $act_text + "\n");
    }
	| WHILE LPAREN e = expression RPAREN s = statement {
        $act_text = "while (" + $e.act_text + ")" + $s.act_text;
        writeIntoparserLogFile("Line " + to_string($s.stop->getLine()) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" + $act_text + "\n");
    }
	| PRINTLN LPAREN ID RPAREN SEMICOLON {
        $act_text = $ctx->getText()+"\n";
        writeIntoparserLogFile("Line " + to_string($PRINTLN->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
        if(!Table.getCurrentScopeTable()->lookup($ID->getText()))
        {
            writeIntoErrorFile("Error at line " + to_string($ID->getLine()) + ": Undeclared variable " + $ID->getText() + "\n");
            writeIntoparserLogFile("Error at line " + to_string($ID->getLine()) + ": Undeclared variable " + $ID->getText() + "\n");
        }
        writeIntoparserLogFile($act_text + "\n");
    }
	| RETURN e = expression SEMICOLON {
        $act_text = "return " + $e.act_text + ";\n";
        $line = $SEMICOLON->getLine();
        writeIntoparserLogFile("Line " + to_string($RETURN->getLine()) + ": statement : RETURN expression SEMICOLON\n\n" + $act_text + "\n");
    };

expression_statement
	returns[string act_text, int line]:
	SEMICOLON {
        $act_text = $ctx->getText();
        $line = $SEMICOLON->getLine();
        writeIntoparserLogFile("Line " + to_string($SEMICOLON->getLine()) + ": expression_statement : SEMICOLON\n\n" + $act_text + "\n");
    }
	| expression SEMICOLON {
        $act_text = $ctx->getText();
        $line = $SEMICOLON->getLine();
        writeIntoparserLogFile("Line " + to_string($SEMICOLON->getLine()) + ": expression_statement : expression SEMICOLON\n\n" + $act_text + "\n");
    } 
    | expression a=ANY {
        writeIntoErrorFile("Error at line " + to_string($a->getLine()) + ": syntax error, expected SEMICOLON\n");
        writeIntoparserLogFile("Error at line " + to_string($a->getLine()) + ": syntax error, expected SEMICOLON\n");
         
    }
    ;

variable
	returns[string act_text, string type]:
	ID {
        $act_text = $ctx->getText();
        SymbolInfo* item = Table.lookup($ID->getText());
        writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": variable : ID\n");
        if (item)
        {
            $type = item->getType();
            int isArray = $type.find(' ');
            if(isArray != string::npos)
            {
                writeIntoErrorFile("Error at line " + to_string($ID->getLine()) + ": Type mismatch, " + $ID->getText() + " is an array\n");
                writeIntoparserLogFile("Error at line " + to_string($ID->getLine()) + ": Type mismatch, " + $ID->getText() + " is an array\n");
            } 
        }
        else{
            writeIntoErrorFile("Error at line " + to_string($ID->getLine()) + ": Undeclared variable " + $ID->getText() + "\n");
            writeIntoparserLogFile("Error at line " + to_string($ID->getLine()) + ": Undeclared variable " + $ID->getText() + "\n");
        }
        writeIntoparserLogFile($act_text + "\n");
        //writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": variable : ID\n\n" + $act_text + "\n");
    }
	| ID LTHIRD e=expression RTHIRD {
        $act_text = $ctx->getText();
        SymbolInfo* item = Table.getCurrentScopeTable()->lookup($ID->getText());
        writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n");
        if (item)
        {
            $type = item->getType();
            int pos = $type.find(' ');
            if(pos == string::npos)
            {
                writeIntoErrorFile("Error at line " + to_string($ID->getLine()) + ": " + $ID->getText() + " not an array\n");
                writeIntoparserLogFile("Error at line " + to_string($ID->getLine()) + ": " + $ID->getText() + " not an array\n");
            }
            $type = $type.substr(0, pos);
        }
        string exp = $e.act_text;
        int isInt = exp.find('.');
        if(isInt != string::npos)
        {
            writeIntoErrorFile("Error at line " + to_string($ID->getLine()) + ": Expression inside third brackets not an integer\n");
            //writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n");
            writeIntoparserLogFile("Error at line " + to_string($ID->getLine()) + ": Expression inside third brackets not an integer\n");
            //writeIntoparserLogFile($act_text + "\n");
        }//else
            //writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n\n" + $act_text + "\n");
        writeIntoparserLogFile($act_text + "\n");
    };

expression
	returns[string act_text, string type]:
	l=logic_expression {

        $act_text = $ctx->getText();
        $type = $l.type ;
        writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": expression : logic expression\n\n" + $act_text + "\n");
    }
	| v=variable ASSIGNOP l=logic_expression {
        $act_text = $ctx->getText();
        $type = $v.type ;
        writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": expression : variable ASSIGNOP logic_expression\n");
        if($l.type == "void")
        {
            writeIntoErrorFile("Error at line " + to_string($ctx->getStart()->getLine()) + ": Void function used in expression\n");
            writeIntoparserLogFile("Error at line " + to_string($ctx->getStart()->getLine()) + ": Void function used in expression\n");
        }
        else if($v.type!= "" && $v.type != $l.type && $v.type == "int")
        {
            writeIntoErrorFile("Error at line " + to_string($ctx->getStart()->getLine()) + ": Type Mismatch\n");
            
            writeIntoparserLogFile("Error at line " + to_string($ctx->getStart()->getLine()) + ": Type Mismatch\n");
            
        }//else
            //writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": expression : variable ASSIGNOP logic_expression\n\n" + $act_text + "\n");
            writeIntoparserLogFile($act_text + "\n");
    };

logic_expression
	returns[string act_text, string type]:
	r=rel_expression {
        $act_text = $ctx->getText();
        $type = $r.type ;
        writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": logic_expression : rel_expression\n\n" + $act_text + "\n");
    }
	| r=rel_expression LOGICOP r1=rel_expression {
        $act_text = $ctx->getText();
        $type = "int" ;
        writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": logic_expression : rel_expression LOGICOP rel_expression\n\n" + $act_text + "\n");
    };

rel_expression
	returns[string act_text, string type]:
	s=simple_expression {
        $act_text = $ctx->getText();
        $type = $s.type ;
        writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": rel_expression : simple_expression\n\n" + $act_text + "\n");
    }
	| s=simple_expression RELOP s1=simple_expression {
        $act_text = $ctx->getText();
        $type = "int" ;
        writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": rel_expression : simple_expression RELOP simple_expression\n\n" + $act_text + "\n");
    };

simple_expression
	returns[string act_text, string type]:
	t=term {
        $act_text = $ctx->getText();
        $type = $t.type ;
        writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": simple_expression : term\n\n" + $act_text + "\n");
    }
	| s=simple_expression ADDOP t=term {
        $act_text = $ctx->getText();
        $type = $t.type ;
        if($s.type == "float" || $t.type == "float")
            $type = "float";
        writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": simple_expression : simple_expression ADDOP term\n\n" + $act_text + "\n");
    } 
    |s=simple_expression ADDOP ASSIGNOP t=term
    {
        writeIntoErrorFile("Error at line " + to_string($ctx->getStart()->getLine()) + ": syntax error, unexpected ASSIGNOP\n");
        writeIntoparserLogFile("Error at line " + to_string($ctx->getStart()->getLine()) + ": syntax error, unexpected ASSIGNOP\n");
    }
    ;

term
	returns[string act_text, string type ]:
	u=unary_expression { $act_text = $ctx->getText() ; $type = $u.type ; writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": term : unary_expression \n\n" + $ctx->getText() + "\n");
		}
	| t=term MULOP u=unary_expression { 
        $act_text = $ctx->getText() ;
        $type = $u.type ;
        if($u.type == "float" || $t.type == "float")
            $type = "float";
        writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": term : term MULOP unary_expression \n");
        if($u.type == "void")
        {
            writeIntoErrorFile( "Error at line " + to_string($ctx->getStart()->getLine()) + ": Void function used in expression\n");
            writeIntoparserLogFile( "Error at line " + to_string($ctx->getStart()->getLine()) + ": Void function used in expression\n");
        }
        if($MULOP->getText()=="%" && ($t.act_text == "0" || $u.act_text == "0"))
        {
            writeIntoErrorFile("Error at line " + to_string($ctx->getStart()->getLine()) + ": Modulus by Zero\n");
            writeIntoparserLogFile("Error at line " + to_string($ctx->getStart()->getLine()) + ": Modulus by Zero\n");
        }
        else if ($MULOP->getText()=="%" && ($t.type != "int" || $u.type != "int"))
        {
            writeIntoErrorFile("Error at line " + to_string($ctx->getStart()->getLine()) + ": Non-Integer operand on modulus operator\n");
            
            writeIntoparserLogFile("Error at line " + to_string($ctx->getStart()->getLine()) + ": Non-Integer operand on modulus operator\n"); 
            
        }//else
            //writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": term : term MULOP unary_expression \n\n" + $ctx->getText() + "\n");
        writeIntoparserLogFile($ctx->getText() + "\n");
	};

unary_expression
	returns[string act_text, string type]:
	ADDOP u=unary_expression { $act_text = $ctx->getText() ; $type = $u.type ; writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": unary_expression : ADDOP unary_expression \n\n" + $ctx->getText() + "\n");
		}
	| NOT u=unary_expression { $act_text = $ctx->getText() ; $type = $u.type ; writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": unary_expression : NOT unary expression \n\n" + $ctx->getText() + "\n");
		}
	| f=factor { $act_text = $ctx->getText() ; $type = $f.type ; writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": unary_expression : factor \n\n" + $ctx->getText() + "\n");
		};

factor
	returns[string act_text, string type]:
	v=variable { 
        $act_text = $ctx->getText() ;
        $type = $v.type;
        writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": factor : variable \n\n" + $ctx->getText() + "\n");
	}
	| ID LPAREN a=argument_list RPAREN { 
        $act_text = $ctx->getText() ;
        SymbolInfo * item = Table.lookup($ID->getText());
        writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": factor : ID LPAREN argument_list RPAREN \n");
        if (item)
        {
            $type = item->getReturnType();
            if($a.types.size() != item->getParamTypes().size())
            {
                writeIntoErrorFile("Error at line " + to_string($ctx->getStart()->getLine()) + ": Total number of arguments mismatch in function " + $ID->getText() + "\n");
                writeIntoparserLogFile("Error at line " + to_string($ctx->getStart()->getLine()) + ": Total number of arguments mismatch in function " + $ID->getText() + "\n");
            }
            else if($a.types != item->getParamTypes())
            {
                writeIntoErrorFile("Error at line " + to_string($ctx->getStart()->getLine()) + ": 1th argument mismatch in function " + $ID->getText() + "\n");
                writeIntoparserLogFile("Error at line " + to_string($ctx->getStart()->getLine()) + ": 1th argument mismatch in function " + $ID->getText() + "\n");
            }
        }else
        {
            writeIntoErrorFile("Error at line " + to_string($ctx->getStart()->getLine()) + ": Undeclared function " + $ID->getText() + "\n");
            writeIntoparserLogFile("Error at line " + to_string($ctx->getStart()->getLine()) + ": Undeclared function " + $ID->getText() + "\n");
        }
        writeIntoparserLogFile($ctx->getText() + "\n");
	}
	| LPAREN e=expression RPAREN { $act_text = $ctx->getText() ; $type = $e.type; writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": factor : LPAREN expression RPAREN \n\n" + $ctx->getText() + "\n");
	}
	| CONST_INT { $act_text = $ctx->getText() ; $type = "int" ; writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": factor : CONST_INT \n\n" + $ctx->getText() + "\n");
	}
	| CONST_FLOAT { $act_text = $ctx->getText() ; $type = "float" ; writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": factor : CONST_FLOAT  \n\n" + $CONST_FLOAT->getText() + "\n");
	}
	| v=variable INCOP { $act_text = $ctx->getText() ; $type = $v.type ; writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": factor : variable INCOP \n\n" + $ctx->getText() + "\n");
	}
	| v=variable DECOP { $act_text = $ctx->getText() ; $type = $v.type ; writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": factor : variable DECOP \n\n" + $ctx->getText() + "\n");
	};

argument_list
	returns[string act_text, vector <string> types]:
	a=arguments {
         $act_text = $ctx->getText() ;
         $types = $a.types;
          writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": argument_list : arguments \n\n" + $ctx->getText() + "\n");
		}
	|;

arguments
	returns[string act_text, vector <string> types]:
	a=arguments COMMA l=logic_expression { 
        $act_text = $ctx->getText() ;
        $types = $a.types;
        $types.push_back($l.type);
        writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": arguments : arguments COMMA logic_expression \n\n" + $ctx->getText() + "\n");
	}
	| l=logic_expression { 
        $act_text = $ctx->getText() ;
        $types.push_back($l.type);
         writeIntoparserLogFile("Line " + to_string($ctx->getStart()->getLine()) + ": arguments : logic_expression \n\n" + $ctx->getText() + "\n");
		};

