#include <iostream>
#include "geoProg.h"

GeoProg::GeoProg(const int first, const int step, const int limit) : index(1), currentValue(first), step(step), limit(limit) {}

int GeoProg::getIndex() const {
    return index;
}

void GeoProg::next() {
    if ( !over() ) {
        currentValue *= step;
        index += 1;
    }
}

void GeoProg::prev() {
    if ( !first() ) {
        currentValue /= step;
        index -= 1;
    }
}

int GeoProg::value() {
    return currentValue;
}

bool GeoProg::over() const {
    return index >= limit;
}

bool GeoProg::first() const {
    return index <= 1;
}

int GeoProg::operator++() {
    next();
    
    return value();
}

int GeoProg::operator++(int) {
    int oldValue = value();
    
    next();
    
    return oldValue;
}

int GeoProg::operator--() {
    prev();
    
    return value();
}

int GeoProg::operator--(int) {
    int oldValue = value();
    
    prev();
    
    return oldValue;
}

int GeoProg::operator*() {
    return value();
}

std::ostream& operator<<(std::ostream& out, GeoProg& a) {
    std::cout << a.value();
    
    return out;
}
