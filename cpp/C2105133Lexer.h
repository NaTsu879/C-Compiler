
    #pragma once
    #include <iostream>
    #include <fstream>
    #include <string>

    extern std::ofstream lexLogFile;


// Generated from C2105133Lexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  C2105133Lexer : public antlr4::Lexer {
public:
  enum {
    LINE_COMMENT = 1, BLOCK_COMMENT = 2, STRING = 3, WS = 4, IF = 5, ELSE = 6, 
    FOR = 7, WHILE = 8, PRINTLN = 9, RETURN = 10, INT = 11, FLOAT = 12, 
    VOID = 13, FORIN = 14, FOREACH = 15, IN = 16, TO = 17, TIMES = 18, SWITCH = 19, 
    CASE = 20, BREAK = 21, DEFAULT = 22, WHEN = 23, LPAREN = 24, RPAREN = 25, 
    LCURL = 26, RCURL = 27, LTHIRD = 28, RTHIRD = 29, SEMICOLON = 30, COMMA = 31, 
    QUES = 32, COLON = 33, ARROW = 34, ADDOP = 35, SUBOP = 36, MULOP = 37, 
    INCOP = 38, DECOP = 39, NOT = 40, RELOP = 41, LOGICOP = 42, ASSIGNOP = 43, 
    ID = 44, CONST_INT = 45, CONST_FLOAT = 46, ANY = 47
  };

  explicit C2105133Lexer(antlr4::CharStream *input);

  ~C2105133Lexer() override;


      void writeIntoLexLogFile(const std::string &message) {
          if (!lexLogFile.is_open()) {
              lexLogFile.open("lexLogFile.txt", std::ios::app);
              if (!lexLogFile) {
                  std::cerr << "Error opening lexLogFile.txt" << std::endl;
                  return;
              }
          }
          lexLogFile << message << std::endl;
          lexLogFile.flush();
      }


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.
  void LINE_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex);
  void BLOCK_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRINGAction(antlr4::RuleContext *context, size_t actionIndex);
  void IFAction(antlr4::RuleContext *context, size_t actionIndex);
  void ELSEAction(antlr4::RuleContext *context, size_t actionIndex);
  void FORAction(antlr4::RuleContext *context, size_t actionIndex);
  void WHILEAction(antlr4::RuleContext *context, size_t actionIndex);
  void PRINTLNAction(antlr4::RuleContext *context, size_t actionIndex);
  void RETURNAction(antlr4::RuleContext *context, size_t actionIndex);
  void INTAction(antlr4::RuleContext *context, size_t actionIndex);
  void FLOATAction(antlr4::RuleContext *context, size_t actionIndex);
  void VOIDAction(antlr4::RuleContext *context, size_t actionIndex);
  void FORINAction(antlr4::RuleContext *context, size_t actionIndex);
  void FOREACHAction(antlr4::RuleContext *context, size_t actionIndex);
  void INAction(antlr4::RuleContext *context, size_t actionIndex);
  void TOAction(antlr4::RuleContext *context, size_t actionIndex);
  void TIMESAction(antlr4::RuleContext *context, size_t actionIndex);
  void SWITCHAction(antlr4::RuleContext *context, size_t actionIndex);
  void CASEAction(antlr4::RuleContext *context, size_t actionIndex);
  void BREAKAction(antlr4::RuleContext *context, size_t actionIndex);
  void DEFAULTAction(antlr4::RuleContext *context, size_t actionIndex);
  void WHENAction(antlr4::RuleContext *context, size_t actionIndex);
  void LPARENAction(antlr4::RuleContext *context, size_t actionIndex);
  void RPARENAction(antlr4::RuleContext *context, size_t actionIndex);
  void LCURLAction(antlr4::RuleContext *context, size_t actionIndex);
  void RCURLAction(antlr4::RuleContext *context, size_t actionIndex);
  void LTHIRDAction(antlr4::RuleContext *context, size_t actionIndex);
  void RTHIRDAction(antlr4::RuleContext *context, size_t actionIndex);
  void SEMICOLONAction(antlr4::RuleContext *context, size_t actionIndex);
  void COMMAAction(antlr4::RuleContext *context, size_t actionIndex);
  void QUESAction(antlr4::RuleContext *context, size_t actionIndex);
  void COLONAction(antlr4::RuleContext *context, size_t actionIndex);
  void ARROWAction(antlr4::RuleContext *context, size_t actionIndex);
  void ADDOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void SUBOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void MULOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void INCOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void DECOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void NOTAction(antlr4::RuleContext *context, size_t actionIndex);
  void RELOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOGICOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void ASSIGNOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void IDAction(antlr4::RuleContext *context, size_t actionIndex);
  void CONST_INTAction(antlr4::RuleContext *context, size_t actionIndex);
  void CONST_FLOATAction(antlr4::RuleContext *context, size_t actionIndex);
  void ANYAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

};

