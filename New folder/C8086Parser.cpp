
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


#include "C8086ParserListener.h"

#include "C8086Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct C8086ParserStaticData final {
  C8086ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C8086ParserStaticData(const C8086ParserStaticData&) = delete;
  C8086ParserStaticData(C8086ParserStaticData&&) = delete;
  C8086ParserStaticData& operator=(const C8086ParserStaticData&) = delete;
  C8086ParserStaticData& operator=(C8086ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c8086parserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C8086ParserStaticData> c8086parserParserStaticData = nullptr;

void c8086parserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c8086parserParserStaticData != nullptr) {
    return;
  }
#else
  assert(c8086parserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C8086ParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "func_declaration", "func_definition", 
      "parameter_list_err", "parameter_list", "compound_statement", "var_declaration", 
      "declaration_list_err", "type_specifier", "declaration_list", "statements", 
      "statement", "expression_statement", "variable", "expression", "logic_expression", 
      "rel_expression", "simple_expression", "term", "unary_expression", 
      "factor", "argument_list", "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'printf'", 
      "'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
      "'['", "']'", "';'", "','", "", "", "", "'++'", "'--'", "'!'", "", 
      "", "'='"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
      "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
      "ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", 
      "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT", "ANY"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,34,460,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,5,1,62,8,1,10,1,12,1,65,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,3,2,76,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,3,3,93,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,121,8,4,1,5,4,5,
  	124,8,5,11,5,12,5,125,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,138,
  	8,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,5,6,151,8,6,10,6,12,6,
  	154,9,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,166,8,7,1,8,1,8,1,
  	8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,178,8,8,1,9,1,9,1,10,1,10,1,10,1,10,
  	1,10,1,10,3,10,188,8,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,
  	198,8,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,5,11,241,8,11,10,11,12,11,244,9,11,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,5,12,254,8,12,10,12,12,12,257,9,12,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,3,13,311,8,13,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,3,14,323,8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,3,15,333,8,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,343,8,
  	16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,3,17,353,8,17,1,18,1,18,1,
  	18,1,18,1,18,1,18,1,18,1,18,3,18,363,8,18,1,19,1,19,1,19,1,19,1,19,1,
  	19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,5,19,380,8,19,10,19,12,
  	19,383,9,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,5,20,394,8,20,
  	10,20,12,20,397,9,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,
  	1,21,3,21,410,8,21,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,3,22,438,8,22,1,23,1,23,1,23,1,23,3,23,444,8,23,1,24,1,24,1,
  	24,1,24,1,24,1,24,1,24,1,24,1,24,5,24,455,8,24,10,24,12,24,458,9,24,1,
  	24,1,125,7,2,12,22,24,38,40,48,25,0,2,4,6,8,10,12,14,16,18,20,22,24,26,
  	28,30,32,34,36,38,40,42,44,46,48,0,0,489,0,50,1,0,0,0,2,53,1,0,0,0,4,
  	75,1,0,0,0,6,92,1,0,0,0,8,120,1,0,0,0,10,123,1,0,0,0,12,137,1,0,0,0,14,
  	165,1,0,0,0,16,177,1,0,0,0,18,179,1,0,0,0,20,187,1,0,0,0,22,197,1,0,0,
  	0,24,245,1,0,0,0,26,310,1,0,0,0,28,322,1,0,0,0,30,332,1,0,0,0,32,342,
  	1,0,0,0,34,352,1,0,0,0,36,362,1,0,0,0,38,364,1,0,0,0,40,384,1,0,0,0,42,
  	409,1,0,0,0,44,437,1,0,0,0,46,443,1,0,0,0,48,445,1,0,0,0,50,51,3,2,1,
  	0,51,52,6,0,-1,0,52,1,1,0,0,0,53,54,6,1,-1,0,54,55,3,4,2,0,55,56,6,1,
  	-1,0,56,63,1,0,0,0,57,58,10,2,0,0,58,59,3,4,2,0,59,60,6,1,-1,0,60,62,
  	1,0,0,0,61,57,1,0,0,0,62,65,1,0,0,0,63,61,1,0,0,0,63,64,1,0,0,0,64,3,
  	1,0,0,0,65,63,1,0,0,0,66,67,3,16,8,0,67,68,6,2,-1,0,68,76,1,0,0,0,69,
  	70,3,6,3,0,70,71,6,2,-1,0,71,76,1,0,0,0,72,73,3,8,4,0,73,74,6,2,-1,0,
  	74,76,1,0,0,0,75,66,1,0,0,0,75,69,1,0,0,0,75,72,1,0,0,0,76,5,1,0,0,0,
  	77,78,3,20,10,0,78,79,5,31,0,0,79,80,5,14,0,0,80,81,3,12,6,0,81,82,5,
  	15,0,0,82,83,5,20,0,0,83,84,6,3,-1,0,84,93,1,0,0,0,85,86,3,20,10,0,86,
  	87,5,31,0,0,87,88,5,14,0,0,88,89,5,15,0,0,89,90,5,20,0,0,90,91,6,3,-1,
  	0,91,93,1,0,0,0,92,77,1,0,0,0,92,85,1,0,0,0,93,7,1,0,0,0,94,95,3,20,10,
  	0,95,96,5,31,0,0,96,97,5,14,0,0,97,98,3,12,6,0,98,99,5,15,0,0,99,100,
  	6,4,-1,0,100,101,3,14,7,0,101,102,6,4,-1,0,102,121,1,0,0,0,103,104,3,
  	20,10,0,104,105,5,31,0,0,105,106,5,14,0,0,106,107,5,15,0,0,107,108,6,
  	4,-1,0,108,109,3,14,7,0,109,110,6,4,-1,0,110,121,1,0,0,0,111,112,3,20,
  	10,0,112,113,5,31,0,0,113,114,5,14,0,0,114,115,3,10,5,0,115,116,5,15,
  	0,0,116,117,6,4,-1,0,117,118,3,14,7,0,118,119,6,4,-1,0,119,121,1,0,0,
  	0,120,94,1,0,0,0,120,103,1,0,0,0,120,111,1,0,0,0,121,9,1,0,0,0,122,124,
  	9,0,0,0,123,122,1,0,0,0,124,125,1,0,0,0,125,126,1,0,0,0,125,123,1,0,0,
  	0,126,127,1,0,0,0,127,128,6,5,-1,0,128,11,1,0,0,0,129,130,6,6,-1,0,130,
  	131,3,20,10,0,131,132,5,31,0,0,132,133,6,6,-1,0,133,138,1,0,0,0,134,135,
  	3,20,10,0,135,136,6,6,-1,0,136,138,1,0,0,0,137,129,1,0,0,0,137,134,1,
  	0,0,0,138,152,1,0,0,0,139,140,10,4,0,0,140,141,5,21,0,0,141,142,3,20,
  	10,0,142,143,5,31,0,0,143,144,6,6,-1,0,144,151,1,0,0,0,145,146,10,3,0,
  	0,146,147,5,21,0,0,147,148,3,20,10,0,148,149,6,6,-1,0,149,151,1,0,0,0,
  	150,139,1,0,0,0,150,145,1,0,0,0,151,154,1,0,0,0,152,150,1,0,0,0,152,153,
  	1,0,0,0,153,13,1,0,0,0,154,152,1,0,0,0,155,156,5,16,0,0,156,157,6,7,-1,
  	0,157,158,3,24,12,0,158,159,5,17,0,0,159,160,6,7,-1,0,160,166,1,0,0,0,
  	161,162,5,16,0,0,162,163,6,7,-1,0,163,164,5,17,0,0,164,166,6,7,-1,0,165,
  	155,1,0,0,0,165,161,1,0,0,0,166,15,1,0,0,0,167,168,3,20,10,0,168,169,
  	3,22,11,0,169,170,5,20,0,0,170,171,6,8,-1,0,171,178,1,0,0,0,172,173,3,
  	20,10,0,173,174,3,18,9,0,174,175,5,20,0,0,175,176,6,8,-1,0,176,178,1,
  	0,0,0,177,167,1,0,0,0,177,172,1,0,0,0,178,17,1,0,0,0,179,180,6,9,-1,0,
  	180,19,1,0,0,0,181,182,5,11,0,0,182,188,6,10,-1,0,183,184,5,12,0,0,184,
  	188,6,10,-1,0,185,186,5,13,0,0,186,188,6,10,-1,0,187,181,1,0,0,0,187,
  	183,1,0,0,0,187,185,1,0,0,0,188,21,1,0,0,0,189,190,6,11,-1,0,190,191,
  	5,31,0,0,191,198,6,11,-1,0,192,193,5,31,0,0,193,194,5,18,0,0,194,195,
  	5,32,0,0,195,196,5,19,0,0,196,198,6,11,-1,0,197,189,1,0,0,0,197,192,1,
  	0,0,0,198,242,1,0,0,0,199,200,10,14,0,0,200,201,5,21,0,0,201,202,5,31,
  	0,0,202,241,6,11,-1,0,203,204,10,13,0,0,204,205,5,21,0,0,205,206,5,31,
  	0,0,206,207,5,18,0,0,207,208,5,32,0,0,208,209,5,19,0,0,209,241,6,11,-1,
  	0,210,211,10,10,0,0,211,212,5,22,0,0,212,241,6,11,-1,0,213,214,10,9,0,
  	0,214,215,5,31,0,0,215,241,6,11,-1,0,216,217,10,8,0,0,217,218,5,23,0,
  	0,218,241,6,11,-1,0,219,220,10,7,0,0,220,221,5,24,0,0,221,241,6,11,-1,
  	0,222,223,10,6,0,0,223,224,5,25,0,0,224,241,6,11,-1,0,225,226,10,5,0,
  	0,226,227,5,26,0,0,227,241,6,11,-1,0,228,229,10,4,0,0,229,230,5,27,0,
  	0,230,241,6,11,-1,0,231,232,10,3,0,0,232,233,5,28,0,0,233,241,6,11,-1,
  	0,234,235,10,2,0,0,235,236,5,29,0,0,236,241,6,11,-1,0,237,238,10,1,0,
  	0,238,239,5,30,0,0,239,241,6,11,-1,0,240,199,1,0,0,0,240,203,1,0,0,0,
  	240,210,1,0,0,0,240,213,1,0,0,0,240,216,1,0,0,0,240,219,1,0,0,0,240,222,
  	1,0,0,0,240,225,1,0,0,0,240,228,1,0,0,0,240,231,1,0,0,0,240,234,1,0,0,
  	0,240,237,1,0,0,0,241,244,1,0,0,0,242,240,1,0,0,0,242,243,1,0,0,0,243,
  	23,1,0,0,0,244,242,1,0,0,0,245,246,6,12,-1,0,246,247,3,26,13,0,247,248,
  	6,12,-1,0,248,255,1,0,0,0,249,250,10,1,0,0,250,251,3,26,13,0,251,252,
  	6,12,-1,0,252,254,1,0,0,0,253,249,1,0,0,0,254,257,1,0,0,0,255,253,1,0,
  	0,0,255,256,1,0,0,0,256,25,1,0,0,0,257,255,1,0,0,0,258,259,3,16,8,0,259,
  	260,6,13,-1,0,260,311,1,0,0,0,261,262,3,28,14,0,262,263,6,13,-1,0,263,
  	311,1,0,0,0,264,265,3,14,7,0,265,266,6,13,-1,0,266,311,1,0,0,0,267,268,
  	5,7,0,0,268,269,5,14,0,0,269,270,3,28,14,0,270,271,3,28,14,0,271,272,
  	3,32,16,0,272,273,5,15,0,0,273,274,3,26,13,0,274,275,6,13,-1,0,275,311,
  	1,0,0,0,276,277,5,5,0,0,277,278,5,14,0,0,278,279,3,32,16,0,279,280,5,
  	15,0,0,280,281,3,26,13,0,281,282,6,13,-1,0,282,311,1,0,0,0,283,284,5,
  	5,0,0,284,285,5,14,0,0,285,286,3,32,16,0,286,287,5,15,0,0,287,288,3,26,
  	13,0,288,289,5,6,0,0,289,290,3,26,13,0,290,291,6,13,-1,0,291,311,1,0,
  	0,0,292,293,5,8,0,0,293,294,5,14,0,0,294,295,3,32,16,0,295,296,5,15,0,
  	0,296,297,3,26,13,0,297,298,6,13,-1,0,298,311,1,0,0,0,299,300,5,9,0,0,
  	300,301,5,14,0,0,301,302,5,31,0,0,302,303,5,15,0,0,303,304,5,20,0,0,304,
  	311,6,13,-1,0,305,306,5,10,0,0,306,307,3,32,16,0,307,308,5,20,0,0,308,
  	309,6,13,-1,0,309,311,1,0,0,0,310,258,1,0,0,0,310,261,1,0,0,0,310,264,
  	1,0,0,0,310,267,1,0,0,0,310,276,1,0,0,0,310,283,1,0,0,0,310,292,1,0,0,
  	0,310,299,1,0,0,0,310,305,1,0,0,0,311,27,1,0,0,0,312,313,5,20,0,0,313,
  	323,6,14,-1,0,314,315,3,32,16,0,315,316,5,20,0,0,316,317,6,14,-1,0,317,
  	323,1,0,0,0,318,319,3,32,16,0,319,320,5,34,0,0,320,321,6,14,-1,0,321,
  	323,1,0,0,0,322,312,1,0,0,0,322,314,1,0,0,0,322,318,1,0,0,0,323,29,1,
  	0,0,0,324,325,5,31,0,0,325,333,6,15,-1,0,326,327,5,31,0,0,327,328,5,18,
  	0,0,328,329,3,32,16,0,329,330,5,19,0,0,330,331,6,15,-1,0,331,333,1,0,
  	0,0,332,324,1,0,0,0,332,326,1,0,0,0,333,31,1,0,0,0,334,335,3,34,17,0,
  	335,336,6,16,-1,0,336,343,1,0,0,0,337,338,3,30,15,0,338,339,5,30,0,0,
  	339,340,3,34,17,0,340,341,6,16,-1,0,341,343,1,0,0,0,342,334,1,0,0,0,342,
  	337,1,0,0,0,343,33,1,0,0,0,344,345,3,36,18,0,345,346,6,17,-1,0,346,353,
  	1,0,0,0,347,348,3,36,18,0,348,349,5,29,0,0,349,350,3,36,18,0,350,351,
  	6,17,-1,0,351,353,1,0,0,0,352,344,1,0,0,0,352,347,1,0,0,0,353,35,1,0,
  	0,0,354,355,3,38,19,0,355,356,6,18,-1,0,356,363,1,0,0,0,357,358,3,38,
  	19,0,358,359,5,28,0,0,359,360,3,38,19,0,360,361,6,18,-1,0,361,363,1,0,
  	0,0,362,354,1,0,0,0,362,357,1,0,0,0,363,37,1,0,0,0,364,365,6,19,-1,0,
  	365,366,3,40,20,0,366,367,6,19,-1,0,367,381,1,0,0,0,368,369,10,2,0,0,
  	369,370,5,22,0,0,370,371,3,40,20,0,371,372,6,19,-1,0,372,380,1,0,0,0,
  	373,374,10,1,0,0,374,375,5,22,0,0,375,376,5,30,0,0,376,377,3,40,20,0,
  	377,378,6,19,-1,0,378,380,1,0,0,0,379,368,1,0,0,0,379,373,1,0,0,0,380,
  	383,1,0,0,0,381,379,1,0,0,0,381,382,1,0,0,0,382,39,1,0,0,0,383,381,1,
  	0,0,0,384,385,6,20,-1,0,385,386,3,42,21,0,386,387,6,20,-1,0,387,395,1,
  	0,0,0,388,389,10,1,0,0,389,390,5,24,0,0,390,391,3,42,21,0,391,392,6,20,
  	-1,0,392,394,1,0,0,0,393,388,1,0,0,0,394,397,1,0,0,0,395,393,1,0,0,0,
  	395,396,1,0,0,0,396,41,1,0,0,0,397,395,1,0,0,0,398,399,5,22,0,0,399,400,
  	3,42,21,0,400,401,6,21,-1,0,401,410,1,0,0,0,402,403,5,27,0,0,403,404,
  	3,42,21,0,404,405,6,21,-1,0,405,410,1,0,0,0,406,407,3,44,22,0,407,408,
  	6,21,-1,0,408,410,1,0,0,0,409,398,1,0,0,0,409,402,1,0,0,0,409,406,1,0,
  	0,0,410,43,1,0,0,0,411,412,3,30,15,0,412,413,6,22,-1,0,413,438,1,0,0,
  	0,414,415,5,31,0,0,415,416,5,14,0,0,416,417,3,46,23,0,417,418,5,15,0,
  	0,418,419,6,22,-1,0,419,438,1,0,0,0,420,421,5,14,0,0,421,422,3,32,16,
  	0,422,423,5,15,0,0,423,424,6,22,-1,0,424,438,1,0,0,0,425,426,5,32,0,0,
  	426,438,6,22,-1,0,427,428,5,33,0,0,428,438,6,22,-1,0,429,430,3,30,15,
  	0,430,431,5,25,0,0,431,432,6,22,-1,0,432,438,1,0,0,0,433,434,3,30,15,
  	0,434,435,5,26,0,0,435,436,6,22,-1,0,436,438,1,0,0,0,437,411,1,0,0,0,
  	437,414,1,0,0,0,437,420,1,0,0,0,437,425,1,0,0,0,437,427,1,0,0,0,437,429,
  	1,0,0,0,437,433,1,0,0,0,438,45,1,0,0,0,439,440,3,48,24,0,440,441,6,23,
  	-1,0,441,444,1,0,0,0,442,444,1,0,0,0,443,439,1,0,0,0,443,442,1,0,0,0,
  	444,47,1,0,0,0,445,446,6,24,-1,0,446,447,3,34,17,0,447,448,6,24,-1,0,
  	448,456,1,0,0,0,449,450,10,2,0,0,450,451,5,21,0,0,451,452,3,34,17,0,452,
  	453,6,24,-1,0,453,455,1,0,0,0,454,449,1,0,0,0,455,458,1,0,0,0,456,454,
  	1,0,0,0,456,457,1,0,0,0,457,49,1,0,0,0,458,456,1,0,0,0,28,63,75,92,120,
  	125,137,150,152,165,177,187,197,240,242,255,310,322,332,342,352,362,379,
  	381,395,409,437,443,456
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c8086parserParserStaticData = std::move(staticData);
}

}

