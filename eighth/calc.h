#ifndef CALC_H
#define CALC_H

#include <iostream>
#include "stack.h"
#include <string>
#include <vector> 

class Calc {
    private: 
    std::string _expression;
    bool _isValid;

    static bool isDigit(const char& c);
    static bool isOperator(const char& c);
    static int whatPriority(const char& c);

    std::string infixToRPN();
    int64_t evaluateRPN(const std::string& rpn);
    bool validateExpression();

    public:
    Calc() : _isValid(false) {}
    Calc(const std::string& expr) { set(expr); }
    
    void set(const std::string& expr);
    bool valid() const { return _isValid; }
    int64_t calc();
    
    std::string getExpression() const { return _expression; }
};

#endif