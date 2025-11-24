
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
    #include <functional>
    #include <sstream>
    #include <vector>
    #include <regex>
    #include <unordered_map>
    #include <unordered_set>
    #include <stack>
    #include "C2105133Lexer.h"
    #include "2105133_SymbolTable.h"

    using namespace std;

    extern ofstream parserLogFile;
    extern ofstream errorFile;
    extern ofstream asmFile;
    extern ifstream libFile;
    extern SymbolTable Table;
    extern int syntaxErrorCount;
    extern int offset;
    extern int labelcount;
    extern int retcount;
    extern stack<string> elselabels;
    extern stack<string> exitlabels;
    extern stack<string> looplabels;
    extern stack<string> inclabels;
    extern stack<string> backlabels;
    extern stack<string> returnlabels;


// Generated from C2105133Parser.g4 by ANTLR 4.13.2


#include "C2105133ParserListener.h"

#include "C2105133Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct C2105133ParserStaticData final {
  C2105133ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C2105133ParserStaticData(const C2105133ParserStaticData&) = delete;
  C2105133ParserStaticData(C2105133ParserStaticData&&) = delete;
  C2105133ParserStaticData& operator=(const C2105133ParserStaticData&) = delete;
  C2105133ParserStaticData& operator=(C2105133ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c2105133parserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C2105133ParserStaticData> c2105133parserParserStaticData = nullptr;

void c2105133parserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c2105133parserParserStaticData != nullptr) {
    return;
  }
#else
  assert(c2105133parserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C2105133ParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "func_declaration", "func_definition", 
      "parameter_list_err", "parameter_list", "compound_statement", "var_declaration", 
      "declaration_list_err", "type_specifier", "declaration_list", "statements", 
      "statement", "expression_statement", "variable", "expression", "logic_expression", 
      "rel_expression", "simple_expression", "term", "unary_expression", 
      "factor", "argument_list", "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'println'", 
      "'return'", "'int'", "'float'", "'void'", "'forin'", "'foreach'", 
      "'in'", "'to'", "'times'", "'switch'", "'case'", "'break'", "'default'", 
      "'when'", "'('", "')'", "'{'", "'}'", "'['", "']'", "';'", "','", 
      "'\\u003F'", "':'", "'->'", "", "", "", "'++'", "'--'", "'!'", "", 
      "", "'='"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "FORIN", 
      "FOREACH", "IN", "TO", "TIMES", "SWITCH", "CASE", "BREAK", "DEFAULT", 
      "WHEN", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", 
      "SEMICOLON", "COMMA", "QUES", "COLON", "ARROW", "ADDOP", "SUBOP", 
      "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", "ASSIGNOP", 
      "ID", "CONST_INT", "CONST_FLOAT", "ANY"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,47,469,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,5,1,63,8,1,10,1,12,1,66,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,3,2,77,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,3,3,94,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,122,8,4,1,5,
  	4,5,125,8,5,11,5,12,5,126,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,
  	139,8,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,5,6,152,8,6,10,6,
  	12,6,155,9,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,167,8,7,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,179,8,8,1,9,1,9,1,10,1,10,1,10,
  	1,10,1,10,1,10,3,10,189,8,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	3,11,199,8,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,5,11,242,8,11,10,11,12,11,245,9,11,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,5,12,255,8,12,10,12,12,12,258,9,12,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	3,13,320,8,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,
  	332,8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,342,8,15,1,16,1,
  	16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,352,8,16,1,17,1,17,1,17,1,17,1,
  	17,1,17,1,17,1,17,3,17,362,8,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,
  	18,3,18,372,8,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,
  	19,1,19,1,19,1,19,1,19,5,19,389,8,19,10,19,12,19,392,9,19,1,20,1,20,1,
  	20,1,20,1,20,1,20,1,20,1,20,1,20,5,20,403,8,20,10,20,12,20,406,9,20,1,
  	21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,3,21,419,8,21,1,
  	22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,
  	22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,3,22,447,8,
  	22,1,23,1,23,1,23,1,23,3,23,453,8,23,1,24,1,24,1,24,1,24,1,24,1,24,1,
  	24,1,24,1,24,5,24,464,8,24,10,24,12,24,467,9,24,1,24,1,126,7,2,12,22,
  	24,38,40,48,25,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,
  	40,42,44,46,48,0,0,498,0,50,1,0,0,0,2,54,1,0,0,0,4,76,1,0,0,0,6,93,1,
  	0,0,0,8,121,1,0,0,0,10,124,1,0,0,0,12,138,1,0,0,0,14,166,1,0,0,0,16,178,
  	1,0,0,0,18,180,1,0,0,0,20,188,1,0,0,0,22,198,1,0,0,0,24,246,1,0,0,0,26,
  	319,1,0,0,0,28,331,1,0,0,0,30,341,1,0,0,0,32,351,1,0,0,0,34,361,1,0,0,
  	0,36,371,1,0,0,0,38,373,1,0,0,0,40,393,1,0,0,0,42,418,1,0,0,0,44,446,
  	1,0,0,0,46,452,1,0,0,0,48,454,1,0,0,0,50,51,6,0,-1,0,51,52,3,2,1,0,52,
  	53,6,0,-1,0,53,1,1,0,0,0,54,55,6,1,-1,0,55,56,3,4,2,0,56,57,6,1,-1,0,
  	57,64,1,0,0,0,58,59,10,2,0,0,59,60,3,4,2,0,60,61,6,1,-1,0,61,63,1,0,0,
  	0,62,58,1,0,0,0,63,66,1,0,0,0,64,62,1,0,0,0,64,65,1,0,0,0,65,3,1,0,0,
  	0,66,64,1,0,0,0,67,68,3,16,8,0,68,69,6,2,-1,0,69,77,1,0,0,0,70,71,3,6,
  	3,0,71,72,6,2,-1,0,72,77,1,0,0,0,73,74,3,8,4,0,74,75,6,2,-1,0,75,77,1,
  	0,0,0,76,67,1,0,0,0,76,70,1,0,0,0,76,73,1,0,0,0,77,5,1,0,0,0,78,79,3,
  	20,10,0,79,80,5,44,0,0,80,81,5,24,0,0,81,82,3,12,6,0,82,83,5,25,0,0,83,
  	84,5,30,0,0,84,85,6,3,-1,0,85,94,1,0,0,0,86,87,3,20,10,0,87,88,5,44,0,
  	0,88,89,5,24,0,0,89,90,5,25,0,0,90,91,5,30,0,0,91,92,6,3,-1,0,92,94,1,
  	0,0,0,93,78,1,0,0,0,93,86,1,0,0,0,94,7,1,0,0,0,95,96,3,20,10,0,96,97,
  	5,44,0,0,97,98,5,24,0,0,98,99,3,12,6,0,99,100,5,25,0,0,100,101,6,4,-1,
  	0,101,102,3,14,7,0,102,103,6,4,-1,0,103,122,1,0,0,0,104,105,3,20,10,0,
  	105,106,5,44,0,0,106,107,5,24,0,0,107,108,5,25,0,0,108,109,6,4,-1,0,109,
  	110,3,14,7,0,110,111,6,4,-1,0,111,122,1,0,0,0,112,113,3,20,10,0,113,114,
  	5,44,0,0,114,115,5,24,0,0,115,116,3,10,5,0,116,117,5,25,0,0,117,118,6,
  	4,-1,0,118,119,3,14,7,0,119,120,6,4,-1,0,120,122,1,0,0,0,121,95,1,0,0,
  	0,121,104,1,0,0,0,121,112,1,0,0,0,122,9,1,0,0,0,123,125,9,0,0,0,124,123,
  	1,0,0,0,125,126,1,0,0,0,126,127,1,0,0,0,126,124,1,0,0,0,127,128,1,0,0,
  	0,128,129,6,5,-1,0,129,11,1,0,0,0,130,131,6,6,-1,0,131,132,3,20,10,0,
  	132,133,5,44,0,0,133,134,6,6,-1,0,134,139,1,0,0,0,135,136,3,20,10,0,136,
  	137,6,6,-1,0,137,139,1,0,0,0,138,130,1,0,0,0,138,135,1,0,0,0,139,153,
  	1,0,0,0,140,141,10,4,0,0,141,142,5,31,0,0,142,143,3,20,10,0,143,144,5,
  	44,0,0,144,145,6,6,-1,0,145,152,1,0,0,0,146,147,10,3,0,0,147,148,5,31,
  	0,0,148,149,3,20,10,0,149,150,6,6,-1,0,150,152,1,0,0,0,151,140,1,0,0,
  	0,151,146,1,0,0,0,152,155,1,0,0,0,153,151,1,0,0,0,153,154,1,0,0,0,154,
  	13,1,0,0,0,155,153,1,0,0,0,156,157,5,26,0,0,157,158,6,7,-1,0,158,159,
  	3,24,12,0,159,160,5,27,0,0,160,161,6,7,-1,0,161,167,1,0,0,0,162,163,5,
  	26,0,0,163,164,6,7,-1,0,164,165,5,27,0,0,165,167,6,7,-1,0,166,156,1,0,
  	0,0,166,162,1,0,0,0,167,15,1,0,0,0,168,169,3,20,10,0,169,170,3,22,11,
  	0,170,171,5,30,0,0,171,172,6,8,-1,0,172,179,1,0,0,0,173,174,3,20,10,0,
  	174,175,3,18,9,0,175,176,5,30,0,0,176,177,6,8,-1,0,177,179,1,0,0,0,178,
  	168,1,0,0,0,178,173,1,0,0,0,179,17,1,0,0,0,180,181,6,9,-1,0,181,19,1,
  	0,0,0,182,183,5,11,0,0,183,189,6,10,-1,0,184,185,5,12,0,0,185,189,6,10,
  	-1,0,186,187,5,13,0,0,187,189,6,10,-1,0,188,182,1,0,0,0,188,184,1,0,0,
  	0,188,186,1,0,0,0,189,21,1,0,0,0,190,191,6,11,-1,0,191,192,5,44,0,0,192,
  	199,6,11,-1,0,193,194,5,44,0,0,194,195,5,28,0,0,195,196,5,45,0,0,196,
  	197,5,29,0,0,197,199,6,11,-1,0,198,190,1,0,0,0,198,193,1,0,0,0,199,243,
  	1,0,0,0,200,201,10,14,0,0,201,202,5,31,0,0,202,203,5,44,0,0,203,242,6,
  	11,-1,0,204,205,10,13,0,0,205,206,5,31,0,0,206,207,5,44,0,0,207,208,5,
  	28,0,0,208,209,5,45,0,0,209,210,5,29,0,0,210,242,6,11,-1,0,211,212,10,
  	10,0,0,212,213,5,35,0,0,213,242,6,11,-1,0,214,215,10,9,0,0,215,216,5,
  	44,0,0,216,242,6,11,-1,0,217,218,10,8,0,0,218,219,5,36,0,0,219,242,6,
  	11,-1,0,220,221,10,7,0,0,221,222,5,37,0,0,222,242,6,11,-1,0,223,224,10,
  	6,0,0,224,225,5,38,0,0,225,242,6,11,-1,0,226,227,10,5,0,0,227,228,5,39,
  	0,0,228,242,6,11,-1,0,229,230,10,4,0,0,230,231,5,40,0,0,231,242,6,11,
  	-1,0,232,233,10,3,0,0,233,234,5,41,0,0,234,242,6,11,-1,0,235,236,10,2,
  	0,0,236,237,5,42,0,0,237,242,6,11,-1,0,238,239,10,1,0,0,239,240,5,43,
  	0,0,240,242,6,11,-1,0,241,200,1,0,0,0,241,204,1,0,0,0,241,211,1,0,0,0,
  	241,214,1,0,0,0,241,217,1,0,0,0,241,220,1,0,0,0,241,223,1,0,0,0,241,226,
  	1,0,0,0,241,229,1,0,0,0,241,232,1,0,0,0,241,235,1,0,0,0,241,238,1,0,0,
  	0,242,245,1,0,0,0,243,241,1,0,0,0,243,244,1,0,0,0,244,23,1,0,0,0,245,
  	243,1,0,0,0,246,247,6,12,-1,0,247,248,3,26,13,0,248,249,6,12,-1,0,249,
  	256,1,0,0,0,250,251,10,1,0,0,251,252,3,26,13,0,252,253,6,12,-1,0,253,
  	255,1,0,0,0,254,250,1,0,0,0,255,258,1,0,0,0,256,254,1,0,0,0,256,257,1,
  	0,0,0,257,25,1,0,0,0,258,256,1,0,0,0,259,260,3,16,8,0,260,261,6,13,-1,
  	0,261,320,1,0,0,0,262,263,3,28,14,0,263,264,6,13,-1,0,264,320,1,0,0,0,
  	265,266,3,14,7,0,266,267,6,13,-1,0,267,320,1,0,0,0,268,269,5,7,0,0,269,
  	270,5,24,0,0,270,271,3,28,14,0,271,272,6,13,-1,0,272,273,3,28,14,0,273,
  	274,6,13,-1,0,274,275,3,32,16,0,275,276,6,13,-1,0,276,277,5,25,0,0,277,
  	278,3,26,13,0,278,279,6,13,-1,0,279,320,1,0,0,0,280,281,5,5,0,0,281,282,
  	5,24,0,0,282,283,3,32,16,0,283,284,6,13,-1,0,284,285,5,25,0,0,285,286,
  	3,26,13,0,286,287,6,13,-1,0,287,320,1,0,0,0,288,289,5,5,0,0,289,290,5,
  	24,0,0,290,291,3,32,16,0,291,292,6,13,-1,0,292,293,5,25,0,0,293,294,3,
  	26,13,0,294,295,6,13,-1,0,295,296,5,6,0,0,296,297,3,26,13,0,297,298,6,
  	13,-1,0,298,320,1,0,0,0,299,300,5,8,0,0,300,301,5,24,0,0,301,302,6,13,
  	-1,0,302,303,3,32,16,0,303,304,6,13,-1,0,304,305,5,25,0,0,305,306,3,26,
  	13,0,306,307,6,13,-1,0,307,320,1,0,0,0,308,309,5,9,0,0,309,310,5,24,0,
  	0,310,311,5,44,0,0,311,312,5,25,0,0,312,313,5,30,0,0,313,320,6,13,-1,
  	0,314,315,5,10,0,0,315,316,3,32,16,0,316,317,5,30,0,0,317,318,6,13,-1,
  	0,318,320,1,0,0,0,319,259,1,0,0,0,319,262,1,0,0,0,319,265,1,0,0,0,319,
  	268,1,0,0,0,319,280,1,0,0,0,319,288,1,0,0,0,319,299,1,0,0,0,319,308,1,
  	0,0,0,319,314,1,0,0,0,320,27,1,0,0,0,321,322,5,30,0,0,322,332,6,14,-1,
  	0,323,324,3,32,16,0,324,325,5,30,0,0,325,326,6,14,-1,0,326,332,1,0,0,
  	0,327,328,3,32,16,0,328,329,5,47,0,0,329,330,6,14,-1,0,330,332,1,0,0,
  	0,331,321,1,0,0,0,331,323,1,0,0,0,331,327,1,0,0,0,332,29,1,0,0,0,333,
  	334,5,44,0,0,334,342,6,15,-1,0,335,336,5,44,0,0,336,337,5,28,0,0,337,
  	338,3,32,16,0,338,339,5,29,0,0,339,340,6,15,-1,0,340,342,1,0,0,0,341,
  	333,1,0,0,0,341,335,1,0,0,0,342,31,1,0,0,0,343,344,3,34,17,0,344,345,
  	6,16,-1,0,345,352,1,0,0,0,346,347,3,30,15,0,347,348,5,43,0,0,348,349,
  	3,34,17,0,349,350,6,16,-1,0,350,352,1,0,0,0,351,343,1,0,0,0,351,346,1,
  	0,0,0,352,33,1,0,0,0,353,354,3,36,18,0,354,355,6,17,-1,0,355,362,1,0,
  	0,0,356,357,3,36,18,0,357,358,5,42,0,0,358,359,3,36,18,0,359,360,6,17,
  	-1,0,360,362,1,0,0,0,361,353,1,0,0,0,361,356,1,0,0,0,362,35,1,0,0,0,363,
  	364,3,38,19,0,364,365,6,18,-1,0,365,372,1,0,0,0,366,367,3,38,19,0,367,
  	368,5,41,0,0,368,369,3,38,19,0,369,370,6,18,-1,0,370,372,1,0,0,0,371,
  	363,1,0,0,0,371,366,1,0,0,0,372,37,1,0,0,0,373,374,6,19,-1,0,374,375,
  	3,40,20,0,375,376,6,19,-1,0,376,390,1,0,0,0,377,378,10,2,0,0,378,379,
  	5,35,0,0,379,380,3,40,20,0,380,381,6,19,-1,0,381,389,1,0,0,0,382,383,
  	10,1,0,0,383,384,5,35,0,0,384,385,5,43,0,0,385,386,3,40,20,0,386,387,
  	6,19,-1,0,387,389,1,0,0,0,388,377,1,0,0,0,388,382,1,0,0,0,389,392,1,0,
  	0,0,390,388,1,0,0,0,390,391,1,0,0,0,391,39,1,0,0,0,392,390,1,0,0,0,393,
  	394,6,20,-1,0,394,395,3,42,21,0,395,396,6,20,-1,0,396,404,1,0,0,0,397,
  	398,10,1,0,0,398,399,5,37,0,0,399,400,3,42,21,0,400,401,6,20,-1,0,401,
  	403,1,0,0,0,402,397,1,0,0,0,403,406,1,0,0,0,404,402,1,0,0,0,404,405,1,
  	0,0,0,405,41,1,0,0,0,406,404,1,0,0,0,407,408,5,35,0,0,408,409,3,42,21,
  	0,409,410,6,21,-1,0,410,419,1,0,0,0,411,412,5,40,0,0,412,413,3,42,21,
  	0,413,414,6,21,-1,0,414,419,1,0,0,0,415,416,3,44,22,0,416,417,6,21,-1,
  	0,417,419,1,0,0,0,418,407,1,0,0,0,418,411,1,0,0,0,418,415,1,0,0,0,419,
  	43,1,0,0,0,420,421,3,30,15,0,421,422,6,22,-1,0,422,447,1,0,0,0,423,424,
  	5,44,0,0,424,425,5,24,0,0,425,426,3,46,23,0,426,427,5,25,0,0,427,428,
  	6,22,-1,0,428,447,1,0,0,0,429,430,5,24,0,0,430,431,3,32,16,0,431,432,
  	5,25,0,0,432,433,6,22,-1,0,433,447,1,0,0,0,434,435,5,45,0,0,435,447,6,
  	22,-1,0,436,437,5,46,0,0,437,447,6,22,-1,0,438,439,3,30,15,0,439,440,
  	5,38,0,0,440,441,6,22,-1,0,441,447,1,0,0,0,442,443,3,30,15,0,443,444,
  	5,39,0,0,444,445,6,22,-1,0,445,447,1,0,0,0,446,420,1,0,0,0,446,423,1,
  	0,0,0,446,429,1,0,0,0,446,434,1,0,0,0,446,436,1,0,0,0,446,438,1,0,0,0,
  	446,442,1,0,0,0,447,45,1,0,0,0,448,449,3,48,24,0,449,450,6,23,-1,0,450,
  	453,1,0,0,0,451,453,1,0,0,0,452,448,1,0,0,0,452,451,1,0,0,0,453,47,1,
  	0,0,0,454,455,6,24,-1,0,455,456,3,34,17,0,456,457,6,24,-1,0,457,465,1,
  	0,0,0,458,459,10,2,0,0,459,460,5,31,0,0,460,461,3,34,17,0,461,462,6,24,
  	-1,0,462,464,1,0,0,0,463,458,1,0,0,0,464,467,1,0,0,0,465,463,1,0,0,0,
  	465,466,1,0,0,0,466,49,1,0,0,0,467,465,1,0,0,0,28,64,76,93,121,126,138,
  	151,153,166,178,188,198,241,243,256,319,331,341,351,361,371,388,390,404,
  	418,446,452,465
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c2105133parserParserStaticData = std::move(staticData);
}

}