C8086Parser::C8086Parser(TokenStream *input) : C8086Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

C8086Parser::C8086Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  C8086Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *c8086parserParserStaticData->atn, c8086parserParserStaticData->decisionToDFA, c8086parserParserStaticData->sharedContextCache, options);
}

C8086Parser::~C8086Parser() {
  delete _interpreter;
}

const atn::ATN& C8086Parser::getATN() const {
  return *c8086parserParserStaticData->atn;
}

std::string C8086Parser::getGrammarFileName() const {
  return "C8086Parser.g4";
}

const std::vector<std::string>& C8086Parser::getRuleNames() const {
  return c8086parserParserStaticData->ruleNames;
}

const dfa::Vocabulary& C8086Parser::getVocabulary() const {
  return c8086parserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C8086Parser::getSerializedATN() const {
  return c8086parserParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

C8086Parser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::ProgramContext* C8086Parser::StartContext::program() {
  return getRuleContext<C8086Parser::ProgramContext>(0);
}


size_t C8086Parser::StartContext::getRuleIndex() const {
  return C8086Parser::RuleStart;
}

void C8086Parser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void C8086Parser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

C8086Parser::StartContext* C8086Parser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, C8086Parser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    antlrcpp::downCast<StartContext *>(_localctx)->p = program(0);

            writeIntoparserLogFile(
                "Line " + to_string((antlrcpp::downCast<StartContext *>(_localctx)->p != nullptr ? (antlrcpp::downCast<StartContext *>(_localctx)->p->stop) : nullptr)->getLine()) +
                ": start : program \n\n" + "\n"
            );
            Table.printAllScopeTable(parserLogFile);
            writeIntoparserLogFile("Total lines: " + to_string((antlrcpp::downCast<StartContext *>(_localctx)->p != nullptr ? (antlrcpp::downCast<StartContext *>(_localctx)->p->stop) : nullptr)->getLine()) +
            "\nTotal errors: " + to_string(syntaxErrorCount) + "\n");
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

C8086Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::UnitContext* C8086Parser::ProgramContext::unit() {
  return getRuleContext<C8086Parser::UnitContext>(0);
}

C8086Parser::ProgramContext* C8086Parser::ProgramContext::program() {
  return getRuleContext<C8086Parser::ProgramContext>(0);
}


size_t C8086Parser::ProgramContext::getRuleIndex() const {
  return C8086Parser::RuleProgram;
}

void C8086Parser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void C8086Parser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


C8086Parser::ProgramContext* C8086Parser::program() {
   return program(0);
}

C8086Parser::ProgramContext* C8086Parser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  C8086Parser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, C8086Parser::RuleProgram, precedence);

    

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
    setState(54);
    antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

            antlrcpp::downCast<ProgramContext *>(_localctx)->act_text =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->act_text;
            writeIntoparserLogFile(
                "Line " + to_string((antlrcpp::downCast<ProgramContext *>(_localctx)->u != nullptr ? (antlrcpp::downCast<ProgramContext *>(_localctx)->u->stop) : nullptr)->getLine()) +
                ": program : unit\n\n" + _localctx->act_text + "\n"
            );
        
    _ctx->stop = _input->LT(-1);
    setState(63);
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
        setState(57);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(58);
        antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

                          antlrcpp::downCast<ProgramContext *>(_localctx)->act_text =  antlrcpp::downCast<ProgramContext *>(_localctx)->p->act_text + antlrcpp::downCast<ProgramContext *>(_localctx)->u->act_text;
                          writeIntoparserLogFile(
                              "Line " + to_string((antlrcpp::downCast<ProgramContext *>(_localctx)->u != nullptr ? (antlrcpp::downCast<ProgramContext *>(_localctx)->u->stop) : nullptr)->getLine()) +
                              ": program : program unit\n\n" + _localctx->act_text + "\n"
                          );
                       
      }
      setState(65);
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

