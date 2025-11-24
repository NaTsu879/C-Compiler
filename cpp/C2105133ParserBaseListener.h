
// Generated from C2105133Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "C2105133ParserListener.h"


/**
 * This class provides an empty implementation of C2105133ParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  C2105133ParserBaseListener : public C2105133ParserListener {
public:

  virtual void enterStart(C2105133Parser::StartContext * /*ctx*/) override { }
  virtual void exitStart(C2105133Parser::StartContext * /*ctx*/) override { }

  virtual void enterProgram(C2105133Parser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(C2105133Parser::ProgramContext * /*ctx*/) override { }

  virtual void enterUnit(C2105133Parser::UnitContext * /*ctx*/) override { }
  virtual void exitUnit(C2105133Parser::UnitContext * /*ctx*/) override { }

  virtual void enterFunc_declaration(C2105133Parser::Func_declarationContext * /*ctx*/) override { }
  virtual void exitFunc_declaration(C2105133Parser::Func_declarationContext * /*ctx*/) override { }

  virtual void enterFunc_definition(C2105133Parser::Func_definitionContext * /*ctx*/) override { }
  virtual void exitFunc_definition(C2105133Parser::Func_definitionContext * /*ctx*/) override { }

  virtual void enterParameter_list_err(C2105133Parser::Parameter_list_errContext * /*ctx*/) override { }
  virtual void exitParameter_list_err(C2105133Parser::Parameter_list_errContext * /*ctx*/) override { }

  virtual void enterParameter_list(C2105133Parser::Parameter_listContext * /*ctx*/) override { }
  virtual void exitParameter_list(C2105133Parser::Parameter_listContext * /*ctx*/) override { }

  virtual void enterCompound_statement(C2105133Parser::Compound_statementContext * /*ctx*/) override { }
  virtual void exitCompound_statement(C2105133Parser::Compound_statementContext * /*ctx*/) override { }

  virtual void enterVar_declaration(C2105133Parser::Var_declarationContext * /*ctx*/) override { }
  virtual void exitVar_declaration(C2105133Parser::Var_declarationContext * /*ctx*/) override { }

  virtual void enterDeclaration_list_err(C2105133Parser::Declaration_list_errContext * /*ctx*/) override { }
  virtual void exitDeclaration_list_err(C2105133Parser::Declaration_list_errContext * /*ctx*/) override { }

  virtual void enterType_specifier(C2105133Parser::Type_specifierContext * /*ctx*/) override { }
  virtual void exitType_specifier(C2105133Parser::Type_specifierContext * /*ctx*/) override { }

  virtual void enterDeclaration_list(C2105133Parser::Declaration_listContext * /*ctx*/) override { }
  virtual void exitDeclaration_list(C2105133Parser::Declaration_listContext * /*ctx*/) override { }

  virtual void enterStatements(C2105133Parser::StatementsContext * /*ctx*/) override { }
  virtual void exitStatements(C2105133Parser::StatementsContext * /*ctx*/) override { }

  virtual void enterStatement(C2105133Parser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(C2105133Parser::StatementContext * /*ctx*/) override { }

  virtual void enterExpression_statement(C2105133Parser::Expression_statementContext * /*ctx*/) override { }
  virtual void exitExpression_statement(C2105133Parser::Expression_statementContext * /*ctx*/) override { }

  virtual void enterVariable(C2105133Parser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(C2105133Parser::VariableContext * /*ctx*/) override { }

  virtual void enterExpression(C2105133Parser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(C2105133Parser::ExpressionContext * /*ctx*/) override { }

  virtual void enterLogic_expression(C2105133Parser::Logic_expressionContext * /*ctx*/) override { }
  virtual void exitLogic_expression(C2105133Parser::Logic_expressionContext * /*ctx*/) override { }

  virtual void enterRel_expression(C2105133Parser::Rel_expressionContext * /*ctx*/) override { }
  virtual void exitRel_expression(C2105133Parser::Rel_expressionContext * /*ctx*/) override { }

  virtual void enterSimple_expression(C2105133Parser::Simple_expressionContext * /*ctx*/) override { }
  virtual void exitSimple_expression(C2105133Parser::Simple_expressionContext * /*ctx*/) override { }

  virtual void enterTerm(C2105133Parser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(C2105133Parser::TermContext * /*ctx*/) override { }

  virtual void enterUnary_expression(C2105133Parser::Unary_expressionContext * /*ctx*/) override { }
  virtual void exitUnary_expression(C2105133Parser::Unary_expressionContext * /*ctx*/) override { }

  virtual void enterFactor(C2105133Parser::FactorContext * /*ctx*/) override { }
  virtual void exitFactor(C2105133Parser::FactorContext * /*ctx*/) override { }

  virtual void enterArgument_list(C2105133Parser::Argument_listContext * /*ctx*/) override { }
  virtual void exitArgument_list(C2105133Parser::Argument_listContext * /*ctx*/) override { }

  virtual void enterArguments(C2105133Parser::ArgumentsContext * /*ctx*/) override { }
  virtual void exitArguments(C2105133Parser::ArgumentsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

