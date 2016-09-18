#include "thing.h"

Thing::Thing() : name("Unknown") {}

Thing::~Thing() {}

const std::string& Thing::getName() const {
    return name;
}

void Thing::walk() {
    std::cout << this->getName() << " going nowhere..." << std::endl;
}

void Thing::jump(){
    std::cout << this->getName() << " jump nowhere..." << std::endl;
}
