#ifndef COLLECTIONER_H
#define COLLECTIONER_H

#include <iostream>
#include <string>
#include <set>
#include "Car.h"

class Car;

class OwnerException {};

class Collectioner {
    private:
        std::string name;
        std::set<Car*> collection;
    public:
        Collectioner(std::string name);
        void addCar(Car* newCar);
        void removeCar(Car* oldCar);
        const std::set<Car*>& getCollection() const;
        const std::string& getName() const;
        ~Collectioner();
};

std::ostream& operator <<(std::ostream& out, const std::set<Car*>& collection );

#endif //COLLECTIONER_H