C8086Parser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Var_declarationContext* C8086Parser::UnitContext::var_declaration() {
  return getRuleContext<C8086Parser::Var_declarationContext>(0);
}

C8086Parser::Func_declarationContext* C8086Parser::UnitContext::func_declaration() {
  return getRuleContext<C8086Parser::Func_declarationContext>(0);
}

C8086Parser::Func_definitionContext* C8086Parser::UnitContext::func_definition() {
  return getRuleContext<C8086Parser::Func_definitionContext>(0);
}


size_t C8086Parser::UnitContext::getRuleIndex() const {
  return C8086Parser::RuleUnit;
}

void C8086Parser::UnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit(this);
}

void C8086Parser::UnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit(this);
}

C8086Parser::UnitContext* C8086Parser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, C8086Parser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(66);
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
      setState(69);
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
      setState(72);
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

C8086Parser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Func_declarationContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

C8086Parser::Type_specifierContext* C8086Parser::Func_declarationContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

C8086Parser::Parameter_listContext* C8086Parser::Func_declarationContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
}


size_t C8086Parser::Func_declarationContext::getRuleIndex() const {
  return C8086Parser::RuleFunc_declaration;
}

void C8086Parser::Func_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_declaration(this);
}

void C8086Parser::Func_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_declaration(this);
}

C8086Parser::Func_declarationContext* C8086Parser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, C8086Parser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(92);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(77);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(78);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(79);
      match(C8086Parser::LPAREN);
      setState(80);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->p = parameter_list(0);
      setState(81);
      match(C8086Parser::RPAREN);
      setState(82);
      match(C8086Parser::SEMICOLON);

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
      setState(85);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(86);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(87);
      match(C8086Parser::LPAREN);
      setState(88);
      match(C8086Parser::RPAREN);
      setState(89);
      match(C8086Parser::SEMICOLON);

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