C2105133Parser::C2105133Parser(TokenStream *input) : C2105133Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

C2105133Parser::C2105133Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  C2105133Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *c2105133parserParserStaticData->atn, c2105133parserParserStaticData->decisionToDFA, c2105133parserParserStaticData->sharedContextCache, options);
}

C2105133Parser::~C2105133Parser() {
  delete _interpreter;
}

const atn::ATN& C2105133Parser::getATN() const {
  return *c2105133parserParserStaticData->atn;
}

std::string C2105133Parser::getGrammarFileName() const {
  return "C2105133Parser.g4";
}

const std::vector<std::string>& C2105133Parser::getRuleNames() const {
  return c2105133parserParserStaticData->ruleNames;
}

const dfa::Vocabulary& C2105133Parser::getVocabulary() const {
  return c2105133parserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C2105133Parser::getSerializedATN() const {
  return c2105133parserParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

C2105133Parser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105133Parser::ProgramContext* C2105133Parser::StartContext::program() {
  return getRuleContext<C2105133Parser::ProgramContext>(0);
}


size_t C2105133Parser::StartContext::getRuleIndex() const {
  return C2105133Parser::RuleStart;
}

void C2105133Parser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void C2105133Parser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

C2105133Parser::StartContext* C2105133Parser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, C2105133Parser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

            asmFile << ".MODEL SMALL" << endl;
            asmFile << ".STACK 100h" << endl;
            asmFile << ".DATA" << endl;
            asmFile << "number DB \"00000$\" "<<endl;
            asmFile << ".CODE" <<endl;
          
    setState(51);
    antlrcpp::downCast<StartContext *>(_localctx)->p = program(0);

            writeIntoparserLogFile(
                "Line " + to_string((antlrcpp::downCast<StartContext *>(_localctx)->p != nullptr ? (antlrcpp::downCast<StartContext *>(_localctx)->p->stop) : nullptr)->getLine()) +
                ": start : program \n\n" + "\n"
            );
            Table.printAllScopeTable(parserLogFile);
            writeIntoparserLogFile("Total lines: " + to_string((antlrcpp::downCast<StartContext *>(_localctx)->p != nullptr ? (antlrcpp::downCast<StartContext *>(_localctx)->p->stop) : nullptr)->getLine()) +
            "\nTotal errors: " + to_string(syntaxErrorCount) + "\n");

            string line;
            while (getline(libFile, line)) {
                asmFile << line << endl;
            }

            asmFile << "END main"<<endl;
            optcodegen();
          
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

C2105133Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105133Parser::UnitContext* C2105133Parser::ProgramContext::unit() {
  return getRuleContext<C2105133Parser::UnitContext>(0);
}

C2105133Parser::ProgramContext* C2105133Parser::ProgramContext::program() {
  return getRuleContext<C2105133Parser::ProgramContext>(0);
}


size_t C2105133Parser::ProgramContext::getRuleIndex() const {
  return C2105133Parser::RuleProgram;
}

void C2105133Parser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void C2105133Parser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


C2105133Parser::ProgramContext* C2105133Parser::program() {
   return program(0);
}

C2105133Parser::ProgramContext* C2105133Parser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105133Parser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  C2105133Parser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, C2105133Parser::RuleProgram, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(55);
    antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

            antlrcpp::downCast<ProgramContext *>(_localctx)->act_text =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->act_text;
            writeIntoparserLogFile(
                "Line " + to_string((antlrcpp::downCast<ProgramContext *>(_localctx)->u != nullptr ? (antlrcpp::downCast<ProgramContext *>(_localctx)->u->stop) : nullptr)->getLine()) +
                ": program : unit\n\n" + _localctx->act_text + "\n"
            );
        
    _ctx->stop = _input->LT(-1);
    setState(64);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ProgramContext>(parentContext, parentState);
        _localctx->p = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleProgram);
        setState(58);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(59);
        antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

                          antlrcpp::downCast<ProgramContext *>(_localctx)->act_text =  antlrcpp::downCast<ProgramContext *>(_localctx)->p->act_text + antlrcpp::downCast<ProgramContext *>(_localctx)->u->act_text;
                          writeIntoparserLogFile(
                              "Line " + to_string((antlrcpp::downCast<ProgramContext *>(_localctx)->u != nullptr ? (antlrcpp::downCast<ProgramContext *>(_localctx)->u->stop) : nullptr)->getLine()) +
                              ": program : program unit\n\n" + _localctx->act_text + "\n"
                          );
                       
      }
      setState(66);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

C2105133Parser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105133Parser::Var_declarationContext* C2105133Parser::UnitContext::var_declaration() {
  return getRuleContext<C2105133Parser::Var_declarationContext>(0);
}

C2105133Parser::Func_declarationContext* C2105133Parser::UnitContext::func_declaration() {
  return getRuleContext<C2105133Parser::Func_declarationContext>(0);
}

C2105133Parser::Func_definitionContext* C2105133Parser::UnitContext::func_definition() {
  return getRuleContext<C2105133Parser::Func_definitionContext>(0);
}


size_t C2105133Parser::UnitContext::getRuleIndex() const {
  return C2105133Parser::RuleUnit;
}

void C2105133Parser::UnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit(this);
}

void C2105133Parser::UnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit(this);
}

C2105133Parser::UnitContext* C2105133Parser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, C2105133Parser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(67);
      antlrcpp::downCast<UnitContext *>(_localctx)->vd = var_declaration();

              antlrcpp::downCast<UnitContext *>(_localctx)->act_text =  antlrcpp::downCast<UnitContext *>(_localctx)->vd->act_text;
              writeIntoparserLogFile(
                  "Line " + to_string(_localctx->getStart()->getLine()) +
                  ": unit : var_declaration\n\n" + _localctx->act_text + "\n"
              );
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(70);
      antlrcpp::downCast<UnitContext *>(_localctx)->fd = func_declaration();

              antlrcpp::downCast<UnitContext *>(_localctx)->act_text =  antlrcpp::downCast<UnitContext *>(_localctx)->fd->act_text;
              writeIntoparserLogFile(
                  "Line " + to_string(_localctx->getStart()->getLine()) +
                  ": unit : func_declaration\n\n" + _localctx->act_text + "\n"
              );
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(73);
      antlrcpp::downCast<UnitContext *>(_localctx)->f = func_definition();

              antlrcpp::downCast<UnitContext *>(_localctx)->act_text =  antlrcpp::downCast<UnitContext *>(_localctx)->f->act_text + "\n";
              writeIntoparserLogFile(
                  "Line " + to_string((antlrcpp::downCast<UnitContext *>(_localctx)->f != nullptr ? (antlrcpp::downCast<UnitContext *>(_localctx)->f->stop) : nullptr)->getLine()) +
                  ": unit : func_definition\n\n" + _localctx->act_text + "\n"
              );
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declarationContext ------------------------------------------------------------------

C2105133Parser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105133Parser::Func_declarationContext::ID() {
  return getToken(C2105133Parser::ID, 0);
}

tree::TerminalNode* C2105133Parser::Func_declarationContext::LPAREN() {
  return getToken(C2105133Parser::LPAREN, 0);
}

tree::TerminalNode* C2105133Parser::Func_declarationContext::RPAREN() {
  return getToken(C2105133Parser::RPAREN, 0);
}

tree::TerminalNode* C2105133Parser::Func_declarationContext::SEMICOLON() {
  return getToken(C2105133Parser::SEMICOLON, 0);
}

C2105133Parser::Type_specifierContext* C2105133Parser::Func_declarationContext::type_specifier() {
  return getRuleContext<C2105133Parser::Type_specifierContext>(0);
}

