#include "stack.h"
#include "calc.h"

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <vector> 


bool Calc::isDigit(const char& c) {
    return c >= '0' && c <= '9';
} 

bool Calc::isOperator(const char& c) {
    return  (c == '+' || c == '-' || c == '*' || c == '/');
}
int Calc::whatPriority(const char& c) {
    if (c == '-' || c == '+') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

void Calc::set(const std::string& expr) {
    _expression = expr;
    _isValid = validateExpression();
    if (!_isValid) {
        throw std::runtime_error("WARNING!!! \nInvalid expression: " + expr);
    }
}

bool Calc::validateExpression()  {
    // Проверка скобочек, операторов
    int brackets = 0;
    bool fl = 0;
    int pr;
    std::string str = "";
    // std::cout << _expression << "\n";
    for (auto c : _expression) {
        if (c == '(') brackets++;
        if (c == ')') {
            brackets--;
            if (brackets < 0) {
                return 0;
            }
        }
        if (c == '+' || c == '-' || c == '/' || c == '*') {
            if (fl == 1) {
                if (pr == '-') {
                    if (pr == '-') {
                        c = '+';
                    }
                }  
                else if (pr == '-' && c == '+') c = '-';
                else if (pr != c) {
                    return 0;
                }
            }
            fl = 1;
            pr = c;
        }
        else {
            if (fl == 1) {
                str += pr;
            }
            str += c;
            pr = 0;
            fl = 0;
        } 
    }
    if (brackets != 0) return 0; // Никаких скобочек не должно быть, всё сгорит 
    if (str != _expression) set(str);
    return 1;
}
std::string Calc::infixToRPN() {
    Stack operators;
    std::stringstream rpn;
    
    for (size_t i = 0; i < _expression.length(); i++) {
        char c = _expression[i];
        
        if (c == ' ') continue;
        
        if (isDigit(c)) {
            while (i < _expression.length() && isDigit(_expression[i])) {
                rpn << _expression[i];
                i++;
            }
            i--;
            rpn << ' ';
            continue;
        }
        
        if (c == '(') {
            operators.push(c);
            continue;
        }
        
        if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                rpn << (char)operators.tpop() << ' ';
            }
            operators.pop();
            continue;
        }
        
        if (isOperator(c)) {
            if (c == '+' || c == '-') {
                bool isUnary = (i == 0) || 
                        (_expression[i-1] == '(') || 
                        isOperator(_expression[i-1]);
        
                if (isUnary) {
                    if (c == '-') {
                        rpn << "0 ";
                    }
                    continue;
                }
            }
            
            while (!operators.empty() && 
                   operators.top() != '(' &&
                   whatPriority((char)operators.top()) >= whatPriority(c)) {
                rpn << (char)operators.tpop() << ' ';
            }
            operators.push(c);
        }
    }
    
    while (!operators.empty()) {
        rpn << (char)operators.tpop() << ' ';
    }
    
    return rpn.str();
}

int64_t Calc::evaluateRPN(const std::string& rpn) {
    Stack values;
    std::stringstream ss(rpn);
    std::string token;
    
    while (ss >> token) {
        if (isDigit(token[0])) {
            values.push(stoll(token));
        } 
        else {
            if (values.size() < 2) {
                throw std::runtime_error("Ex. Invalid RPN expression");
            }
            
            int64_t b = values.tpop();
            int64_t a = values.tpop();
            
            switch (token[0]) {
                case '+': values.push(a + b); break;
                case '-': values.push(a - b); break;
                case '*': values.push(a * b); break;
                case '/': 
                    if (b == 0) throw std::runtime_error("Division by zero! You don't know basic math?");
                    values.push(a / b); 
                    break;
                default:
                    throw std::runtime_error("Bro, it is unknown operator: " + token);
            }
        }
    }
    
    if (values.size() != 1) {
        throw std::runtime_error("Bro, it is invalid expression");
    }
    
    return values.tpop();
}

int64_t Calc::calc() {
    if (!_isValid) {
        throw std::runtime_error("Bro stop! Cannot calculate invalid expression");
    }
    
    std::string rpn = infixToRPN();
    return evaluateRPN(rpn);
}