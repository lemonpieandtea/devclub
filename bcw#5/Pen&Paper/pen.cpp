#include "pen.h"

Pen::Pen() : capacity(DEFAULT_PEN_CAPACITY), ink(DEFAULT_PEN_CAPACITY) {}

Pen::Pen(const int capacity) {
    if ( capacity < 0 ) {
        throw CapacityPenException();
    }
    
    this->capacity = capacity;
    this->ink = capacity;
}

Pen::~Pen() {}

int Pen::getCapacity() const {
    return capacity;
}

int Pen::getInk() const {
    return ink;
}

void Pen::fillInk(const int quantity) {
    int differ = capacity - ink;
    
    if ( quantity > differ ) {
        throw OverflowPenException();
    }
    
    ink += quantity;
}

void Pen::write(Paper& paper, const std::string& text) {
    for ( int i = 0; i < text.length(); i++) {
        if ( ink == 0 ) {
            throw NoInkPenException();
        }
        
        paper.putText(text[i]);
        
        if ( text[i] != ' ' ) {
            ink -= 1;
        }
    }
}