C8086Parser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Func_definitionContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::Func_definitionContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

tree::TerminalNode* C8086Parser::Func_definitionContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

C8086Parser::Type_specifierContext* C8086Parser::Func_definitionContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

C8086Parser::Parameter_listContext* C8086Parser::Func_definitionContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
}

C8086Parser::Compound_statementContext* C8086Parser::Func_definitionContext::compound_statement() {
  return getRuleContext<C8086Parser::Compound_statementContext>(0);
}

C8086Parser::Parameter_list_errContext* C8086Parser::Func_definitionContext::parameter_list_err() {
  return getRuleContext<C8086Parser::Parameter_list_errContext>(0);
}


size_t C8086Parser::Func_definitionContext::getRuleIndex() const {
  return C8086Parser::RuleFunc_definition;
}

void C8086Parser::Func_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_definition(this);
}

void C8086Parser::Func_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_definition(this);
}

C8086Parser::Func_definitionContext* C8086Parser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, C8086Parser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(120);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(94);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(95);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(96);
      match(C8086Parser::LPAREN);
      setState(97);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->p = parameter_list(0);
      setState(98);
      match(C8086Parser::RPAREN);

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
          
      setState(100);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->c = compound_statement(false);

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->act_text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->act_text + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "(" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->p->act_text + ")" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->act_text;
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->Line =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->Line;
              writeIntoparserLogFile(
                  "Line " + to_string((antlrcpp::downCast<Func_definitionContext *>(_localctx)->c != nullptr ? (antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->stop) : nullptr)->getLine()) +
                  ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n" +
                  _localctx->act_text + "\n"
              );
              Table.exitScope();
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(103);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(104);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(105);
      match(C8086Parser::LPAREN);
      setState(106);
      match(C8086Parser::RPAREN);

              SymbolInfo* temp = Table.lookup(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());
              if(temp!=nullptr){
                  if(!temp->getIsDeclared())
                       insertFunctionDeclaration(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(),antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->act_text,"",true);
                  Table.enterScope();
              }else
              {
                  insertFunctionDeclaration(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(),antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->act_text,"",true);
                  Table.enterScope();
              }
          
      setState(108);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->c = compound_statement(false);

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->act_text =   antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->act_text + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "(" + ")" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->act_text;
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->Line =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->Line;
              writeIntoparserLogFile(
                  "Line " + to_string((antlrcpp::downCast<Func_definitionContext *>(_localctx)->c != nullptr ? (antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->stop) : nullptr)->getLine()) +
                  ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n" +
                  _localctx->act_text + "\n"
              );
              Table.exitScope();
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(111);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(112);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(113);
      match(C8086Parser::LPAREN);
      setState(114);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->pe = parameter_list_err();
      setState(115);
      match(C8086Parser::RPAREN);

              // This block handles error in parameter list
              writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Syntax error in parameter list of function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
              writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Syntax error in parameter list of function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
              Table.enterScope();  // still enter scope to allow compound_statement parsing
          
      setState(117);
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

C8086Parser::Parameter_list_errContext::Parameter_list_errContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C8086Parser::Parameter_list_errContext::getRuleIndex() const {
  return C8086Parser::RuleParameter_list_err;
}

void C8086Parser::Parameter_list_errContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list_err(this);
}

void C8086Parser::Parameter_list_errContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list_err(this);
}

C8086Parser::Parameter_list_errContext* C8086Parser::parameter_list_err() {
  Parameter_list_errContext *_localctx = _tracker.createInstance<Parameter_list_errContext>(_ctx, getState());
  enterRule(_localctx, 10, C8086Parser::RuleParameter_list_err);

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
    setState(123); 
    _errHandler->sync(this);
    alt = 1 + 1;
    do {
      switch (alt) {
        case 1 + 1: {
              setState(122);
              matchWildcard();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(125); 
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

C8086Parser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Parameter_listContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

C8086Parser::Type_specifierContext* C8086Parser::Parameter_listContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C8086Parser::Parameter_listContext::COMMA() {
  return getToken(C8086Parser::COMMA, 0);
}

C8086Parser::Parameter_listContext* C8086Parser::Parameter_listContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
}


size_t C8086Parser::Parameter_listContext::getRuleIndex() const {
  return C8086Parser::RuleParameter_list;
}

void C8086Parser::Parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list(this);
}

void C8086Parser::Parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list(this);
}


C8086Parser::Parameter_listContext* C8086Parser::parameter_list() {
   return parameter_list(0);
}

C8086Parser::Parameter_listContext* C8086Parser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  C8086Parser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, C8086Parser::RuleParameter_list, precedence);

    

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
    setState(137);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(130);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
      setState(131);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C8086Parser::ID);

              antlrcpp::downCast<Parameter_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->act_text + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText();
              writeIntoparserLogFile(
                  "Line " + to_string(_localctx->getStart()->getLine()) +
                  ": parameter_list : type_specifier ID\n\n" +
                  _localctx->act_text + "\n"
              );
          
      break;
    }

    case 2: {
      setState(134);
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
    setState(152);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(150);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->p = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(139);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(140);
          match(C8086Parser::COMMA);
          setState(141);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
          setState(142);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C8086Parser::ID);

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
          setState(145);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(146);
          match(C8086Parser::COMMA);
          setState(147);
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
      setState(154);
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

C8086Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState, bool flagScope)
  : ParserRuleContext(parent, invokingState) {
  this->flagScope = flagScope;
}

tree::TerminalNode* C8086Parser::Compound_statementContext::LCURL() {
  return getToken(C8086Parser::LCURL, 0);
}

tree::TerminalNode* C8086Parser::Compound_statementContext::RCURL() {
  return getToken(C8086Parser::RCURL, 0);
}

C8086Parser::StatementsContext* C8086Parser::Compound_statementContext::statements() {
  return getRuleContext<C8086Parser::StatementsContext>(0);
}


size_t C8086Parser::Compound_statementContext::getRuleIndex() const {
  return C8086Parser::RuleCompound_statement;
}

void C8086Parser::Compound_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_statement(this);
}

void C8086Parser::Compound_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_statement(this);
}

C8086Parser::Compound_statementContext* C8086Parser::compound_statement(bool flagScope) {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState(), flagScope);
  enterRule(_localctx, 14, C8086Parser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(165);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(155);
      match(C8086Parser::LCURL);
      if (flagScope) Table.enterScope();
      setState(157);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->s = statements(0);
      setState(158);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken = match(C8086Parser::RCURL);

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
      setState(161);
      match(C8086Parser::LCURL);
      if (flagScope) Table.enterScope();
      setState(163);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken = match(C8086Parser::RCURL);

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

C8086Parser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Type_specifierContext* C8086Parser::Var_declarationContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

C8086Parser::Declaration_listContext* C8086Parser::Var_declarationContext::declaration_list() {
  return getRuleContext<C8086Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C8086Parser::Var_declarationContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

C8086Parser::Declaration_list_errContext* C8086Parser::Var_declarationContext::declaration_list_err() {
  return getRuleContext<C8086Parser::Declaration_list_errContext>(0);
}


size_t C8086Parser::Var_declarationContext::getRuleIndex() const {
  return C8086Parser::RuleVar_declaration;
}

void C8086Parser::Var_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declaration(this);
}

void C8086Parser::Var_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declaration(this);
}

C8086Parser::Var_declarationContext* C8086Parser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 16, C8086Parser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(177);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(167);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(168);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl = declaration_list(0);
      setState(169);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C8086Parser::SEMICOLON);

              antlrcpp::downCast<Var_declarationContext *>(_localctx)->act_text =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->act_text + " " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->act_text + ";\n" ;
              antlrcpp::downCast<Var_declarationContext *>(_localctx)->line =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine();
              writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON \n");
              if(antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->act_text == "void")
              {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": Variable type cannot be void " + "\n");
                  writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": Variable type cannot be void " + "\n"); 
                  
              }else
                  insertVarDeclarations(antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->act_text, antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->act_text);
              writeIntoparserLogFile(_localctx->act_text);
            
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(172);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(173);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->de = declaration_list_err();
      setState(174);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C8086Parser::SEMICOLON);

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