C2105133Parser::Parameter_listContext* C2105133Parser::Func_declarationContext::parameter_list() {
  return getRuleContext<C2105133Parser::Parameter_listContext>(0);
}


size_t C2105133Parser::Func_declarationContext::getRuleIndex() const {
  return C2105133Parser::RuleFunc_declaration;
}

void C2105133Parser::Func_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_declaration(this);
}

void C2105133Parser::Func_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_declaration(this);
}

C2105133Parser::Func_declarationContext* C2105133Parser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, C2105133Parser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(93);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(78);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(79);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C2105133Parser::ID);
      setState(80);
      match(C2105133Parser::LPAREN);
      setState(81);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->p = parameter_list(0);
      setState(82);
      match(C2105133Parser::RPAREN);
      setState(83);
      match(C2105133Parser::SEMICOLON);

              antlrcpp::downCast<Func_declarationContext *>(_localctx)->act_text =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->act_text + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() + "(" + antlrcpp::downCast<Func_declarationContext *>(_localctx)->p->act_text + ")" + ";\n";
              writeIntoparserLogFile(
                  "Line " + to_string(_localctx->getStart()->getLine()) +
                  ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n" +
                  _localctx->act_text + "\n"
              );
              insertFunctionDeclaration(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText(),antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->act_text,antlrcpp::downCast<Func_declarationContext *>(_localctx)->p->act_text);
              Table.enterScope();
              vector <string> store = extractParamTypes(antlrcpp::downCast<Func_declarationContext *>(_localctx)->p->act_text, true, true, _localctx->getStart()->getLine());
              Table.exitScope();
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(86);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(87);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C2105133Parser::ID);
      setState(88);
      match(C2105133Parser::LPAREN);
      setState(89);
      match(C2105133Parser::RPAREN);
      setState(90);
      match(C2105133Parser::SEMICOLON);

               antlrcpp::downCast<Func_declarationContext *>(_localctx)->act_text =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->act_text + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() + "(" + ")" + ";\n";
              writeIntoparserLogFile(
                  "Line " + to_string(_localctx->getStart()->getLine()) +
                  ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n" +
                  _localctx->act_text + "\n"
              );
              insertFunctionDeclaration(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText(),antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->act_text);
              Table.enterScope();
              Table.exitScope();
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_definitionContext ------------------------------------------------------------------

C2105133Parser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105133Parser::Func_definitionContext::ID() {
  return getToken(C2105133Parser::ID, 0);
}

tree::TerminalNode* C2105133Parser::Func_definitionContext::LPAREN() {
  return getToken(C2105133Parser::LPAREN, 0);
}

tree::TerminalNode* C2105133Parser::Func_definitionContext::RPAREN() {
  return getToken(C2105133Parser::RPAREN, 0);
}

C2105133Parser::Type_specifierContext* C2105133Parser::Func_definitionContext::type_specifier() {
  return getRuleContext<C2105133Parser::Type_specifierContext>(0);
}

C2105133Parser::Parameter_listContext* C2105133Parser::Func_definitionContext::parameter_list() {
  return getRuleContext<C2105133Parser::Parameter_listContext>(0);
}

C2105133Parser::Compound_statementContext* C2105133Parser::Func_definitionContext::compound_statement() {
  return getRuleContext<C2105133Parser::Compound_statementContext>(0);
}

C2105133Parser::Parameter_list_errContext* C2105133Parser::Func_definitionContext::parameter_list_err() {
  return getRuleContext<C2105133Parser::Parameter_list_errContext>(0);
}


size_t C2105133Parser::Func_definitionContext::getRuleIndex() const {
  return C2105133Parser::RuleFunc_definition;
}

void C2105133Parser::Func_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_definition(this);
}

void C2105133Parser::Func_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_definition(this);
}

C2105133Parser::Func_definitionContext* C2105133Parser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, C2105133Parser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(121);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(95);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(96);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C2105133Parser::ID);
      setState(97);
      match(C2105133Parser::LPAREN);
      setState(98);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->p = parameter_list(0);
      setState(99);
      match(C2105133Parser::RPAREN);

          SymbolInfo* temp = Table.lookup(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());
              if(temp!=nullptr){
                  if(!temp->getIsDeclared())
                  {
                      //insertFunctionDeclaration(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(),antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->act_text,antlrcpp::downCast<Func_definitionContext *>(_localctx)->p->act_text,true);
                      writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
                      writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n"); 
                  }
                  else{
                      if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->act_text != temp->getReturnType())
                      {
                          writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Return type mismatch with function declaration in function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
                          writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Return type mismatch with function declaration in function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");   
                      }
                      vector <string> param = extractParamTypes(antlrcpp::downCast<Func_definitionContext *>(_localctx)->p->act_text, false);
                      if(param.size() != temp->getParamTypes().size())
                      {
                          writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
                          writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n"); 
                      }
                  }
                  Table.enterScope();
                  vector <string> store = extractParamTypes(antlrcpp::downCast<Func_definitionContext *>(_localctx)->p->act_text, true, true, _localctx->getStart()->getLine());
              }else
              {
                  
                  insertFunctionDeclaration(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(),antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->act_text,antlrcpp::downCast<Func_definitionContext *>(_localctx)->p->act_text,true);
                  Table.enterScope();
                  vector <string> store = extractParamTypes(antlrcpp::downCast<Func_definitionContext *>(_localctx)->p->act_text, true, true, _localctx->getStart()->getLine());
              }

              asmFile <<antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText()<< " PROC" <<"\t\t\t; Line "<< to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine())<<endl;
              asmFile << "\tPUSH BP"<<endl;
              asmFile <<  "\tMOV BP, SP"<<endl;
          
      setState(101);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->c = compound_statement(false);

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->act_text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->act_text + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "(" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->p->act_text + ")" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->act_text;
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->Line =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->Line;
              writeIntoparserLogFile(
                  "Line " + to_string((antlrcpp::downCast<Func_definitionContext *>(_localctx)->c != nullptr ? (antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->stop) : nullptr)->getLine()) +
                  ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n" +
                  _localctx->act_text + "\n"
              );
              Table.exitScope();
              SymbolInfo *item = Table.getCurrentScopeTable()->lookup(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());
              vector <string > store;
              if(item)
              {
                  store = item->getParamTypes();
              }
              if(!returnlabels.empty())
              {   
                  asmFile<<returnlabels.top()<<":"<<endl;
                  returnlabels.pop();
              }
              asmFile<< "\tADD SP, "<<offset-2<<endl;
              offset = 2;
              asmFile <<"\tPOP BP"<<endl;
              asmFile <<"\tRET "<<store.size()*2<<endl;
              asmFile << antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() << " ENDP" << endl;
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(104);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(105);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C2105133Parser::ID);
      setState(106);
      match(C2105133Parser::LPAREN);
      setState(107);
      match(C2105133Parser::RPAREN);

              SymbolInfo* temp = Table.lookup(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());
              if(temp!=nullptr){
                  if(!temp->getIsDeclared())
                       insertFunctionDeclaration(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(),antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->act_text,"",true);
                  Table.enterScope();
              }else
              {
                  if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText()=="main")
                  {    
                     
                      asmFile << "main PROC" <<"\t\t\t; Line "<< to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine())<<endl;
                      asmFile << "\tMOV AX, @DATA"<<endl;
                      asmFile << "\tMOV DS, AX"<<endl;
                      asmFile << "\tPUSH BP"<<endl;
                      asmFile <<  "\tMOV BP, SP"<<endl;
                  }else
                  {
                      asmFile <<antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText()<< " PROC"<<"\t\t\t; Line "<< to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) <<endl;
                      asmFile << "\tPUSH BP"<<endl;
                      asmFile <<  "\tMOV BP, SP"<<endl;
                  }
                  insertFunctionDeclaration(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(),antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->act_text,"",true);
                  Table.enterScope();
              }
          
      setState(109);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->c = compound_statement(false);

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->act_text =   antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->act_text + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "(" + ")" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->act_text;
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->Line =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->Line;
              writeIntoparserLogFile(
                  "Line " + to_string((antlrcpp::downCast<Func_definitionContext *>(_localctx)->c != nullptr ? (antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->stop) : nullptr)->getLine()) +
                  ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n" +
                  _localctx->act_text + "\n"
              );
              Table.exitScope();

              if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText()=="main")
              {    
                     
                      if(!returnlabels.empty())
                      {   
                          asmFile<<returnlabels.top()<<":"<<endl;
                          returnlabels.pop();
                      }
                      asmFile<< "\tADD SP, "<<offset-2<<endl;
      	            asmFile <<"\tPOP BP"<<endl;
                      asmFile << "\tMOV AX, 4C00H" << endl;
                      asmFile << "\tINT 21H" << endl;
                      asmFile << "MAIN ENDP" << endl;
              }else
              {
                      if(!returnlabels.empty())
                      {   
                          asmFile<<returnlabels.top()<<":"<<endl;
                          returnlabels.pop();
                      }
                      asmFile<< "\tADD SP, "<<offset-2<<endl;
      	            asmFile <<"\tPOP BP"<<endl;
                      asmFile <<"\tRET"<<endl;
                      asmFile << antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() << " ENDP" << endl;
              }
              offset = 2;
              
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(112);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(113);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C2105133Parser::ID);
      setState(114);
      match(C2105133Parser::LPAREN);
      setState(115);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->pe = parameter_list_err();
      setState(116);
      match(C2105133Parser::RPAREN);

              // This block handles error in parameter list
              writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Syntax error in parameter list of function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
              writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Syntax error in parameter list of function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
              Table.enterScope();  // still enter scope to allow compound_statement parsing
          
      setState(118);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->c = compound_statement(false);

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->act_text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->act_text + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "(" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->pe->act_text + ")" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->act_text;
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->Line =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->Line;
              writeIntoparserLogFile("Line " + to_string((antlrcpp::downCast<Func_definitionContext *>(_localctx)->c != nullptr ? (antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->stop) : nullptr)->getLine()) + ": func_definition : type_specifier ID LPAREN parameter_list_err RPAREN compound_statement\n\n" + _localctx->act_text + "\n");
              Table.exitScope();
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_list_errContext ------------------------------------------------------------------

C2105133Parser::Parameter_list_errContext::Parameter_list_errContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C2105133Parser::Parameter_list_errContext::getRuleIndex() const {
  return C2105133Parser::RuleParameter_list_err;
}

void C2105133Parser::Parameter_list_errContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list_err(this);
}

void C2105133Parser::Parameter_list_errContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list_err(this);
}

C2105133Parser::Parameter_list_errContext* C2105133Parser::parameter_list_err() {
  Parameter_list_errContext *_localctx = _tracker.createInstance<Parameter_list_errContext>(_ctx, getState());
  enterRule(_localctx, 10, C2105133Parser::RuleParameter_list_err);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(124); 
    _errHandler->sync(this);
    alt = 1 + 1;
    do {
      switch (alt) {
        case 1 + 1: {
              setState(123);
              matchWildcard();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(126); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    } while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER);

        antlrcpp::downCast<Parameter_list_errContext *>(_localctx)->act_text =  _localctx->getText();

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

C2105133Parser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105133Parser::Parameter_listContext::ID() {
  return getToken(C2105133Parser::ID, 0);
}

C2105133Parser::Type_specifierContext* C2105133Parser::Parameter_listContext::type_specifier() {
  return getRuleContext<C2105133Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105133Parser::Parameter_listContext::COMMA() {
  return getToken(C2105133Parser::COMMA, 0);
}

C2105133Parser::Parameter_listContext* C2105133Parser::Parameter_listContext::parameter_list() {
  return getRuleContext<C2105133Parser::Parameter_listContext>(0);
}


size_t C2105133Parser::Parameter_listContext::getRuleIndex() const {
  return C2105133Parser::RuleParameter_list;
}

void C2105133Parser::Parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list(this);
}

void C2105133Parser::Parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list(this);
}


C2105133Parser::Parameter_listContext* C2105133Parser::parameter_list() {
   return parameter_list(0);
}

C2105133Parser::Parameter_listContext* C2105133Parser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105133Parser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  C2105133Parser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, C2105133Parser::RuleParameter_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(138);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(131);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
      setState(132);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C2105133Parser::ID);

              antlrcpp::downCast<Parameter_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->act_text + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText();
              writeIntoparserLogFile(
                  "Line " + to_string(_localctx->getStart()->getLine()) +
                  ": parameter_list : type_specifier ID\n\n" +
                  _localctx->act_text + "\n"
              );
          
      break;
    }

    case 2: {
      setState(135);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();

              antlrcpp::downCast<Parameter_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->act_text ;
              writeIntoparserLogFile(
                  "Line " + to_string(_localctx->getStart()->getLine()) +
                  ": parameter_list : type_specifier\n\n" +
                  _localctx->act_text + "\n"
              );
          
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(153);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(151);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->p = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(140);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(141);
          match(C2105133Parser::COMMA);
          setState(142);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
          setState(143);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C2105133Parser::ID);

                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->p->act_text + "," + antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->act_text + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText();
                            writeIntoparserLogFile(
                                "Line " + to_string(_localctx->getStart()->getLine()) +
                                ": parameter_list : parameter_list COMMA type_specifier ID\n\n" +
                                _localctx->act_text + "\n"
                            );
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->p = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(146);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(147);
          match(C2105133Parser::COMMA);
          setState(148);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();

                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->p->act_text + "," + antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->act_text;
                            writeIntoparserLogFile(
                                "Line " + to_string(_localctx->getStart()->getLine()) +
                                ": parameter_list : parameter_list COMMA type_specifier\n\n" +
                                _localctx->act_text + "\n"
                            );
                        
          break;
        }

        default:
          break;
        } 
      }
      setState(155);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

