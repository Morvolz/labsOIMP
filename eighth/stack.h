#ifndef STACK_H
#define STACK_H

#pragma once 

#include <cstdint>

const int base_size = 32;

class Stack {
    private: 
    int64_t* _data;
    int _size; 
    int _top; 

    void resize(int new_size);
    
    public: 
    Stack(int in_size = base_size);
    Stack(const Stack& other);
    ~Stack();

    int getTop();

    void push(int x);
    int64_t top();
    void pop();
    int64_t tpop();
    int size();
    bool empty();

    Stack& operator<<(int x);
    Stack& operator>>(int& x);

    Stack& operator=(const Stack& other);

    bool operator==(const Stack& other) const; 

    int64_t& operator[](int index);
    const int64_t& operator[](int index) const ;
};
#endif


/// Это авторский стек, так что автор создавал структуру удобную для него и при использовании которой он не будет допускать ошибок(наверное).
/// Спасибо за понимание (^-^)