C8086Parser::Declaration_list_errContext::Declaration_list_errContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C8086Parser::Declaration_list_errContext::getRuleIndex() const {
  return C8086Parser::RuleDeclaration_list_err;
}

void C8086Parser::Declaration_list_errContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list_err(this);
}

void C8086Parser::Declaration_list_errContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list_err(this);
}

C8086Parser::Declaration_list_errContext* C8086Parser::declaration_list_err() {
  Declaration_list_errContext *_localctx = _tracker.createInstance<Declaration_list_errContext>(_ctx, getState());
  enterRule(_localctx, 18, C8086Parser::RuleDeclaration_list_err);

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

C8086Parser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Type_specifierContext::INT() {
  return getToken(C8086Parser::INT, 0);
}

tree::TerminalNode* C8086Parser::Type_specifierContext::FLOAT() {
  return getToken(C8086Parser::FLOAT, 0);
}

tree::TerminalNode* C8086Parser::Type_specifierContext::VOID() {
  return getToken(C8086Parser::VOID, 0);
}


size_t C8086Parser::Type_specifierContext::getRuleIndex() const {
  return C8086Parser::RuleType_specifier;
}

void C8086Parser::Type_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_specifier(this);
}

void C8086Parser::Type_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_specifier(this);
}

C8086Parser::Type_specifierContext* C8086Parser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 20, C8086Parser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(187);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(181);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken = match(C8086Parser::INT);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->act_text =  _localctx->getText();
                    writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getLine()) + ": type_specifier : INT \n\nint \n");
                
        break;
      }

      case C8086Parser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(183);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken = match(C8086Parser::FLOAT);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->act_text =  _localctx->getText();
                     writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getLine()) + ": type_specifier : FLOAT \n\nfloat \n");
                
        break;
      }

      case C8086Parser::VOID: {
        enterOuterAlt(_localctx, 3);
        setState(185);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken = match(C8086Parser::VOID);

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

C8086Parser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Declaration_listContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::LTHIRD() {
  return getToken(C8086Parser::LTHIRD, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::CONST_INT() {
  return getToken(C8086Parser::CONST_INT, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::RTHIRD() {
  return getToken(C8086Parser::RTHIRD, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::COMMA() {
  return getToken(C8086Parser::COMMA, 0);
}

C8086Parser::Declaration_listContext* C8086Parser::Declaration_listContext::declaration_list() {
  return getRuleContext<C8086Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::ADDOP() {
  return getToken(C8086Parser::ADDOP, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::SUBOP() {
  return getToken(C8086Parser::SUBOP, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::MULOP() {
  return getToken(C8086Parser::MULOP, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::INCOP() {
  return getToken(C8086Parser::INCOP, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::DECOP() {
  return getToken(C8086Parser::DECOP, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::NOT() {
  return getToken(C8086Parser::NOT, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::RELOP() {
  return getToken(C8086Parser::RELOP, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::LOGICOP() {
  return getToken(C8086Parser::LOGICOP, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::ASSIGNOP() {
  return getToken(C8086Parser::ASSIGNOP, 0);
}


size_t C8086Parser::Declaration_listContext::getRuleIndex() const {
  return C8086Parser::RuleDeclaration_list;
}

void C8086Parser::Declaration_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list(this);
}

void C8086Parser::Declaration_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list(this);
}


C8086Parser::Declaration_listContext* C8086Parser::declaration_list() {
   return declaration_list(0);
}

C8086Parser::Declaration_listContext* C8086Parser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  C8086Parser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, C8086Parser::RuleDeclaration_list, precedence);

    

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
    setState(197);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(190);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);
       
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
      setState(192);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(193);
      match(C8086Parser::LTHIRD);
      setState(194);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C8086Parser::CONST_INT);
      setState(195);
      match(C8086Parser::RTHIRD);
       
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
    setState(242);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(240);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(199);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(200);
          match(C8086Parser::COMMA);
          setState(201);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);
           
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
          setState(203);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(204);
          match(C8086Parser::COMMA);
          setState(205);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);
          setState(206);
          match(C8086Parser::LTHIRD);
          setState(207);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C8086Parser::CONST_INT);
          setState(208);
          match(C8086Parser::RTHIRD);
           
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
          setState(210);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(211);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken = match(C8086Parser::ADDOP);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(213);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(214);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": syntax error, unexpected ID, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": syntax error, unexpected ID, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(216);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(217);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->subopToken = match(C8086Parser::SUBOP);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->subopToken->getLine()) + ": syntax error, unexpected SUBOP, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->subopToken->getLine()) + ": syntax error, unexpected SUBOP, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(219);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(220);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->mulopToken = match(C8086Parser::MULOP);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->mulopToken->getLine()) + ": syntax error, unexpected MULOP, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->mulopToken->getLine()) + ": syntax error, unexpected MULOP, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(222);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(223);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->incopToken = match(C8086Parser::INCOP);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->incopToken->getLine()) + ": syntax error, unexpected INCOP, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->incopToken->getLine()) + ": syntax error, unexpected INCOP, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(225);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(226);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->decopToken = match(C8086Parser::DECOP);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->decopToken->getLine()) + ": syntax error, unexpected DECOP, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->decopToken->getLine()) + ": syntax error, unexpected DECOP, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(228);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(229);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->notToken = match(C8086Parser::NOT);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->notToken->getLine()) + ": syntax error, unexpected NOT, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->notToken->getLine()) + ": syntax error, unexpected NOT, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(231);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(232);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->relopToken = match(C8086Parser::RELOP);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->relopToken->getLine()) + ": syntax error, unexpected RELOP, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->relopToken->getLine()) + ": syntax error, unexpected RELOP, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(234);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(235);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->logicopToken = match(C8086Parser::LOGICOP);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->logicopToken->getLine()) + ": syntax error, unexpected LOGICOP, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->logicopToken->getLine()) + ": syntax error, unexpected LOGICOP, expecting COMMA or SEMICOLON");
                          
          break;
        }

        case 12: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(237);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(238);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->assignopToken = match(C8086Parser::ASSIGNOP);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->act_text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->act_text;
                            writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->assignopToken->getLine()) + ": syntax error, unexpected ASSIGNOP, expecting COMMA or SEMICOLON");
                            writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->assignopToken->getLine()) + ": syntax error, unexpected ASSIGNOP, expecting COMMA or SEMICOLON");
                          
          break;
        }

        default:
          break;
        } 
      }
      setState(244);
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

C8086Parser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::StatementContext* C8086Parser::StatementsContext::statement() {
  return getRuleContext<C8086Parser::StatementContext>(0);
}

C8086Parser::StatementsContext* C8086Parser::StatementsContext::statements() {
  return getRuleContext<C8086Parser::StatementsContext>(0);
}


size_t C8086Parser::StatementsContext::getRuleIndex() const {
  return C8086Parser::RuleStatements;
}

void C8086Parser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void C8086Parser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}


C8086Parser::StatementsContext* C8086Parser::statements() {
   return statements(0);
}

