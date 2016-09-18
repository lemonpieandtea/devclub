#include "man.h"

Man::Man() : name("Dude") {}

Man::~Man() {}

const std::string& Man::getName() const {
    return name;
}

void Man::walk() {
    std::cout << this->getName() << " going stright on the street..." << std::endl;
}

void Man::jump(){
    std::cout << this->getName() << " jump to the bus..." << std::endl;
}
