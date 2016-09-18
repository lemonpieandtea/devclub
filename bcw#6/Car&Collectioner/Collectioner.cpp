#include "Collectioner.h"

Collectioner::Collectioner(std::string name) : name(name) {}

void Collectioner::addCar(Car* newCar) {
    if ( newCar->getOwner() != this ) {
        throw OwnerException();
    }
    collection.insert(newCar);
}

void Collectioner::removeCar(Car* oldCar) {
    if ( oldCar->getOwner() != this ) {
        throw OwnerException();
    }
    collection.erase(oldCar);
}

const std::set<Car*>& Collectioner::getCollection() const {
    return collection;
}

const std::string& Collectioner::getName() const {
    return name;
}

Collectioner::~Collectioner() {
    std::set<Car*>::iterator it;
    for ( it = collection.begin(); it != collection.end(); ) {
         std::set<Car*>::iterator current = it++;
         (*current)->changeOwner(NULL);
    }
}

std::ostream& operator<<(std::ostream& out, const std::set<Car*>& collection ) {
    std::set<Car*>::iterator it;
    for ( it = collection.begin(); it != collection.end(); it++ ) {
        out << (*it)->getModel() << std::endl;
    }
    
    return out;
}