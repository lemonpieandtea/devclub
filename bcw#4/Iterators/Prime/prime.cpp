#include <iostream>
#include "prime.h"

PrimeException::PrimeException(int code) : code(code) {}

bool Prime::isPrime(int number) {
    int modulo;
    int half = number / 2;
    
    if ( number < 2 ) {
        return false;
    }
    
    for ( int i = 2; i <= half; i++ ) {
        modulo = number % i;
        if ( modulo == 0 ) {
            return false;
        }
    }
    
    return true;
}

int Prime::prime(int number) {
    int position = this->index - start;
    int index = cache[position];
    
    if ( index != 0 ) {
        return index;
    }
    
    for ( int counter = 1; counter <= number; index++ ) {
        if ( isPrime(index) ) {
            counter += 1;
        }
    }
    
    cache[position] = index - 1;
    
    return cache[position];
}

Prime::Prime(const int first, const int limit) : start(first), index(first), limit(first+limit-1) {
    if ( first < 0 ) {
        throw PrimeException(1);
    }
    
    cache = new int [limit];
    
    for ( int i = 0; i < limit; i++ ) {
        cache[i] = 0;
    }
    
    currentValue = prime(first);
}

Prime::~Prime() {
    delete [] cache;
}

int Prime::getIndex() const {
    return index;
}

void Prime::next() {
    if ( !over() ) {
        index += 1;
        currentValue = prime(index);
    }
}

void Prime::prev() {
    if ( !first() ) {
        index -= 1;
        currentValue = prime(index);
    }
}

int Prime::value() {
    return currentValue;
}

bool Prime::over() const {
    return index >= limit;
}

bool Prime::first() const {
    return index <= start;
}

int Prime::operator++() {
    next();
    
    return currentValue;
}

int Prime::operator++(int) {
    int oldValue = value();
    
    next();
    
    return oldValue;
}

int Prime::operator--() {
    prev();
    
    return currentValue;
}

int Prime::operator--(int) {
    int oldValue = value();
    
    prev();
    
    return oldValue;
}

int Prime::operator*() {
    return value();
}

std::ostream& operator<<(std::ostream& out, Prime& a) {
    std::cout << a.value();
    
    return out;
}
