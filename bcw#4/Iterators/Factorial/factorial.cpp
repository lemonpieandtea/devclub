#include <iostream>
#include "factorial.h"

FactorialException::FactorialException(int code) : code(code) {}

int Factorial::factorial(int n) {
    if ( n <= 1 ) {
        return 1;
    }
    return n * factorial(n-1);
}

Factorial::Factorial(const int first, const int limit) : start(first), index(first), limit(first+limit-1) {
    if ( first < 0 ) {
        throw FactorialException(1);
    }
    
    currentValue = factorial(first);
}

int Factorial::getIndex() const {
    return index;
}

void Factorial::next() {
    if ( !over() ) {
        index += 1;
        currentValue = factorial(index);
    }
}

void Factorial::prev() {
    if ( !first() ) {
        index -= 1;
        currentValue = factorial(index);
    }
}

int Factorial::value() {
    return currentValue;
}

bool Factorial::over() const {
    return index >= limit;
}

bool Factorial::first() const {
    return index <= start;
}

int Factorial::operator++() {
    next();
    
    return currentValue;
}

int Factorial::operator++(int) {
    int oldValue = value();
    
    next();
    
    return oldValue;
}

int Factorial::operator--() {
    prev();
    
    return currentValue;
}

int Factorial::operator--(int) {
    int oldValue = value();
    
    prev();
    
    return oldValue;
}

int Factorial::operator*() {
    return value();
}

std::ostream& operator<<(std::ostream& out, Factorial& a) {
    std::cout << a.value();
    
    return out;
}