C8086Parser::StatementsContext* C8086Parser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  C8086Parser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, C8086Parser::RuleStatements, precedence);

    

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
    setState(246);
    antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

            antlrcpp::downCast<StatementsContext *>(_localctx)->act_text =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->act_text;
            writeIntoparserLogFile("Line " + to_string((antlrcpp::downCast<StatementsContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementsContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statements : statement\n\n" + _localctx->act_text + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(255);
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
        setState(249);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(250);
        antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

                          antlrcpp::downCast<StatementsContext *>(_localctx)->act_text =  antlrcpp::downCast<StatementsContext *>(_localctx)->ss->act_text + antlrcpp::downCast<StatementsContext *>(_localctx)->s->act_text;
                          writeIntoparserLogFile("Line " + to_string((antlrcpp::downCast<StatementsContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementsContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statements : statements statement\n\n" + _localctx->act_text + "\n");
                       
      }
      setState(257);
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

C8086Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Var_declarationContext* C8086Parser::StatementContext::var_declaration() {
  return getRuleContext<C8086Parser::Var_declarationContext>(0);
}

std::vector<C8086Parser::Expression_statementContext *> C8086Parser::StatementContext::expression_statement() {
  return getRuleContexts<C8086Parser::Expression_statementContext>();
}

C8086Parser::Expression_statementContext* C8086Parser::StatementContext::expression_statement(size_t i) {
  return getRuleContext<C8086Parser::Expression_statementContext>(i);
}

C8086Parser::Compound_statementContext* C8086Parser::StatementContext::compound_statement() {
  return getRuleContext<C8086Parser::Compound_statementContext>(0);
}

tree::TerminalNode* C8086Parser::StatementContext::FOR() {
  return getToken(C8086Parser::FOR, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

C8086Parser::ExpressionContext* C8086Parser::StatementContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}

std::vector<C8086Parser::StatementContext *> C8086Parser::StatementContext::statement() {
  return getRuleContexts<C8086Parser::StatementContext>();
}

C8086Parser::StatementContext* C8086Parser::StatementContext::statement(size_t i) {
  return getRuleContext<C8086Parser::StatementContext>(i);
}

tree::TerminalNode* C8086Parser::StatementContext::IF() {
  return getToken(C8086Parser::IF, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::ELSE() {
  return getToken(C8086Parser::ELSE, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::WHILE() {
  return getToken(C8086Parser::WHILE, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::PRINTLN() {
  return getToken(C8086Parser::PRINTLN, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::RETURN() {
  return getToken(C8086Parser::RETURN, 0);
}


size_t C8086Parser::StatementContext::getRuleIndex() const {
  return C8086Parser::RuleStatement;
}

void C8086Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void C8086Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

C8086Parser::StatementContext* C8086Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 26, C8086Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(310);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(258);
      antlrcpp::downCast<StatementContext *>(_localctx)->vd = var_declaration();

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  antlrcpp::downCast<StatementContext *>(_localctx)->vd->act_text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->vd->line;
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": statement : var_declaration\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(261);
      antlrcpp::downCast<StatementContext *>(_localctx)->es = expression_statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  antlrcpp::downCast<StatementContext *>(_localctx)->es->act_text +"\n";
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->es->line;
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": statement : expression_statement\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(264);
      antlrcpp::downCast<StatementContext *>(_localctx)->cs = compound_statement(true);

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  antlrcpp::downCast<StatementContext *>(_localctx)->cs->act_text;
              writeIntoparserLogFile("Line " + to_string((antlrcpp::downCast<StatementContext *>(_localctx)->cs != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->cs->stop) : nullptr)->getLine()) + ": statement : compound_statement\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(267);
      match(C8086Parser::FOR);
      setState(268);
      match(C8086Parser::LPAREN);
      setState(269);
      antlrcpp::downCast<StatementContext *>(_localctx)->es1 = expression_statement();
      setState(270);
      antlrcpp::downCast<StatementContext *>(_localctx)->es2 = expression_statement();
      setState(271);
      antlrcpp::downCast<StatementContext *>(_localctx)->e1 = expression();
      setState(272);
      match(C8086Parser::RPAREN);
      setState(273);
      antlrcpp::downCast<StatementContext *>(_localctx)->s1 = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  "for(" + antlrcpp::downCast<StatementContext *>(_localctx)->es1->act_text + antlrcpp::downCast<StatementContext *>(_localctx)->es2->act_text + antlrcpp::downCast<StatementContext *>(_localctx)->e1->act_text + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->s1->act_text ;
              writeIntoparserLogFile("Line " + to_string((antlrcpp::downCast<StatementContext *>(_localctx)->s1 != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->s1->stop) : nullptr)->getLine()) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(276);
      match(C8086Parser::IF);
      setState(277);
      match(C8086Parser::LPAREN);
      setState(278);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(279);
      match(C8086Parser::RPAREN);
      setState(280);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  "if (" + antlrcpp::downCast<StatementContext *>(_localctx)->e->act_text + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->s->act_text ;
              writeIntoparserLogFile("Line " + to_string((antlrcpp::downCast<StatementContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statement : IF LPAREN expression RPAREN statement\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(283);
      match(C8086Parser::IF);
      setState(284);
      match(C8086Parser::LPAREN);
      setState(285);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(286);
      match(C8086Parser::RPAREN);
      setState(287);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();
      setState(288);
      match(C8086Parser::ELSE);
      setState(289);
      antlrcpp::downCast<StatementContext *>(_localctx)->s1 = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  "if (" + antlrcpp::downCast<StatementContext *>(_localctx)->e->act_text + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->s->act_text + "else\n" + antlrcpp::downCast<StatementContext *>(_localctx)->s1->act_text;
              writeIntoparserLogFile("Line " + to_string((antlrcpp::downCast<StatementContext *>(_localctx)->s1 != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->s1->stop) : nullptr)->getLine()) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(292);
      match(C8086Parser::WHILE);
      setState(293);
      match(C8086Parser::LPAREN);
      setState(294);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(295);
      match(C8086Parser::RPAREN);
      setState(296);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  "while (" + antlrcpp::downCast<StatementContext *>(_localctx)->e->act_text + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->s->act_text;
              writeIntoparserLogFile("Line " + to_string((antlrcpp::downCast<StatementContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(299);
      antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken = match(C8086Parser::PRINTLN);
      setState(300);
      match(C8086Parser::LPAREN);
      setState(301);
      antlrcpp::downCast<StatementContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(302);
      match(C8086Parser::RPAREN);
      setState(303);
      match(C8086Parser::SEMICOLON);

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  _localctx->getText()+"\n";
              writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
              if(!Table.getCurrentScopeTable()->lookup(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText()))
              {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine()) + ": Undeclared variable " + antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() + "\n");
                  writeIntoparserLogFile("Error at line " + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine()) + ": Undeclared variable " + antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() + "\n");
              }
              writeIntoparserLogFile(_localctx->act_text + "\n");
          
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(305);
      antlrcpp::downCast<StatementContext *>(_localctx)->returnToken = match(C8086Parser::RETURN);
      setState(306);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(307);
      antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

              antlrcpp::downCast<StatementContext *>(_localctx)->act_text =  "return " + antlrcpp::downCast<StatementContext *>(_localctx)->e->act_text + ";\n";
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken->getLine();
              writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getLine()) + ": statement : RETURN expression SEMICOLON\n\n" + _localctx->act_text + "\n");
          
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

C8086Parser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Expression_statementContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

C8086Parser::ExpressionContext* C8086Parser::Expression_statementContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}

tree::TerminalNode* C8086Parser::Expression_statementContext::ANY() {
  return getToken(C8086Parser::ANY, 0);
}


size_t C8086Parser::Expression_statementContext::getRuleIndex() const {
  return C8086Parser::RuleExpression_statement;
}

void C8086Parser::Expression_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_statement(this);
}

void C8086Parser::Expression_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_statement(this);
}

C8086Parser::Expression_statementContext* C8086Parser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 28, C8086Parser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(322);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(312);
      antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

              antlrcpp::downCast<Expression_statementContext *>(_localctx)->act_text =  _localctx->getText();
              antlrcpp::downCast<Expression_statementContext *>(_localctx)->line =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine();
              writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine()) + ": expression_statement : SEMICOLON\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(314);
      expression();
      setState(315);
      antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

              antlrcpp::downCast<Expression_statementContext *>(_localctx)->act_text =  _localctx->getText();
              antlrcpp::downCast<Expression_statementContext *>(_localctx)->line =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine();
              writeIntoparserLogFile("Line " + to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine()) + ": expression_statement : expression SEMICOLON\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(318);
      expression();
      setState(319);
      antlrcpp::downCast<Expression_statementContext *>(_localctx)->a = match(C8086Parser::ANY);

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

C8086Parser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::VariableContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::VariableContext::LTHIRD() {
  return getToken(C8086Parser::LTHIRD, 0);
}

tree::TerminalNode* C8086Parser::VariableContext::RTHIRD() {
  return getToken(C8086Parser::RTHIRD, 0);
}

C8086Parser::ExpressionContext* C8086Parser::VariableContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}


size_t C8086Parser::VariableContext::getRuleIndex() const {
  return C8086Parser::RuleVariable;
}

void C8086Parser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void C8086Parser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

C8086Parser::VariableContext* C8086Parser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 30, C8086Parser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(332);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(324);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C8086Parser::ID);

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
      setState(326);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(327);
      match(C8086Parser::LTHIRD);
      setState(328);
      antlrcpp::downCast<VariableContext *>(_localctx)->e = expression();
      setState(329);
      match(C8086Parser::RTHIRD);

              antlrcpp::downCast<VariableContext *>(_localctx)->act_text =  _localctx->getText();
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

C8086Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Logic_expressionContext* C8086Parser::ExpressionContext::logic_expression() {
  return getRuleContext<C8086Parser::Logic_expressionContext>(0);
}

tree::TerminalNode* C8086Parser::ExpressionContext::ASSIGNOP() {
  return getToken(C8086Parser::ASSIGNOP, 0);
}

C8086Parser::VariableContext* C8086Parser::ExpressionContext::variable() {
  return getRuleContext<C8086Parser::VariableContext>(0);
}


size_t C8086Parser::ExpressionContext::getRuleIndex() const {
  return C8086Parser::RuleExpression;
}

void C8086Parser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void C8086Parser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

C8086Parser::ExpressionContext* C8086Parser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 32, C8086Parser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(342);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(334);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->l = logic_expression();


              antlrcpp::downCast<ExpressionContext *>(_localctx)->act_text =  _localctx->getText();
              antlrcpp::downCast<ExpressionContext *>(_localctx)->type =  antlrcpp::downCast<ExpressionContext *>(_localctx)->l->type ;
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": expression : logic expression\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(337);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->v = variable();
      setState(338);
      match(C8086Parser::ASSIGNOP);
      setState(339);
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

C8086Parser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C8086Parser::Rel_expressionContext *> C8086Parser::Logic_expressionContext::rel_expression() {
  return getRuleContexts<C8086Parser::Rel_expressionContext>();
}

C8086Parser::Rel_expressionContext* C8086Parser::Logic_expressionContext::rel_expression(size_t i) {
  return getRuleContext<C8086Parser::Rel_expressionContext>(i);
}

tree::TerminalNode* C8086Parser::Logic_expressionContext::LOGICOP() {
  return getToken(C8086Parser::LOGICOP, 0);
}


size_t C8086Parser::Logic_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleLogic_expression;
}

void C8086Parser::Logic_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_expression(this);
}

void C8086Parser::Logic_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_expression(this);
}

C8086Parser::Logic_expressionContext* C8086Parser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 34, C8086Parser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(352);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(344);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r = rel_expression();

              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->act_text =  _localctx->getText();
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->type ;
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": logic_expression : rel_expression\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(347);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r = rel_expression();
      setState(348);
      match(C8086Parser::LOGICOP);
      setState(349);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1 = rel_expression();

              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->act_text =  _localctx->getText();
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->type =  "int" ;
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": logic_expression : rel_expression LOGICOP rel_expression\n\n" + _localctx->act_text + "\n");
          
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

C8086Parser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C8086Parser::Simple_expressionContext *> C8086Parser::Rel_expressionContext::simple_expression() {
  return getRuleContexts<C8086Parser::Simple_expressionContext>();
}

C8086Parser::Simple_expressionContext* C8086Parser::Rel_expressionContext::simple_expression(size_t i) {
  return getRuleContext<C8086Parser::Simple_expressionContext>(i);
}

tree::TerminalNode* C8086Parser::Rel_expressionContext::RELOP() {
  return getToken(C8086Parser::RELOP, 0);
}


size_t C8086Parser::Rel_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleRel_expression;
}

void C8086Parser::Rel_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_expression(this);
}

void C8086Parser::Rel_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_expression(this);
}

C8086Parser::Rel_expressionContext* C8086Parser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 36, C8086Parser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(362);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(354);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s = simple_expression(0);

              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->act_text =  _localctx->getText();
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->type ;
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": rel_expression : simple_expression\n\n" + _localctx->act_text + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(357);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s = simple_expression(0);
      setState(358);
      match(C8086Parser::RELOP);
      setState(359);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s1 = simple_expression(0);

              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->act_text =  _localctx->getText();
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->type =  "int" ;
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": rel_expression : simple_expression RELOP simple_expression\n\n" + _localctx->act_text + "\n");
          
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

C8086Parser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::TermContext* C8086Parser::Simple_expressionContext::term() {
  return getRuleContext<C8086Parser::TermContext>(0);
}

tree::TerminalNode* C8086Parser::Simple_expressionContext::ADDOP() {
  return getToken(C8086Parser::ADDOP, 0);
}

C8086Parser::Simple_expressionContext* C8086Parser::Simple_expressionContext::simple_expression() {
  return getRuleContext<C8086Parser::Simple_expressionContext>(0);
}

tree::TerminalNode* C8086Parser::Simple_expressionContext::ASSIGNOP() {
  return getToken(C8086Parser::ASSIGNOP, 0);
}


size_t C8086Parser::Simple_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleSimple_expression;
}