C2105133Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105133Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState, bool flagScope)
  : ParserRuleContext(parent, invokingState) {
  this->flagScope = flagScope;
}

tree::TerminalNode* C2105133Parser::Compound_statementContext::LCURL() {
  return getToken(C2105133Parser::LCURL, 0);
}

tree::TerminalNode* C2105133Parser::Compound_statementContext::RCURL() {
  return getToken(C2105133Parser::RCURL, 0);
}

C2105133Parser::StatementsContext* C2105133Parser::Compound_statementContext::statements() {
  return getRuleContext<C2105133Parser::StatementsContext>(0);
}


size_t C2105133Parser::Compound_statementContext::getRuleIndex() const {
  return C2105133Parser::RuleCompound_statement;
}

void C2105133Parser::Compound_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_statement(this);
}

void C2105133Parser::Compound_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_statement(this);
}

C2105133Parser::Compound_statementContext* C2105133Parser::compound_statement(bool flagScope) {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState(), flagScope);
  enterRule(_localctx, 14, C2105133Parser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(166);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(156);
      match(C2105133Parser::LCURL);
      if (flagScope) Table.enterScope();
      setState(158);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->s = statements(0);
      setState(159);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken = match(C2105133Parser::RCURL);

              antlrcpp::downCast<Compound_statementContext *>(_localctx)->act_text =  "{\n" + antlrcpp::downCast<Compound_statementContext *>(_localctx)->s->act_text + "}\n" ;
              antlrcpp::downCast<Compound_statementContext *>(_localctx)->Line =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine();
              writeIntoparserLogFile(
                  "Line " + to_string(antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine()) +
                  ": compound_statement : LCURL statements RCURL\n\n" +
                  _localctx->act_text + "\n\n\n"
              );
              Table.printAllScopeTable(parserLogFile);
              if (flagScope) Table.exitScope();
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(162);
      match(C2105133Parser::LCURL);
      if (flagScope) Table.enterScope();
      setState(164);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken = match(C2105133Parser::RCURL);

              antlrcpp::downCast<Compound_statementContext *>(_localctx)->act_text =  _localctx->getText();
              antlrcpp::downCast<Compound_statementContext *>(_localctx)->Line =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine();
              writeIntoparserLogFile(
                  "Line " + to_string(antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine()) +
                  ": compound_statement : LCURL RCURL\n\n" +
                  _localctx->act_text + "\n\n\n"
              );
              Table.printAllScopeTable(parserLogFile);
              if (flagScope) Table.exitScope();
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declarationContext ------------------------------------------------------------------

C2105133Parser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105133Parser::Type_specifierContext* C2105133Parser::Var_declarationContext::type_specifier() {
  return getRuleContext<C2105133Parser::Type_specifierContext>(0);
}

C2105133Parser::Declaration_listContext* C2105133Parser::Var_declarationContext::declaration_list() {
  return getRuleContext<C2105133Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C2105133Parser::Var_declarationContext::SEMICOLON() {
  return getToken(C2105133Parser::SEMICOLON, 0);
}

C2105133Parser::Declaration_list_errContext* C2105133Parser::Var_declarationContext::declaration_list_err() {
  return getRuleContext<C2105133Parser::Declaration_list_errContext>(0);
}


size_t C2105133Parser::Var_declarationContext::getRuleIndex() const {
  return C2105133Parser::RuleVar_declaration;
}

void C2105133Parser::Var_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declaration(this);
}

void C2105133Parser::Var_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declaration(this);
}

C2105133Parser::Var_declarationContext* C2105133Parser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 16, C2105133Parser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(178);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(168);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(169);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl = declaration_list(0);
      setState(170);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C2105133Parser::SEMICOLON);

              antlrcpp::downCast<Var_declarationContext *>(_localctx)->act_text =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->act_text + " " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->act_text + ";\n" ;
              antlrcpp::downCast<Var_declarationContext *>(_localctx)->line =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine();
              writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON \n");
              if(antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->act_text == "void")
              {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": Variable type cannot be void " + "\n");
                  writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": Variable type cannot be void " + "\n"); 
                  
              }else
                  insertVarDeclarations(antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->act_text, antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->act_text,to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()));
              writeIntoparserLogFile(_localctx->act_text);
            
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(173);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(174);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->de = declaration_list_err();
      setState(175);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C2105133Parser::SEMICOLON);

              writeIntoErrorFile(
                  string("Line# ") + to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) +
                  " with error name: " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->de->error_name +
                  " - Syntax error at declaration list of variable declaration"
              );

              syntaxErrorCount++;
            
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_list_errContext ------------------------------------------------------------------

C2105133Parser::Declaration_list_errContext::Declaration_list_errContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C2105133Parser::Declaration_list_errContext::getRuleIndex() const {
  return C2105133Parser::RuleDeclaration_list_err;
}

void C2105133Parser::Declaration_list_errContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list_err(this);
}

void C2105133Parser::Declaration_list_errContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list_err(this);
}

C2105133Parser::Declaration_list_errContext* C2105133Parser::declaration_list_err() {
  Declaration_list_errContext *_localctx = _tracker.createInstance<Declaration_list_errContext>(_ctx, getState());
  enterRule(_localctx, 18, C2105133Parser::RuleDeclaration_list_err);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

            antlrcpp::downCast<Declaration_list_errContext *>(_localctx)->error_name =  "Error in declaration list";
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specifierContext ------------------------------------------------------------------

C2105133Parser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105133Parser::Type_specifierContext::INT() {
  return getToken(C2105133Parser::INT, 0);
}

tree::TerminalNode* C2105133Parser::Type_specifierContext::FLOAT() {
  return getToken(C2105133Parser::FLOAT, 0);
}

tree::TerminalNode* C2105133Parser::Type_specifierContext::VOID() {
  return getToken(C2105133Parser::VOID, 0);
}


size_t C2105133Parser::Type_specifierContext::getRuleIndex() const {
  return C2105133Parser::RuleType_specifier;
}

void C2105133Parser::Type_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_specifier(this);
}

void C2105133Parser::Type_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_specifier(this);
}

C2105133Parser::Type_specifierContext* C2105133Parser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 20, C2105133Parser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(188);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105133Parser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(182);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken = match(C2105133Parser::INT);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->act_text =  _localctx->getText();
                    writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getLine()) + ": type_specifier : INT \n\nint \n");
                
        break;
      }

      case C2105133Parser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(184);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken = match(C2105133Parser::FLOAT);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->act_text =  _localctx->getText();
                     writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getLine()) + ": type_specifier : FLOAT \n\nfloat \n");
                
        break;
      }

      case C2105133Parser::VOID: {
        enterOuterAlt(_localctx, 3);
        setState(186);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken = match(C2105133Parser::VOID);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->act_text =  _localctx->getText();
                    writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getLine()) + ": type_specifier : VOID \n\nvoid \n");
                
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_listContext ------------------------------------------------------------------

C2105133Parser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105133Parser::Declaration_listContext::ID() {
  return getToken(C2105133Parser::ID, 0);
}

tree::TerminalNode* C2105133Parser::Declaration_listContext::LTHIRD() {
  return getToken(C2105133Parser::LTHIRD, 0);
}

tree::TerminalNode* C2105133Parser::Declaration_listContext::CONST_INT() {
  return getToken(C2105133Parser::CONST_INT, 0);
}

tree::TerminalNode* C2105133Parser::Declaration_listContext::RTHIRD() {
  return getToken(C2105133Parser::RTHIRD, 0);
}

tree::TerminalNode* C2105133Parser::Declaration_listContext::COMMA() {
  return getToken(C2105133Parser::COMMA, 0);
}

C2105133Parser::Declaration_listContext* C2105133Parser::Declaration_listContext::declaration_list() {
  return getRuleContext<C2105133Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C2105133Parser::Declaration_listContext::ADDOP() {
  return getToken(C2105133Parser::ADDOP, 0);
}

tree::TerminalNode* C2105133Parser::Declaration_listContext::SUBOP() {
  return getToken(C2105133Parser::SUBOP, 0);
}

tree::TerminalNode* C2105133Parser::Declaration_listContext::MULOP() {
  return getToken(C2105133Parser::MULOP, 0);
}

tree::TerminalNode* C2105133Parser::Declaration_listContext::INCOP() {
  return getToken(C2105133Parser::INCOP, 0);
}

tree::TerminalNode* C2105133Parser::Declaration_listContext::DECOP() {
  return getToken(C2105133Parser::DECOP, 0);
}

tree::TerminalNode* C2105133Parser::Declaration_listContext::NOT() {
  return getToken(C2105133Parser::NOT, 0);
}

tree::TerminalNode* C2105133Parser::Declaration_listContext::RELOP() {
  return getToken(C2105133Parser::RELOP, 0);
}

tree::TerminalNode* C2105133Parser::Declaration_listContext::LOGICOP() {
  return getToken(C2105133Parser::LOGICOP, 0);
}

tree::TerminalNode* C2105133Parser::Declaration_listContext::ASSIGNOP() {
  return getToken(C2105133Parser::ASSIGNOP, 0);
}


size_t C2105133Parser::Declaration_listContext::getRuleIndex() const {
  return C2105133Parser::RuleDeclaration_list;
}

void C2105133Parser::Declaration_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list(this);
}

void C2105133Parser::Declaration_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list(this);
}


C2105133Parser::Declaration_listContext* C2105133Parser::declaration_list() {
   return declaration_list(0);
}

C2105133Parser::Declaration_listContext* C2105133Parser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105133Parser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  C2105133Parser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, C2105133Parser::RuleDeclaration_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(198);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(191);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105133Parser::ID);
       
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  _localctx->getText(); 
              if(Table.getCurrentScopeTable()->lookup(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText()))
              {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "\n");
                  writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "\n");
              }
              writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : ID \n\n" + _localctx->getText() + "\n");
      	
      break;
    }

    case 2: {
      setState(193);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105133Parser::ID);
      setState(194);
      match(C2105133Parser::LTHIRD);
      setState(195);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C2105133Parser::CONST_INT);
      setState(196);
      match(C2105133Parser::RTHIRD);
       
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  _localctx->getText();
              if(Table.getCurrentScopeTable()->lookup(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText()))
              {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "\n");
                  writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "\n");
              }
              writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD \n\n" + _localctx->getText() + "\n");
      	
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(243);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(241);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(200);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(201);
          match(C2105133Parser::COMMA);
          setState(202);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105133Parser::ID);
           
                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text + "," + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText()  ;
                            if(Table.getCurrentScopeTable()->lookup(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText()))
                            {
                                writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "\n");
                                writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "\n");
                            }
                            writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : declaration_list COMMA ID \n\n" + _localctx->act_text + "\n");
                    	
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(204);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(205);
          match(C2105133Parser::COMMA);
          setState(206);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105133Parser::ID);
          setState(207);
          match(C2105133Parser::LTHIRD);
          setState(208);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C2105133Parser::CONST_INT);
          setState(209);
          match(C2105133Parser::RTHIRD);
           
                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text + "," + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + "]" ;
                            if(Table.getCurrentScopeTable()->lookup(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText()))
                            {
                                writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "\n");
                                writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "\n");
                            } 
                            writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD \n\n" + _localctx->act_text + "\n");
                    	
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(211);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(212);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken = match(C2105133Parser::ADDOP);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(214);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(215);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105133Parser::ID);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": syntax error, unexpected ID, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": syntax error, unexpected ID, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(217);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(218);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->subopToken = match(C2105133Parser::SUBOP);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->subopToken->getLine()) + ": syntax error, unexpected SUBOP, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->subopToken->getLine()) + ": syntax error, unexpected SUBOP, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(220);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(221);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->mulopToken = match(C2105133Parser::MULOP);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->mulopToken->getLine()) + ": syntax error, unexpected MULOP, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->mulopToken->getLine()) + ": syntax error, unexpected MULOP, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(223);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(224);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->incopToken = match(C2105133Parser::INCOP);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->incopToken->getLine()) + ": syntax error, unexpected INCOP, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->incopToken->getLine()) + ": syntax error, unexpected INCOP, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(226);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(227);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->decopToken = match(C2105133Parser::DECOP);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->decopToken->getLine()) + ": syntax error, unexpected DECOP, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->decopToken->getLine()) + ": syntax error, unexpected DECOP, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(229);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(230);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->notToken = match(C2105133Parser::NOT);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->notToken->getLine()) + ": syntax error, unexpected NOT, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->notToken->getLine()) + ": syntax error, unexpected NOT, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(232);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(233);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->relopToken = match(C2105133Parser::RELOP);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->relopToken->getLine()) + ": syntax error, unexpected RELOP, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->relopToken->getLine()) + ": syntax error, unexpected RELOP, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(235);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(236);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->logicopToken = match(C2105133Parser::LOGICOP);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->logicopToken->getLine()) + ": syntax error, unexpected LOGICOP, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->logicopToken->getLine()) + ": syntax error, unexpected LOGICOP, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 12: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(238);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(239);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->assignopToken = match(C2105133Parser::ASSIGNOP);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->assignopToken->getLine()) + ": syntax error, unexpected ASSIGNOP, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->assignopToken->getLine()) + ": syntax error, unexpected ASSIGNOP, expecting COMMA or SEMICOLON");
                          
          break;
        }

        default:
          break;
        } 
      }
      setState(245);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

C2105133Parser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105133Parser::StatementContext* C2105133Parser::StatementsContext::statement() {
  return getRuleContext<C2105133Parser::StatementContext>(0);
}

C2105133Parser::StatementsContext* C2105133Parser::StatementsContext::statements() {
  return getRuleContext<C2105133Parser::StatementsContext>(0);
}


size_t C2105133Parser::StatementsContext::getRuleIndex() const {
  return C2105133Parser::RuleStatements;
}

void C2105133Parser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void C2105133Parser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}


