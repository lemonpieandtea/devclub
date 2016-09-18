#include "spider.h"

Spider::Spider() : name("Tarantul") {}

Spider::~Spider() {}

const std::string& Spider::getName() const {
    return name;
}

void Spider::walk() {
    std::cout << this->getName() << " going up on the tree..." << std::endl;
}

void Spider::jump(){
    std::cout << this->getName() << " jump to the fly..." << std::endl;
}