void C8086Parser::Simple_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression(this);
}

void C8086Parser::Simple_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression(this);
}


C8086Parser::Simple_expressionContext* C8086Parser::simple_expression() {
   return simple_expression(0);
}

C8086Parser::Simple_expressionContext* C8086Parser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  C8086Parser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, C8086Parser::RuleSimple_expression, precedence);

    

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
    setState(365);
    antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->act_text =  _localctx->getText();
            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->type ;
            writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": simple_expression : term\n\n" + _localctx->act_text + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(381);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(379);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
          _localctx->s = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
          setState(368);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(369);
          match(C8086Parser::ADDOP);
          setState(370);
          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->act_text =  _localctx->getText();
                            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->type ;
                            if(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->type == "float" || antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->type == "float")
                                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  "float";
                            writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": simple_expression : simple_expression ADDOP term\n\n" + _localctx->act_text + "\n");
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
          _localctx->s = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
          setState(373);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(374);
          match(C8086Parser::ADDOP);
          setState(375);
          match(C8086Parser::ASSIGNOP);
          setState(376);
          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                            writeIntoErrorFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": syntax error, unexpected ASSIGNOP\n");
                            writeIntoparserLogFile("Error at line " + to_string(_localctx->getStart()->getLine()) + ": syntax error, unexpected ASSIGNOP\n");
                        
          break;
        }

        default:
          break;
        } 
      }
      setState(383);
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

C8086Parser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Unary_expressionContext* C8086Parser::TermContext::unary_expression() {
  return getRuleContext<C8086Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C8086Parser::TermContext::MULOP() {
  return getToken(C8086Parser::MULOP, 0);
}

C8086Parser::TermContext* C8086Parser::TermContext::term() {
  return getRuleContext<C8086Parser::TermContext>(0);
}


size_t C8086Parser::TermContext::getRuleIndex() const {
  return C8086Parser::RuleTerm;
}

void C8086Parser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void C8086Parser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


C8086Parser::TermContext* C8086Parser::term() {
   return term(0);
}

C8086Parser::TermContext* C8086Parser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  C8086Parser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, C8086Parser::RuleTerm, precedence);

    

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
    setState(385);
    antlrcpp::downCast<TermContext *>(_localctx)->u = unary_expression();
     antlrcpp::downCast<TermContext *>(_localctx)->act_text =  _localctx->getText() ; antlrcpp::downCast<TermContext *>(_localctx)->type =  antlrcpp::downCast<TermContext *>(_localctx)->u->type ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": term : unary_expression \n\n" + _localctx->getText() + "\n");
    		
    _ctx->stop = _input->LT(-1);
    setState(395);
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
        setState(388);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(389);
        antlrcpp::downCast<TermContext *>(_localctx)->mulopToken = match(C8086Parser::MULOP);
        setState(390);
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
                  	 
      }
      setState(397);
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

C8086Parser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Unary_expressionContext::ADDOP() {
  return getToken(C8086Parser::ADDOP, 0);
}

