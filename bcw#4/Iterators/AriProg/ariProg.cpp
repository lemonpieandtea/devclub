#include <iostream>
#include "ariProg.h"

AriProg::AriProg(const int first, const int step, const int limit) : index(1), currentValue(first), step(step), limit(limit) {}

int AriProg::getIndex() const {
    return index;
}

void AriProg::next() {
    if ( !over() ) {
        currentValue += step;
        index += 1;
    }
}

void AriProg::prev() {
    if ( !first() ) {
        currentValue -= step;
        index -= 1;
    }
}

int AriProg::value() {
    return currentValue;
}

bool AriProg::over() const {
    return index >= limit;
}

bool AriProg::first() const {
    return index <= 1;
}

int AriProg::operator++() {
    next();
    
    return value();
}

int AriProg::operator++(int) {
    int oldValue = value();
    
    next();
    
    return oldValue;
}

int AriProg::operator--() {
    prev();
    
    return value();
}

int AriProg::operator--(int) {
    int oldValue = value();
    
    prev();
    
    return oldValue;
}

int AriProg::operator*() {
    return value();
}

std::ostream& operator<<(std::ostream& out, AriProg& a) {
    std::cout << a.value();
    
    return out;
}