C2105133Parser::StatementsContext* C2105133Parser::statements() {
   return statements(0);
}

C2105133Parser::StatementsContext* C2105133Parser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105133Parser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  C2105133Parser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, C2105133Parser::RuleStatements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(247);
    antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

            antlrcpp::downCast<StatementsContext *>(_localctx)->act_text =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->act_text;
            writeIntoparserLogFile("Line " + to_string((antlrcpp::downCast<StatementsContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementsContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statements : statement\n\n" + _localctx->act_text + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(256);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StatementsContext>(parentContext, parentState);
        _localctx->ss = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleStatements);
        setState(250);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(251);
        antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

                          antlrcpp::downCast<StatementsContext *>(_localctx)->act_text =  antlrcpp::downCast<StatementsContext *>(_localctx)->ss->act_text + antlrcpp::downCast<StatementsContext *>(_localctx)->s->act_text;
                          writeIntoparserLogFile("Line " + to_string((antlrcpp::downCast<StatementsContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementsContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statements : statements statement\n\n" + _localctx->act_text + "\n");
                       
      }
      setState(258);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

C2105133Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105133Parser::Var_declarationContext* C2105133Parser::StatementContext::var_declaration() {
  return getRuleContext<C2105133Parser::Var_declarationContext>(0);
}

std::vector<C2105133Parser::Expression_statementContext *> C2105133Parser::StatementContext::expression_statement() {
  return getRuleContexts<C2105133Parser::Expression_statementContext>();
}

C2105133Parser::Expression_statementContext* C2105133Parser::StatementContext::expression_statement(size_t i) {
  return getRuleContext<C2105133Parser::Expression_statementContext>(i);
}

C2105133Parser::Compound_statementContext* C2105133Parser::StatementContext::compound_statement() {
  return getRuleContext<C2105133Parser::Compound_statementContext>(0);
}

tree::TerminalNode* C2105133Parser::StatementContext::FOR() {
  return getToken(C2105133Parser::FOR, 0);
}

tree::TerminalNode* C2105133Parser::StatementContext::LPAREN() {
  return getToken(C2105133Parser::LPAREN, 0);
}

tree::TerminalNode* C2105133Parser::StatementContext::RPAREN() {
  return getToken(C2105133Parser::RPAREN, 0);
}

C2105133Parser::ExpressionContext* C2105133Parser::StatementContext::expression() {
  return getRuleContext<C2105133Parser::ExpressionContext>(0);
}

std::vector<C2105133Parser::StatementContext *> C2105133Parser::StatementContext::statement() {
  return getRuleContexts<C2105133Parser::StatementContext>();
}

C2105133Parser::StatementContext* C2105133Parser::StatementContext::statement(size_t i) {
  return getRuleContext<C2105133Parser::StatementContext>(i);
}

tree::TerminalNode* C2105133Parser::StatementContext::IF() {
  return getToken(C2105133Parser::IF, 0);
}

tree::TerminalNode* C2105133Parser::StatementContext::ELSE() {
  return getToken(C2105133Parser::ELSE, 0);
}

tree::TerminalNode* C2105133Parser::StatementContext::WHILE() {
  return getToken(C2105133Parser::WHILE, 0);
}

tree::TerminalNode* C2105133Parser::StatementContext::PRINTLN() {
  return getToken(C2105133Parser::PRINTLN, 0);
}

tree::TerminalNode* C2105133Parser::StatementContext::ID() {
  return getToken(C2105133Parser::ID, 0);
}

tree::TerminalNode* C2105133Parser::StatementContext::SEMICOLON() {
  return getToken(C2105133Parser::SEMICOLON, 0);
}

tree::TerminalNode* C2105133Parser::StatementContext::RETURN() {
  return getToken(C2105133Parser::RETURN, 0);
}


size_t C2105133Parser::StatementContext::getRuleIndex() const {
  return C2105133Parser::RuleStatement;
}

void C2105133Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void C2105133Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

C2105133Parser::StatementContext* C2105133Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 26, C2105133Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(319);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(259);
      antlrcpp::downCast<StatementContext *>(_localctx)->vd = var_declaration();

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  antlrcpp::downCast<StatementContext *>(_localctx)->vd->act_text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->vd->line;
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": statement : var_declaration\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(262);
      antlrcpp::downCast<StatementContext *>(_localctx)->es = expression_statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  antlrcpp::downCast<StatementContext *>(_localctx)->es->act_text +"\n";
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->es->line;
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": statement : expression_statement\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(265);
      antlrcpp::downCast<StatementContext *>(_localctx)->cs = compound_statement(true);

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  antlrcpp::downCast<StatementContext *>(_localctx)->cs->act_text;
              writeIntoparserLogFile("Line " + to_string((antlrcpp::downCast<StatementContext *>(_localctx)->cs != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->cs->stop) : nullptr)->getLine()) + ": statement : compound_statement\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(268);
      antlrcpp::downCast<StatementContext *>(_localctx)->forToken = match(C2105133Parser::FOR);
      setState(269);
      match(C2105133Parser::LPAREN);
      setState(270);
      antlrcpp::downCast<StatementContext *>(_localctx)->es1 = expression_statement();

              string looplabel = newlabel();
              looplabels.push(looplabel);
              asmFile <<looplabel<<":" <<"\t\t\t; Line "<< to_string(antlrcpp::downCast<StatementContext *>(_localctx)->forToken->getLine())<<endl;
          
      setState(272);
      antlrcpp::downCast<StatementContext *>(_localctx)->es2 = expression_statement();
       
              string inclabel = newlabel();
              string backlabel = newlabel();
              string exitlabel = newlabel();
              inclabels.push(inclabel);
              exitlabels.push(exitlabel);
              backlabels.push(backlabel);
              asmFile << "\tCMP AX, 1" <<"\t\t\t; Line "<< to_string(antlrcpp::downCast<StatementContext *>(_localctx)->forToken->getLine())<<endl;
              asmFile << "\tJE "<<inclabel<<endl;
              asmFile << "\tJMP "<<exitlabel<<endl;
              asmFile << backlabel << ":" <<endl;
              //backlabel;
              
          
      setState(274);
      antlrcpp::downCast<StatementContext *>(_localctx)->e1 = expression();

              asmFile <<"\tPOP AX"<<"\t\t\t; Line "<< to_string(antlrcpp::downCast<StatementContext *>(_localctx)->forToken->getLine())<<endl;
              asmFile << "\tJMP "<<looplabels.top() <<endl;//looplabel
              looplabels.pop();
              asmFile << inclabels.top() <<":"<<endl;
              inclabels.pop();
              //inclabel

          
      setState(276);
      match(C2105133Parser::RPAREN);
      setState(277);
      antlrcpp::downCast<StatementContext *>(_localctx)->s1 = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  "for(" + antlrcpp::downCast<StatementContext *>(_localctx)->es1->act_text + antlrcpp::downCast<StatementContext *>(_localctx)->es2->act_text + antlrcpp::downCast<StatementContext *>(_localctx)->e1->act_text + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->s1->act_text ;
              writeIntoparserLogFile("Line " + to_string((antlrcpp::downCast<StatementContext *>(_localctx)->s1 != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->s1->stop) : nullptr)->getLine()) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" + _localctx->act_text + "\n");
              asmFile << "\tJMP "<<backlabels.top() <<endl;
              //jmp backlabel
              backlabels.pop();
              asmFile <<exitlabels.top()<<":"<<endl;
              exitlabels.pop();

          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(280);
      antlrcpp::downCast<StatementContext *>(_localctx)->ifToken = match(C2105133Parser::IF);
      setState(281);
      match(C2105133Parser::LPAREN);
      setState(282);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();

              string elselabel = newlabel();
              elselabels.push(elselabel);
              asmFile<< "\tPOP AX"<<"\t\t\t; Line "<< to_string(antlrcpp::downCast<StatementContext *>(_localctx)->ifToken->getLine())<<endl;
              asmFile<< "\tCMP AX, 0"<<endl;
              asmFile<< "\tJE "<<elselabel<<endl;

          
      setState(284);
      match(C2105133Parser::RPAREN);
      setState(285);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  "if (" + antlrcpp::downCast<StatementContext *>(_localctx)->e->act_text + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->s->act_text ;
              writeIntoparserLogFile("Line " + to_string((antlrcpp::downCast<StatementContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statement : IF LPAREN expression RPAREN statement\n\n" + _localctx->act_text + "\n");
          
              asmFile<< elselabels.top()<< ":" <<endl;
              elselabels.pop();
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(288);
      antlrcpp::downCast<StatementContext *>(_localctx)->ifToken = match(C2105133Parser::IF);
      setState(289);
      match(C2105133Parser::LPAREN);
      setState(290);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();

              string elselabel = newlabel();
              elselabels.push(elselabel);
              asmFile<< "\tPOP AX"<<"\t\t\t; Line "<< to_string(antlrcpp::downCast<StatementContext *>(_localctx)->ifToken->getLine())<<endl;
              asmFile<< "\tCMP AX, 0"<<endl;
              asmFile<< "\tJE "<<elselabel<<endl; 

          
      setState(292);
      match(C2105133Parser::RPAREN);
      setState(293);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              string exitlabel = newlabel();
              exitlabels.push(exitlabel);
              asmFile<< "\tJMP "<<exitlabel<<endl;
              asmFile<< elselabels.top()<< ":" <<endl;
              elselabels.pop();

          
      setState(295);
      antlrcpp::downCast<StatementContext *>(_localctx)->elseToken = match(C2105133Parser::ELSE);
      setState(296);
      antlrcpp::downCast<StatementContext *>(_localctx)->s1 = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  "if (" + antlrcpp::downCast<StatementContext *>(_localctx)->e->act_text + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->s->act_text + "else\n" + antlrcpp::downCast<StatementContext *>(_localctx)->s1->act_text;
              writeIntoparserLogFile("Line " + to_string((antlrcpp::downCast<StatementContext *>(_localctx)->s1 != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->s1->stop) : nullptr)->getLine()) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" + _localctx->act_text + "\n");
          
              asmFile<<exitlabels.top() <<":"<<"\t\t\t; Line "<< to_string(antlrcpp::downCast<StatementContext *>(_localctx)->elseToken->getLine())<<endl;
              exitlabels.pop();
          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(299);
      antlrcpp::downCast<StatementContext *>(_localctx)->whileToken = match(C2105133Parser::WHILE);
      setState(300);
      match(C2105133Parser::LPAREN);

              string looplabel = newlabel();
              looplabels.push(looplabel);
              asmFile <<looplabel<<":"<<endl;
          
      setState(302);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
       
              string exitlabel = newlabel();
              exitlabels.push(exitlabel);
              asmFile << "\tPOP AX"<<"\t\t\t; Line "<< to_string(antlrcpp::downCast<StatementContext *>(_localctx)->whileToken->getLine())<<endl;
              asmFile << "\tCMP AX, 0" <<endl;
              asmFile << "\tJE "<<exitlabel<<endl;
          
      setState(304);
      match(C2105133Parser::RPAREN);
      setState(305);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  "while (" + antlrcpp::downCast<StatementContext *>(_localctx)->e->act_text + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->s->act_text;
              writeIntoparserLogFile("Line " + to_string((antlrcpp::downCast<StatementContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" + _localctx->act_text + "\n");
              asmFile <<"\tJMP "<<looplabels.top()<<endl;
              looplabels.pop();
              asmFile<<exitlabels.top()<<":"<<endl;
              exitlabels.pop();
          
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(308);
      antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken = match(C2105133Parser::PRINTLN);
      setState(309);
      match(C2105133Parser::LPAREN);
      setState(310);
      antlrcpp::downCast<StatementContext *>(_localctx)->idToken = match(C2105133Parser::ID);
      setState(311);
      match(C2105133Parser::RPAREN);
      setState(312);
      match(C2105133Parser::SEMICOLON);

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  _localctx->getText()+"\n";
              writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
              if(!Table.getCurrentScopeTable()->lookup(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText()))
              {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine()) + ": Undeclared variable " + antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() + "\n");
                  writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine()) + ": Undeclared variable " + antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() + "\n");
              }
              writeIntoparserLogFile(_localctx->act_text + "\n");
              SymbolInfo *item = Table.lookup(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText());
              if(item)
              {
                  if(item->getGlobal())
                      asmFile << "\tMOV AX, " << item->getName()<<"\t\t\t; Line "<< to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine()) <<endl;
                  else
                      asmFile << "\tMOV AX, [BP-" << item->getOffset() << "]" <<endl;

                  asmFile << "\tCALL print_output"<<"\t\t\t; Line "<< to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine()) <<endl;
                  asmFile<< "\tCALL new_line"<<endl;
              }
          
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(314);
      antlrcpp::downCast<StatementContext *>(_localctx)->returnToken = match(C2105133Parser::RETURN);
      setState(315);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(316);
      antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken = match(C2105133Parser::SEMICOLON);

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  "return " + antlrcpp::downCast<StatementContext *>(_localctx)->e->act_text + ";\n";
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken->getLine();
              writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getLine()) + ": statement : RETURN expression SEMICOLON\n\n" + _localctx->act_text + "\n");
              
              if(returnlabels.empty())
              {    
                  string returnlabel = newlabel();
                  returnlabels.push(returnlabel);
              }
              asmFile <<"\tPOP AX"<<"\t\t\t; Line "<< to_string(antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getLine())<<endl;    
              asmFile <<"\tJMP "<<returnlabels.top()<<endl; 
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_statementContext ------------------------------------------------------------------

C2105133Parser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105133Parser::Expression_statementContext::SEMICOLON() {
  return getToken(C2105133Parser::SEMICOLON, 0);
}

C2105133Parser::ExpressionContext* C2105133Parser::Expression_statementContext::expression() {
  return getRuleContext<C2105133Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105133Parser::Expression_statementContext::ANY() {
  return getToken(C2105133Parser::ANY, 0);
}


size_t C2105133Parser::Expression_statementContext::getRuleIndex() const {
  return C2105133Parser::RuleExpression_statement;
}

void C2105133Parser::Expression_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_statement(this);
}

void C2105133Parser::Expression_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_statement(this);
}

C2105133Parser::Expression_statementContext* C2105133Parser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 28, C2105133Parser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(331);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(321);
      antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken = match(C2105133Parser::SEMICOLON);

              antlrcpp::downCast<Expression_statementContext *>(_localctx)->act_text =  _localctx->getText();
              antlrcpp::downCast<Expression_statementContext *>(_localctx)->line =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine();
              writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine()) + ": expression_statement : SEMICOLON\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(323);
      expression();
      setState(324);
      antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken = match(C2105133Parser::SEMICOLON);

              antlrcpp::downCast<Expression_statementContext *>(_localctx)->act_text =  _localctx->getText();
              antlrcpp::downCast<Expression_statementContext *>(_localctx)->line =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine();
              writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine()) + ": expression_statement : expression SEMICOLON\n\n" + _localctx->act_text + "\n");
              asmFile << "\tPOP AX" <<"\t\t\t; Line "<< to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine())<<endl;
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(327);
      expression();
      setState(328);
      antlrcpp::downCast<Expression_statementContext *>(_localctx)->a = match(C2105133Parser::ANY);

              writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->a->getLine()) + ": syntax error, expected SEMICOLON\n");
              writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->a->getLine()) + ": syntax error, expected SEMICOLON\n");
               
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

