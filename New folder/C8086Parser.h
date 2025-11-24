
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


// Generated from C8086Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  C8086Parser : public antlr4::Parser {
public:
  enum {
    LINE_COMMENT = 1, BLOCK_COMMENT = 2, STRING = 3, WS = 4, IF = 5, ELSE = 6, 
    FOR = 7, WHILE = 8, PRINTLN = 9, RETURN = 10, INT = 11, FLOAT = 12, 
    VOID = 13, LPAREN = 14, RPAREN = 15, LCURL = 16, RCURL = 17, LTHIRD = 18, 
    RTHIRD = 19, SEMICOLON = 20, COMMA = 21, ADDOP = 22, SUBOP = 23, MULOP = 24, 
    INCOP = 25, DECOP = 26, NOT = 27, RELOP = 28, LOGICOP = 29, ASSIGNOP = 30, 
    ID = 31, CONST_INT = 32, CONST_FLOAT = 33, ANY = 34
  };

  enum {
    RuleStart = 0, RuleProgram = 1, RuleUnit = 2, RuleFunc_declaration = 3, 
    RuleFunc_definition = 4, RuleParameter_list_err = 5, RuleParameter_list = 6, 
    RuleCompound_statement = 7, RuleVar_declaration = 8, RuleDeclaration_list_err = 9, 
    RuleType_specifier = 10, RuleDeclaration_list = 11, RuleStatements = 12, 
    RuleStatement = 13, RuleExpression_statement = 14, RuleVariable = 15, 
    RuleExpression = 16, RuleLogic_expression = 17, RuleRel_expression = 18, 
    RuleSimple_expression = 19, RuleTerm = 20, RuleUnary_expression = 21, 
    RuleFactor = 22, RuleArgument_list = 23, RuleArguments = 24
  };

  explicit C8086Parser(antlr4::TokenStream *input);

  C8086Parser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~C8086Parser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


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



  class StartContext;
  class ProgramContext;
  class UnitContext;
  class Func_declarationContext;
  class Func_definitionContext;
  class Parameter_list_errContext;
  class Parameter_listContext;
  class Compound_statementContext;
  class Var_declarationContext;
  class Declaration_list_errContext;
  class Type_specifierContext;
  class Declaration_listContext;
  class StatementsContext;
  class StatementContext;
  class Expression_statementContext;
  class VariableContext;
  class ExpressionContext;
  class Logic_expressionContext;
  class Rel_expressionContext;
  class Simple_expressionContext;
  class TermContext;
  class Unary_expressionContext;
  class FactorContext;
  class Argument_listContext;
  class ArgumentsContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    C8086Parser::ProgramContext *p = nullptr;
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StartContext* start();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    C8086Parser::ProgramContext *p = nullptr;
    C8086Parser::UnitContext *u = nullptr;
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnitContext *unit();
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramContext* program();
  ProgramContext* program(int precedence);
  class  UnitContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    C8086Parser::Var_declarationContext *vd = nullptr;
    C8086Parser::Func_declarationContext *fd = nullptr;
    C8086Parser::Func_definitionContext *f = nullptr;
    UnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    Func_declarationContext *func_declaration();
    Func_definitionContext *func_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnitContext* unit();

  class  Func_declarationContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    C8086Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *idToken = nullptr;
    C8086Parser::Parameter_listContext *p = nullptr;
    Func_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMICOLON();
    Type_specifierContext *type_specifier();
    Parameter_listContext *parameter_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Func_declarationContext* func_declaration();

  class  Func_definitionContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    int Line;
    C8086Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *idToken = nullptr;
    C8086Parser::Parameter_listContext *p = nullptr;
    C8086Parser::Compound_statementContext *c = nullptr;
    C8086Parser::Parameter_list_errContext *pe = nullptr;
    Func_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Type_specifierContext *type_specifier();
    Parameter_listContext *parameter_list();
    Compound_statementContext *compound_statement();
    Parameter_list_errContext *parameter_list_err();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Func_definitionContext* func_definition();

  class  Parameter_list_errContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    Parameter_list_errContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parameter_list_errContext* parameter_list_err();

  class  Parameter_listContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    C8086Parser::Parameter_listContext *p = nullptr;
    C8086Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *idToken = nullptr;
    Parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *COMMA();
    Parameter_listContext *parameter_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parameter_listContext* parameter_list();
  Parameter_listContext* parameter_list(int precedence);
  class  Compound_statementContext : public antlr4::ParserRuleContext {
  public:
    bool flagScope;
    string act_text;
    int Line;
    C8086Parser::StatementsContext *s = nullptr;
    antlr4::Token *rcurlToken = nullptr;
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState, bool flagScope);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCURL();
    antlr4::tree::TerminalNode *RCURL();
    StatementsContext *statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compound_statementContext* compound_statement(bool flagScope);

  class  Var_declarationContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    int line;
    C8086Parser::Type_specifierContext *t = nullptr;
    C8086Parser::Declaration_listContext *dl = nullptr;
    antlr4::Token *sm = nullptr;
    C8086Parser::Declaration_list_errContext *de = nullptr;
    Var_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *SEMICOLON();
    Declaration_list_errContext *declaration_list_err();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Var_declarationContext* var_declaration();

  class  Declaration_list_errContext : public antlr4::ParserRuleContext {
  public:
    string error_name;
    Declaration_list_errContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declaration_list_errContext* declaration_list_err();

  class  Type_specifierContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    antlr4::Token *intToken = nullptr;
    antlr4::Token *floatToken = nullptr;
    antlr4::Token *voidToken = nullptr;
    Type_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *VOID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Type_specifierContext* type_specifier();

  class  Declaration_listContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    C8086Parser::Declaration_listContext *dl = nullptr;
    antlr4::Token *idToken = nullptr;
    antlr4::Token *const_intToken = nullptr;
    antlr4::Token *addopToken = nullptr;
    antlr4::Token *subopToken = nullptr;
    antlr4::Token *mulopToken = nullptr;
    antlr4::Token *incopToken = nullptr;
    antlr4::Token *decopToken = nullptr;
    antlr4::Token *notToken = nullptr;
    antlr4::Token *relopToken = nullptr;
    antlr4::Token *logicopToken = nullptr;
    antlr4::Token *assignopToken = nullptr;
    Declaration_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *RTHIRD();
    antlr4::tree::TerminalNode *COMMA();
    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *ADDOP();
    antlr4::tree::TerminalNode *SUBOP();
    antlr4::tree::TerminalNode *MULOP();
    antlr4::tree::TerminalNode *INCOP();
    antlr4::tree::TerminalNode *DECOP();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *RELOP();
    antlr4::tree::TerminalNode *LOGICOP();
    antlr4::tree::TerminalNode *ASSIGNOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declaration_listContext* declaration_list();
  Declaration_listContext* declaration_list(int precedence);
  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    C8086Parser::StatementsContext *ss = nullptr;
    C8086Parser::StatementContext *s = nullptr;
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    StatementsContext *statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementsContext* statements();
  StatementsContext* statements(int precedence);
  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    int line;
    C8086Parser::Var_declarationContext *vd = nullptr;
    C8086Parser::Expression_statementContext *es = nullptr;
    C8086Parser::Compound_statementContext *cs = nullptr;
    C8086Parser::Expression_statementContext *es1 = nullptr;
    C8086Parser::Expression_statementContext *es2 = nullptr;
    C8086Parser::ExpressionContext *e1 = nullptr;
    C8086Parser::StatementContext *s1 = nullptr;
    C8086Parser::ExpressionContext *e = nullptr;
    C8086Parser::StatementContext *s = nullptr;
    antlr4::Token *printlnToken = nullptr;
    antlr4::Token *idToken = nullptr;
    antlr4::Token *returnToken = nullptr;
    antlr4::Token *semicolonToken = nullptr;
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    std::vector<Expression_statementContext *> expression_statement();
    Expression_statementContext* expression_statement(size_t i);
    Compound_statementContext *compound_statement();
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionContext *expression();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *PRINTLN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *RETURN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  Expression_statementContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    int line;
    antlr4::Token *semicolonToken = nullptr;
    antlr4::Token *a = nullptr;
    Expression_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *ANY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expression_statementContext* expression_statement();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    string type;
    antlr4::Token *idToken = nullptr;
    C8086Parser::ExpressionContext *e = nullptr;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *RTHIRD();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableContext* variable();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    string type;
    C8086Parser::Logic_expressionContext *l = nullptr;
    C8086Parser::VariableContext *v = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    antlr4::tree::TerminalNode *ASSIGNOP();
    VariableContext *variable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  Logic_expressionContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    string type;
    C8086Parser::Rel_expressionContext *r = nullptr;
    C8086Parser::Rel_expressionContext *r1 = nullptr;
    Logic_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Rel_expressionContext *> rel_expression();
    Rel_expressionContext* rel_expression(size_t i);
    antlr4::tree::TerminalNode *LOGICOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Logic_expressionContext* logic_expression();

  class  Rel_expressionContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    string type;
    C8086Parser::Simple_expressionContext *s = nullptr;
    C8086Parser::Simple_expressionContext *s1 = nullptr;
    Rel_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Simple_expressionContext *> simple_expression();
    Simple_expressionContext* simple_expression(size_t i);
    antlr4::tree::TerminalNode *RELOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Rel_expressionContext* rel_expression();

  class  Simple_expressionContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    string type;
    C8086Parser::Simple_expressionContext *s = nullptr;
    C8086Parser::TermContext *t = nullptr;
    Simple_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    antlr4::tree::TerminalNode *ADDOP();
    Simple_expressionContext *simple_expression();
    antlr4::tree::TerminalNode *ASSIGNOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Simple_expressionContext* simple_expression();
  Simple_expressionContext* simple_expression(int precedence);
  class  TermContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    string type;
    C8086Parser::TermContext *t = nullptr;
    C8086Parser::Unary_expressionContext *u = nullptr;
    antlr4::Token *mulopToken = nullptr;
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_expressionContext *unary_expression();
    antlr4::tree::TerminalNode *MULOP();
    TermContext *term();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  Unary_expressionContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    string type;
    C8086Parser::Unary_expressionContext *u = nullptr;
    C8086Parser::FactorContext *f = nullptr;
    Unary_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDOP();
    Unary_expressionContext *unary_expression();
    antlr4::tree::TerminalNode *NOT();
    FactorContext *factor();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Unary_expressionContext* unary_expression();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    string type;
    C8086Parser::VariableContext *v = nullptr;
    antlr4::Token *idToken = nullptr;
    C8086Parser::Argument_listContext *a = nullptr;
    C8086Parser::ExpressionContext *e = nullptr;
    antlr4::Token *const_floatToken = nullptr;
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Argument_listContext *argument_list();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *CONST_FLOAT();
    antlr4::tree::TerminalNode *INCOP();
    antlr4::tree::TerminalNode *DECOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FactorContext* factor();

  class  Argument_listContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    vector <string> types;
    C8086Parser::ArgumentsContext *a = nullptr;
    Argument_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Argument_listContext* argument_list();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    string act_text;
    vector <string> types;
    C8086Parser::ArgumentsContext *a = nullptr;
    C8086Parser::Logic_expressionContext *l = nullptr;
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    antlr4::tree::TerminalNode *COMMA();
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgumentsContext* arguments();
  ArgumentsContext* arguments(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool programSempred(ProgramContext *_localctx, size_t predicateIndex);
  bool parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex);
  bool declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex);
  bool statementsSempred(StatementsContext *_localctx, size_t predicateIndex);
  bool simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex);
  bool termSempred(TermContext *_localctx, size_t predicateIndex);
  bool argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

