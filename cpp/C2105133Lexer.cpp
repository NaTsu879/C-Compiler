
    #pragma once
    #include <iostream>
    #include <fstream>
    #include <string>

    extern std::ofstream lexLogFile;


// Generated from C2105133Lexer.g4 by ANTLR 4.13.2


#include "C2105133Lexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct C2105133LexerStaticData final {
  C2105133LexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C2105133LexerStaticData(const C2105133LexerStaticData&) = delete;
  C2105133LexerStaticData(C2105133LexerStaticData&&) = delete;
  C2105133LexerStaticData& operator=(const C2105133LexerStaticData&) = delete;
  C2105133LexerStaticData& operator=(C2105133LexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c2105133lexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C2105133LexerStaticData> c2105133lexerLexerStaticData = nullptr;

void c2105133lexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c2105133lexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(c2105133lexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C2105133LexerStaticData>(
    std::vector<std::string>{
      "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", "FOR", 
      "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "FORIN", "FOREACH", 
      "IN", "TO", "TIMES", "SWITCH", "CASE", "BREAK", "DEFAULT", "WHEN", 
      "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", 
      "COMMA", "QUES", "COLON", "ARROW", "ADDOP", "SUBOP", "MULOP", "INCOP", 
      "DECOP", "NOT", "RELOP", "LOGICOP", "ASSIGNOP", "ID", "CONST_INT", 
      "CONST_FLOAT", "ANY"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,47,431,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,1,0,1,0,1,0,1,0,5,0,100,
  	8,0,10,0,12,0,103,9,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,5,1,114,8,1,
  	10,1,12,1,117,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,5,2,130,
  	8,2,10,2,12,2,133,9,2,1,2,1,2,1,2,1,2,1,2,1,3,4,3,141,8,3,11,3,12,3,142,
  	1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,
  	10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,
  	12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,16,1,16,1,
  	16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,
  	18,1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,20,1,
  	20,1,20,1,20,1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,
  	21,1,21,1,21,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,23,1,23,1,23,1,24,1,
  	24,1,24,1,25,1,25,1,25,1,26,1,26,1,26,1,27,1,27,1,27,1,28,1,28,1,28,1,
  	29,1,29,1,29,1,30,1,30,1,30,1,31,1,31,1,31,1,32,1,32,1,32,1,33,1,33,1,
  	33,1,33,1,33,1,34,1,34,1,34,1,35,1,35,1,35,1,36,1,36,1,36,1,37,1,37,1,
  	37,1,37,1,37,1,38,1,38,1,38,1,38,1,38,1,39,1,39,1,39,1,40,1,40,1,40,1,
  	40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,3,40,358,8,40,1,41,1,41,1,41,1,
  	41,1,41,1,41,3,41,366,8,41,1,42,1,42,1,42,1,43,1,43,5,43,373,8,43,10,
  	43,12,43,376,9,43,1,43,1,43,1,44,4,44,381,8,44,11,44,12,44,382,1,44,1,
  	44,1,45,4,45,388,8,45,11,45,12,45,389,1,45,1,45,5,45,394,8,45,10,45,12,
  	45,397,9,45,3,45,399,8,45,1,45,1,45,3,45,403,8,45,1,45,4,45,406,8,45,
  	11,45,12,45,407,3,45,410,8,45,1,45,1,45,1,45,4,45,415,8,45,11,45,12,45,
  	416,1,45,1,45,4,45,421,8,45,11,45,12,45,422,1,45,1,45,3,45,427,8,45,1,
  	46,1,46,1,46,1,115,0,47,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,
  	21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,
  	22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,
  	67,34,69,35,71,36,73,37,75,38,77,39,79,40,81,41,83,42,85,43,87,44,89,
  	45,91,46,93,47,1,0,10,2,0,10,10,13,13,4,0,10,10,13,13,34,34,92,92,3,0,
  	9,10,12,13,32,32,2,0,43,43,45,45,3,0,37,37,42,42,47,47,2,0,60,60,62,62,
  	3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,1,0,48,57,2,0,69,
  	69,101,101,453,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,
  	0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,
  	0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,
  	31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,
  	0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,
  	0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,
  	63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,
  	0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,
  	0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,91,1,0,0,0,0,93,1,0,0,0,1,
  	95,1,0,0,0,3,108,1,0,0,0,5,125,1,0,0,0,7,140,1,0,0,0,9,146,1,0,0,0,11,
  	151,1,0,0,0,13,158,1,0,0,0,15,164,1,0,0,0,17,172,1,0,0,0,19,182,1,0,0,
  	0,21,191,1,0,0,0,23,197,1,0,0,0,25,205,1,0,0,0,27,212,1,0,0,0,29,220,
  	1,0,0,0,31,230,1,0,0,0,33,235,1,0,0,0,35,240,1,0,0,0,37,248,1,0,0,0,39,
  	257,1,0,0,0,41,264,1,0,0,0,43,272,1,0,0,0,45,282,1,0,0,0,47,289,1,0,0,
  	0,49,292,1,0,0,0,51,295,1,0,0,0,53,298,1,0,0,0,55,301,1,0,0,0,57,304,
  	1,0,0,0,59,307,1,0,0,0,61,310,1,0,0,0,63,313,1,0,0,0,65,316,1,0,0,0,67,
  	319,1,0,0,0,69,324,1,0,0,0,71,327,1,0,0,0,73,330,1,0,0,0,75,333,1,0,0,
  	0,77,338,1,0,0,0,79,343,1,0,0,0,81,357,1,0,0,0,83,365,1,0,0,0,85,367,
  	1,0,0,0,87,370,1,0,0,0,89,380,1,0,0,0,91,426,1,0,0,0,93,428,1,0,0,0,95,
  	96,5,47,0,0,96,97,5,47,0,0,97,101,1,0,0,0,98,100,8,0,0,0,99,98,1,0,0,
  	0,100,103,1,0,0,0,101,99,1,0,0,0,101,102,1,0,0,0,102,104,1,0,0,0,103,
  	101,1,0,0,0,104,105,6,0,0,0,105,106,1,0,0,0,106,107,6,0,1,0,107,2,1,0,
  	0,0,108,109,5,47,0,0,109,110,5,42,0,0,110,115,1,0,0,0,111,114,9,0,0,0,
  	112,114,7,0,0,0,113,111,1,0,0,0,113,112,1,0,0,0,114,117,1,0,0,0,115,116,
  	1,0,0,0,115,113,1,0,0,0,116,118,1,0,0,0,117,115,1,0,0,0,118,119,5,42,
  	0,0,119,120,5,47,0,0,120,121,1,0,0,0,121,122,6,1,2,0,122,123,1,0,0,0,
  	123,124,6,1,1,0,124,4,1,0,0,0,125,131,5,34,0,0,126,127,5,92,0,0,127,130,
  	9,0,0,0,128,130,8,1,0,0,129,126,1,0,0,0,129,128,1,0,0,0,130,133,1,0,0,
  	0,131,129,1,0,0,0,131,132,1,0,0,0,132,134,1,0,0,0,133,131,1,0,0,0,134,
  	135,5,34,0,0,135,136,6,2,3,0,136,137,1,0,0,0,137,138,6,2,1,0,138,6,1,
  	0,0,0,139,141,7,2,0,0,140,139,1,0,0,0,141,142,1,0,0,0,142,140,1,0,0,0,
  	142,143,1,0,0,0,143,144,1,0,0,0,144,145,6,3,1,0,145,8,1,0,0,0,146,147,
  	5,105,0,0,147,148,5,102,0,0,148,149,1,0,0,0,149,150,6,4,4,0,150,10,1,
  	0,0,0,151,152,5,101,0,0,152,153,5,108,0,0,153,154,5,115,0,0,154,155,5,
  	101,0,0,155,156,1,0,0,0,156,157,6,5,5,0,157,12,1,0,0,0,158,159,5,102,
  	0,0,159,160,5,111,0,0,160,161,5,114,0,0,161,162,1,0,0,0,162,163,6,6,6,
  	0,163,14,1,0,0,0,164,165,5,119,0,0,165,166,5,104,0,0,166,167,5,105,0,
  	0,167,168,5,108,0,0,168,169,5,101,0,0,169,170,1,0,0,0,170,171,6,7,7,0,
  	171,16,1,0,0,0,172,173,5,112,0,0,173,174,5,114,0,0,174,175,5,105,0,0,
  	175,176,5,110,0,0,176,177,5,116,0,0,177,178,5,108,0,0,178,179,5,110,0,
  	0,179,180,1,0,0,0,180,181,6,8,8,0,181,18,1,0,0,0,182,183,5,114,0,0,183,
  	184,5,101,0,0,184,185,5,116,0,0,185,186,5,117,0,0,186,187,5,114,0,0,187,
  	188,5,110,0,0,188,189,1,0,0,0,189,190,6,9,9,0,190,20,1,0,0,0,191,192,
  	5,105,0,0,192,193,5,110,0,0,193,194,5,116,0,0,194,195,1,0,0,0,195,196,
  	6,10,10,0,196,22,1,0,0,0,197,198,5,102,0,0,198,199,5,108,0,0,199,200,
  	5,111,0,0,200,201,5,97,0,0,201,202,5,116,0,0,202,203,1,0,0,0,203,204,
  	6,11,11,0,204,24,1,0,0,0,205,206,5,118,0,0,206,207,5,111,0,0,207,208,
  	5,105,0,0,208,209,5,100,0,0,209,210,1,0,0,0,210,211,6,12,12,0,211,26,
  	1,0,0,0,212,213,5,102,0,0,213,214,5,111,0,0,214,215,5,114,0,0,215,216,
  	5,105,0,0,216,217,5,110,0,0,217,218,1,0,0,0,218,219,6,13,13,0,219,28,
  	1,0,0,0,220,221,5,102,0,0,221,222,5,111,0,0,222,223,5,114,0,0,223,224,
  	5,101,0,0,224,225,5,97,0,0,225,226,5,99,0,0,226,227,5,104,0,0,227,228,
  	1,0,0,0,228,229,6,14,14,0,229,30,1,0,0,0,230,231,5,105,0,0,231,232,5,
  	110,0,0,232,233,1,0,0,0,233,234,6,15,15,0,234,32,1,0,0,0,235,236,5,116,
  	0,0,236,237,5,111,0,0,237,238,1,0,0,0,238,239,6,16,16,0,239,34,1,0,0,
  	0,240,241,5,116,0,0,241,242,5,105,0,0,242,243,5,109,0,0,243,244,5,101,
  	0,0,244,245,5,115,0,0,245,246,1,0,0,0,246,247,6,17,17,0,247,36,1,0,0,
  	0,248,249,5,115,0,0,249,250,5,119,0,0,250,251,5,105,0,0,251,252,5,116,
  	0,0,252,253,5,99,0,0,253,254,5,104,0,0,254,255,1,0,0,0,255,256,6,18,18,
  	0,256,38,1,0,0,0,257,258,5,99,0,0,258,259,5,97,0,0,259,260,5,115,0,0,
  	260,261,5,101,0,0,261,262,1,0,0,0,262,263,6,19,19,0,263,40,1,0,0,0,264,
  	265,5,98,0,0,265,266,5,114,0,0,266,267,5,101,0,0,267,268,5,97,0,0,268,
  	269,5,107,0,0,269,270,1,0,0,0,270,271,6,20,20,0,271,42,1,0,0,0,272,273,
  	5,100,0,0,273,274,5,101,0,0,274,275,5,102,0,0,275,276,5,97,0,0,276,277,
  	5,117,0,0,277,278,5,108,0,0,278,279,5,116,0,0,279,280,1,0,0,0,280,281,
  	6,21,21,0,281,44,1,0,0,0,282,283,5,119,0,0,283,284,5,104,0,0,284,285,
  	5,101,0,0,285,286,5,110,0,0,286,287,1,0,0,0,287,288,6,22,22,0,288,46,
  	1,0,0,0,289,290,5,40,0,0,290,291,6,23,23,0,291,48,1,0,0,0,292,293,5,41,
  	0,0,293,294,6,24,24,0,294,50,1,0,0,0,295,296,5,123,0,0,296,297,6,25,25,
  	0,297,52,1,0,0,0,298,299,5,125,0,0,299,300,6,26,26,0,300,54,1,0,0,0,301,
  	302,5,91,0,0,302,303,6,27,27,0,303,56,1,0,0,0,304,305,5,93,0,0,305,306,
  	6,28,28,0,306,58,1,0,0,0,307,308,5,59,0,0,308,309,6,29,29,0,309,60,1,
  	0,0,0,310,311,5,44,0,0,311,312,6,30,30,0,312,62,1,0,0,0,313,314,5,63,
  	0,0,314,315,6,31,31,0,315,64,1,0,0,0,316,317,5,58,0,0,317,318,6,32,32,
  	0,318,66,1,0,0,0,319,320,5,45,0,0,320,321,5,62,0,0,321,322,1,0,0,0,322,
  	323,6,33,33,0,323,68,1,0,0,0,324,325,7,3,0,0,325,326,6,34,34,0,326,70,
  	1,0,0,0,327,328,7,3,0,0,328,329,6,35,35,0,329,72,1,0,0,0,330,331,7,4,
  	0,0,331,332,6,36,36,0,332,74,1,0,0,0,333,334,5,43,0,0,334,335,5,43,0,
  	0,335,336,1,0,0,0,336,337,6,37,37,0,337,76,1,0,0,0,338,339,5,45,0,0,339,
  	340,5,45,0,0,340,341,1,0,0,0,341,342,6,38,38,0,342,78,1,0,0,0,343,344,
  	5,33,0,0,344,345,6,39,39,0,345,80,1,0,0,0,346,347,5,60,0,0,347,358,5,
  	61,0,0,348,349,5,61,0,0,349,358,5,61,0,0,350,351,5,62,0,0,351,358,5,61,
  	0,0,352,358,7,5,0,0,353,354,5,33,0,0,354,355,5,61,0,0,355,356,1,0,0,0,
  	356,358,6,40,40,0,357,346,1,0,0,0,357,348,1,0,0,0,357,350,1,0,0,0,357,
  	352,1,0,0,0,357,353,1,0,0,0,358,82,1,0,0,0,359,360,5,38,0,0,360,366,5,
  	38,0,0,361,362,5,124,0,0,362,363,5,124,0,0,363,364,1,0,0,0,364,366,6,
  	41,41,0,365,359,1,0,0,0,365,361,1,0,0,0,366,84,1,0,0,0,367,368,5,61,0,
  	0,368,369,6,42,42,0,369,86,1,0,0,0,370,374,7,6,0,0,371,373,7,7,0,0,372,
  	371,1,0,0,0,373,376,1,0,0,0,374,372,1,0,0,0,374,375,1,0,0,0,375,377,1,
  	0,0,0,376,374,1,0,0,0,377,378,6,43,43,0,378,88,1,0,0,0,379,381,7,8,0,
  	0,380,379,1,0,0,0,381,382,1,0,0,0,382,380,1,0,0,0,382,383,1,0,0,0,383,
  	384,1,0,0,0,384,385,6,44,44,0,385,90,1,0,0,0,386,388,7,8,0,0,387,386,
  	1,0,0,0,388,389,1,0,0,0,389,387,1,0,0,0,389,390,1,0,0,0,390,398,1,0,0,
  	0,391,395,5,46,0,0,392,394,7,8,0,0,393,392,1,0,0,0,394,397,1,0,0,0,395,
  	393,1,0,0,0,395,396,1,0,0,0,396,399,1,0,0,0,397,395,1,0,0,0,398,391,1,
  	0,0,0,398,399,1,0,0,0,399,409,1,0,0,0,400,402,7,9,0,0,401,403,7,3,0,0,
  	402,401,1,0,0,0,402,403,1,0,0,0,403,405,1,0,0,0,404,406,7,8,0,0,405,404,
  	1,0,0,0,406,407,1,0,0,0,407,405,1,0,0,0,407,408,1,0,0,0,408,410,1,0,0,
  	0,409,400,1,0,0,0,409,410,1,0,0,0,410,411,1,0,0,0,411,427,6,45,45,0,412,
  	414,5,46,0,0,413,415,7,8,0,0,414,413,1,0,0,0,415,416,1,0,0,0,416,414,
  	1,0,0,0,416,417,1,0,0,0,417,418,1,0,0,0,418,427,6,45,46,0,419,421,7,8,
  	0,0,420,419,1,0,0,0,421,422,1,0,0,0,422,420,1,0,0,0,422,423,1,0,0,0,423,
  	424,1,0,0,0,424,425,5,46,0,0,425,427,6,45,47,0,426,387,1,0,0,0,426,412,
  	1,0,0,0,426,420,1,0,0,0,427,92,1,0,0,0,428,429,9,0,0,0,429,430,6,46,48,
  	0,430,94,1,0,0,0,20,0,101,113,115,129,131,142,357,365,374,382,389,395,
  	398,402,407,409,416,422,426,49,1,0,0,6,0,0,1,1,1,1,2,2,1,4,3,1,5,4,1,
  	6,5,1,7,6,1,8,7,1,9,8,1,10,9,1,11,10,1,12,11,1,13,12,1,14,13,1,15,14,
  	1,16,15,1,17,16,1,18,17,1,19,18,1,20,19,1,21,20,1,22,21,1,23,22,1,24,
  	23,1,25,24,1,26,25,1,27,26,1,28,27,1,29,28,1,30,29,1,31,30,1,32,31,1,
  	33,32,1,34,33,1,35,34,1,36,35,1,37,36,1,38,37,1,39,38,1,40,39,1,41,40,
  	1,42,41,1,43,42,1,44,43,1,45,44,1,45,45,1,45,46,1,46,47
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c2105133lexerLexerStaticData = std::move(staticData);
}

}

C2105133Lexer::C2105133Lexer(CharStream *input) : Lexer(input) {
  C2105133Lexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *c2105133lexerLexerStaticData->atn, c2105133lexerLexerStaticData->decisionToDFA, c2105133lexerLexerStaticData->sharedContextCache);
}

C2105133Lexer::~C2105133Lexer() {
  delete _interpreter;
}

std::string C2105133Lexer::getGrammarFileName() const {
  return "C2105133Lexer.g4";
}

const std::vector<std::string>& C2105133Lexer::getRuleNames() const {
  return c2105133lexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& C2105133Lexer::getChannelNames() const {
  return c2105133lexerLexerStaticData->channelNames;
}

const std::vector<std::string>& C2105133Lexer::getModeNames() const {
  return c2105133lexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& C2105133Lexer::getVocabulary() const {
  return c2105133lexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C2105133Lexer::getSerializedATN() const {
  return c2105133lexerLexerStaticData->serializedATN;
}

const atn::ATN& C2105133Lexer::getATN() const {
  return *c2105133lexerLexerStaticData->atn;
}


void C2105133Lexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 0: LINE_COMMENTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 1: BLOCK_COMMENTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 2: STRINGAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 4: IFAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 5: ELSEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 6: FORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 7: WHILEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 8: PRINTLNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 9: RETURNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 10: INTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 11: FLOATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 12: VOIDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 13: FORINAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 14: FOREACHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 15: INAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 16: TOAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 17: TIMESAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 18: SWITCHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 19: CASEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 20: BREAKAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 21: DEFAULTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 22: WHENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 23: LPARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 24: RPARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 25: LCURLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 26: RCURLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 27: LTHIRDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 28: RTHIRDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 29: SEMICOLONAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 30: COMMAAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 31: QUESAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 32: COLONAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 33: ARROWAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 34: ADDOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 35: SUBOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 36: MULOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 37: INCOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 38: DECOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 39: NOTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 40: RELOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 41: LOGICOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 42: ASSIGNOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 43: IDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 44: CONST_INTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 45: CONST_FLOATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 46: ANYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

void C2105133Lexer::LINE_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <SINGLE LINE COMMENT> Lexeme "
              + getText()
            );
         break;

  default:
    break;
  }
}

void C2105133Lexer::BLOCK_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1: 
          // extra braces create a new scope for your variables
          {
            std::string txt = getText();
            std::string content = txt.substr(2, txt.size() - 4);
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <MULTI LINE COMMENT> Lexeme /*"
              + content + "*/"
            );
          }
         break;

  default:
    break;
  }
}