C2105133Parser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105133Parser::VariableContext::ID() {
  return getToken(C2105133Parser::ID, 0);
}

tree::TerminalNode* C2105133Parser::VariableContext::LTHIRD() {
  return getToken(C2105133Parser::LTHIRD, 0);
}

tree::TerminalNode* C2105133Parser::VariableContext::RTHIRD() {
  return getToken(C2105133Parser::RTHIRD, 0);
}

C2105133Parser::ExpressionContext* C2105133Parser::VariableContext::expression() {
  return getRuleContext<C2105133Parser::ExpressionContext>(0);
}


size_t C2105133Parser::VariableContext::getRuleIndex() const {
  return C2105133Parser::RuleVariable;
}

void C2105133Parser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void C2105133Parser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

C2105133Parser::VariableContext* C2105133Parser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 30, C2105133Parser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(341);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(333);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C2105133Parser::ID);

              antlrcpp::downCast<VariableContext *>(_localctx)->act_text =  _localctx->getText();
              SymbolInfo* item = Table.lookup(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": variable : ID\n");
              if (item)
              {
                  antlrcpp::downCast<VariableContext *>(_localctx)->type =  item->getType();
                  int isArray = _localctx->type.find(' ');
                  if(isArray != string::npos)
                  {
                      writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Type mismatch, " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + " is an array\n");
                      writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Type mismatch, " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + " is an array\n");
                  } 
              }
              else{
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Undeclared variable " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + "\n");
                  writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Undeclared variable " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + "\n");
              }
              writeIntoparserLogFile(_localctx->act_text + "\n");
              //writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": variable : ID\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(335);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C2105133Parser::ID);
      setState(336);
      match(C2105133Parser::LTHIRD);
      setState(337);
      antlrcpp::downCast<VariableContext *>(_localctx)->e = expression();
      setState(338);
      match(C2105133Parser::RTHIRD);

              //antlrcpp::downCast<VariableContext *>(_localctx)->act_text =  _localctx->getText();
              antlrcpp::downCast<VariableContext *>(_localctx)->act_text = antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText();
              SymbolInfo* item = Table.getCurrentScopeTable()->lookup(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n");
              if (item)
              {
                  antlrcpp::downCast<VariableContext *>(_localctx)->type =  item->getType();
                  int pos = _localctx->type.find(' ');
                  if(pos == string::npos)
                  {
                      writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + " not an array\n");
                      writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + " not an array\n");
                  }
                  antlrcpp::downCast<VariableContext *>(_localctx)->type =  _localctx->type.substr(0, pos);
              }
              string exp = antlrcpp::downCast<VariableContext *>(_localctx)->e->act_text;
              int isInt = exp.find('.');
              if(isInt != string::npos)
              {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Expression inside third brackets not an integer\n");
                  //writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n");
                  writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Expression inside third brackets not an integer\n");
                  //writeIntoparserLogFile(_localctx->act_text + "\n");
              }//else
                  //writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n\n" + _localctx->act_text + "\n");
              writeIntoparserLogFile(_localctx->act_text + "\n");
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

C2105133Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105133Parser::Logic_expressionContext* C2105133Parser::ExpressionContext::logic_expression() {
  return getRuleContext<C2105133Parser::Logic_expressionContext>(0);
}

tree::TerminalNode* C2105133Parser::ExpressionContext::ASSIGNOP() {
  return getToken(C2105133Parser::ASSIGNOP, 0);
}

C2105133Parser::VariableContext* C2105133Parser::ExpressionContext::variable() {
  return getRuleContext<C2105133Parser::VariableContext>(0);
}


size_t C2105133Parser::ExpressionContext::getRuleIndex() const {
  return C2105133Parser::RuleExpression;
}

void C2105133Parser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void C2105133Parser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

C2105133Parser::ExpressionContext* C2105133Parser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 32, C2105133Parser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(351);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(343);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->l = logic_expression();


              antlrcpp::downCast<ExpressionContext *>(_localctx)->act_text =  _localctx->getText();
              antlrcpp::downCast<ExpressionContext *>(_localctx)->type =  antlrcpp::downCast<ExpressionContext *>(_localctx)->l->type ;
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": expression : logic expression\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(346);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->v = variable();
      setState(347);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken = match(C2105133Parser::ASSIGNOP);
      setState(348);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->l = logic_expression();

              antlrcpp::downCast<ExpressionContext *>(_localctx)->act_text =  _localctx->getText();
              antlrcpp::downCast<ExpressionContext *>(_localctx)->type =  antlrcpp::downCast<ExpressionContext *>(_localctx)->v->type ;
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": expression : variable ASSIGNOP logic_expression\n");
              if(antlrcpp::downCast<ExpressionContext *>(_localctx)->l->type == "void")
              {
                  writeIntoErrorFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Void function used in expression\n");
                  writeIntoparserLogFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Void function used in expression\n");
              }
              else if(antlrcpp::downCast<ExpressionContext *>(_localctx)->v->type!= "" && antlrcpp::downCast<ExpressionContext *>(_localctx)->v->type != antlrcpp::downCast<ExpressionContext *>(_localctx)->l->type && antlrcpp::downCast<ExpressionContext *>(_localctx)->v->type == "int")
              {
                  writeIntoErrorFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Type Mismatch\n");
                  
                  writeIntoparserLogFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Type Mismatch\n");
                  
              }//else
                  //writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": expression : variable ASSIGNOP logic_expression\n\n" + _localctx->act_text + "\n");
                  writeIntoparserLogFile(_localctx->act_text + "\n");


              SymbolInfo* itemglobal = Table.lookup(antlrcpp::downCast<ExpressionContext *>(_localctx)->v->act_text);
              SymbolInfo* item = Table.getCurrentScopeTable()->lookup(antlrcpp::downCast<ExpressionContext *>(_localctx)->v->act_text);

              SymbolInfo* sym = item ? item : itemglobal;

              if(sym){
                  bool isLocal = (sym == item);
                  bool isGlobal = sym->getGlobal();
                  bool isArray = sym->getarray();
                  int offset = sym->getOffset();

                  if (isArray && isGlobal){
                      asmFile << "\tPOP AX" <<"\t\t\t; Line "<< to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken->getLine())<<endl;
                      asmFile << "\tPOP BX" << endl;
                      asmFile << "\tPUSH AX" << endl;
                      asmFile << "\tMOV AX, 2" << endl;
                      asmFile << "\tMUL BX" << endl;
                      asmFile << "\tMOV BX, AX" <<endl;
                      asmFile << "\tPOP AX" <<endl;
                      asmFile << "\tMOV " << antlrcpp::downCast<ExpressionContext *>(_localctx)->v->act_text << "[BX], AX" << endl;
                      asmFile << "\tPUSH AX" <<endl;
                  }else if(isArray)
                  {
                      asmFile << "\tPOP AX"<<"\t\t\t; Line "<< to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken->getLine()) << endl;
                      asmFile << "\tPOP BX" << endl;
                      asmFile << "\tPUSH AX" << endl;
                      asmFile << "\tMOV AX, 2" << endl;
                      asmFile << "\tMUL BX" << endl;
                      asmFile << "\tMOV BX, AX" <<endl;
                      asmFile << "\tMOV AX, "<< sym->getarraylen()*2+sym->getOffset()-4 <<endl;
                      asmFile << "\tSUB AX, BX"<<endl;
                      asmFile << "\tMOV BX, AX"<<endl;
                      asmFile << "\tPOP AX" <<endl;
                      asmFile << "\tMOV SI, BX "<<endl;
                      asmFile << "\tNEG SI" <<endl;
                      asmFile << "\tMOV [BP+SI], AX" << endl;
                      asmFile << "\tPUSH AX" <<endl;
                  }
                  else {
                      asmFile << "\tPOP AX" <<"\t\t\t; Line "<< to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken->getLine())<< endl;

                      if (isGlobal) {
                          asmFile << "\tMOV " << antlrcpp::downCast<ExpressionContext *>(_localctx)->v->act_text << ", AX" << endl;
                      } else {
                          string sign = offset < 0 ? "+" : "-";
                          int absOffset = abs(offset);
                          asmFile << "\tMOV [BP" << sign << absOffset << "], AX" << endl;
                      }

                      asmFile << "\tPUSH AX" << endl;
                  }
              }
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_expressionContext ------------------------------------------------------------------

C2105133Parser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C2105133Parser::Rel_expressionContext *> C2105133Parser::Logic_expressionContext::rel_expression() {
  return getRuleContexts<C2105133Parser::Rel_expressionContext>();
}

C2105133Parser::Rel_expressionContext* C2105133Parser::Logic_expressionContext::rel_expression(size_t i) {
  return getRuleContext<C2105133Parser::Rel_expressionContext>(i);
}

tree::TerminalNode* C2105133Parser::Logic_expressionContext::LOGICOP() {
  return getToken(C2105133Parser::LOGICOP, 0);
}


size_t C2105133Parser::Logic_expressionContext::getRuleIndex() const {
  return C2105133Parser::RuleLogic_expression;
}

void C2105133Parser::Logic_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_expression(this);
}

void C2105133Parser::Logic_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_expression(this);
}

C2105133Parser::Logic_expressionContext* C2105133Parser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 34, C2105133Parser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(361);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(353);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r = rel_expression();

              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->act_text =  _localctx->getText();
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->type ;
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": logic_expression : rel_expression\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(356);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r = rel_expression();
      setState(357);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken = match(C2105133Parser::LOGICOP);
      setState(358);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1 = rel_expression();

              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->act_text =  _localctx->getText();
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->type =  "int" ;
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": logic_expression : rel_expression LOGICOP rel_expression\n\n" + _localctx->act_text + "\n");
          

              asmFile <<"\tPOP BX "<<"\t\t\t; Line "<< to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getLine())<<endl;
              asmFile << "\tPOP AX " <<endl;

              string trueLabel = newlabel();
              string falseLabel = newlabel();

              if(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText() == "||")
              {
                  asmFile<<"\tOR BX, AX"<<endl;
                  asmFile<<"\tCMP BX, 0"<<endl;
                  asmFile<<"\tJNE "<<trueLabel<<endl;

                  asmFile << "\tPUSH 0" <<endl;
                  asmFile << "\tJMP " << falseLabel <<endl;
                  asmFile << trueLabel << ":" <<endl;
                  asmFile << "\tPUSH 1" <<endl;
                  asmFile << falseLabel <<":"<<endl<<endl;
              }else if(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText() == "&&")
              {
                  asmFile<<"\tCMP BX, 0"<<endl;
                  asmFile<<"\tJE "<<trueLabel<<endl;
                  asmFile<<"\tCMP AX, 0"<<endl;
                  asmFile<<"\tJE "<<trueLabel<<endl;

                  asmFile << "\tPUSH 1" <<endl;
                  asmFile << "\tJMP " << falseLabel <<endl;
                  asmFile << trueLabel << ":" <<endl;
                  asmFile << "\tPUSH 0" <<endl;
                  asmFile << falseLabel <<":"<<endl<<endl;
              }
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_expressionContext ------------------------------------------------------------------

C2105133Parser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C2105133Parser::Simple_expressionContext *> C2105133Parser::Rel_expressionContext::simple_expression() {
  return getRuleContexts<C2105133Parser::Simple_expressionContext>();
}

C2105133Parser::Simple_expressionContext* C2105133Parser::Rel_expressionContext::simple_expression(size_t i) {
  return getRuleContext<C2105133Parser::Simple_expressionContext>(i);
}

tree::TerminalNode* C2105133Parser::Rel_expressionContext::RELOP() {
  return getToken(C2105133Parser::RELOP, 0);
}


size_t C2105133Parser::Rel_expressionContext::getRuleIndex() const {
  return C2105133Parser::RuleRel_expression;
}

void C2105133Parser::Rel_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_expression(this);
}

void C2105133Parser::Rel_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_expression(this);
}

