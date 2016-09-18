#include <iostream>
#include "gun.h"

GunException::GunException(const int code) : code(code) {}

Gun::Gun() : capacity(DEFAULT_MAGAZINE), bullets(0) {}

Gun::Gun(const int capacity) : bullets(0) {
    if ( capacity < 1 ) {
        throw GunException(1);
    }
    this->capacity = capacity;
}

int Gun::getCapacity() const {
    return capacity;
}

int Gun::getBullets() const {
    return bullets;
}

void Gun::recharge(const int quantity) {
    int freeSlots = capacity - bullets;
    
    if ( quantity > freeSlots ) {
        throw GunException(2);
    }
    
    bullets += quantity;
}

void Gun::shoot() {
    if ( bullets == 0 ) {
        throw GunException(3);
    }
    
    bullets -= 1;
    std::cout << "BANG!" << std::endl;
}
