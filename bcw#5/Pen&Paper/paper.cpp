#include <iostream>
#include "paper.h"

Paper::Paper() : capacity(DEFAULT_PAPER_CAPACITY), text(DEFAULT_PAPER_TEXT) {}

Paper::Paper(const int capacity) : text(DEFAULT_PAPER_TEXT) {
    if ( capacity < 0 ) {
        throw BadPaperException();
    }
    
    this->capacity = capacity;
}

int Paper::getCapacity() const {
    return capacity;
}

std::string Paper::getText() const {
    return text;
}

void Paper::showText() const {
    std::cout << text << std::endl;
}

void Paper::putText(const char& character) {
    if ( capacity == 0 ) {
        throw CapacityPaperException();
    }
    
    text += character;
    capacity -= 1;
}

std::ostream& operator<<(std::ostream& out, const Paper& paper) {
    out << paper.getText();
    
    return out;
}
