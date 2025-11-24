#pragma once
#include "antlr4-runtime.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MyCustomErrorListener : public antlr4::BaseErrorListener {
public:
    ofstream errorLog;

    MyCustomErrorListener(const string &filename) {
        errorLog.open(filename);
    }

    ~MyCustomErrorListener() {
        if (errorLog.is_open())
            errorLog.close();
    }

    void syntaxError(antlr4::Recognizer *recognizer,
                     antlr4::Token *offendingSymbol,
                     size_t line,
                     size_t charPositionInLine,
                     const string &msg,
                     exception_ptr e) override {

        string customMessage = "Syntax Error at Line " + to_string(line) +
                                ", Column " + to_string(charPositionInLine) +
                                ": unexpected token '" + offendingSymbol->getText() + "'";

        if (errorLog.is_open())
            errorLog << customMessage << endl;

        // You can also print to console if you want
        // cerr << customMessage << endl;
    }
};
