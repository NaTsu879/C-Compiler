// Generated from /mnt/d/2105133/3-1/Compiler/Syntax_Analyzer/antlr4-resources/antlr4-resources/antlr4-skeletons/cpp/C8086Parser.g4 by ANTLR 4.13.1

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

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class C8086Parser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		LINE_COMMENT=1, BLOCK_COMMENT=2, STRING=3, WS=4, IF=5, ELSE=6, FOR=7, 
		WHILE=8, PRINTLN=9, RETURN=10, INT=11, FLOAT=12, VOID=13, LPAREN=14, RPAREN=15, 
		LCURL=16, RCURL=17, LTHIRD=18, RTHIRD=19, SEMICOLON=20, COMMA=21, ADDOP=22, 
		SUBOP=23, MULOP=24, INCOP=25, DECOP=26, NOT=27, RELOP=28, LOGICOP=29, 
		ASSIGNOP=30, ID=31, CONST_INT=32, CONST_FLOAT=33, ANY=34;
	public static final int
		RULE_start = 0, RULE_program = 1, RULE_unit = 2, RULE_func_declaration = 3, 
		RULE_func_definition = 4, RULE_parameter_list_err = 5, RULE_parameter_list = 6, 
		RULE_compound_statement = 7, RULE_var_declaration = 8, RULE_declaration_list_err = 9, 
		RULE_type_specifier = 10, RULE_declaration_list = 11, RULE_statements = 12, 
		RULE_statement = 13, RULE_expression_statement = 14, RULE_variable = 15, 
		RULE_expression = 16, RULE_logic_expression = 17, RULE_rel_expression = 18, 
		RULE_simple_expression = 19, RULE_term = 20, RULE_unary_expression = 21, 
		RULE_factor = 22, RULE_argument_list = 23, RULE_arguments = 24;
	private static String[] makeRuleNames() {
		return new String[] {
			"start", "program", "unit", "func_declaration", "func_definition", "parameter_list_err", 
			"parameter_list", "compound_statement", "var_declaration", "declaration_list_err", 
			"type_specifier", "declaration_list", "statements", "statement", "expression_statement", 
			"variable", "expression", "logic_expression", "rel_expression", "simple_expression", 
			"term", "unary_expression", "factor", "argument_list", "arguments"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, "'if'", "'else'", "'for'", "'while'", "'printf'", 
			"'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
			"'['", "']'", "';'", "','", null, null, null, "'++'", "'--'", "'!'", 
			null, null, "'='"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
			"FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
			"RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
			"ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", 
			"ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT", "ANY"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "C8086Parser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }


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


	public C8086Parser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StartContext extends ParserRuleContext {
		public ProgramContext p;
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public StartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_start; }
	}

	public final StartContext start() throws RecognitionException {
		StartContext _localctx = new StartContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_start);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(50);
			((StartContext)_localctx).p = program(0);

			        writeIntoparserLogFile(
			            "Line " + to_string((((StartContext)_localctx).p!=null?(((StartContext)_localctx).p.stop):null)->getLine()) +
			            ": start : program \n\n" + "\n"
			        );
			        Table.printAllScopeTable(parserLogFile);
			        writeIntoparserLogFile("Total lines: " + to_string((((StartContext)_localctx).p!=null?(((StartContext)_localctx).p.stop):null)->getLine()) +
			        "\nTotal errors: " + to_string(syntaxErrorCount) + "\n");
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public string act_text;
		public ProgramContext p;
		public UnitContext u;
		public UnitContext unit() {
			return getRuleContext(UnitContext.class,0);
		}
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		return program(0);
	}

	private ProgramContext program(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ProgramContext _localctx = new ProgramContext(_ctx, _parentState);
		ProgramContext _prevctx = _localctx;
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_program, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(54);
			((ProgramContext)_localctx).u = unit();

			        ((ProgramContext)_localctx).act_text =  ((ProgramContext)_localctx).u.act_text;
			        writeIntoparserLogFile(
			            "Line " + to_string((((ProgramContext)_localctx).u!=null?(((ProgramContext)_localctx).u.stop):null)->getLine()) +
			            ": program : unit\n\n" + _localctx.act_text + "\n"
			        );
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(63);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ProgramContext(_parentctx, _parentState);
					_localctx.p = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_program);
					setState(57);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(58);
					((ProgramContext)_localctx).u = unit();

					                  ((ProgramContext)_localctx).act_text =  ((ProgramContext)_localctx).p.act_text + ((ProgramContext)_localctx).u.act_text;
					                  writeIntoparserLogFile(
					                      "Line " + to_string((((ProgramContext)_localctx).u!=null?(((ProgramContext)_localctx).u.stop):null)->getLine()) +
					                      ": program : program unit\n\n" + _localctx.act_text + "\n"
					                  );
					              
					}
					} 
				}
				setState(65);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class UnitContext extends ParserRuleContext {
		public string act_text;
		public Var_declarationContext vd;
		public Func_declarationContext fd;
		public Func_definitionContext f;
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public Func_declarationContext func_declaration() {
			return getRuleContext(Func_declarationContext.class,0);
		}
		public Func_definitionContext func_definition() {
			return getRuleContext(Func_definitionContext.class,0);
		}
		public UnitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unit; }
	}

	public final UnitContext unit() throws RecognitionException {
		UnitContext _localctx = new UnitContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_unit);
		try {
			setState(75);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(66);
				((UnitContext)_localctx).vd = var_declaration();

				        ((UnitContext)_localctx).act_text =  ((UnitContext)_localctx).vd.act_text;
				        writeIntoparserLogFile(
				            "Line " + to_string(_localctx->getStart()->getLine()) +
				            ": unit : var_declaration\n\n" + _localctx.act_text + "\n"
				        );
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(69);
				((UnitContext)_localctx).fd = func_declaration();

				        ((UnitContext)_localctx).act_text =  ((UnitContext)_localctx).fd.act_text;
				        writeIntoparserLogFile(
				            "Line " + to_string(_localctx->getStart()->getLine()) +
				            ": unit : func_declaration\n\n" + _localctx.act_text + "\n"
				        );
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(72);
				((UnitContext)_localctx).f = func_definition();

				        ((UnitContext)_localctx).act_text =  ((UnitContext)_localctx).f.act_text + "\n";
				        writeIntoparserLogFile(
				            "Line " + to_string((((UnitContext)_localctx).f!=null?(((UnitContext)_localctx).f.stop):null)->getLine()) +
				            ": unit : func_definition\n\n" + _localctx.act_text + "\n"
				        );
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_declarationContext extends ParserRuleContext {
		public string act_text;
		public Type_specifierContext t;
		public Token ID;
		public Parameter_listContext p;
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C8086Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C8086Parser.RPAREN, 0); }
		public TerminalNode SEMICOLON() { return getToken(C8086Parser.SEMICOLON, 0); }
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public Func_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_declaration; }
	}

	public final Func_declarationContext func_declaration() throws RecognitionException {
		Func_declarationContext _localctx = new Func_declarationContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_func_declaration);
		try {
			setState(92);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(77);
				((Func_declarationContext)_localctx).t = type_specifier();
				setState(78);
				((Func_declarationContext)_localctx).ID = match(ID);
				setState(79);
				match(LPAREN);
				setState(80);
				((Func_declarationContext)_localctx).p = parameter_list(0);
				setState(81);
				match(RPAREN);
				setState(82);
				match(SEMICOLON);

				        ((Func_declarationContext)_localctx).act_text =  ((Func_declarationContext)_localctx).t.act_text + " " + ((Func_declarationContext)_localctx).ID->getText() + "(" + ((Func_declarationContext)_localctx).p.act_text + ")" + ";\n";
				        writeIntoparserLogFile(
				            "Line " + to_string(_localctx->getStart()->getLine()) +
				            ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n" +
				            _localctx.act_text + "\n"
				        );
				        insertFunctionDeclaration(((Func_declarationContext)_localctx).ID->getText(),((Func_declarationContext)_localctx).t.act_text,((Func_declarationContext)_localctx).p.act_text);
				        Table.enterScope();
				        vector <string> store = extractParamTypes(((Func_declarationContext)_localctx).p.act_text, true, true, _localctx->getStart()->getLine());
				        Table.exitScope();
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(85);
				((Func_declarationContext)_localctx).t = type_specifier();
				setState(86);
				((Func_declarationContext)_localctx).ID = match(ID);
				setState(87);
				match(LPAREN);
				setState(88);
				match(RPAREN);
				setState(89);
				match(SEMICOLON);

				         ((Func_declarationContext)_localctx).act_text =  ((Func_declarationContext)_localctx).t.act_text + " " + ((Func_declarationContext)_localctx).ID->getText() + "(" + ")" + ";\n";
				        writeIntoparserLogFile(
				            "Line " + to_string(_localctx->getStart()->getLine()) +
				            ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n" +
				            _localctx.act_text + "\n"
				        );
				        insertFunctionDeclaration(((Func_declarationContext)_localctx).ID->getText(),((Func_declarationContext)_localctx).t.act_text);
				        Table.enterScope();
				        Table.exitScope();
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_definitionContext extends ParserRuleContext {
		public string act_text;
		public int Line;
		public Type_specifierContext t;
		public Token ID;
		public Parameter_listContext p;
		public Compound_statementContext c;
		public Parameter_list_errContext pe;
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C8086Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C8086Parser.RPAREN, 0); }
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public Parameter_list_errContext parameter_list_err() {
			return getRuleContext(Parameter_list_errContext.class,0);
		}
		public Func_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_definition; }
	}

	public final Func_definitionContext func_definition() throws RecognitionException {
		Func_definitionContext _localctx = new Func_definitionContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_func_definition);
		try {
			setState(120);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(94);
				((Func_definitionContext)_localctx).t = type_specifier();
				setState(95);
				((Func_definitionContext)_localctx).ID = match(ID);
				setState(96);
				match(LPAREN);
				setState(97);
				((Func_definitionContext)_localctx).p = parameter_list(0);
				setState(98);
				match(RPAREN);

				    SymbolInfo* temp = Table.lookup(((Func_definitionContext)_localctx).ID->getText());
				        if(temp!=nullptr){
				            if(!temp->getIsDeclared())
				            {
				                //insertFunctionDeclaration(((Func_definitionContext)_localctx).ID->getText(),((Func_definitionContext)_localctx).t.act_text,((Func_definitionContext)_localctx).p.act_text,true);
				                writeIntoErrorFile("Error at line " + to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Multiple declaration of " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				                writeIntoparserLogFile("Error at line " + to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Multiple declaration of " + ((Func_definitionContext)_localctx).ID->getText() + "\n"); 
				            }
				            else{
				                if(((Func_definitionContext)_localctx).t.act_text != temp->getReturnType())
				                {
				                    writeIntoErrorFile("Error at line " + to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Return type mismatch with function declaration in function " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				                    writeIntoparserLogFile("Error at line " + to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Return type mismatch with function declaration in function " + ((Func_definitionContext)_localctx).ID->getText() + "\n");   
				                }
				                vector <string> param = extractParamTypes(((Func_definitionContext)_localctx).p.act_text, false);
				                if(param.size() != temp->getParamTypes().size())
				                {
				                    writeIntoErrorFile("Error at line " + to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Total number of arguments mismatch with declaration in function " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				                    writeIntoparserLogFile("Error at line " + to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Total number of arguments mismatch with declaration in function " + ((Func_definitionContext)_localctx).ID->getText() + "\n"); 
				                }
				            }
				            Table.enterScope();
				            vector <string> store = extractParamTypes(((Func_definitionContext)_localctx).p.act_text, true, true, _localctx->getStart()->getLine());
				        }else
				        {
				            insertFunctionDeclaration(((Func_definitionContext)_localctx).ID->getText(),((Func_definitionContext)_localctx).t.act_text,((Func_definitionContext)_localctx).p.act_text,true);
				            Table.enterScope();
				            vector <string> store = extractParamTypes(((Func_definitionContext)_localctx).p.act_text, true, true, _localctx->getStart()->getLine());
				        }
				    
				setState(100);
				((Func_definitionContext)_localctx).c = compound_statement(false);

				        ((Func_definitionContext)_localctx).act_text =  ((Func_definitionContext)_localctx).t.act_text + " " + ((Func_definitionContext)_localctx).ID->getText() + "(" + ((Func_definitionContext)_localctx).p.act_text + ")" + ((Func_definitionContext)_localctx).c.act_text;
				        ((Func_definitionContext)_localctx).Line =  ((Func_definitionContext)_localctx).c.Line;
				        writeIntoparserLogFile(
				            "Line " + to_string((((Func_definitionContext)_localctx).c!=null?(((Func_definitionContext)_localctx).c.stop):null)->getLine()) +
				            ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n" +
				            _localctx.act_text + "\n"
				        );
				        Table.exitScope();
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(103);
				((Func_definitionContext)_localctx).t = type_specifier();
				setState(104);
				((Func_definitionContext)_localctx).ID = match(ID);
				setState(105);
				match(LPAREN);
				setState(106);
				match(RPAREN);

				        SymbolInfo* temp = Table.lookup(((Func_definitionContext)_localctx).ID->getText());
				        if(temp!=nullptr){
				            if(!temp->getIsDeclared())
				                 insertFunctionDeclaration(((Func_definitionContext)_localctx).ID->getText(),((Func_definitionContext)_localctx).t.act_text,"",true);
				            Table.enterScope();
				        }else
				        {
				            insertFunctionDeclaration(((Func_definitionContext)_localctx).ID->getText(),((Func_definitionContext)_localctx).t.act_text,"",true);
				            Table.enterScope();
				        }
				    
				setState(108);
				((Func_definitionContext)_localctx).c = compound_statement(false);

				        ((Func_definitionContext)_localctx).act_text =   ((Func_definitionContext)_localctx).t.act_text + " " + ((Func_definitionContext)_localctx).ID->getText() + "(" + ")" + ((Func_definitionContext)_localctx).c.act_text;
				        ((Func_definitionContext)_localctx).Line =  ((Func_definitionContext)_localctx).c.Line;
				        writeIntoparserLogFile(
				            "Line " + to_string((((Func_definitionContext)_localctx).c!=null?(((Func_definitionContext)_localctx).c.stop):null)->getLine()) +
				            ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n" +
				            _localctx.act_text + "\n"
				        );
				        Table.exitScope();
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(111);
				((Func_definitionContext)_localctx).t = type_specifier();
				setState(112);
				((Func_definitionContext)_localctx).ID = match(ID);
				setState(113);
				match(LPAREN);
				setState(114);
				((Func_definitionContext)_localctx).pe = parameter_list_err();
				setState(115);
				match(RPAREN);

				        // This block handles error in parameter list
				        writeIntoErrorFile("Error at line " + to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Syntax error in parameter list of function " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				        writeIntoparserLogFile("Error at line " + to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Syntax error in parameter list of function " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				        Table.enterScope();  // still enter scope to allow compound_statement parsing
				    
				setState(117);
				((Func_definitionContext)_localctx).c = compound_statement(false);

				        ((Func_definitionContext)_localctx).act_text =  ((Func_definitionContext)_localctx).t.act_text + " " + ((Func_definitionContext)_localctx).ID->getText() + "(" + ((Func_definitionContext)_localctx).pe.act_text + ")" + ((Func_definitionContext)_localctx).c.act_text;
				        ((Func_definitionContext)_localctx).Line =  ((Func_definitionContext)_localctx).c.Line;
				        writeIntoparserLogFile("Line " + to_string((((Func_definitionContext)_localctx).c!=null?(((Func_definitionContext)_localctx).c.stop):null)->getLine()) + ": func_definition : type_specifier ID LPAREN parameter_list_err RPAREN compound_statement\n\n" + _localctx.act_text + "\n");
				        Table.exitScope();
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Parameter_list_errContext extends ParserRuleContext {
		public string act_text;
		public Parameter_list_errContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter_list_err; }
	}

	public final Parameter_list_errContext parameter_list_err() throws RecognitionException {
		Parameter_list_errContext _localctx = new Parameter_list_errContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_parameter_list_err);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(123); 
			_errHandler.sync(this);
			_alt = 1+1;
			do {
				switch (_alt) {
				case 1+1:
					{
					{
					setState(122);
					matchWildcard();
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(125); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			} while ( _alt!=1 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );

			    ((Parameter_list_errContext)_localctx).act_text =  _localctx->getText();

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Parameter_listContext extends ParserRuleContext {
		public string act_text;
		public Parameter_listContext p;
		public Type_specifierContext t;
		public Token ID;
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(C8086Parser.COMMA, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public Parameter_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter_list; }
	}

	public final Parameter_listContext parameter_list() throws RecognitionException {
		return parameter_list(0);
	}

	private Parameter_listContext parameter_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Parameter_listContext _localctx = new Parameter_listContext(_ctx, _parentState);
		Parameter_listContext _prevctx = _localctx;
		int _startState = 12;
		enterRecursionRule(_localctx, 12, RULE_parameter_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(137);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				{
				setState(130);
				((Parameter_listContext)_localctx).t = type_specifier();
				setState(131);
				((Parameter_listContext)_localctx).ID = match(ID);

				        ((Parameter_listContext)_localctx).act_text =  ((Parameter_listContext)_localctx).t.act_text + " " + ((Parameter_listContext)_localctx).ID->getText();
				        writeIntoparserLogFile(
				            "Line " + to_string(_localctx->getStart()->getLine()) +
				            ": parameter_list : type_specifier ID\n\n" +
				            _localctx.act_text + "\n"
				        );
				    
				}
				break;
			case 2:
				{
				setState(134);
				((Parameter_listContext)_localctx).t = type_specifier();

				        ((Parameter_listContext)_localctx).act_text =  ((Parameter_listContext)_localctx).t.act_text ;
				        writeIntoparserLogFile(
				            "Line " + to_string(_localctx->getStart()->getLine()) +
				            ": parameter_list : type_specifier\n\n" +
				            _localctx.act_text + "\n"
				        );
				    
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(152);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(150);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
					case 1:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						_localctx.p = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(139);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(140);
						match(COMMA);
						setState(141);
						((Parameter_listContext)_localctx).t = type_specifier();
						setState(142);
						((Parameter_listContext)_localctx).ID = match(ID);

						                  ((Parameter_listContext)_localctx).act_text =  ((Parameter_listContext)_localctx).p.act_text + "," + ((Parameter_listContext)_localctx).t.act_text + " " + ((Parameter_listContext)_localctx).ID->getText();
						                  writeIntoparserLogFile(
						                      "Line " + to_string(_localctx->getStart()->getLine()) +
						                      ": parameter_list : parameter_list COMMA type_specifier ID\n\n" +
						                      _localctx.act_text + "\n"
						                  );
						              
						}
						break;
					case 2:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						_localctx.p = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(145);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(146);
						match(COMMA);
						setState(147);
						((Parameter_listContext)_localctx).t = type_specifier();

						                  ((Parameter_listContext)_localctx).act_text =  ((Parameter_listContext)_localctx).p.act_text + "," + ((Parameter_listContext)_localctx).t.act_text;
						                  writeIntoparserLogFile(
						                      "Line " + to_string(_localctx->getStart()->getLine()) +
						                      ": parameter_list : parameter_list COMMA type_specifier\n\n" +
						                      _localctx.act_text + "\n"
						                  );
						              
						}
						break;
					}
					} 
				}
				setState(154);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Compound_statementContext extends ParserRuleContext {
		public bool flagScope;
		public string act_text;
		public int Line;
		public StatementsContext s;
		public Token RCURL;
		public TerminalNode LCURL() { return getToken(C8086Parser.LCURL, 0); }
		public TerminalNode RCURL() { return getToken(C8086Parser.RCURL, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public Compound_statementContext(ParserRuleContext parent, int invokingState) { super(parent, invokingState); }
		public Compound_statementContext(ParserRuleContext parent, int invokingState, bool flagScope) {
			super(parent, invokingState);
			this.flagScope = flagScope;
		}
		@Override public int getRuleIndex() { return RULE_compound_statement; }
	}

	public final Compound_statementContext compound_statement(bool flagScope) throws RecognitionException {
		Compound_statementContext _localctx = new Compound_statementContext(_ctx, getState(), flagScope);
		enterRule(_localctx, 14, RULE_compound_statement);
		try {
			setState(165);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(155);
				match(LCURL);
				if (flagScope) Table.enterScope();
				setState(157);
				((Compound_statementContext)_localctx).s = statements(0);
				setState(158);
				((Compound_statementContext)_localctx).RCURL = match(RCURL);

				        ((Compound_statementContext)_localctx).act_text =  "{\n" + ((Compound_statementContext)_localctx).s.act_text + "}\n" ;
				        ((Compound_statementContext)_localctx).Line =  ((Compound_statementContext)_localctx).RCURL->getLine();
				        writeIntoparserLogFile(
				            "Line " + to_string(((Compound_statementContext)_localctx).RCURL->getLine()) +
				            ": compound_statement : LCURL statements RCURL\n\n" +
				            _localctx.act_text + "\n\n\n"
				        );
				        Table.printAllScopeTable(parserLogFile);
				        if (flagScope) Table.exitScope();
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(161);
				match(LCURL);
				if (flagScope) Table.enterScope();
				setState(163);
				((Compound_statementContext)_localctx).RCURL = match(RCURL);

				        ((Compound_statementContext)_localctx).act_text =  _localctx->getText();
				        ((Compound_statementContext)_localctx).Line =  ((Compound_statementContext)_localctx).RCURL->getLine();
				        writeIntoparserLogFile(
				            "Line " + to_string(((Compound_statementContext)_localctx).RCURL->getLine()) +
				            ": compound_statement : LCURL RCURL\n\n" +
				            _localctx.act_text + "\n\n\n"
				        );
				        Table.printAllScopeTable(parserLogFile);
				        if (flagScope) Table.exitScope();
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Var_declarationContext extends ParserRuleContext {
		public string act_text;
		public int line;
		public Type_specifierContext t;
		public Declaration_listContext dl;
		public Token sm;
		public Declaration_list_errContext de;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(C8086Parser.SEMICOLON, 0); }
		public Declaration_list_errContext declaration_list_err() {
			return getRuleContext(Declaration_list_errContext.class,0);
		}
		public Var_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var_declaration; }
	}

	public final Var_declarationContext var_declaration() throws RecognitionException {
		Var_declarationContext _localctx = new Var_declarationContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_var_declaration);
		try {
			setState(177);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(167);
				((Var_declarationContext)_localctx).t = type_specifier();
				setState(168);
				((Var_declarationContext)_localctx).dl = declaration_list(0);
				setState(169);
				((Var_declarationContext)_localctx).sm = match(SEMICOLON);

				        ((Var_declarationContext)_localctx).act_text =  ((Var_declarationContext)_localctx).t.act_text + " " + ((Var_declarationContext)_localctx).dl.act_text + ";\n" ;
				        ((Var_declarationContext)_localctx).line =  ((Var_declarationContext)_localctx).sm->getLine();
				        writeIntoparserLogFile("Line " + to_string(((Var_declarationContext)_localctx).sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON \n");
				        if(((Var_declarationContext)_localctx).t.act_text == "void")
				        {
				            writeIntoErrorFile("Error at line " + to_string(((Var_declarationContext)_localctx).sm->getLine()) + ": Variable type cannot be void " + "\n");
				            writeIntoparserLogFile("Error at line " + to_string(((Var_declarationContext)_localctx).sm->getLine()) + ": Variable type cannot be void " + "\n"); 
				            
				        }else
				            insertVarDeclarations(((Var_declarationContext)_localctx).t.act_text, ((Var_declarationContext)_localctx).dl.act_text);
				        writeIntoparserLogFile(_localctx.act_text);
				      
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(172);
				((Var_declarationContext)_localctx).t = type_specifier();
				setState(173);
				((Var_declarationContext)_localctx).de = declaration_list_err();
				setState(174);
				((Var_declarationContext)_localctx).sm = match(SEMICOLON);

				        writeIntoErrorFile(
				            string("Line# ") + to_string(((Var_declarationContext)_localctx).sm->getLine()) +
				            " with error name: " + ((Var_declarationContext)_localctx).de.error_name +
				            " - Syntax error at declaration list of variable declaration"
				        );

				        syntaxErrorCount++;
				      
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_list_errContext extends ParserRuleContext {
		public string error_name;
		public Declaration_list_errContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration_list_err; }
	}

	public final Declaration_list_errContext declaration_list_err() throws RecognitionException {
		Declaration_list_errContext _localctx = new Declaration_list_errContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_declaration_list_err);
		try {
			enterOuterAlt(_localctx, 1);
			{

			        ((Declaration_list_errContext)_localctx).error_name =  "Error in declaration list";
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Type_specifierContext extends ParserRuleContext {
		public string act_text;
		public Token INT;
		public Token FLOAT;
		public Token VOID;
		public TerminalNode INT() { return getToken(C8086Parser.INT, 0); }
		public TerminalNode FLOAT() { return getToken(C8086Parser.FLOAT, 0); }
		public TerminalNode VOID() { return getToken(C8086Parser.VOID, 0); }
		public Type_specifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_specifier; }
	}

	public final Type_specifierContext type_specifier() throws RecognitionException {
		Type_specifierContext _localctx = new Type_specifierContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_type_specifier);
		try {
			setState(187);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(181);
				((Type_specifierContext)_localctx).INT = match(INT);

				            ((Type_specifierContext)_localctx).act_text =  _localctx->getText();
				            writeIntoparserLogFile("Line " + to_string(((Type_specifierContext)_localctx).INT->getLine()) + ": type_specifier : INT \n\nint \n");
				        
				}
				break;
			case FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(183);
				((Type_specifierContext)_localctx).FLOAT = match(FLOAT);

				            ((Type_specifierContext)_localctx).act_text =  _localctx->getText();
				             writeIntoparserLogFile("Line " + to_string(((Type_specifierContext)_localctx).FLOAT->getLine()) + ": type_specifier : FLOAT \n\nfloat \n");
				        
				}
				break;
			case VOID:
				enterOuterAlt(_localctx, 3);
				{
				setState(185);
				((Type_specifierContext)_localctx).VOID = match(VOID);

				            ((Type_specifierContext)_localctx).act_text =  _localctx->getText();
				            writeIntoparserLogFile("Line " + to_string(((Type_specifierContext)_localctx).VOID->getLine()) + ": type_specifier : VOID \n\nvoid \n");
				        
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_listContext extends ParserRuleContext {
		public string act_text;
		public Declaration_listContext dl;
		public Token ID;
		public Token CONST_INT;
		public Token ADDOP;
		public Token SUBOP;
		public Token MULOP;
		public Token INCOP;
		public Token DECOP;
		public Token NOT;
		public Token RELOP;
		public Token LOGICOP;
		public Token ASSIGNOP;
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C8086Parser.LTHIRD, 0); }
		public TerminalNode CONST_INT() { return getToken(C8086Parser.CONST_INT, 0); }
		public TerminalNode RTHIRD() { return getToken(C8086Parser.RTHIRD, 0); }
		public TerminalNode COMMA() { return getToken(C8086Parser.COMMA, 0); }
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public TerminalNode ADDOP() { return getToken(C8086Parser.ADDOP, 0); }
		public TerminalNode SUBOP() { return getToken(C8086Parser.SUBOP, 0); }
		public TerminalNode MULOP() { return getToken(C8086Parser.MULOP, 0); }
		public TerminalNode INCOP() { return getToken(C8086Parser.INCOP, 0); }
		public TerminalNode DECOP() { return getToken(C8086Parser.DECOP, 0); }
		public TerminalNode NOT() { return getToken(C8086Parser.NOT, 0); }
		public TerminalNode RELOP() { return getToken(C8086Parser.RELOP, 0); }
		public TerminalNode LOGICOP() { return getToken(C8086Parser.LOGICOP, 0); }
		public TerminalNode ASSIGNOP() { return getToken(C8086Parser.ASSIGNOP, 0); }
		public Declaration_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration_list; }
	}

	public final Declaration_listContext declaration_list() throws RecognitionException {
		return declaration_list(0);
	}

	private Declaration_listContext declaration_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Declaration_listContext _localctx = new Declaration_listContext(_ctx, _parentState);
		Declaration_listContext _prevctx = _localctx;
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_declaration_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(197);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				{
				setState(190);
				((Declaration_listContext)_localctx).ID = match(ID);
				 
				        ((Declaration_listContext)_localctx).act_text =  _localctx->getText(); 
				        if(Table.getCurrentScopeTable()->lookup(((Declaration_listContext)_localctx).ID->getText()))
				        {
				            writeIntoErrorFile("Error at line " + to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": Multiple declaration of " + ((Declaration_listContext)_localctx).ID->getText() + "\n");
				            writeIntoparserLogFile("Error at line " + to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": Multiple declaration of " + ((Declaration_listContext)_localctx).ID->getText() + "\n");
				        }
				        writeIntoparserLogFile("Line " + to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": declaration_list : ID \n\n" + _localctx->getText() + "\n");
					
				}
				break;
			case 2:
				{
				setState(192);
				((Declaration_listContext)_localctx).ID = match(ID);
				setState(193);
				match(LTHIRD);
				setState(194);
				((Declaration_listContext)_localctx).CONST_INT = match(CONST_INT);
				setState(195);
				match(RTHIRD);
				 
				        ((Declaration_listContext)_localctx).act_text =  _localctx->getText();
				        if(Table.getCurrentScopeTable()->lookup(((Declaration_listContext)_localctx).ID->getText()))
				        {
				            writeIntoErrorFile("Error at line " + to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": Multiple declaration of " + ((Declaration_listContext)_localctx).ID->getText() + "\n");
				            writeIntoparserLogFile("Error at line " + to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": Multiple declaration of " + ((Declaration_listContext)_localctx).ID->getText() + "\n");
				        }
				        writeIntoparserLogFile("Line " + to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD \n\n" + _localctx->getText() + "\n");
					
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(242);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(240);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
					case 1:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(199);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(200);
						match(COMMA);
						setState(201);
						((Declaration_listContext)_localctx).ID = match(ID);
						 
						                  ((Declaration_listContext)_localctx).act_text =  ((Declaration_listContext)_localctx).dl.act_text + "," + ((Declaration_listContext)_localctx).ID->getText()  ;
						                  if(Table.getCurrentScopeTable()->lookup(((Declaration_listContext)_localctx).ID->getText()))
						                  {
						                      writeIntoErrorFile("Error at line " + to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": Multiple declaration of " + ((Declaration_listContext)_localctx).ID->getText() + "\n");
						                      writeIntoparserLogFile("Error at line " + to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": Multiple declaration of " + ((Declaration_listContext)_localctx).ID->getText() + "\n");
						                  }
						                  writeIntoparserLogFile("Line " + to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": declaration_list : declaration_list COMMA ID \n\n" + _localctx.act_text + "\n");
						          	
						}
						break;
					case 2:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(203);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(204);
						match(COMMA);
						setState(205);
						((Declaration_listContext)_localctx).ID = match(ID);
						setState(206);
						match(LTHIRD);
						setState(207);
						((Declaration_listContext)_localctx).CONST_INT = match(CONST_INT);
						setState(208);
						match(RTHIRD);
						 
						                  ((Declaration_listContext)_localctx).act_text =  ((Declaration_listContext)_localctx).dl.act_text + "," + ((Declaration_listContext)_localctx).ID->getText() + "[" + ((Declaration_listContext)_localctx).CONST_INT->getText() + "]" ;
						                  if(Table.getCurrentScopeTable()->lookup(((Declaration_listContext)_localctx).ID->getText()))
						                  {
						                      writeIntoErrorFile("Error at line " + to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": Multiple declaration of " + ((Declaration_listContext)_localctx).ID->getText() + "\n");
						                      writeIntoparserLogFile("Error at line " + to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": Multiple declaration of " + ((Declaration_listContext)_localctx).ID->getText() + "\n");
						                  } 
						                  writeIntoparserLogFile("Line " + to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD \n\n" + _localctx.act_text + "\n");
						          	
						}
						break;
					case 3:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(210);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(211);
						((Declaration_listContext)_localctx).ADDOP = match(ADDOP);
						((Declaration_listContext)_localctx).act_text =  ((Declaration_listContext)_localctx).dl.act_text;
						                  writeIntoErrorFile("Error at line " + to_string(((Declaration_listContext)_localctx).ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON");
						                  writeIntoparserLogFile("Error at line " + to_string(((Declaration_listContext)_localctx).ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON");
						                
						}
						break;
					case 4:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(213);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(214);
						((Declaration_listContext)_localctx).ID = match(ID);
						((Declaration_listContext)_localctx).act_text =  ((Declaration_listContext)_localctx).dl.act_text;
						                  writeIntoErrorFile("Error at line " + to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": syntax error, unexpected ID, expecting COMMA or SEMICOLON");
						                  writeIntoparserLogFile("Error at line " + to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": syntax error, unexpected ID, expecting COMMA or SEMICOLON");
						                
						}
						break;
					case 5:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(216);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(217);
						((Declaration_listContext)_localctx).SUBOP = match(SUBOP);
						((Declaration_listContext)_localctx).act_text =  ((Declaration_listContext)_localctx).dl.act_text;
						                  writeIntoErrorFile("Error at line " + to_string(((Declaration_listContext)_localctx).SUBOP->getLine()) + ": syntax error, unexpected SUBOP, expecting COMMA or SEMICOLON");
						                  writeIntoparserLogFile("Error at line " + to_string(((Declaration_listContext)_localctx).SUBOP->getLine()) + ": syntax error, unexpected SUBOP, expecting COMMA or SEMICOLON");
						                
						}
						break;
					case 6:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(219);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(220);
						((Declaration_listContext)_localctx).MULOP = match(MULOP);
						((Declaration_listContext)_localctx).act_text =  ((Declaration_listContext)_localctx).dl.act_text;
						                  writeIntoErrorFile("Error at line " + to_string(((Declaration_listContext)_localctx).MULOP->getLine()) + ": syntax error, unexpected MULOP, expecting COMMA or SEMICOLON");
						                  writeIntoparserLogFile("Error at line " + to_string(((Declaration_listContext)_localctx).MULOP->getLine()) + ": syntax error, unexpected MULOP, expecting COMMA or SEMICOLON");
						                
						}
						break;
					case 7:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(222);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(223);
						((Declaration_listContext)_localctx).INCOP = match(INCOP);
						((Declaration_listContext)_localctx).act_text =  ((Declaration_listContext)_localctx).dl.act_text;
						                  writeIntoErrorFile("Error at line " + to_string(((Declaration_listContext)_localctx).INCOP->getLine()) + ": syntax error, unexpected INCOP, expecting COMMA or SEMICOLON");
						                  writeIntoparserLogFile("Error at line " + to_string(((Declaration_listContext)_localctx).INCOP->getLine()) + ": syntax error, unexpected INCOP, expecting COMMA or SEMICOLON");
						                
						}
						break;
					case 8:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(225);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(226);
						((Declaration_listContext)_localctx).DECOP = match(DECOP);
						((Declaration_listContext)_localctx).act_text =  ((Declaration_listContext)_localctx).dl.act_text;
						                  writeIntoErrorFile("Error at line " + to_string(((Declaration_listContext)_localctx).DECOP->getLine()) + ": syntax error, unexpected DECOP, expecting COMMA or SEMICOLON");
						                  writeIntoparserLogFile("Error at line " + to_string(((Declaration_listContext)_localctx).DECOP->getLine()) + ": syntax error, unexpected DECOP, expecting COMMA or SEMICOLON");
						                
						}
						break;
					case 9:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(228);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(229);
						((Declaration_listContext)_localctx).NOT = match(NOT);
						((Declaration_listContext)_localctx).act_text =  ((Declaration_listContext)_localctx).dl.act_text;
						                  writeIntoErrorFile("Error at line " + to_string(((Declaration_listContext)_localctx).NOT->getLine()) + ": syntax error, unexpected NOT, expecting COMMA or SEMICOLON");
						                  writeIntoparserLogFile("Error at line " + to_string(((Declaration_listContext)_localctx).NOT->getLine()) + ": syntax error, unexpected NOT, expecting COMMA or SEMICOLON");
						                
						}
						break;
					case 10:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(231);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(232);
						((Declaration_listContext)_localctx).RELOP = match(RELOP);
						((Declaration_listContext)_localctx).act_text =  ((Declaration_listContext)_localctx).dl.act_text;
						                  writeIntoErrorFile("Error at line " + to_string(((Declaration_listContext)_localctx).RELOP->getLine()) + ": syntax error, unexpected RELOP, expecting COMMA or SEMICOLON");
						                  writeIntoparserLogFile("Error at line " + to_string(((Declaration_listContext)_localctx).RELOP->getLine()) + ": syntax error, unexpected RELOP, expecting COMMA or SEMICOLON");
						                
						}
						break;
					case 11:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(234);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(235);
						((Declaration_listContext)_localctx).LOGICOP = match(LOGICOP);
						((Declaration_listContext)_localctx).act_text =  ((Declaration_listContext)_localctx).dl.act_text;
						                  writeIntoErrorFile("Error at line " + to_string(((Declaration_listContext)_localctx).LOGICOP->getLine()) + ": syntax error, unexpected LOGICOP, expecting COMMA or SEMICOLON");
						                  writeIntoparserLogFile("Error at line " + to_string(((Declaration_listContext)_localctx).LOGICOP->getLine()) + ": syntax error, unexpected LOGICOP, expecting COMMA or SEMICOLON");
						                
						}
						break;
					case 12:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(237);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(238);
						((Declaration_listContext)_localctx).ASSIGNOP = match(ASSIGNOP);
						((Declaration_listContext)_localctx).act_text =  ((Declaration_listContext)_localctx).dl.act_text;
						                  writeIntoErrorFile("Error at line " + to_string(((Declaration_listContext)_localctx).ASSIGNOP->getLine()) + ": syntax error, unexpected ASSIGNOP, expecting COMMA or SEMICOLON");
						                  writeIntoparserLogFile("Error at line " + to_string(((Declaration_listContext)_localctx).ASSIGNOP->getLine()) + ": syntax error, unexpected ASSIGNOP, expecting COMMA or SEMICOLON");
						                
						}
						break;
					}
					} 
				}
				setState(244);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementsContext extends ParserRuleContext {
		public string act_text;
		public StatementsContext ss;
		public StatementContext s;
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public StatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statements; }
	}

	public final StatementsContext statements() throws RecognitionException {
		return statements(0);
	}

	private StatementsContext statements(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		StatementsContext _localctx = new StatementsContext(_ctx, _parentState);
		StatementsContext _prevctx = _localctx;
		int _startState = 24;
		enterRecursionRule(_localctx, 24, RULE_statements, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(246);
			((StatementsContext)_localctx).s = statement();

			        ((StatementsContext)_localctx).act_text =  ((StatementsContext)_localctx).s.act_text;
			        writeIntoparserLogFile("Line " + to_string((((StatementsContext)_localctx).s!=null?(((StatementsContext)_localctx).s.stop):null)->getLine()) + ": statements : statement\n\n" + _localctx.act_text + "\n");
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(255);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new StatementsContext(_parentctx, _parentState);
					_localctx.ss = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_statements);
					setState(249);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(250);
					((StatementsContext)_localctx).s = statement();

					                  ((StatementsContext)_localctx).act_text =  ((StatementsContext)_localctx).ss.act_text + ((StatementsContext)_localctx).s.act_text;
					                  writeIntoparserLogFile("Line " + to_string((((StatementsContext)_localctx).s!=null?(((StatementsContext)_localctx).s.stop):null)->getLine()) + ": statements : statements statement\n\n" + _localctx.act_text + "\n");
					              
					}
					} 
				}
				setState(257);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementContext extends ParserRuleContext {
		public string act_text;
		public int line;
		public Var_declarationContext vd;
		public Expression_statementContext es;
		public Compound_statementContext cs;
		public Expression_statementContext es1;
		public Expression_statementContext es2;
		public ExpressionContext e1;
		public StatementContext s1;
		public ExpressionContext e;
		public StatementContext s;
		public Token PRINTLN;
		public Token ID;
		public Token RETURN;
		public Token SEMICOLON;
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public List<Expression_statementContext> expression_statement() {
			return getRuleContexts(Expression_statementContext.class);
		}
		public Expression_statementContext expression_statement(int i) {
			return getRuleContext(Expression_statementContext.class,i);
		}
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public TerminalNode FOR() { return getToken(C8086Parser.FOR, 0); }
		public TerminalNode LPAREN() { return getToken(C8086Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C8086Parser.RPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode IF() { return getToken(C8086Parser.IF, 0); }
		public TerminalNode ELSE() { return getToken(C8086Parser.ELSE, 0); }
		public TerminalNode WHILE() { return getToken(C8086Parser.WHILE, 0); }
		public TerminalNode PRINTLN() { return getToken(C8086Parser.PRINTLN, 0); }
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode SEMICOLON() { return getToken(C8086Parser.SEMICOLON, 0); }
		public TerminalNode RETURN() { return getToken(C8086Parser.RETURN, 0); }
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_statement);
		try {
			setState(310);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(258);
				((StatementContext)_localctx).vd = var_declaration();

				        ((StatementContext)_localctx).act_text =  ((StatementContext)_localctx).vd.act_text;
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).vd.line;
				        writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": statement : var_declaration\n\n" + _localctx.act_text + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(261);
				((StatementContext)_localctx).es = expression_statement();

				        ((StatementContext)_localctx).act_text =  ((StatementContext)_localctx).es.act_text +"\n";
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).es.line;
				        writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": statement : expression_statement\n\n" + _localctx.act_text + "\n");
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(264);
				((StatementContext)_localctx).cs = compound_statement(true);

				        ((StatementContext)_localctx).act_text =  ((StatementContext)_localctx).cs.act_text;
				        writeIntoparserLogFile("Line " + to_string((((StatementContext)_localctx).cs!=null?(((StatementContext)_localctx).cs.stop):null)->getLine()) + ": statement : compound_statement\n\n" + _localctx.act_text + "\n");
				    
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(267);
				match(FOR);
				setState(268);
				match(LPAREN);
				setState(269);
				((StatementContext)_localctx).es1 = expression_statement();
				setState(270);
				((StatementContext)_localctx).es2 = expression_statement();
				setState(271);
				((StatementContext)_localctx).e1 = expression();
				setState(272);
				match(RPAREN);
				setState(273);
				((StatementContext)_localctx).s1 = statement();

				        ((StatementContext)_localctx).act_text =  "for(" + ((StatementContext)_localctx).es1.act_text + ((StatementContext)_localctx).es2.act_text + ((StatementContext)_localctx).e1.act_text + ")" + ((StatementContext)_localctx).s1.act_text ;
				        writeIntoparserLogFile("Line " + to_string((((StatementContext)_localctx).s1!=null?(((StatementContext)_localctx).s1.stop):null)->getLine()) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" + _localctx.act_text + "\n");
				    
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(276);
				match(IF);
				setState(277);
				match(LPAREN);
				setState(278);
				((StatementContext)_localctx).e = expression();
				setState(279);
				match(RPAREN);
				setState(280);
				((StatementContext)_localctx).s = statement();

				        ((StatementContext)_localctx).act_text =  "if (" + ((StatementContext)_localctx).e.act_text + ")" + ((StatementContext)_localctx).s.act_text ;
				        writeIntoparserLogFile("Line " + to_string((((StatementContext)_localctx).s!=null?(((StatementContext)_localctx).s.stop):null)->getLine()) + ": statement : IF LPAREN expression RPAREN statement\n\n" + _localctx.act_text + "\n");
				    
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(283);
				match(IF);
				setState(284);
				match(LPAREN);
				setState(285);
				((StatementContext)_localctx).e = expression();
				setState(286);
				match(RPAREN);
				setState(287);
				((StatementContext)_localctx).s = statement();
				setState(288);
				match(ELSE);
				setState(289);
				((StatementContext)_localctx).s1 = statement();

				        ((StatementContext)_localctx).act_text =  "if (" + ((StatementContext)_localctx).e.act_text + ")" + ((StatementContext)_localctx).s.act_text + "else\n" + ((StatementContext)_localctx).s1.act_text;
				        writeIntoparserLogFile("Line " + to_string((((StatementContext)_localctx).s1!=null?(((StatementContext)_localctx).s1.stop):null)->getLine()) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" + _localctx.act_text + "\n");
				    
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(292);
				match(WHILE);
				setState(293);
				match(LPAREN);
				setState(294);
				((StatementContext)_localctx).e = expression();
				setState(295);
				match(RPAREN);
				setState(296);
				((StatementContext)_localctx).s = statement();

				        ((StatementContext)_localctx).act_text =  "while (" + ((StatementContext)_localctx).e.act_text + ")" + ((StatementContext)_localctx).s.act_text;
				        writeIntoparserLogFile("Line " + to_string((((StatementContext)_localctx).s!=null?(((StatementContext)_localctx).s.stop):null)->getLine()) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" + _localctx.act_text + "\n");
				    
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(299);
				((StatementContext)_localctx).PRINTLN = match(PRINTLN);
				setState(300);
				match(LPAREN);
				setState(301);
				((StatementContext)_localctx).ID = match(ID);
				setState(302);
				match(RPAREN);
				setState(303);
				match(SEMICOLON);

				        ((StatementContext)_localctx).act_text =  _localctx->getText()+"\n";
				        writeIntoparserLogFile("Line " + to_string(((StatementContext)_localctx).PRINTLN->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
				        if(!Table.getCurrentScopeTable()->lookup(((StatementContext)_localctx).ID->getText()))
				        {
				            writeIntoErrorFile("Error at line " + to_string(((StatementContext)_localctx).ID->getLine()) + ": Undeclared variable " + ((StatementContext)_localctx).ID->getText() + "\n");
				            writeIntoparserLogFile("Error at line " + to_string(((StatementContext)_localctx).ID->getLine()) + ": Undeclared variable " + ((StatementContext)_localctx).ID->getText() + "\n");
				        }
				        writeIntoparserLogFile(_localctx.act_text + "\n");
				    
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(305);
				((StatementContext)_localctx).RETURN = match(RETURN);
				setState(306);
				((StatementContext)_localctx).e = expression();
				setState(307);
				((StatementContext)_localctx).SEMICOLON = match(SEMICOLON);

				        ((StatementContext)_localctx).act_text =  "return " + ((StatementContext)_localctx).e.act_text + ";\n";
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).SEMICOLON->getLine();
				        writeIntoparserLogFile("Line " + to_string(((StatementContext)_localctx).RETURN->getLine()) + ": statement : RETURN expression SEMICOLON\n\n" + _localctx.act_text + "\n");
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Expression_statementContext extends ParserRuleContext {
		public string act_text;
		public int line;
		public Token SEMICOLON;
		public Token a;
		public TerminalNode SEMICOLON() { return getToken(C8086Parser.SEMICOLON, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode ANY() { return getToken(C8086Parser.ANY, 0); }
		public Expression_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression_statement; }
	}

	public final Expression_statementContext expression_statement() throws RecognitionException {
		Expression_statementContext _localctx = new Expression_statementContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_expression_statement);
		try {
			setState(322);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(312);
				((Expression_statementContext)_localctx).SEMICOLON = match(SEMICOLON);

				        ((Expression_statementContext)_localctx).act_text =  _localctx->getText();
				        ((Expression_statementContext)_localctx).line =  ((Expression_statementContext)_localctx).SEMICOLON->getLine();
				        writeIntoparserLogFile("Line " + to_string(((Expression_statementContext)_localctx).SEMICOLON->getLine()) + ": expression_statement : SEMICOLON\n\n" + _localctx.act_text + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(314);
				expression();
				setState(315);
				((Expression_statementContext)_localctx).SEMICOLON = match(SEMICOLON);

				        ((Expression_statementContext)_localctx).act_text =  _localctx->getText();
				        ((Expression_statementContext)_localctx).line =  ((Expression_statementContext)_localctx).SEMICOLON->getLine();
				        writeIntoparserLogFile("Line " + to_string(((Expression_statementContext)_localctx).SEMICOLON->getLine()) + ": expression_statement : expression SEMICOLON\n\n" + _localctx.act_text + "\n");
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(318);
				expression();
				setState(319);
				((Expression_statementContext)_localctx).a = match(ANY);

				        writeIntoErrorFile("Error at line " + to_string(((Expression_statementContext)_localctx).a->getLine()) + ": syntax error, expected SEMICOLON\n");
				        writeIntoparserLogFile("Error at line " + to_string(((Expression_statementContext)_localctx).a->getLine()) + ": syntax error, expected SEMICOLON\n");
				         
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VariableContext extends ParserRuleContext {
		public string act_text;
		public string type;
		public Token ID;
		public ExpressionContext e;
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C8086Parser.LTHIRD, 0); }
		public TerminalNode RTHIRD() { return getToken(C8086Parser.RTHIRD, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_variable);
		try {
			setState(332);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(324);
				((VariableContext)_localctx).ID = match(ID);

				        ((VariableContext)_localctx).act_text =  _localctx->getText();
				        SymbolInfo* item = Table.lookup(((VariableContext)_localctx).ID->getText());
				        writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": variable : ID\n");
				        if (item)
				        {
				            ((VariableContext)_localctx).type =  item->getType();
				            int isArray = _localctx.type.find(' ');
				            if(isArray != string::npos)
				            {
				                writeIntoErrorFile("Error at line " + to_string(((VariableContext)_localctx).ID->getLine()) + ": Type mismatch, " + ((VariableContext)_localctx).ID->getText() + " is an array\n");
				                writeIntoparserLogFile("Error at line " + to_string(((VariableContext)_localctx).ID->getLine()) + ": Type mismatch, " + ((VariableContext)_localctx).ID->getText() + " is an array\n");
				            } 
				        }
				        else{
				            writeIntoErrorFile("Error at line " + to_string(((VariableContext)_localctx).ID->getLine()) + ": Undeclared variable " + ((VariableContext)_localctx).ID->getText() + "\n");
				            writeIntoparserLogFile("Error at line " + to_string(((VariableContext)_localctx).ID->getLine()) + ": Undeclared variable " + ((VariableContext)_localctx).ID->getText() + "\n");
				        }
				        writeIntoparserLogFile(_localctx.act_text + "\n");
				        //writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": variable : ID\n\n" + _localctx.act_text + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(326);
				((VariableContext)_localctx).ID = match(ID);
				setState(327);
				match(LTHIRD);
				setState(328);
				((VariableContext)_localctx).e = expression();
				setState(329);
				match(RTHIRD);

				        ((VariableContext)_localctx).act_text =  _localctx->getText();
				        SymbolInfo* item = Table.getCurrentScopeTable()->lookup(((VariableContext)_localctx).ID->getText());
				        writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n");
				        if (item)
				        {
				            ((VariableContext)_localctx).type =  item->getType();
				            int pos = _localctx.type.find(' ');
				            if(pos == string::npos)
				            {
				                writeIntoErrorFile("Error at line " + to_string(((VariableContext)_localctx).ID->getLine()) + ": " + ((VariableContext)_localctx).ID->getText() + " not an array\n");
				                writeIntoparserLogFile("Error at line " + to_string(((VariableContext)_localctx).ID->getLine()) + ": " + ((VariableContext)_localctx).ID->getText() + " not an array\n");
				            }
				            ((VariableContext)_localctx).type =  _localctx.type.substr(0, pos);
				        }
				        string exp = ((VariableContext)_localctx).e.act_text;
				        int isInt = exp.find('.');
				        if(isInt != string::npos)
				        {
				            writeIntoErrorFile("Error at line " + to_string(((VariableContext)_localctx).ID->getLine()) + ": Expression inside third brackets not an integer\n");
				            //writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n");
				            writeIntoparserLogFile("Error at line " + to_string(((VariableContext)_localctx).ID->getLine()) + ": Expression inside third brackets not an integer\n");
				            //writeIntoparserLogFile(_localctx.act_text + "\n");
				        }//else
				            //writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n\n" + _localctx.act_text + "\n");
				        writeIntoparserLogFile(_localctx.act_text + "\n");
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public string act_text;
		public string type;
		public Logic_expressionContext l;
		public VariableContext v;
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public TerminalNode ASSIGNOP() { return getToken(C8086Parser.ASSIGNOP, 0); }
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_expression);
		try {
			setState(342);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(334);
				((ExpressionContext)_localctx).l = logic_expression();


				        ((ExpressionContext)_localctx).act_text =  _localctx->getText();
				        ((ExpressionContext)_localctx).type =  ((ExpressionContext)_localctx).l.type ;
				        writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": expression : logic expression\n\n" + _localctx.act_text + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(337);
				((ExpressionContext)_localctx).v = variable();
				setState(338);
				match(ASSIGNOP);
				setState(339);
				((ExpressionContext)_localctx).l = logic_expression();

				        ((ExpressionContext)_localctx).act_text =  _localctx->getText();
				        ((ExpressionContext)_localctx).type =  ((ExpressionContext)_localctx).v.type ;
				        writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": expression : variable ASSIGNOP logic_expression\n");
				        if(((ExpressionContext)_localctx).l.type == "void")
				        {
				            writeIntoErrorFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Void function used in expression\n");
				            writeIntoparserLogFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Void function used in expression\n");
				        }
				        else if(((ExpressionContext)_localctx).v.type!= "" && ((ExpressionContext)_localctx).v.type != ((ExpressionContext)_localctx).l.type && ((ExpressionContext)_localctx).v.type == "int")
				        {
				            writeIntoErrorFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Type Mismatch\n");
				            
				            writeIntoparserLogFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Type Mismatch\n");
				            
				        }//else
				            //writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": expression : variable ASSIGNOP logic_expression\n\n" + _localctx.act_text + "\n");
				            writeIntoparserLogFile(_localctx.act_text + "\n");
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Logic_expressionContext extends ParserRuleContext {
		public string act_text;
		public string type;
		public Rel_expressionContext r;
		public Rel_expressionContext r1;
		public List<Rel_expressionContext> rel_expression() {
			return getRuleContexts(Rel_expressionContext.class);
		}
		public Rel_expressionContext rel_expression(int i) {
			return getRuleContext(Rel_expressionContext.class,i);
		}
		public TerminalNode LOGICOP() { return getToken(C8086Parser.LOGICOP, 0); }
		public Logic_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logic_expression; }
	}

	public final Logic_expressionContext logic_expression() throws RecognitionException {
		Logic_expressionContext _localctx = new Logic_expressionContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_logic_expression);
		try {
			setState(352);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(344);
				((Logic_expressionContext)_localctx).r = rel_expression();

				        ((Logic_expressionContext)_localctx).act_text =  _localctx->getText();
				        ((Logic_expressionContext)_localctx).type =  ((Logic_expressionContext)_localctx).r.type ;
				        writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": logic_expression : rel_expression\n\n" + _localctx.act_text + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(347);
				((Logic_expressionContext)_localctx).r = rel_expression();
				setState(348);
				match(LOGICOP);
				setState(349);
				((Logic_expressionContext)_localctx).r1 = rel_expression();

				        ((Logic_expressionContext)_localctx).act_text =  _localctx->getText();
				        ((Logic_expressionContext)_localctx).type =  "int" ;
				        writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": logic_expression : rel_expression LOGICOP rel_expression\n\n" + _localctx.act_text + "\n");
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Rel_expressionContext extends ParserRuleContext {
		public string act_text;
		public string type;
		public Simple_expressionContext s;
		public Simple_expressionContext s1;
		public List<Simple_expressionContext> simple_expression() {
			return getRuleContexts(Simple_expressionContext.class);
		}
		public Simple_expressionContext simple_expression(int i) {
			return getRuleContext(Simple_expressionContext.class,i);
		}
		public TerminalNode RELOP() { return getToken(C8086Parser.RELOP, 0); }
		public Rel_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rel_expression; }
	}

	public final Rel_expressionContext rel_expression() throws RecognitionException {
		Rel_expressionContext _localctx = new Rel_expressionContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_rel_expression);
		try {
			setState(362);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(354);
				((Rel_expressionContext)_localctx).s = simple_expression(0);

				        ((Rel_expressionContext)_localctx).act_text =  _localctx->getText();
				        ((Rel_expressionContext)_localctx).type =  ((Rel_expressionContext)_localctx).s.type ;
				        writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": rel_expression : simple_expression\n\n" + _localctx.act_text + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(357);
				((Rel_expressionContext)_localctx).s = simple_expression(0);
				setState(358);
				match(RELOP);
				setState(359);
				((Rel_expressionContext)_localctx).s1 = simple_expression(0);

				        ((Rel_expressionContext)_localctx).act_text =  _localctx->getText();
				        ((Rel_expressionContext)_localctx).type =  "int" ;
				        writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": rel_expression : simple_expression RELOP simple_expression\n\n" + _localctx.act_text + "\n");
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Simple_expressionContext extends ParserRuleContext {
		public string act_text;
		public string type;
		public Simple_expressionContext s;
		public TermContext t;
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public TerminalNode ADDOP() { return getToken(C8086Parser.ADDOP, 0); }
		public Simple_expressionContext simple_expression() {
			return getRuleContext(Simple_expressionContext.class,0);
		}
		public TerminalNode ASSIGNOP() { return getToken(C8086Parser.ASSIGNOP, 0); }
		public Simple_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_expression; }
	}

	public final Simple_expressionContext simple_expression() throws RecognitionException {
		return simple_expression(0);
	}

	private Simple_expressionContext simple_expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Simple_expressionContext _localctx = new Simple_expressionContext(_ctx, _parentState);
		Simple_expressionContext _prevctx = _localctx;
		int _startState = 38;
		enterRecursionRule(_localctx, 38, RULE_simple_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(365);
			((Simple_expressionContext)_localctx).t = term(0);

			        ((Simple_expressionContext)_localctx).act_text =  _localctx->getText();
			        ((Simple_expressionContext)_localctx).type =  ((Simple_expressionContext)_localctx).t.type ;
			        writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": simple_expression : term\n\n" + _localctx.act_text + "\n");
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(381);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(379);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,21,_ctx) ) {
					case 1:
						{
						_localctx = new Simple_expressionContext(_parentctx, _parentState);
						_localctx.s = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_simple_expression);
						setState(368);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(369);
						match(ADDOP);
						setState(370);
						((Simple_expressionContext)_localctx).t = term(0);

						                  ((Simple_expressionContext)_localctx).act_text =  _localctx->getText();
						                  ((Simple_expressionContext)_localctx).type =  ((Simple_expressionContext)_localctx).t.type ;
						                  if(((Simple_expressionContext)_localctx).s.type == "float" || ((Simple_expressionContext)_localctx).t.type == "float")
						                      ((Simple_expressionContext)_localctx).type =  "float";
						                  writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": simple_expression : simple_expression ADDOP term\n\n" + _localctx.act_text + "\n");
						              
						}
						break;
					case 2:
						{
						_localctx = new Simple_expressionContext(_parentctx, _parentState);
						_localctx.s = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_simple_expression);
						setState(373);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(374);
						match(ADDOP);
						setState(375);
						match(ASSIGNOP);
						setState(376);
						((Simple_expressionContext)_localctx).t = term(0);

						                  writeIntoErrorFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": syntax error, unexpected ASSIGNOP\n");
						                  writeIntoparserLogFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": syntax error, unexpected ASSIGNOP\n");
						              
						}
						break;
					}
					} 
				}
				setState(383);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TermContext extends ParserRuleContext {
		public string act_text;
		public string type;
		public TermContext t;
		public Unary_expressionContext u;
		public Token MULOP;
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TerminalNode MULOP() { return getToken(C8086Parser.MULOP, 0); }
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public TermContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term; }
	}

	public final TermContext term() throws RecognitionException {
		return term(0);
	}

	private TermContext term(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		TermContext _localctx = new TermContext(_ctx, _parentState);
		TermContext _prevctx = _localctx;
		int _startState = 40;
		enterRecursionRule(_localctx, 40, RULE_term, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(385);
			((TermContext)_localctx).u = unary_expression();
			 ((TermContext)_localctx).act_text =  _localctx->getText() ; ((TermContext)_localctx).type =  ((TermContext)_localctx).u.type ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": term : unary_expression \n\n" + _localctx->getText() + "\n");
					
			}
			_ctx.stop = _input.LT(-1);
			setState(395);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new TermContext(_parentctx, _parentState);
					_localctx.t = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_term);
					setState(388);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(389);
					((TermContext)_localctx).MULOP = match(MULOP);
					setState(390);
					((TermContext)_localctx).u = unary_expression();
					 
					                  ((TermContext)_localctx).act_text =  _localctx->getText() ;
					                  ((TermContext)_localctx).type =  ((TermContext)_localctx).u.type ;
					                  if(((TermContext)_localctx).u.type == "float" || ((TermContext)_localctx).t.type == "float")
					                      ((TermContext)_localctx).type =  "float";
					                  writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": term : term MULOP unary_expression \n");
					                  if(((TermContext)_localctx).u.type == "void")
					                  {
					                      writeIntoErrorFile( "Error at line " + to_string(_localctx->getStart()->getLine()) + ": Void function used in expression\n");
					                      writeIntoparserLogFile( "Error at line " + to_string(_localctx->getStart()->getLine()) + ": Void function used in expression\n");
					                  }
					                  if(((TermContext)_localctx).MULOP->getText()=="%" && (((TermContext)_localctx).t.act_text == "0" || ((TermContext)_localctx).u.act_text == "0"))
					                  {
					                      writeIntoErrorFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Modulus by Zero\n");
					                      writeIntoparserLogFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Modulus by Zero\n");
					                  }
					                  else if (((TermContext)_localctx).MULOP->getText()=="%" && (((TermContext)_localctx).t.type != "int" || ((TermContext)_localctx).u.type != "int"))
					                  {
					                      writeIntoErrorFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Non-Integer operand on modulus operator\n");
					                      
					                      writeIntoparserLogFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Non-Integer operand on modulus operator\n"); 
					                      
					                  }//else
					                      //writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": term : term MULOP unary_expression \n\n" + _localctx->getText() + "\n");
					                  writeIntoparserLogFile(_localctx->getText() + "\n");
					          	
					}
					} 
				}
				setState(397);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Unary_expressionContext extends ParserRuleContext {
		public string act_text;
		public string type;
		public Unary_expressionContext u;
		public FactorContext f;
		public TerminalNode ADDOP() { return getToken(C8086Parser.ADDOP, 0); }
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TerminalNode NOT() { return getToken(C8086Parser.NOT, 0); }
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public Unary_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary_expression; }
	}

	public final Unary_expressionContext unary_expression() throws RecognitionException {
		Unary_expressionContext _localctx = new Unary_expressionContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_unary_expression);
		try {
			setState(409);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ADDOP:
				enterOuterAlt(_localctx, 1);
				{
				setState(398);
				match(ADDOP);
				setState(399);
				((Unary_expressionContext)_localctx).u = unary_expression();
				 ((Unary_expressionContext)_localctx).act_text =  _localctx->getText() ; ((Unary_expressionContext)_localctx).type =  ((Unary_expressionContext)_localctx).u.type ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": unary_expression : ADDOP unary_expression \n\n" + _localctx->getText() + "\n");
						
				}
				break;
			case NOT:
				enterOuterAlt(_localctx, 2);
				{
				setState(402);
				match(NOT);
				setState(403);
				((Unary_expressionContext)_localctx).u = unary_expression();
				 ((Unary_expressionContext)_localctx).act_text =  _localctx->getText() ; ((Unary_expressionContext)_localctx).type =  ((Unary_expressionContext)_localctx).u.type ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": unary_expression : NOT unary expression \n\n" + _localctx->getText() + "\n");
						
				}
				break;
			case LPAREN:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 3);
				{
				setState(406);
				((Unary_expressionContext)_localctx).f = factor();
				 ((Unary_expressionContext)_localctx).act_text =  _localctx->getText() ; ((Unary_expressionContext)_localctx).type =  ((Unary_expressionContext)_localctx).f.type ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": unary_expression : factor \n\n" + _localctx->getText() + "\n");
						
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FactorContext extends ParserRuleContext {
		public string act_text;
		public string type;
		public VariableContext v;
		public Token ID;
		public Argument_listContext a;
		public ExpressionContext e;
		public Token CONST_FLOAT;
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C8086Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C8086Parser.RPAREN, 0); }
		public Argument_listContext argument_list() {
			return getRuleContext(Argument_listContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode CONST_INT() { return getToken(C8086Parser.CONST_INT, 0); }
		public TerminalNode CONST_FLOAT() { return getToken(C8086Parser.CONST_FLOAT, 0); }
		public TerminalNode INCOP() { return getToken(C8086Parser.INCOP, 0); }
		public TerminalNode DECOP() { return getToken(C8086Parser.DECOP, 0); }
		public FactorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_factor; }
	}

	public final FactorContext factor() throws RecognitionException {
		FactorContext _localctx = new FactorContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_factor);
		try {
			setState(437);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(411);
				((FactorContext)_localctx).v = variable();
				 
				        ((FactorContext)_localctx).act_text =  _localctx->getText() ;
				        ((FactorContext)_localctx).type =  ((FactorContext)_localctx).v.type;
				        writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : variable \n\n" + _localctx->getText() + "\n");
					
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(414);
				((FactorContext)_localctx).ID = match(ID);
				setState(415);
				match(LPAREN);
				setState(416);
				((FactorContext)_localctx).a = argument_list();
				setState(417);
				match(RPAREN);
				 
				        ((FactorContext)_localctx).act_text =  _localctx->getText() ;
				        SymbolInfo * item = Table.lookup(((FactorContext)_localctx).ID->getText());
				        writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : ID LPAREN argument_list RPAREN \n");
				        if (item)
				        {
				            ((FactorContext)_localctx).type =  item->getReturnType();
				            if(((FactorContext)_localctx).a.types.size() != item->getParamTypes().size())
				            {
				                writeIntoErrorFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Total number of arguments mismatch in function " + ((FactorContext)_localctx).ID->getText() + "\n");
				                writeIntoparserLogFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Total number of arguments mismatch in function " + ((FactorContext)_localctx).ID->getText() + "\n");
				            }
				            else if(((FactorContext)_localctx).a.types != item->getParamTypes())
				            {
				                writeIntoErrorFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": 1th argument mismatch in function " + ((FactorContext)_localctx).ID->getText() + "\n");
				                writeIntoparserLogFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": 1th argument mismatch in function " + ((FactorContext)_localctx).ID->getText() + "\n");
				            }
				        }else
				        {
				            writeIntoErrorFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Undeclared function " + ((FactorContext)_localctx).ID->getText() + "\n");
				            writeIntoparserLogFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Undeclared function " + ((FactorContext)_localctx).ID->getText() + "\n");
				        }
				        writeIntoparserLogFile(_localctx->getText() + "\n");
					
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(420);
				match(LPAREN);
				setState(421);
				((FactorContext)_localctx).e = expression();
				setState(422);
				match(RPAREN);
				 ((FactorContext)_localctx).act_text =  _localctx->getText() ; ((FactorContext)_localctx).type =  ((FactorContext)_localctx).e.type; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : LPAREN expression RPAREN \n\n" + _localctx->getText() + "\n");
					
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(425);
				match(CONST_INT);
				 ((FactorContext)_localctx).act_text =  _localctx->getText() ; ((FactorContext)_localctx).type =  "int" ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : CONST_INT \n\n" + _localctx->getText() + "\n");
					
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(427);
				((FactorContext)_localctx).CONST_FLOAT = match(CONST_FLOAT);
				 ((FactorContext)_localctx).act_text =  _localctx->getText() ; ((FactorContext)_localctx).type =  "float" ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : CONST_FLOAT  \n\n" + ((FactorContext)_localctx).CONST_FLOAT->getText() + "\n");
					
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(429);
				((FactorContext)_localctx).v = variable();
				setState(430);
				match(INCOP);
				 ((FactorContext)_localctx).act_text =  _localctx->getText() ; ((FactorContext)_localctx).type =  ((FactorContext)_localctx).v.type ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : variable INCOP \n\n" + _localctx->getText() + "\n");
					
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(433);
				((FactorContext)_localctx).v = variable();
				setState(434);
				match(DECOP);
				 ((FactorContext)_localctx).act_text =  _localctx->getText() ; ((FactorContext)_localctx).type =  ((FactorContext)_localctx).v.type ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : variable DECOP \n\n" + _localctx->getText() + "\n");
					
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Argument_listContext extends ParserRuleContext {
		public string act_text;
		public vector <string> types;
		public ArgumentsContext a;
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public Argument_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argument_list; }
	}

	public final Argument_listContext argument_list() throws RecognitionException {
		Argument_listContext _localctx = new Argument_listContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_argument_list);
		try {
			setState(443);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LPAREN:
			case ADDOP:
			case NOT:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 1);
				{
				setState(439);
				((Argument_listContext)_localctx).a = arguments(0);

				         ((Argument_listContext)_localctx).act_text =  _localctx->getText() ;
				         ((Argument_listContext)_localctx).types =  ((Argument_listContext)_localctx).a.types;
				          writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": argument_list : arguments \n\n" + _localctx->getText() + "\n");
						
				}
				break;
			case RPAREN:
				enterOuterAlt(_localctx, 2);
				{
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentsContext extends ParserRuleContext {
		public string act_text;
		public vector <string> types;
		public ArgumentsContext a;
		public Logic_expressionContext l;
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(C8086Parser.COMMA, 0); }
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public ArgumentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arguments; }
	}

	public final ArgumentsContext arguments() throws RecognitionException {
		return arguments(0);
	}

	private ArgumentsContext arguments(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ArgumentsContext _localctx = new ArgumentsContext(_ctx, _parentState);
		ArgumentsContext _prevctx = _localctx;
		int _startState = 48;
		enterRecursionRule(_localctx, 48, RULE_arguments, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(446);
			((ArgumentsContext)_localctx).l = logic_expression();
			 
			        ((ArgumentsContext)_localctx).act_text =  _localctx->getText() ;
			        _localctx.types.push_back(((ArgumentsContext)_localctx).l.type);
			         writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": arguments : logic_expression \n\n" + _localctx->getText() + "\n");
					
			}
			_ctx.stop = _input.LT(-1);
			setState(456);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ArgumentsContext(_parentctx, _parentState);
					_localctx.a = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_arguments);
					setState(449);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(450);
					match(COMMA);
					setState(451);
					((ArgumentsContext)_localctx).l = logic_expression();
					 
					                  ((ArgumentsContext)_localctx).act_text =  _localctx->getText() ;
					                  ((ArgumentsContext)_localctx).types =  ((ArgumentsContext)_localctx).a.types;
					                  _localctx.types.push_back(((ArgumentsContext)_localctx).l.type);
					                  writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": arguments : arguments COMMA logic_expression \n\n" + _localctx->getText() + "\n");
					          	
					}
					} 
				}
				setState(458);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 1:
			return program_sempred((ProgramContext)_localctx, predIndex);
		case 6:
			return parameter_list_sempred((Parameter_listContext)_localctx, predIndex);
		case 11:
			return declaration_list_sempred((Declaration_listContext)_localctx, predIndex);
		case 12:
			return statements_sempred((StatementsContext)_localctx, predIndex);
		case 19:
			return simple_expression_sempred((Simple_expressionContext)_localctx, predIndex);
		case 20:
			return term_sempred((TermContext)_localctx, predIndex);
		case 24:
			return arguments_sempred((ArgumentsContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean program_sempred(ProgramContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean parameter_list_sempred(Parameter_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 4);
		case 2:
			return precpred(_ctx, 3);
		}
		return true;
	}
	private boolean declaration_list_sempred(Declaration_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 3:
			return precpred(_ctx, 14);
		case 4:
			return precpred(_ctx, 13);
		case 5:
			return precpred(_ctx, 10);
		case 6:
			return precpred(_ctx, 9);
		case 7:
			return precpred(_ctx, 8);
		case 8:
			return precpred(_ctx, 7);
		case 9:
			return precpred(_ctx, 6);
		case 10:
			return precpred(_ctx, 5);
		case 11:
			return precpred(_ctx, 4);
		case 12:
			return precpred(_ctx, 3);
		case 13:
			return precpred(_ctx, 2);
		case 14:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean statements_sempred(StatementsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 15:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean simple_expression_sempred(Simple_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 16:
			return precpred(_ctx, 2);
		case 17:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean term_sempred(TermContext _localctx, int predIndex) {
		switch (predIndex) {
		case 18:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean arguments_sempred(ArgumentsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 19:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001\"\u01cc\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002\u0018\u0007\u0018"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0005\u0001"+
		">\b\u0001\n\u0001\f\u0001A\t\u0001\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0003\u0002L\b\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0003\u0003"+
		"]\b\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0003\u0004y\b\u0004\u0001\u0005"+
		"\u0004\u0005|\b\u0005\u000b\u0005\f\u0005}\u0001\u0005\u0001\u0005\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0003\u0006\u008a\b\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0005\u0006\u0097\b\u0006\n\u0006\f\u0006"+
		"\u009a\t\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0003\u0007"+
		"\u00a6\b\u0007\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b"+
		"\u0001\b\u0001\b\u0001\b\u0003\b\u00b2\b\b\u0001\t\u0001\t\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0003\n\u00bc\b\n\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0003\u000b\u00c6\b\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0005\u000b\u00f1\b\u000b\n\u000b\f\u000b\u00f4\t\u000b"+
		"\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0005"+
		"\f\u00fe\b\f\n\f\f\f\u0101\t\f\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r"+
		"\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0003\r\u0137\b\r\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0003\u000e\u0143\b\u000e\u0001\u000f\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0003\u000f"+
		"\u014d\b\u000f\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010"+
		"\u0001\u0010\u0001\u0010\u0001\u0010\u0003\u0010\u0157\b\u0010\u0001\u0011"+
		"\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011"+
		"\u0001\u0011\u0003\u0011\u0161\b\u0011\u0001\u0012\u0001\u0012\u0001\u0012"+
		"\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0003\u0012"+
		"\u016b\b\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0005\u0013\u017c\b\u0013"+
		"\n\u0013\f\u0013\u017f\t\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0005"+
		"\u0014\u018a\b\u0014\n\u0014\f\u0014\u018d\t\u0014\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0003\u0015\u019a\b\u0015\u0001\u0016"+
		"\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0003\u0016\u01b6\b\u0016\u0001\u0017\u0001\u0017\u0001\u0017"+
		"\u0001\u0017\u0003\u0017\u01bc\b\u0017\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0005\u0018\u01c7\b\u0018\n\u0018\f\u0018\u01ca\t\u0018\u0001\u0018\u0001"+
		"}\u0007\u0002\f\u0016\u0018&(0\u0019\u0000\u0002\u0004\u0006\b\n\f\u000e"+
		"\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \"$&(*,.0\u0000\u0000"+
		"\u01e9\u00002\u0001\u0000\u0000\u0000\u00025\u0001\u0000\u0000\u0000\u0004"+
		"K\u0001\u0000\u0000\u0000\u0006\\\u0001\u0000\u0000\u0000\bx\u0001\u0000"+
		"\u0000\u0000\n{\u0001\u0000\u0000\u0000\f\u0089\u0001\u0000\u0000\u0000"+
		"\u000e\u00a5\u0001\u0000\u0000\u0000\u0010\u00b1\u0001\u0000\u0000\u0000"+
		"\u0012\u00b3\u0001\u0000\u0000\u0000\u0014\u00bb\u0001\u0000\u0000\u0000"+
		"\u0016\u00c5\u0001\u0000\u0000\u0000\u0018\u00f5\u0001\u0000\u0000\u0000"+
		"\u001a\u0136\u0001\u0000\u0000\u0000\u001c\u0142\u0001\u0000\u0000\u0000"+
		"\u001e\u014c\u0001\u0000\u0000\u0000 \u0156\u0001\u0000\u0000\u0000\""+
		"\u0160\u0001\u0000\u0000\u0000$\u016a\u0001\u0000\u0000\u0000&\u016c\u0001"+
		"\u0000\u0000\u0000(\u0180\u0001\u0000\u0000\u0000*\u0199\u0001\u0000\u0000"+
		"\u0000,\u01b5\u0001\u0000\u0000\u0000.\u01bb\u0001\u0000\u0000\u00000"+
		"\u01bd\u0001\u0000\u0000\u000023\u0003\u0002\u0001\u000034\u0006\u0000"+
		"\uffff\uffff\u00004\u0001\u0001\u0000\u0000\u000056\u0006\u0001\uffff"+
		"\uffff\u000067\u0003\u0004\u0002\u000078\u0006\u0001\uffff\uffff\u0000"+
		"8?\u0001\u0000\u0000\u00009:\n\u0002\u0000\u0000:;\u0003\u0004\u0002\u0000"+
		";<\u0006\u0001\uffff\uffff\u0000<>\u0001\u0000\u0000\u0000=9\u0001\u0000"+
		"\u0000\u0000>A\u0001\u0000\u0000\u0000?=\u0001\u0000\u0000\u0000?@\u0001"+
		"\u0000\u0000\u0000@\u0003\u0001\u0000\u0000\u0000A?\u0001\u0000\u0000"+
		"\u0000BC\u0003\u0010\b\u0000CD\u0006\u0002\uffff\uffff\u0000DL\u0001\u0000"+
		"\u0000\u0000EF\u0003\u0006\u0003\u0000FG\u0006\u0002\uffff\uffff\u0000"+
		"GL\u0001\u0000\u0000\u0000HI\u0003\b\u0004\u0000IJ\u0006\u0002\uffff\uffff"+
		"\u0000JL\u0001\u0000\u0000\u0000KB\u0001\u0000\u0000\u0000KE\u0001\u0000"+
		"\u0000\u0000KH\u0001\u0000\u0000\u0000L\u0005\u0001\u0000\u0000\u0000"+
		"MN\u0003\u0014\n\u0000NO\u0005\u001f\u0000\u0000OP\u0005\u000e\u0000\u0000"+
		"PQ\u0003\f\u0006\u0000QR\u0005\u000f\u0000\u0000RS\u0005\u0014\u0000\u0000"+
		"ST\u0006\u0003\uffff\uffff\u0000T]\u0001\u0000\u0000\u0000UV\u0003\u0014"+
		"\n\u0000VW\u0005\u001f\u0000\u0000WX\u0005\u000e\u0000\u0000XY\u0005\u000f"+
		"\u0000\u0000YZ\u0005\u0014\u0000\u0000Z[\u0006\u0003\uffff\uffff\u0000"+
		"[]\u0001\u0000\u0000\u0000\\M\u0001\u0000\u0000\u0000\\U\u0001\u0000\u0000"+
		"\u0000]\u0007\u0001\u0000\u0000\u0000^_\u0003\u0014\n\u0000_`\u0005\u001f"+
		"\u0000\u0000`a\u0005\u000e\u0000\u0000ab\u0003\f\u0006\u0000bc\u0005\u000f"+
		"\u0000\u0000cd\u0006\u0004\uffff\uffff\u0000de\u0003\u000e\u0007\u0000"+
		"ef\u0006\u0004\uffff\uffff\u0000fy\u0001\u0000\u0000\u0000gh\u0003\u0014"+
		"\n\u0000hi\u0005\u001f\u0000\u0000ij\u0005\u000e\u0000\u0000jk\u0005\u000f"+
		"\u0000\u0000kl\u0006\u0004\uffff\uffff\u0000lm\u0003\u000e\u0007\u0000"+
		"mn\u0006\u0004\uffff\uffff\u0000ny\u0001\u0000\u0000\u0000op\u0003\u0014"+
		"\n\u0000pq\u0005\u001f\u0000\u0000qr\u0005\u000e\u0000\u0000rs\u0003\n"+
		"\u0005\u0000st\u0005\u000f\u0000\u0000tu\u0006\u0004\uffff\uffff\u0000"+
		"uv\u0003\u000e\u0007\u0000vw\u0006\u0004\uffff\uffff\u0000wy\u0001\u0000"+
		"\u0000\u0000x^\u0001\u0000\u0000\u0000xg\u0001\u0000\u0000\u0000xo\u0001"+
		"\u0000\u0000\u0000y\t\u0001\u0000\u0000\u0000z|\t\u0000\u0000\u0000{z"+
		"\u0001\u0000\u0000\u0000|}\u0001\u0000\u0000\u0000}~\u0001\u0000\u0000"+
		"\u0000}{\u0001\u0000\u0000\u0000~\u007f\u0001\u0000\u0000\u0000\u007f"+
		"\u0080\u0006\u0005\uffff\uffff\u0000\u0080\u000b\u0001\u0000\u0000\u0000"+
		"\u0081\u0082\u0006\u0006\uffff\uffff\u0000\u0082\u0083\u0003\u0014\n\u0000"+
		"\u0083\u0084\u0005\u001f\u0000\u0000\u0084\u0085\u0006\u0006\uffff\uffff"+
		"\u0000\u0085\u008a\u0001\u0000\u0000\u0000\u0086\u0087\u0003\u0014\n\u0000"+
		"\u0087\u0088\u0006\u0006\uffff\uffff\u0000\u0088\u008a\u0001\u0000\u0000"+
		"\u0000\u0089\u0081\u0001\u0000\u0000\u0000\u0089\u0086\u0001\u0000\u0000"+
		"\u0000\u008a\u0098\u0001\u0000\u0000\u0000\u008b\u008c\n\u0004\u0000\u0000"+
		"\u008c\u008d\u0005\u0015\u0000\u0000\u008d\u008e\u0003\u0014\n\u0000\u008e"+
		"\u008f\u0005\u001f\u0000\u0000\u008f\u0090\u0006\u0006\uffff\uffff\u0000"+
		"\u0090\u0097\u0001\u0000\u0000\u0000\u0091\u0092\n\u0003\u0000\u0000\u0092"+
		"\u0093\u0005\u0015\u0000\u0000\u0093\u0094\u0003\u0014\n\u0000\u0094\u0095"+
		"\u0006\u0006\uffff\uffff\u0000\u0095\u0097\u0001\u0000\u0000\u0000\u0096"+
		"\u008b\u0001\u0000\u0000\u0000\u0096\u0091\u0001\u0000\u0000\u0000\u0097"+
		"\u009a\u0001\u0000\u0000\u0000\u0098\u0096\u0001\u0000\u0000\u0000\u0098"+
		"\u0099\u0001\u0000\u0000\u0000\u0099\r\u0001\u0000\u0000\u0000\u009a\u0098"+
		"\u0001\u0000\u0000\u0000\u009b\u009c\u0005\u0010\u0000\u0000\u009c\u009d"+
		"\u0006\u0007\uffff\uffff\u0000\u009d\u009e\u0003\u0018\f\u0000\u009e\u009f"+
		"\u0005\u0011\u0000\u0000\u009f\u00a0\u0006\u0007\uffff\uffff\u0000\u00a0"+
		"\u00a6\u0001\u0000\u0000\u0000\u00a1\u00a2\u0005\u0010\u0000\u0000\u00a2"+
		"\u00a3\u0006\u0007\uffff\uffff\u0000\u00a3\u00a4\u0005\u0011\u0000\u0000"+
		"\u00a4\u00a6\u0006\u0007\uffff\uffff\u0000\u00a5\u009b\u0001\u0000\u0000"+
		"\u0000\u00a5\u00a1\u0001\u0000\u0000\u0000\u00a6\u000f\u0001\u0000\u0000"+
		"\u0000\u00a7\u00a8\u0003\u0014\n\u0000\u00a8\u00a9\u0003\u0016\u000b\u0000"+
		"\u00a9\u00aa\u0005\u0014\u0000\u0000\u00aa\u00ab\u0006\b\uffff\uffff\u0000"+
		"\u00ab\u00b2\u0001\u0000\u0000\u0000\u00ac\u00ad\u0003\u0014\n\u0000\u00ad"+
		"\u00ae\u0003\u0012\t\u0000\u00ae\u00af\u0005\u0014\u0000\u0000\u00af\u00b0"+
		"\u0006\b\uffff\uffff\u0000\u00b0\u00b2\u0001\u0000\u0000\u0000\u00b1\u00a7"+
		"\u0001\u0000\u0000\u0000\u00b1\u00ac\u0001\u0000\u0000\u0000\u00b2\u0011"+
		"\u0001\u0000\u0000\u0000\u00b3\u00b4\u0006\t\uffff\uffff\u0000\u00b4\u0013"+
		"\u0001\u0000\u0000\u0000\u00b5\u00b6\u0005\u000b\u0000\u0000\u00b6\u00bc"+
		"\u0006\n\uffff\uffff\u0000\u00b7\u00b8\u0005\f\u0000\u0000\u00b8\u00bc"+
		"\u0006\n\uffff\uffff\u0000\u00b9\u00ba\u0005\r\u0000\u0000\u00ba\u00bc"+
		"\u0006\n\uffff\uffff\u0000\u00bb\u00b5\u0001\u0000\u0000\u0000\u00bb\u00b7"+
		"\u0001\u0000\u0000\u0000\u00bb\u00b9\u0001\u0000\u0000\u0000\u00bc\u0015"+
		"\u0001\u0000\u0000\u0000\u00bd\u00be\u0006\u000b\uffff\uffff\u0000\u00be"+
		"\u00bf\u0005\u001f\u0000\u0000\u00bf\u00c6\u0006\u000b\uffff\uffff\u0000"+
		"\u00c0\u00c1\u0005\u001f\u0000\u0000\u00c1\u00c2\u0005\u0012\u0000\u0000"+
		"\u00c2\u00c3\u0005 \u0000\u0000\u00c3\u00c4\u0005\u0013\u0000\u0000\u00c4"+
		"\u00c6\u0006\u000b\uffff\uffff\u0000\u00c5\u00bd\u0001\u0000\u0000\u0000"+
		"\u00c5\u00c0\u0001\u0000\u0000\u0000\u00c6\u00f2\u0001\u0000\u0000\u0000"+
		"\u00c7\u00c8\n\u000e\u0000\u0000\u00c8\u00c9\u0005\u0015\u0000\u0000\u00c9"+
		"\u00ca\u0005\u001f\u0000\u0000\u00ca\u00f1\u0006\u000b\uffff\uffff\u0000"+
		"\u00cb\u00cc\n\r\u0000\u0000\u00cc\u00cd\u0005\u0015\u0000\u0000\u00cd"+
		"\u00ce\u0005\u001f\u0000\u0000\u00ce\u00cf\u0005\u0012\u0000\u0000\u00cf"+
		"\u00d0\u0005 \u0000\u0000\u00d0\u00d1\u0005\u0013\u0000\u0000\u00d1\u00f1"+
		"\u0006\u000b\uffff\uffff\u0000\u00d2\u00d3\n\n\u0000\u0000\u00d3\u00d4"+
		"\u0005\u0016\u0000\u0000\u00d4\u00f1\u0006\u000b\uffff\uffff\u0000\u00d5"+
		"\u00d6\n\t\u0000\u0000\u00d6\u00d7\u0005\u001f\u0000\u0000\u00d7\u00f1"+
		"\u0006\u000b\uffff\uffff\u0000\u00d8\u00d9\n\b\u0000\u0000\u00d9\u00da"+
		"\u0005\u0017\u0000\u0000\u00da\u00f1\u0006\u000b\uffff\uffff\u0000\u00db"+
		"\u00dc\n\u0007\u0000\u0000\u00dc\u00dd\u0005\u0018\u0000\u0000\u00dd\u00f1"+
		"\u0006\u000b\uffff\uffff\u0000\u00de\u00df\n\u0006\u0000\u0000\u00df\u00e0"+
		"\u0005\u0019\u0000\u0000\u00e0\u00f1\u0006\u000b\uffff\uffff\u0000\u00e1"+
		"\u00e2\n\u0005\u0000\u0000\u00e2\u00e3\u0005\u001a\u0000\u0000\u00e3\u00f1"+
		"\u0006\u000b\uffff\uffff\u0000\u00e4\u00e5\n\u0004\u0000\u0000\u00e5\u00e6"+
		"\u0005\u001b\u0000\u0000\u00e6\u00f1\u0006\u000b\uffff\uffff\u0000\u00e7"+
		"\u00e8\n\u0003\u0000\u0000\u00e8\u00e9\u0005\u001c\u0000\u0000\u00e9\u00f1"+
		"\u0006\u000b\uffff\uffff\u0000\u00ea\u00eb\n\u0002\u0000\u0000\u00eb\u00ec"+
		"\u0005\u001d\u0000\u0000\u00ec\u00f1\u0006\u000b\uffff\uffff\u0000\u00ed"+
		"\u00ee\n\u0001\u0000\u0000\u00ee\u00ef\u0005\u001e\u0000\u0000\u00ef\u00f1"+
		"\u0006\u000b\uffff\uffff\u0000\u00f0\u00c7\u0001\u0000\u0000\u0000\u00f0"+
		"\u00cb\u0001\u0000\u0000\u0000\u00f0\u00d2\u0001\u0000\u0000\u0000\u00f0"+
		"\u00d5\u0001\u0000\u0000\u0000\u00f0\u00d8\u0001\u0000\u0000\u0000\u00f0"+
		"\u00db\u0001\u0000\u0000\u0000\u00f0\u00de\u0001\u0000\u0000\u0000\u00f0"+
		"\u00e1\u0001\u0000\u0000\u0000\u00f0\u00e4\u0001\u0000\u0000\u0000\u00f0"+
		"\u00e7\u0001\u0000\u0000\u0000\u00f0\u00ea\u0001\u0000\u0000\u0000\u00f0"+
		"\u00ed\u0001\u0000\u0000\u0000\u00f1\u00f4\u0001\u0000\u0000\u0000\u00f2"+
		"\u00f0\u0001\u0000\u0000\u0000\u00f2\u00f3\u0001\u0000\u0000\u0000\u00f3"+
		"\u0017\u0001\u0000\u0000\u0000\u00f4\u00f2\u0001\u0000\u0000\u0000\u00f5"+
		"\u00f6\u0006\f\uffff\uffff\u0000\u00f6\u00f7\u0003\u001a\r\u0000\u00f7"+
		"\u00f8\u0006\f\uffff\uffff\u0000\u00f8\u00ff\u0001\u0000\u0000\u0000\u00f9"+
		"\u00fa\n\u0001\u0000\u0000\u00fa\u00fb\u0003\u001a\r\u0000\u00fb\u00fc"+
		"\u0006\f\uffff\uffff\u0000\u00fc\u00fe\u0001\u0000\u0000\u0000\u00fd\u00f9"+
		"\u0001\u0000\u0000\u0000\u00fe\u0101\u0001\u0000\u0000\u0000\u00ff\u00fd"+
		"\u0001\u0000\u0000\u0000\u00ff\u0100\u0001\u0000\u0000\u0000\u0100\u0019"+
		"\u0001\u0000\u0000\u0000\u0101\u00ff\u0001\u0000\u0000\u0000\u0102\u0103"+
		"\u0003\u0010\b\u0000\u0103\u0104\u0006\r\uffff\uffff\u0000\u0104\u0137"+
		"\u0001\u0000\u0000\u0000\u0105\u0106\u0003\u001c\u000e\u0000\u0106\u0107"+
		"\u0006\r\uffff\uffff\u0000\u0107\u0137\u0001\u0000\u0000\u0000\u0108\u0109"+
		"\u0003\u000e\u0007\u0000\u0109\u010a\u0006\r\uffff\uffff\u0000\u010a\u0137"+
		"\u0001\u0000\u0000\u0000\u010b\u010c\u0005\u0007\u0000\u0000\u010c\u010d"+
		"\u0005\u000e\u0000\u0000\u010d\u010e\u0003\u001c\u000e\u0000\u010e\u010f"+
		"\u0003\u001c\u000e\u0000\u010f\u0110\u0003 \u0010\u0000\u0110\u0111\u0005"+
		"\u000f\u0000\u0000\u0111\u0112\u0003\u001a\r\u0000\u0112\u0113\u0006\r"+
		"\uffff\uffff\u0000\u0113\u0137\u0001\u0000\u0000\u0000\u0114\u0115\u0005"+
		"\u0005\u0000\u0000\u0115\u0116\u0005\u000e\u0000\u0000\u0116\u0117\u0003"+
		" \u0010\u0000\u0117\u0118\u0005\u000f\u0000\u0000\u0118\u0119\u0003\u001a"+
		"\r\u0000\u0119\u011a\u0006\r\uffff\uffff\u0000\u011a\u0137\u0001\u0000"+
		"\u0000\u0000\u011b\u011c\u0005\u0005\u0000\u0000\u011c\u011d\u0005\u000e"+
		"\u0000\u0000\u011d\u011e\u0003 \u0010\u0000\u011e\u011f\u0005\u000f\u0000"+
		"\u0000\u011f\u0120\u0003\u001a\r\u0000\u0120\u0121\u0005\u0006\u0000\u0000"+
		"\u0121\u0122\u0003\u001a\r\u0000\u0122\u0123\u0006\r\uffff\uffff\u0000"+
		"\u0123\u0137\u0001\u0000\u0000\u0000\u0124\u0125\u0005\b\u0000\u0000\u0125"+
		"\u0126\u0005\u000e\u0000\u0000\u0126\u0127\u0003 \u0010\u0000\u0127\u0128"+
		"\u0005\u000f\u0000\u0000\u0128\u0129\u0003\u001a\r\u0000\u0129\u012a\u0006"+
		"\r\uffff\uffff\u0000\u012a\u0137\u0001\u0000\u0000\u0000\u012b\u012c\u0005"+
		"\t\u0000\u0000\u012c\u012d\u0005\u000e\u0000\u0000\u012d\u012e\u0005\u001f"+
		"\u0000\u0000\u012e\u012f\u0005\u000f\u0000\u0000\u012f\u0130\u0005\u0014"+
		"\u0000\u0000\u0130\u0137\u0006\r\uffff\uffff\u0000\u0131\u0132\u0005\n"+
		"\u0000\u0000\u0132\u0133\u0003 \u0010\u0000\u0133\u0134\u0005\u0014\u0000"+
		"\u0000\u0134\u0135\u0006\r\uffff\uffff\u0000\u0135\u0137\u0001\u0000\u0000"+
		"\u0000\u0136\u0102\u0001\u0000\u0000\u0000\u0136\u0105\u0001\u0000\u0000"+
		"\u0000\u0136\u0108\u0001\u0000\u0000\u0000\u0136\u010b\u0001\u0000\u0000"+
		"\u0000\u0136\u0114\u0001\u0000\u0000\u0000\u0136\u011b\u0001\u0000\u0000"+
		"\u0000\u0136\u0124\u0001\u0000\u0000\u0000\u0136\u012b\u0001\u0000\u0000"+
		"\u0000\u0136\u0131\u0001\u0000\u0000\u0000\u0137\u001b\u0001\u0000\u0000"+
		"\u0000\u0138\u0139\u0005\u0014\u0000\u0000\u0139\u0143\u0006\u000e\uffff"+
		"\uffff\u0000\u013a\u013b\u0003 \u0010\u0000\u013b\u013c\u0005\u0014\u0000"+
		"\u0000\u013c\u013d\u0006\u000e\uffff\uffff\u0000\u013d\u0143\u0001\u0000"+
		"\u0000\u0000\u013e\u013f\u0003 \u0010\u0000\u013f\u0140\u0005\"\u0000"+
		"\u0000\u0140\u0141\u0006\u000e\uffff\uffff\u0000\u0141\u0143\u0001\u0000"+
		"\u0000\u0000\u0142\u0138\u0001\u0000\u0000\u0000\u0142\u013a\u0001\u0000"+
		"\u0000\u0000\u0142\u013e\u0001\u0000\u0000\u0000\u0143\u001d\u0001\u0000"+
		"\u0000\u0000\u0144\u0145\u0005\u001f\u0000\u0000\u0145\u014d\u0006\u000f"+
		"\uffff\uffff\u0000\u0146\u0147\u0005\u001f\u0000\u0000\u0147\u0148\u0005"+
		"\u0012\u0000\u0000\u0148\u0149\u0003 \u0010\u0000\u0149\u014a\u0005\u0013"+
		"\u0000\u0000\u014a\u014b\u0006\u000f\uffff\uffff\u0000\u014b\u014d\u0001"+
		"\u0000\u0000\u0000\u014c\u0144\u0001\u0000\u0000\u0000\u014c\u0146\u0001"+
		"\u0000\u0000\u0000\u014d\u001f\u0001\u0000\u0000\u0000\u014e\u014f\u0003"+
		"\"\u0011\u0000\u014f\u0150\u0006\u0010\uffff\uffff\u0000\u0150\u0157\u0001"+
		"\u0000\u0000\u0000\u0151\u0152\u0003\u001e\u000f\u0000\u0152\u0153\u0005"+
		"\u001e\u0000\u0000\u0153\u0154\u0003\"\u0011\u0000\u0154\u0155\u0006\u0010"+
		"\uffff\uffff\u0000\u0155\u0157\u0001\u0000\u0000\u0000\u0156\u014e\u0001"+
		"\u0000\u0000\u0000\u0156\u0151\u0001\u0000\u0000\u0000\u0157!\u0001\u0000"+
		"\u0000\u0000\u0158\u0159\u0003$\u0012\u0000\u0159\u015a\u0006\u0011\uffff"+
		"\uffff\u0000\u015a\u0161\u0001\u0000\u0000\u0000\u015b\u015c\u0003$\u0012"+
		"\u0000\u015c\u015d\u0005\u001d\u0000\u0000\u015d\u015e\u0003$\u0012\u0000"+
		"\u015e\u015f\u0006\u0011\uffff\uffff\u0000\u015f\u0161\u0001\u0000\u0000"+
		"\u0000\u0160\u0158\u0001\u0000\u0000\u0000\u0160\u015b\u0001\u0000\u0000"+
		"\u0000\u0161#\u0001\u0000\u0000\u0000\u0162\u0163\u0003&\u0013\u0000\u0163"+
		"\u0164\u0006\u0012\uffff\uffff\u0000\u0164\u016b\u0001\u0000\u0000\u0000"+
		"\u0165\u0166\u0003&\u0013\u0000\u0166\u0167\u0005\u001c\u0000\u0000\u0167"+
		"\u0168\u0003&\u0013\u0000\u0168\u0169\u0006\u0012\uffff\uffff\u0000\u0169"+
		"\u016b\u0001\u0000\u0000\u0000\u016a\u0162\u0001\u0000\u0000\u0000\u016a"+
		"\u0165\u0001\u0000\u0000\u0000\u016b%\u0001\u0000\u0000\u0000\u016c\u016d"+
		"\u0006\u0013\uffff\uffff\u0000\u016d\u016e\u0003(\u0014\u0000\u016e\u016f"+
		"\u0006\u0013\uffff\uffff\u0000\u016f\u017d\u0001\u0000\u0000\u0000\u0170"+
		"\u0171\n\u0002\u0000\u0000\u0171\u0172\u0005\u0016\u0000\u0000\u0172\u0173"+
		"\u0003(\u0014\u0000\u0173\u0174\u0006\u0013\uffff\uffff\u0000\u0174\u017c"+
		"\u0001\u0000\u0000\u0000\u0175\u0176\n\u0001\u0000\u0000\u0176\u0177\u0005"+
		"\u0016\u0000\u0000\u0177\u0178\u0005\u001e\u0000\u0000\u0178\u0179\u0003"+
		"(\u0014\u0000\u0179\u017a\u0006\u0013\uffff\uffff\u0000\u017a\u017c\u0001"+
		"\u0000\u0000\u0000\u017b\u0170\u0001\u0000\u0000\u0000\u017b\u0175\u0001"+
		"\u0000\u0000\u0000\u017c\u017f\u0001\u0000\u0000\u0000\u017d\u017b\u0001"+
		"\u0000\u0000\u0000\u017d\u017e\u0001\u0000\u0000\u0000\u017e\'\u0001\u0000"+
		"\u0000\u0000\u017f\u017d\u0001\u0000\u0000\u0000\u0180\u0181\u0006\u0014"+
		"\uffff\uffff\u0000\u0181\u0182\u0003*\u0015\u0000\u0182\u0183\u0006\u0014"+
		"\uffff\uffff\u0000\u0183\u018b\u0001\u0000\u0000\u0000\u0184\u0185\n\u0001"+
		"\u0000\u0000\u0185\u0186\u0005\u0018\u0000\u0000\u0186\u0187\u0003*\u0015"+
		"\u0000\u0187\u0188\u0006\u0014\uffff\uffff\u0000\u0188\u018a\u0001\u0000"+
		"\u0000\u0000\u0189\u0184\u0001\u0000\u0000\u0000\u018a\u018d\u0001\u0000"+
		"\u0000\u0000\u018b\u0189\u0001\u0000\u0000\u0000\u018b\u018c\u0001\u0000"+
		"\u0000\u0000\u018c)\u0001\u0000\u0000\u0000\u018d\u018b\u0001\u0000\u0000"+
		"\u0000\u018e\u018f\u0005\u0016\u0000\u0000\u018f\u0190\u0003*\u0015\u0000"+
		"\u0190\u0191\u0006\u0015\uffff\uffff\u0000\u0191\u019a\u0001\u0000\u0000"+
		"\u0000\u0192\u0193\u0005\u001b\u0000\u0000\u0193\u0194\u0003*\u0015\u0000"+
		"\u0194\u0195\u0006\u0015\uffff\uffff\u0000\u0195\u019a\u0001\u0000\u0000"+
		"\u0000\u0196\u0197\u0003,\u0016\u0000\u0197\u0198\u0006\u0015\uffff\uffff"+
		"\u0000\u0198\u019a\u0001\u0000\u0000\u0000\u0199\u018e\u0001\u0000\u0000"+
		"\u0000\u0199\u0192\u0001\u0000\u0000\u0000\u0199\u0196\u0001\u0000\u0000"+
		"\u0000\u019a+\u0001\u0000\u0000\u0000\u019b\u019c\u0003\u001e\u000f\u0000"+
		"\u019c\u019d\u0006\u0016\uffff\uffff\u0000\u019d\u01b6\u0001\u0000\u0000"+
		"\u0000\u019e\u019f\u0005\u001f\u0000\u0000\u019f\u01a0\u0005\u000e\u0000"+
		"\u0000\u01a0\u01a1\u0003.\u0017\u0000\u01a1\u01a2\u0005\u000f\u0000\u0000"+
		"\u01a2\u01a3\u0006\u0016\uffff\uffff\u0000\u01a3\u01b6\u0001\u0000\u0000"+
		"\u0000\u01a4\u01a5\u0005\u000e\u0000\u0000\u01a5\u01a6\u0003 \u0010\u0000"+
		"\u01a6\u01a7\u0005\u000f\u0000\u0000\u01a7\u01a8\u0006\u0016\uffff\uffff"+
		"\u0000\u01a8\u01b6\u0001\u0000\u0000\u0000\u01a9\u01aa\u0005 \u0000\u0000"+
		"\u01aa\u01b6\u0006\u0016\uffff\uffff\u0000\u01ab\u01ac\u0005!\u0000\u0000"+
		"\u01ac\u01b6\u0006\u0016\uffff\uffff\u0000\u01ad\u01ae\u0003\u001e\u000f"+
		"\u0000\u01ae\u01af\u0005\u0019\u0000\u0000\u01af\u01b0\u0006\u0016\uffff"+
		"\uffff\u0000\u01b0\u01b6\u0001\u0000\u0000\u0000\u01b1\u01b2\u0003\u001e"+
		"\u000f\u0000\u01b2\u01b3\u0005\u001a\u0000\u0000\u01b3\u01b4\u0006\u0016"+
		"\uffff\uffff\u0000\u01b4\u01b6\u0001\u0000\u0000\u0000\u01b5\u019b\u0001"+
		"\u0000\u0000\u0000\u01b5\u019e\u0001\u0000\u0000\u0000\u01b5\u01a4\u0001"+
		"\u0000\u0000\u0000\u01b5\u01a9\u0001\u0000\u0000\u0000\u01b5\u01ab\u0001"+
		"\u0000\u0000\u0000\u01b5\u01ad\u0001\u0000\u0000\u0000\u01b5\u01b1\u0001"+
		"\u0000\u0000\u0000\u01b6-\u0001\u0000\u0000\u0000\u01b7\u01b8\u00030\u0018"+
		"\u0000\u01b8\u01b9\u0006\u0017\uffff\uffff\u0000\u01b9\u01bc\u0001\u0000"+
		"\u0000\u0000\u01ba\u01bc\u0001\u0000\u0000\u0000\u01bb\u01b7\u0001\u0000"+
		"\u0000\u0000\u01bb\u01ba\u0001\u0000\u0000\u0000\u01bc/\u0001\u0000\u0000"+
		"\u0000\u01bd\u01be\u0006\u0018\uffff\uffff\u0000\u01be\u01bf\u0003\"\u0011"+
		"\u0000\u01bf\u01c0\u0006\u0018\uffff\uffff\u0000\u01c0\u01c8\u0001\u0000"+
		"\u0000\u0000\u01c1\u01c2\n\u0002\u0000\u0000\u01c2\u01c3\u0005\u0015\u0000"+
		"\u0000\u01c3\u01c4\u0003\"\u0011\u0000\u01c4\u01c5\u0006\u0018\uffff\uffff"+
		"\u0000\u01c5\u01c7\u0001\u0000\u0000\u0000\u01c6\u01c1\u0001\u0000\u0000"+
		"\u0000\u01c7\u01ca\u0001\u0000\u0000\u0000\u01c8\u01c6\u0001\u0000\u0000"+
		"\u0000\u01c8\u01c9\u0001\u0000\u0000\u0000\u01c91\u0001\u0000\u0000\u0000"+
		"\u01ca\u01c8\u0001\u0000\u0000\u0000\u001c?K\\x}\u0089\u0096\u0098\u00a5"+
		"\u00b1\u00bb\u00c5\u00f0\u00f2\u00ff\u0136\u0142\u014c\u0156\u0160\u016a"+
		"\u017b\u017d\u018b\u0199\u01b5\u01bb\u01c8";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}