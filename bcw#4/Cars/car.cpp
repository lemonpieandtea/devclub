#include <iostream>
#include "car.h"

CarException::CarException(const int code) : code(code) {}

Car::Car() : tankCapacity(DEFAULT_TANK_CAPACITY), fuel(0), consumption(DEFAULT_CONSUMPTION), position(Point()) {}

Car::Car(const int tankCapacity, const double consumption) : fuel(0), position(Point()) {
    if ( tankCapacity < 0 ) {
        throw CarException(1);
    }
    if ( consumption < 0 ) {
        throw CarException(2);
    }
    
    this->tankCapacity = tankCapacity;
    this->consumption = consumption;
}

Car::Car(const int tankCapacity, const double consumption, const Point& position) : fuel(0), position(position) {
    if ( tankCapacity < 0 ) {
        throw CarException(1);
    }
    if ( consumption < 0 ) {
        throw CarException(2);
    }
    
    this->tankCapacity = tankCapacity;
    this->consumption = consumption;
}

int Car::getTankCapacity() const {
    return tankCapacity;
}

int Car::getFuel() const {
    return fuel;
}

double Car::getConsumption() const {
    return consumption;
}

Point Car::getPosition() const {
    return position;
}

void Car::ride(Point& destination) {
    double distance = destination.distance(position);
    int requiedFuel = distance * consumption;
    
    if ( requiedFuel <= fuel ) {
        position = destination;
        fuel -= requiedFuel;
    }
}

void Car::refill(const int value) {
    int difference = tankCapacity - fuel;
    
    if ( value > difference ) {
        throw CarException(3);
    }
    if ( value < 0 ) {
        std::cout << "Get your fucking hands out off my car!" << std::endl;
        throw CarException(4);
    }
    
    fuel += value;
}

void Car::refillFull() {
    fuel = tankCapacity;
}

void Car::updateTankCapacity(const int newTankCapacity) {
    if ( tankCapacity < 0 ) {
        throw CarException(1);
    }
    
    tankCapacity = newTankCapacity;
}

void Car::updateConsumption(const double newConsumption) {
    if ( consumption < 0 ) {
        throw CarException(2);
    }
    
    consumption = newConsumption;
}

void Car::update(const int newTankCapacity, const double newConsumption) {
    updateTankCapacity(newTankCapacity);
    updateConsumption(newConsumption);
}
