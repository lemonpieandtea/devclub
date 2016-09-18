#include <iostream>
#include "fibonacci.h"

int Fibonacci::fibonacci(int number) {
    long fib = 0;
    int sign = 1;
    
    if ( number < 0 ) {
        number *= -1;
        if ( number % DEVISOR == 0 ) {
            sign = -1;
        }
    }
    
    for ( int last = 0, preLast = 1; number > 0; number-- ) {
        fib = last + preLast;
        preLast = last;
        last = fib;
    }
    fib *= sign;
    
    return fib;
}

Fibonacci::Fibonacci(const int first, const int limit) : start(first), index(first), limit(first+limit-1) {
    currentValue = fibonacci(first);
}

int Fibonacci::getIndex() const {
    return index;
}

void Fibonacci::next() {
    if ( !over() ) {
        index += 1;
        currentValue = fibonacci(index);
    }
}

void Fibonacci::prev() {
    if ( !first() ) {
        index -= 1;
        currentValue = fibonacci(index);
    }
}

int Fibonacci::value() {
    return currentValue;
}

bool Fibonacci::over() const {
    return index >= limit;
}

bool Fibonacci::first() const {
    return index <= start;
}

int Fibonacci::operator++() {
    next();
    
    return currentValue;
}

int Fibonacci::operator++(int) {
    int oldValue = value();
    
    next();
    
    return oldValue;
}

int Fibonacci::operator--() {
    prev();
    
    return currentValue;
}

int Fibonacci::operator--(int) {
    int oldValue = value();
    
    prev();
    
    return oldValue;
}

int Fibonacci::operator*() {
    return value();
}

std::ostream& operator<<(std::ostream& out, Fibonacci& a) {
    std::cout << a.value();
    
    return out;
}
