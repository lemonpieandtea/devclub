#include "spiderMan.h"

SpiderMan::SpiderMan() : name("Spidy") {}

SpiderMan::~SpiderMan() {}

const std::string& SpiderMan::getName() const {
    return name;
}

void SpiderMan::walk() {
    std::cout << this->getName() << " going to save the planet..." << std::endl;
}

void SpiderMan::jump(){
    std::cout << this->getName() << " jump on the bad guy..." << std::endl;
}
