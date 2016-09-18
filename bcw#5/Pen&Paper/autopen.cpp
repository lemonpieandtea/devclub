#include "autopen.h"

bool AutoPen::isOpen() const {
    return open;
}

AutoPen::AutoPen() : Pen(), open(false) {}

AutoPen::AutoPen(const int capacity) : Pen(capacity), open(false) {}

AutoPen::~AutoPen() {}

void AutoPen::click() {
    open = !open;
}

void AutoPen::write(Paper& paper, const std::string& text) {
    if ( isOpen() == false ) {
        throw ClickAutoPenException();
    }
    
    Pen::write(paper, text);
}
