#include <iostream>
#include "stack.h"  
#include "calc.h"

int main() {
    Calc x, y;
    y.set("14++(5--++2)**3");
    std::cout << y.getExpression() << "\n";
    std::cout << y.calc() << "\n";
    return 0;
}