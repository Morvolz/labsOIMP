#include "stack.h"
#include "calc.h"

#include <cassert>
#include <iostream>

void testStack() {
    Stack st;

    assert(st.size() == 0);
    assert(st.empty());
    //////////////////////////////////////////////

    st << 1 << -1;

    assert(st.size() == 2);
    assert(!st.empty());
    assert(st.top() == -1);
    //////////////////////////////////////////////

    st.pop();
    st.push(1e9);

    assert(st.size() == 2);
    assert(st.top() == 1e9);
    //////////////////////////////////////////////

    Stack twinkSt(2);
    twinkSt = st;
    assert(twinkSt.size() == st.size());
    assert(twinkSt == st);
    //////////////////////////////////////////////

    st[0] = 14;
    st[1] = 42;
    
    assert(st[0] == 14);
    assert(st[1] == 42);
    //////////////////////////////////////////////

    std::cout << "Stack is good\n";
}

void testCalc() {
    Calc expression("");

    expression.set("(3+5)*2");
    assert(expression.valid());
    assert(expression.calc() == 16);

    expression.set("(3+5)*2--3/5");
    assert(expression.valid());
    assert(expression.calc() == 16);

    std::cout << "Calc is good\n";
}

int main() {
    testStack();
    testCalc();

    std::cout << "Pobeda!!!\n";
    return 0;
}