C2105133Parser::Rel_expressionContext* C2105133Parser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 36, C2105133Parser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(371);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(363);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s = simple_expression(0);

              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->act_text =  _localctx->getText();
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->type ;
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": rel_expression : simple_expression\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(366);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s = simple_expression(0);
      setState(367);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken = match(C2105133Parser::RELOP);
      setState(368);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s1 = simple_expression(0);

              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->act_text =  _localctx->getText();
              string relop = antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText();
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->type =  "int" ;
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": rel_expression : simple_expression RELOP simple_expression\n\n" + _localctx->act_text + "\n");

              
              asmFile <<"\tPOP BX "<<"\t\t\t; Line "<< to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getLine())<<endl;
              asmFile << "\tPOP AX " <<endl;
              asmFile <<"\tCMP AX, BX" <<endl;

              string trueLabel = newlabel();
              string falseLabel = newlabel();

              if(relop == "<=")
              {
                  asmFile<<"\tJLE "<<trueLabel<<endl;
              }else if(relop == ">=")
              {
                  asmFile<<"\tJGE "<<trueLabel<<endl;
              }else if(relop == "<")
              {
                  asmFile<<"\tJL "<<trueLabel<<endl;
              }else if(relop == ">")
              {
                  asmFile<<"\tJG "<<trueLabel<<endl;
              }else if(relop == "==")
              {
                  asmFile<<"\tJE "<<trueLabel<<endl;
              }else if(relop == "!=")
              {
                  asmFile<<"\tJNE "<<trueLabel<<endl;
              }

              asmFile << "\tPUSH 0" <<endl;
              asmFile << "\tJMP " << falseLabel <<endl;
              asmFile << trueLabel << ":" <<endl;
              asmFile << "\tPUSH 1" <<endl;
              asmFile << falseLabel <<":"<<endl<<endl;
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

C2105133Parser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105133Parser::TermContext* C2105133Parser::Simple_expressionContext::term() {
  return getRuleContext<C2105133Parser::TermContext>(0);
}

tree::TerminalNode* C2105133Parser::Simple_expressionContext::ADDOP() {
  return getToken(C2105133Parser::ADDOP, 0);
}

C2105133Parser::Simple_expressionContext* C2105133Parser::Simple_expressionContext::simple_expression() {
  return getRuleContext<C2105133Parser::Simple_expressionContext>(0);
}

tree::TerminalNode* C2105133Parser::Simple_expressionContext::ASSIGNOP() {
  return getToken(C2105133Parser::ASSIGNOP, 0);
}


size_t C2105133Parser::Simple_expressionContext::getRuleIndex() const {
  return C2105133Parser::RuleSimple_expression;
}

void C2105133Parser::Simple_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression(this);
}

void C2105133Parser::Simple_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression(this);
}


C2105133Parser::Simple_expressionContext* C2105133Parser::simple_expression() {
   return simple_expression(0);
}

C2105133Parser::Simple_expressionContext* C2105133Parser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105133Parser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  C2105133Parser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, C2105133Parser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(374);
    antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->act_text =  _localctx->getText();
            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->type ;
            writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": simple_expression : term\n\n" + _localctx->act_text + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(390);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(388);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
          _localctx->s = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
          setState(377);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(378);
          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken = match(C2105133Parser::ADDOP);
          setState(379);
          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->act_text =  _localctx->getText();
                            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->type ;
                            if(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->type == "float" || antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->type == "float")
                                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  "float";
                            writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": simple_expression : simple_expression ADDOP term\n\n" + _localctx->act_text + "\n");
                            asmFile << "\tPOP BX"<<"\t\t\t; Line "<< to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine())<<endl;
                            asmFile << "\tPOP AX"<<endl;
                            if(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText()=="-")
                                asmFile << "\tSUB AX, BX"<<endl;
                            else
                                asmFile << "\tADD AX, BX"<<endl;
                            asmFile << "\tPUSH AX"<<endl;
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
          _localctx->s = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
          setState(382);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(383);
          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken = match(C2105133Parser::ADDOP);
          setState(384);
          match(C2105133Parser::ASSIGNOP);
          setState(385);
          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                            writeIntoErrorFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": syntax error, unexpected ASSIGNOP\n");
                            writeIntoparserLogFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": syntax error, unexpected ASSIGNOP\n");
                        
          break;
        }

        default:
          break;
        } 
      }
      setState(392);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

C2105133Parser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105133Parser::Unary_expressionContext* C2105133Parser::TermContext::unary_expression() {
  return getRuleContext<C2105133Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C2105133Parser::TermContext::MULOP() {
  return getToken(C2105133Parser::MULOP, 0);
}

C2105133Parser::TermContext* C2105133Parser::TermContext::term() {
  return getRuleContext<C2105133Parser::TermContext>(0);
}


size_t C2105133Parser::TermContext::getRuleIndex() const {
  return C2105133Parser::RuleTerm;
}

void C2105133Parser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void C2105133Parser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


C2105133Parser::TermContext* C2105133Parser::term() {
   return term(0);
}

C2105133Parser::TermContext* C2105133Parser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105133Parser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  C2105133Parser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, C2105133Parser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(394);
    antlrcpp::downCast<TermContext *>(_localctx)->u = unary_expression();
     antlrcpp::downCast<TermContext *>(_localctx)->act_text =  _localctx->getText() ; antlrcpp::downCast<TermContext *>(_localctx)->type =  antlrcpp::downCast<TermContext *>(_localctx)->u->type ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": term : unary_expression \n\n" + _localctx->getText() + "\n");
    		
    _ctx->stop = _input->LT(-1);
    setState(404);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        _localctx->t = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(397);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(398);
        antlrcpp::downCast<TermContext *>(_localctx)->mulopToken = match(C2105133Parser::MULOP);
        setState(399);
        antlrcpp::downCast<TermContext *>(_localctx)->u = unary_expression();
         
                          antlrcpp::downCast<TermContext *>(_localctx)->act_text =  _localctx->getText() ;
                          antlrcpp::downCast<TermContext *>(_localctx)->type =  antlrcpp::downCast<TermContext *>(_localctx)->u->type ;
                          if(antlrcpp::downCast<TermContext *>(_localctx)->u->type == "float" || antlrcpp::downCast<TermContext *>(_localctx)->t->type == "float")
                              antlrcpp::downCast<TermContext *>(_localctx)->type =  "float";
                          writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": term : term MULOP unary_expression \n");
                          if(antlrcpp::downCast<TermContext *>(_localctx)->u->type == "void")
                          {
                              writeIntoErrorFile( "Error at line " + to_string(_localctx->getStart()->getLine()) + ": Void function used in expression\n");
                              writeIntoparserLogFile( "Error at line " + to_string(_localctx->getStart()->getLine()) + ": Void function used in expression\n");
                          }
                          if(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText()=="%" && (antlrcpp::downCast<TermContext *>(_localctx)->t->act_text == "0" || antlrcpp::downCast<TermContext *>(_localctx)->u->act_text == "0"))
                          {
                              writeIntoErrorFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Modulus by Zero\n");
                              writeIntoparserLogFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Modulus by Zero\n");
                          }
                          else if (antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText()=="%" && (antlrcpp::downCast<TermContext *>(_localctx)->t->type != "int" || antlrcpp::downCast<TermContext *>(_localctx)->u->type != "int"))
                          {
                              writeIntoErrorFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Non-Integer operand on modulus operator\n");
                              
                              writeIntoparserLogFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Non-Integer operand on modulus operator\n"); 
                              
                          }//else
                              //writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": term : term MULOP unary_expression \n\n" + _localctx->getText() + "\n");
                          writeIntoparserLogFile(_localctx->getText() + "\n");

                          
                          asmFile << "\tPOP BX"<<"\t\t\t; Line "<< to_string(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getLine())<<endl;
                          asmFile << "\tPOP AX"<<endl;
                          if(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText()=="*")
                          {
                              asmFile << "\tMUL BX"<<endl;
                              asmFile << "\tPUSH AX"<<endl;
                          }else if(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText()=="/")
                          {
                              asmFile << "\tMOV DX, 0000H"<<endl;
                              asmFile << "\tDIV BX"<<endl;
                              asmFile << "\tPUSH AX"<<endl;
                          }else if(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText()=="%")
                          {
                              asmFile << "\tMOV DX, 0000H"<<endl;
                              asmFile << "\tDIV BX"<<endl;
                              asmFile << "\tPUSH DX"<<endl;
                          }
                  	 
      }
      setState(406);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

C2105133Parser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105133Parser::Unary_expressionContext::ADDOP() {
  return getToken(C2105133Parser::ADDOP, 0);
}

C2105133Parser::Unary_expressionContext* C2105133Parser::Unary_expressionContext::unary_expression() {
  return getRuleContext<C2105133Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C2105133Parser::Unary_expressionContext::NOT() {
  return getToken(C2105133Parser::NOT, 0);
}

C2105133Parser::FactorContext* C2105133Parser::Unary_expressionContext::factor() {
  return getRuleContext<C2105133Parser::FactorContext>(0);
}


size_t C2105133Parser::Unary_expressionContext::getRuleIndex() const {
  return C2105133Parser::RuleUnary_expression;
}

void C2105133Parser::Unary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expression(this);
}

void C2105133Parser::Unary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expression(this);
}

C2105133Parser::Unary_expressionContext* C2105133Parser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 42, C2105133Parser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(418);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105133Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(407);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken = match(C2105133Parser::ADDOP);
        setState(408);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->u = unary_expression();
         
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->act_text =  _localctx->getText() ; antlrcpp::downCast<Unary_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->u->type ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": unary_expression : ADDOP unary_expression \n\n" + _localctx->getText() + "\n");
                if(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getText()=="-")
                {
                    asmFile << "\tPOP AX"<<"\t\t\t; Line "<< to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getLine())<<endl;
                    asmFile << "\tNEG AX"<<endl;
                    asmFile << "\tPUSH AX"<<endl;
                }
        	
        break;
      }

      case C2105133Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(411);
        match(C2105133Parser::NOT);
        setState(412);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->u = unary_expression();
         antlrcpp::downCast<Unary_expressionContext *>(_localctx)->act_text =  _localctx->getText() ; antlrcpp::downCast<Unary_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->u->type ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": unary_expression : NOT unary expression \n\n" + _localctx->getText() + "\n");
        		
        break;
      }

      case C2105133Parser::LPAREN:
      case C2105133Parser::ID:
      case C2105133Parser::CONST_INT:
      case C2105133Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(415);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f = factor();
         antlrcpp::downCast<Unary_expressionContext *>(_localctx)->act_text =  _localctx->getText() ; antlrcpp::downCast<Unary_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->type ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": unary_expression : factor \n\n" + _localctx->getText() + "\n");
        		
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

C2105133Parser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105133Parser::VariableContext* C2105133Parser::FactorContext::variable() {
  return getRuleContext<C2105133Parser::VariableContext>(0);
}

tree::TerminalNode* C2105133Parser::FactorContext::ID() {
  return getToken(C2105133Parser::ID, 0);
}

tree::TerminalNode* C2105133Parser::FactorContext::LPAREN() {
  return getToken(C2105133Parser::LPAREN, 0);
}

tree::TerminalNode* C2105133Parser::FactorContext::RPAREN() {
  return getToken(C2105133Parser::RPAREN, 0);
}

C2105133Parser::Argument_listContext* C2105133Parser::FactorContext::argument_list() {
  return getRuleContext<C2105133Parser::Argument_listContext>(0);
}

C2105133Parser::ExpressionContext* C2105133Parser::FactorContext::expression() {
  return getRuleContext<C2105133Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105133Parser::FactorContext::CONST_INT() {
  return getToken(C2105133Parser::CONST_INT, 0);
}

tree::TerminalNode* C2105133Parser::FactorContext::CONST_FLOAT() {
  return getToken(C2105133Parser::CONST_FLOAT, 0);
}

tree::TerminalNode* C2105133Parser::FactorContext::INCOP() {
  return getToken(C2105133Parser::INCOP, 0);
}

tree::TerminalNode* C2105133Parser::FactorContext::DECOP() {
  return getToken(C2105133Parser::DECOP, 0);
}


size_t C2105133Parser::FactorContext::getRuleIndex() const {
  return C2105133Parser::RuleFactor;
}

void C2105133Parser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void C2105133Parser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}

