#include "Car.h"

Car::Car(Collectioner* owner, const std::string& model) : owner(owner), model(model) {
    owner->addCar(this);
}

Collectioner* Car::getOwner() const {
    return owner;
}

const std::string& Car::getModel() const {
    return model;
}

void Car::changeOwner(Collectioner* newOwner) {
    if ( newOwner == owner ) {
        return;
    }
    Collectioner* oldOwner = owner;
    
    owner = newOwner;
    if ( oldOwner != NULL ) {
        oldOwner->removeCar(this);
    }
    
    if ( owner == NULL ) {
        delete this;
        return;
    }
    
    owner->addCar(this);
}

Car::~Car() {
    if ( owner != NULL ) {
        Collectioner* oldOwner = owner;
        owner = NULL;
        oldOwner->removeCar(this);
    }
}