void C2105133Lexer::STRINGAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <STRING> Lexeme " + getText()
            );
         break;

  default:
    break;
  }
}

void C2105133Lexer::IFAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <IF> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::ELSEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ELSE> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::FORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <FOR> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::WHILEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <WHILE> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::PRINTLNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 7:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <PRINTLN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::RETURNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 8:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RETURN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::INTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 9:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <INT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::FLOATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 10:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <FLOAT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::VOIDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 11:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <VOID> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::FORINAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 12:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <FORIN> Lexeme " + getText()); break;

  default:
    break;
  }
}

void C2105133Lexer::FOREACHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 13:   writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <FOREACH> Lexeme " + getText()); break;

  default:
    break;
  }
}

void C2105133Lexer::INAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 14: writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <IN> Lexeme " + getText()); break;

  default:
    break;
  }
}

void C2105133Lexer::TOAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 15: writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <TO> Lexeme " + getText()); break;

  default:
    break;
  }
}

void C2105133Lexer::TIMESAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 16: writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <TIMES> Lexeme " + getText()); break;

  default:
    break;
  }
}

void C2105133Lexer::SWITCHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 17: writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <SWITCH> Lexeme " + getText()); break;

  default:
    break;
  }
}

void C2105133Lexer::CASEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 18: writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <CASE> Lexeme " + getText()); break;

  default:
    break;
  }
}

