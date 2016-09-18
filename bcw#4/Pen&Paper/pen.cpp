#include "pen.h"

PenException::PenException(const int code) : code(code) {}

Pen::Pen() : capacity(DEFAULT_PEN_CAPACITY), ink(DEFAULT_PEN_CAPACITY) {}

Pen::Pen(const int capacity) {
    if ( capacity < 0 ) {
        throw PenException(1);
    }
    
    this->capacity = capacity;
    this->ink = capacity;
}

int Pen::getCapacity() const {
    return capacity;
}

int Pen::getInk() const {
    return ink;
}

void Pen::fillInk(const int quantity) {
    int differ = capacity - ink;
    
    if ( quantity > differ ) {
        throw PenException(2);
    }
    
    ink += quantity;
}

void Pen::write(Paper& paper, const std::string& text) {
    for ( int i = 0; i < text.length(); i++) {
        if ( ink == 0 ) {
            throw PenException(3);
        }
        
        paper.putText(text[i]);
        
        if ( text[i] != ' ' ) {
            ink -= 1;
        }
    }
}

void Pen::write(Paper& paper, const char text[]) {
    char buff = text[0];
    
    for ( int i = 0; buff != 0; i++) {
        if ( ink == 0 ) {
            throw PenException(3);
        }
        
        buff = text[i];
        
        paper.putText(buff);
        
        if ( buff != ' ' ) {
            ink -= 1;
        }
    }
}
