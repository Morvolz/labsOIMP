#include "stack.h" 
#include <algorithm>
#include <stdexcept>
#include <iostream>

Stack::Stack(int in_size) : _size(in_size), _top(-1), _data(new int64_t[_size]) {}

Stack::Stack(const Stack& other) : _size(other._size), _top(other._top), _data(new int64_t[other._size]) {
    for (int i = 0; i < _top; i++) {
        _data[i] = other._data[i];
    }
}


Stack::~Stack() {
    delete[] _data;
}


// Будет работать даже если элементов больше чем new_size, в таком случае берём только new_size эллементов  
void Stack::resize(int new_size) {
    int64_t* new_data = new int64_t[new_size];
    for (int i = 0; i < std::min(_top + 1, new_size); i++) {
        new_data[i] = _data[i]; 
    }  
    delete []_data;
    _data = new_data;
    _top = std::min(_top, new_size - 1);
    _size = new_size;

}  

int Stack::getTop() {
    return _top;
}

void Stack::push(int x) {
    _top++;
    if (_top == _size) resize(_size * 2); 
    _data[_top] = x;
} 

int64_t Stack::top() {
    if (_top < 0) throw std::runtime_error("Stack is epmty!");
    return _data[_top];
}

// Если нет элементов, то мы ничего не делаем
void Stack::pop() {
    if (_top == -1) return; 
    _top--;
    if (_top < _size / 4 && _size > base_size) resize(_size / 2);
}

// Top + pop
int64_t Stack::tpop() {
    int64_t x = top();
    pop();
    return x;
}

int Stack::size() {
    return (_top+1);
}

bool Stack::empty() {
    return (size() == 0);
}

Stack& Stack::operator<<(int x) {
    push(x);
    return *this;
}
Stack& Stack::operator>>(int& x) {
    x = tpop();
    return *this;
}

Stack& Stack::operator=(const Stack& other) { 
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        _top = other._top;
        _data = new int64_t[_size];
        for (int i = 0; i <= _top; i++) {
            _data[i] = other._data[i];
        }
    }
    return *this;
}

bool Stack::operator==(const Stack& other) const {
    if (_top != other._top) return 0;
    for (int i = 0; i <= _top; i++) {
        // std::cout << _data[i] << " " << other._data[i] << "\n";
        if (_data[i] != other._data[i]) return 0;
    }
    return 1;
}


int64_t& Stack::operator[](int index) {
    static int64_t c = -1;
    if (index < 0 || index > _top) return c;
    return (_data[index]);
}

const int64_t& Stack::operator[](int index) const {
    static const int64_t c = -1;
    if (index < 0 || index > _top) return c;
    return (_data[index]);
}

    