C2105133Parser::FactorContext* C2105133Parser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 44, C2105133Parser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(446);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(420);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
       
              antlrcpp::downCast<FactorContext *>(_localctx)->act_text =  _localctx->getText() ;
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->v->type;
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : variable \n\n" + _localctx->getText() + "\n");     
              
              SymbolInfo* itemglobal = Table.lookup(antlrcpp::downCast<FactorContext *>(_localctx)->v->act_text);
              SymbolInfo* item = Table.getCurrentScopeTable()->lookup(antlrcpp::downCast<FactorContext *>(_localctx)->v->act_text);

              SymbolInfo* sym = item ? item : itemglobal;

              if(sym){
                  bool isLocal = (sym == item);
                  bool isGlobal = sym->getGlobal();
                  bool isArray = sym->getarray();
                  int offset = sym->getOffset();

                  if (isArray && isGlobal){
                      asmFile << "\tPOP BX"<<"\t\t\t; Line "<< to_string(_localctx->getStart()->getLine()) << endl;
                      asmFile << "\tSHL BX, 1 "<<endl;
                      asmFile << "\tMOV AX, " << antlrcpp::downCast<FactorContext *>(_localctx)->v->act_text << "[BX]" << endl;
                      asmFile << "\tPUSH AX "<<endl;           
                  }else if(isArray)
                  {
                      asmFile << "\tPOP BX" <<"\t\t\t; Line "<< to_string(_localctx->getStart()->getLine()) << endl;
                      asmFile << "\tSHL BX, 1"<< endl;
                      asmFile << "\tMOV AX, "<< sym->getarraylen()*2+sym->getOffset()-4 <<endl;
                      asmFile << "\tSUB AX, BX"<<endl;
                      asmFile << "\tMOV BX, AX"<<endl;
                      asmFile << "\tMOV SI, BX "<<endl;
                      asmFile << "\tNEG SI" <<endl;
                      asmFile << "\tMOV AX, [BP+SI]" << endl;
                      asmFile << "\tPUSH AX" <<endl;
                  }
                  else {
                      
                      if (isGlobal) {
                          asmFile << "\tPUSH " << sym->getName() <<"\t\t\t; Line "<< to_string(_localctx->getStart()->getLine()) << endl;
                      } else {
                          string sign = offset < 0 ? "+" : "-";
                          int absOffset = abs(offset);
                          asmFile << "\tPUSH [BP" << sign << absOffset << "]" <<"\t\t; Line "<< to_string(_localctx->getStart()->getLine()) << endl;
                      }

                  }
              }
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(423);
      antlrcpp::downCast<FactorContext *>(_localctx)->idToken = match(C2105133Parser::ID);
      setState(424);
      match(C2105133Parser::LPAREN);
      setState(425);
      antlrcpp::downCast<FactorContext *>(_localctx)->a = argument_list();
      setState(426);
      match(C2105133Parser::RPAREN);
       
              antlrcpp::downCast<FactorContext *>(_localctx)->act_text =  _localctx->getText() ;
              SymbolInfo * item = Table.lookup(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText());
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : ID LPAREN argument_list RPAREN \n");
              if (item)
              {
                  antlrcpp::downCast<FactorContext *>(_localctx)->type =  item->getReturnType();
                  if(antlrcpp::downCast<FactorContext *>(_localctx)->a->types.size() != item->getParamTypes().size())
                  {
                      writeIntoErrorFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Total number of arguments mismatch in function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");
                      writeIntoparserLogFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Total number of arguments mismatch in function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");
                  }
                  else if(antlrcpp::downCast<FactorContext *>(_localctx)->a->types != item->getParamTypes())
                  {
                      writeIntoErrorFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": 1th argument mismatch in function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");
                      writeIntoparserLogFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": 1th argument mismatch in function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");
                  }
              }else
              {
                  writeIntoErrorFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Undeclared function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");
                  writeIntoparserLogFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": Undeclared function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");
              }
              writeIntoparserLogFile(_localctx->getText() + "\n");
              asmFile << "\tCALL "<< antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText()<<"\t\t; Line "<< to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine())  <<endl;
              asmFile << "\tPUSH AX"<<endl;
      	
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(429);
      match(C2105133Parser::LPAREN);
      setState(430);
      antlrcpp::downCast<FactorContext *>(_localctx)->e = expression();
      setState(431);
      match(C2105133Parser::RPAREN);
       antlrcpp::downCast<FactorContext *>(_localctx)->act_text =  _localctx->getText() ; antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->e->type; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : LPAREN expression RPAREN \n\n" + _localctx->getText() + "\n");
      	
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(434);
      match(C2105133Parser::CONST_INT);
       antlrcpp::downCast<FactorContext *>(_localctx)->act_text =  _localctx->getText() ; antlrcpp::downCast<FactorContext *>(_localctx)->type =  "int" ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : CONST_INT \n\n" + _localctx->getText() + "\n");
                          asmFile<<"\tPUSH " << _localctx->getText() <<"\t\t\t; Line "<< to_string(_localctx->getStart()->getLine())<<endl;
          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(436);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken = match(C2105133Parser::CONST_FLOAT);
       antlrcpp::downCast<FactorContext *>(_localctx)->act_text =  _localctx->getText() ; antlrcpp::downCast<FactorContext *>(_localctx)->type =  "float" ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : CONST_FLOAT  \n\n" + antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getText() + "\n");
      	
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(438);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(439);
      antlrcpp::downCast<FactorContext *>(_localctx)->incopToken = match(C2105133Parser::INCOP);

              antlrcpp::downCast<FactorContext *>(_localctx)->act_text =  _localctx->getText() ; antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->v->type ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : variable INCOP \n\n" + _localctx->getText() + "\n");
              
              SymbolInfo* itemglobal = Table.lookup(antlrcpp::downCast<FactorContext *>(_localctx)->v->act_text);
              SymbolInfo* item = Table.getCurrentScopeTable()->lookup(antlrcpp::downCast<FactorContext *>(_localctx)->v->act_text);

              SymbolInfo* sym = item ? item : itemglobal;

              if(sym){
                  bool isLocal = (sym == item);
                  bool isGlobal = sym->getGlobal();
                  bool isArray = sym->getarray();
                  int offset = sym->getOffset();

                  if (isArray && isGlobal){
                      asmFile << "\tPOP BX" <<"\t\t\t; Line "<< to_string(antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getLine())<< endl;
                      asmFile << "\tSHL BX, 1 "<<endl;
                      asmFile << "\tMOV AX, " << antlrcpp::downCast<FactorContext *>(_localctx)->v->act_text << "[BX]" << endl;
                      asmFile << "\tPUSH AX "<<endl;
                      asmFile << "\tINC AX " <<endl;
                      asmFile << "\tMOV "<< antlrcpp::downCast<FactorContext *>(_localctx)->v->act_text << "[BX], AX" << endl;
                  }else if(isArray)
                  {
                      asmFile << "\tPOP BX" <<"\t\t\t; Line "<< to_string(antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getLine())<< endl;
                      asmFile << "\tSHL BX, 1"<< endl;
                      asmFile << "\tMOV AX, "<< sym->getarraylen()*2+sym->getOffset()-4 <<endl;
                      asmFile << "\tSUB AX, BX"<<endl;
                      asmFile << "\tMOV BX, AX"<<endl;
                      asmFile << "\tMOV SI, BX "<<endl;
                      asmFile << "\tNEG SI" <<endl;
                      asmFile << "\tMOV AX, [BP+SI]" << endl;
                      asmFile << "\tPUSH AX" <<endl;
                      asmFile << "\tINC AX"<<endl;
                      asmFile << "\tMOV [BP+SI], AX" <<endl;
                  }
                  else {
                      
                      if (isGlobal) {
                          asmFile << "\tPUSH " << sym->getName() <<"\t\t\t; Line "<< to_string(antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getLine())<< endl;
                          asmFile << "\tINC " << sym->getName() << endl;
                      } else {
                          string sign = offset < 0 ? "+" : "-";
                          int absOffset = abs(offset);
                          string addr = "[BP" + sign + to_string(absOffset) + "]";

                          asmFile << "\tPUSH " << addr <<"\t\t\t; Line "<< to_string(antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getLine())<< endl;
                          asmFile << "\tINC " << addr << endl;
                      }
                  }
              }
          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(442);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(443);
      antlrcpp::downCast<FactorContext *>(_localctx)->decopToken = match(C2105133Parser::DECOP);

              antlrcpp::downCast<FactorContext *>(_localctx)->act_text =  _localctx->getText() ; antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->v->type ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : variable DECOP \n\n" + _localctx->getText() + "\n");
              
              SymbolInfo* itemglobal = Table.lookup(antlrcpp::downCast<FactorContext *>(_localctx)->v->act_text);
              SymbolInfo* item = Table.getCurrentScopeTable()->lookup(antlrcpp::downCast<FactorContext *>(_localctx)->v->act_text);

              SymbolInfo* sym = item ? item : itemglobal;

              if(sym){
                  bool isLocal = (sym == item);
                  bool isGlobal = sym->getGlobal();
                  bool isArray = sym->getarray();
                  int offset = sym->getOffset();

                  if (isArray && isGlobal){
                      asmFile << "\tPOP BX" <<"\t\t\t; Line "<< to_string(antlrcpp::downCast<FactorContext *>(_localctx)->decopToken->getLine())<< endl;
                      asmFile << "\tSHL BX, 1 "<<endl;
                      asmFile << "\tMOV AX, " << antlrcpp::downCast<FactorContext *>(_localctx)->v->act_text << "[BX]" << endl;
                      asmFile << "\tPUSH AX "<<endl;
                      asmFile << "\tDEC AX " <<endl;
                      asmFile << "\tMOV "<< antlrcpp::downCast<FactorContext *>(_localctx)->v->act_text << "[BX], AX" << endl;
                  }else if(isArray)
                  {
                      asmFile << "\tPOP BX" <<"\t\t\t; Line "<< to_string(antlrcpp::downCast<FactorContext *>(_localctx)->decopToken->getLine())<< endl;
                      asmFile << "\tSHL BX, 1"<< endl;
                      asmFile << "\tMOV AX, "<< sym->getarraylen()*2+sym->getOffset()-4 <<endl;
                      asmFile << "\tSUB AX, BX"<<endl;
                      asmFile << "\tMOV BX, AX"<<endl;
                      asmFile << "\tMOV SI, BX "<<endl;
                      asmFile << "\tNEG SI" <<endl;
                      asmFile << "\tMOV AX, [BP+SI]" << endl;
                      asmFile << "\tPUSH AX" <<endl;
                      asmFile << "\tDEC AX"<<endl;
                      asmFile << "\tMOV [BP+SI], AX" <<endl;
                  }
                  else {
                      
                      if (isGlobal) {
                          asmFile << "\tMOV AX, " << sym->getName() <<"\t\t\t; Line "<< to_string(antlrcpp::downCast<FactorContext *>(_localctx)->decopToken->getLine())<< endl;
                          asmFile << "\tPUSH AX" << endl;
                          asmFile << "\tDEC AX "<< endl;
                          asmFile << "\tMOV " << sym->getName() <<", AX" <<endl;
                      } else {
                          string sign = offset < 0 ? "+" : "-";
                          int absOffset = abs(offset);
                          string addr = "[BP" + sign + to_string(absOffset) + "]";

                          asmFile << "\tMOV AX, " << addr <<"\t\t\t; Line "<< to_string(antlrcpp::downCast<FactorContext *>(_localctx)->decopToken->getLine())<< endl;
                          asmFile << "\tPUSH AX" << endl;
                          asmFile << "\tDEC AX "<< endl;
                          asmFile << "\tMOV " << addr <<", AX" <<endl;
                      }
                  }
              }
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_listContext ------------------------------------------------------------------

C2105133Parser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105133Parser::ArgumentsContext* C2105133Parser::Argument_listContext::arguments() {
  return getRuleContext<C2105133Parser::ArgumentsContext>(0);
}


size_t C2105133Parser::Argument_listContext::getRuleIndex() const {
  return C2105133Parser::RuleArgument_list;
}

void C2105133Parser::Argument_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument_list(this);
}

void C2105133Parser::Argument_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument_list(this);
}

C2105133Parser::Argument_listContext* C2105133Parser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 46, C2105133Parser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(452);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105133Parser::LPAREN:
      case C2105133Parser::ADDOP:
      case C2105133Parser::NOT:
      case C2105133Parser::ID:
      case C2105133Parser::CONST_INT:
      case C2105133Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(448);
        antlrcpp::downCast<Argument_listContext *>(_localctx)->a = arguments(0);

                 antlrcpp::downCast<Argument_listContext *>(_localctx)->act_text =  _localctx->getText() ;
                 antlrcpp::downCast<Argument_listContext *>(_localctx)->types =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->types;
                  writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": argument_list : arguments \n\n" + _localctx->getText() + "\n");
        		
        break;
      }

      case C2105133Parser::RPAREN: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

C2105133Parser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105133Parser::Logic_expressionContext* C2105133Parser::ArgumentsContext::logic_expression() {
  return getRuleContext<C2105133Parser::Logic_expressionContext>(0);
}

tree::TerminalNode* C2105133Parser::ArgumentsContext::COMMA() {
  return getToken(C2105133Parser::COMMA, 0);
}

C2105133Parser::ArgumentsContext* C2105133Parser::ArgumentsContext::arguments() {
  return getRuleContext<C2105133Parser::ArgumentsContext>(0);
}


size_t C2105133Parser::ArgumentsContext::getRuleIndex() const {
  return C2105133Parser::RuleArguments;
}

void C2105133Parser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void C2105133Parser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105133ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


C2105133Parser::ArgumentsContext* C2105133Parser::arguments() {
   return arguments(0);
}

C2105133Parser::ArgumentsContext* C2105133Parser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105133Parser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  C2105133Parser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, C2105133Parser::RuleArguments, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(455);
    antlrcpp::downCast<ArgumentsContext *>(_localctx)->l = logic_expression();
     
            antlrcpp::downCast<ArgumentsContext *>(_localctx)->act_text =  _localctx->getText() ;
            _localctx->types.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->type);
             writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": arguments : logic_expression \n\n" + _localctx->getText() + "\n");
    		
    _ctx->stop = _input->LT(-1);
    setState(465);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentsContext>(parentContext, parentState);
        _localctx->a = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleArguments);
        setState(458);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(459);
        match(C2105133Parser::COMMA);
        setState(460);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->l = logic_expression();
         
                          antlrcpp::downCast<ArgumentsContext *>(_localctx)->act_text =  _localctx->getText() ;
                          antlrcpp::downCast<ArgumentsContext *>(_localctx)->types =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->types;
                          _localctx->types.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->type);
                          writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": arguments : arguments COMMA logic_expression \n\n" + _localctx->getText() + "\n");
                  	 
      }
      setState(467);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool C2105133Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 6: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 11: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 12: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 19: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 20: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 24: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool C2105133Parser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool C2105133Parser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool C2105133Parser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 14);
    case 4: return precpred(_ctx, 13);
    case 5: return precpred(_ctx, 10);
    case 6: return precpred(_ctx, 9);
    case 7: return precpred(_ctx, 8);
    case 8: return precpred(_ctx, 7);
    case 9: return precpred(_ctx, 6);
    case 10: return precpred(_ctx, 5);
    case 11: return precpred(_ctx, 4);
    case 12: return precpred(_ctx, 3);
    case 13: return precpred(_ctx, 2);
    case 14: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105133Parser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 15: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105133Parser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 16: return precpred(_ctx, 2);
    case 17: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105133Parser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 18: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105133Parser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 19: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void C2105133Parser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c2105133parserParserInitialize();
#else
  ::antlr4::internal::call_once(c2105133parserParserOnceFlag, c2105133parserParserInitialize);
#endif
}
