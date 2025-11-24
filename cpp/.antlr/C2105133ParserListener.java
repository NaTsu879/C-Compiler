// Generated from /mnt/d/2105133/3-1/Compiler/Syntax_Analyzer/antlr4-resources/antlr4-resources/antlr4-skeletons/cpp/C2105133Parser.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link C2105133Parser}.
 */
public interface C2105133ParserListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#start}.
	 * @param ctx the parse tree
	 */
	void enterStart(C2105133Parser.StartContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#start}.
	 * @param ctx the parse tree
	 */
	void exitStart(C2105133Parser.StartContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(C2105133Parser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(C2105133Parser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#unit}.
	 * @param ctx the parse tree
	 */
	void enterUnit(C2105133Parser.UnitContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#unit}.
	 * @param ctx the parse tree
	 */
	void exitUnit(C2105133Parser.UnitContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#func_declaration}.
	 * @param ctx the parse tree
	 */
	void enterFunc_declaration(C2105133Parser.Func_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#func_declaration}.
	 * @param ctx the parse tree
	 */
	void exitFunc_declaration(C2105133Parser.Func_declarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#func_definition}.
	 * @param ctx the parse tree
	 */
	void enterFunc_definition(C2105133Parser.Func_definitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#func_definition}.
	 * @param ctx the parse tree
	 */
	void exitFunc_definition(C2105133Parser.Func_definitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#parameter_list_err}.
	 * @param ctx the parse tree
	 */
	void enterParameter_list_err(C2105133Parser.Parameter_list_errContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#parameter_list_err}.
	 * @param ctx the parse tree
	 */
	void exitParameter_list_err(C2105133Parser.Parameter_list_errContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void enterParameter_list(C2105133Parser.Parameter_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void exitParameter_list(C2105133Parser.Parameter_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#compound_statement}.
	 * @param ctx the parse tree
	 */
	void enterCompound_statement(C2105133Parser.Compound_statementContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#compound_statement}.
	 * @param ctx the parse tree
	 */
	void exitCompound_statement(C2105133Parser.Compound_statementContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#var_declaration}.
	 * @param ctx the parse tree
	 */
	void enterVar_declaration(C2105133Parser.Var_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#var_declaration}.
	 * @param ctx the parse tree
	 */
	void exitVar_declaration(C2105133Parser.Var_declarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#declaration_list_err}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration_list_err(C2105133Parser.Declaration_list_errContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#declaration_list_err}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration_list_err(C2105133Parser.Declaration_list_errContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#type_specifier}.
	 * @param ctx the parse tree
	 */
	void enterType_specifier(C2105133Parser.Type_specifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#type_specifier}.
	 * @param ctx the parse tree
	 */
	void exitType_specifier(C2105133Parser.Type_specifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration_list(C2105133Parser.Declaration_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration_list(C2105133Parser.Declaration_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#statements}.
	 * @param ctx the parse tree
	 */
	void enterStatements(C2105133Parser.StatementsContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#statements}.
	 * @param ctx the parse tree
	 */
	void exitStatements(C2105133Parser.StatementsContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(C2105133Parser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(C2105133Parser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#expression_statement}.
	 * @param ctx the parse tree
	 */
	void enterExpression_statement(C2105133Parser.Expression_statementContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#expression_statement}.
	 * @param ctx the parse tree
	 */
	void exitExpression_statement(C2105133Parser.Expression_statementContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariable(C2105133Parser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariable(C2105133Parser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(C2105133Parser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(C2105133Parser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#logic_expression}.
	 * @param ctx the parse tree
	 */
	void enterLogic_expression(C2105133Parser.Logic_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#logic_expression}.
	 * @param ctx the parse tree
	 */
	void exitLogic_expression(C2105133Parser.Logic_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#rel_expression}.
	 * @param ctx the parse tree
	 */
	void enterRel_expression(C2105133Parser.Rel_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#rel_expression}.
	 * @param ctx the parse tree
	 */
	void exitRel_expression(C2105133Parser.Rel_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#simple_expression}.
	 * @param ctx the parse tree
	 */
	void enterSimple_expression(C2105133Parser.Simple_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#simple_expression}.
	 * @param ctx the parse tree
	 */
	void exitSimple_expression(C2105133Parser.Simple_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#term}.
	 * @param ctx the parse tree
	 */
	void enterTerm(C2105133Parser.TermContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#term}.
	 * @param ctx the parse tree
	 */
	void exitTerm(C2105133Parser.TermContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void enterUnary_expression(C2105133Parser.Unary_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void exitUnary_expression(C2105133Parser.Unary_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#factor}.
	 * @param ctx the parse tree
	 */
	void enterFactor(C2105133Parser.FactorContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#factor}.
	 * @param ctx the parse tree
	 */
	void exitFactor(C2105133Parser.FactorContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#argument_list}.
	 * @param ctx the parse tree
	 */
	void enterArgument_list(C2105133Parser.Argument_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#argument_list}.
	 * @param ctx the parse tree
	 */
	void exitArgument_list(C2105133Parser.Argument_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105133Parser#arguments}.
	 * @param ctx the parse tree
	 */
	void enterArguments(C2105133Parser.ArgumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105133Parser#arguments}.
	 * @param ctx the parse tree
	 */
	void exitArguments(C2105133Parser.ArgumentsContext ctx);
}