void C2105133Lexer::BREAKAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 19: writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <BREAK> Lexeme " + getText()); break;

  default:
    break;
  }
}

void C2105133Lexer::DEFAULTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 20: writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <DEFAULT> Lexeme " + getText()); break;

  default:
    break;
  }
}

void C2105133Lexer::WHENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 21: writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <WHEN> Lexeme " + getText()); break;

  default:
    break;
  }
}

void C2105133Lexer::LPARENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 22:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LPAREN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::RPARENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 23:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RPAREN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::LCURLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 24:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LCURL> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::RCURLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 25:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RCURL> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::LTHIRDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 26:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LTHIRD> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::RTHIRDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 27:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RTHIRD> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::SEMICOLONAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 28:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <SEMICOLON> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::COMMAAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 29:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <COMMA> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::QUESAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 30:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <QUES> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::COLONAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 31:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <COLON> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::ARROWAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 32:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ARROW> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::ADDOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 33:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ADDOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::SUBOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 34:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <SUBOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::MULOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 35:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <MULOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::INCOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 36:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <INCOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::DECOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 37:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <DECOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::NOTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 38:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <NOT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::RELOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 39:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RELOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::LOGICOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 40:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LOGICOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::ASSIGNOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 41:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ASSIGNOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::IDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 42:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ID> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::CONST_INTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 43:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <CONST_INT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105133Lexer::CONST_FLOATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 44: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <CONST_FLOAT> Lexeme " + getText()
            );
         break;
    case 45: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <CONST_FLOAT> Lexeme " + getText()
            );
         break;
    case 46: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <CONST_FLOAT> Lexeme " + getText()
            );
         break;

  default:
    break;
  }
}

void C2105133Lexer::ANYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 47: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <ANY> Lexeme " + getText()
            );
         break;

  default:
    break;
  }
}



void C2105133Lexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c2105133lexerLexerInitialize();
#else
  ::antlr4::internal::call_once(c2105133lexerLexerOnceFlag, c2105133lexerLexerInitialize);
#endif
}