C8086Parser::Unary_expressionContext* C8086Parser::Unary_expressionContext::unary_expression() {
  return getRuleContext<C8086Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C8086Parser::Unary_expressionContext::NOT() {
  return getToken(C8086Parser::NOT, 0);
}

C8086Parser::FactorContext* C8086Parser::Unary_expressionContext::factor() {
  return getRuleContext<C8086Parser::FactorContext>(0);
}


size_t C8086Parser::Unary_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleUnary_expression;
}

void C8086Parser::Unary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expression(this);
}

void C8086Parser::Unary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expression(this);
}

C8086Parser::Unary_expressionContext* C8086Parser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 42, C8086Parser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(409);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(398);
        match(C8086Parser::ADDOP);
        setState(399);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->u = unary_expression();
         antlrcpp::downCast<Unary_expressionContext *>(_localctx)->act_text =  _localctx->getText() ; antlrcpp::downCast<Unary_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->u->type ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": unary_expression : ADDOP unary_expression \n\n" + _localctx->getText() + "\n");
        		
        break;
      }

      case C8086Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(402);
        match(C8086Parser::NOT);
        setState(403);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->u = unary_expression();
         antlrcpp::downCast<Unary_expressionContext *>(_localctx)->act_text =  _localctx->getText() ; antlrcpp::downCast<Unary_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->u->type ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": unary_expression : NOT unary expression \n\n" + _localctx->getText() + "\n");
        		
        break;
      }

      case C8086Parser::LPAREN:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(406);
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

C8086Parser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::VariableContext* C8086Parser::FactorContext::variable() {
  return getRuleContext<C8086Parser::VariableContext>(0);
}

tree::TerminalNode* C8086Parser::FactorContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

C8086Parser::Argument_listContext* C8086Parser::FactorContext::argument_list() {
  return getRuleContext<C8086Parser::Argument_listContext>(0);
}

C8086Parser::ExpressionContext* C8086Parser::FactorContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}

tree::TerminalNode* C8086Parser::FactorContext::CONST_INT() {
  return getToken(C8086Parser::CONST_INT, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::CONST_FLOAT() {
  return getToken(C8086Parser::CONST_FLOAT, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::INCOP() {
  return getToken(C8086Parser::INCOP, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::DECOP() {
  return getToken(C8086Parser::DECOP, 0);
}


size_t C8086Parser::FactorContext::getRuleIndex() const {
  return C8086Parser::RuleFactor;
}

void C8086Parser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void C8086Parser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}

C8086Parser::FactorContext* C8086Parser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 44, C8086Parser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(437);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(411);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
       
              antlrcpp::downCast<FactorContext *>(_localctx)->act_text =  _localctx->getText() ;
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->v->type;
              writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : variable \n\n" + _localctx->getText() + "\n");
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(414);
      antlrcpp::downCast<FactorContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(415);
      match(C8086Parser::LPAREN);
      setState(416);
      antlrcpp::downCast<FactorContext *>(_localctx)->a = argument_list();
      setState(417);
      match(C8086Parser::RPAREN);
       
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
      	
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(420);
      match(C8086Parser::LPAREN);
      setState(421);
      antlrcpp::downCast<FactorContext *>(_localctx)->e = expression();
      setState(422);
      match(C8086Parser::RPAREN);
       antlrcpp::downCast<FactorContext *>(_localctx)->act_text =  _localctx->getText() ; antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->e->type; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : LPAREN expression RPAREN \n\n" + _localctx->getText() + "\n");
      	
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(425);
      match(C8086Parser::CONST_INT);
       antlrcpp::downCast<FactorContext *>(_localctx)->act_text =  _localctx->getText() ; antlrcpp::downCast<FactorContext *>(_localctx)->type =  "int" ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : CONST_INT \n\n" + _localctx->getText() + "\n");
      	
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(427);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken = match(C8086Parser::CONST_FLOAT);
       antlrcpp::downCast<FactorContext *>(_localctx)->act_text =  _localctx->getText() ; antlrcpp::downCast<FactorContext *>(_localctx)->type =  "float" ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : CONST_FLOAT  \n\n" + antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getText() + "\n");
      	
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(429);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(430);
      match(C8086Parser::INCOP);
       antlrcpp::downCast<FactorContext *>(_localctx)->act_text =  _localctx->getText() ; antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->v->type ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : variable INCOP \n\n" + _localctx->getText() + "\n");
      	
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(433);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(434);
      match(C8086Parser::DECOP);
       antlrcpp::downCast<FactorContext *>(_localctx)->act_text =  _localctx->getText() ; antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->v->type ; writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": factor : variable DECOP \n\n" + _localctx->getText() + "\n");
      	
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

C8086Parser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::ArgumentsContext* C8086Parser::Argument_listContext::arguments() {
  return getRuleContext<C8086Parser::ArgumentsContext>(0);
}


size_t C8086Parser::Argument_listContext::getRuleIndex() const {
  return C8086Parser::RuleArgument_list;
}

void C8086Parser::Argument_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument_list(this);
}

void C8086Parser::Argument_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument_list(this);
}

C8086Parser::Argument_listContext* C8086Parser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 46, C8086Parser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(443);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::LPAREN:
      case C8086Parser::ADDOP:
      case C8086Parser::NOT:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(439);
        antlrcpp::downCast<Argument_listContext *>(_localctx)->a = arguments(0);

                 antlrcpp::downCast<Argument_listContext *>(_localctx)->act_text =  _localctx->getText() ;
                 antlrcpp::downCast<Argument_listContext *>(_localctx)->types =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->types;
                  writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": argument_list : arguments \n\n" + _localctx->getText() + "\n");
        		
        break;
      }

      case C8086Parser::RPAREN: {
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

C8086Parser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Logic_expressionContext* C8086Parser::ArgumentsContext::logic_expression() {
  return getRuleContext<C8086Parser::Logic_expressionContext>(0);
}

tree::TerminalNode* C8086Parser::ArgumentsContext::COMMA() {
  return getToken(C8086Parser::COMMA, 0);
}

C8086Parser::ArgumentsContext* C8086Parser::ArgumentsContext::arguments() {
  return getRuleContext<C8086Parser::ArgumentsContext>(0);
}


size_t C8086Parser::ArgumentsContext::getRuleIndex() const {
  return C8086Parser::RuleArguments;
}

void C8086Parser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void C8086Parser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


C8086Parser::ArgumentsContext* C8086Parser::arguments() {
   return arguments(0);
}

C8086Parser::ArgumentsContext* C8086Parser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  C8086Parser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, C8086Parser::RuleArguments, precedence);

    

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
    setState(446);
    antlrcpp::downCast<ArgumentsContext *>(_localctx)->l = logic_expression();
     
            antlrcpp::downCast<ArgumentsContext *>(_localctx)->act_text =  _localctx->getText() ;
            _localctx->types.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->type);
             writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": arguments : logic_expression \n\n" + _localctx->getText() + "\n");
    		
    _ctx->stop = _input->LT(-1);
    setState(456);
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
        setState(449);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(450);
        match(C8086Parser::COMMA);
        setState(451);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->l = logic_expression();
         
                          antlrcpp::downCast<ArgumentsContext *>(_localctx)->act_text =  _localctx->getText() ;
                          antlrcpp::downCast<ArgumentsContext *>(_localctx)->types =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->types;
                          _localctx->types.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->type);
                          writeIntoparserLogFile("Line " + to_string(_localctx->getStart()->getLine()) + ": arguments : arguments COMMA logic_expression \n\n" + _localctx->getText() + "\n");
                  	 
      }
      setState(458);
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

bool C8086Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
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

bool C8086Parser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool C8086Parser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool C8086Parser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
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

bool C8086Parser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 15: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C8086Parser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 16: return precpred(_ctx, 2);
    case 17: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C8086Parser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 18: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C8086Parser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 19: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void C8086Parser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c8086parserParserInitialize();
#else
  ::antlr4::internal::call_once(c8086parserParserOnceFlag, c8086parserParserInitialize);
#endif
}
