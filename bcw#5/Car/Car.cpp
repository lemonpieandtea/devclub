#include "Car.h"

double Car::getMaxDistance() const {
    return fuel / consumption;
}

Car::Car(std::string model, double maxFuel, double consumption) : model(model), fuel(0), maxFuel(maxFuel), consumption(consumption), running(false), totalDistance(0) {}

Car::~Car() {}

void Car::startEngine() {
    if ( fuel == 0 ) {
        throw NoFuelException();
    }
    
    std::cout << "DR-DR-DR" << std::endl;
    running = true;
}

void Car::stopEngine() {
    running = false;
}

void Car::addFuel(double fuel) {
    double fuelDiff = maxFuel - this->fuel;
    
    if ( fuel > fuelDiff ) {
        throw FuelOverflowException();
    }
    
    this->fuel += fuel;
}

void Car::travel(double distance) {
    double maxDistance = getMaxDistance();
    double requidFuel = distance * consumption;
    
    if ( fuel == 0 ) {
        throw NoFuelException();
    }
    
    if ( running == false ) {
        throw MovementException();
    }
    
    if ( maxDistance <= distance ) {
        distance = maxDistance;
        fuel = 0;
        stopEngine();
    } else {
        fuel -= requidFuel;
    }
    
    totalDistance += distance;
}

std::string Car::getModel() const {
    return model;
}

double Car::getConsumption() const {
    return consumption;
}

double Car::getFuel() const {
    return fuel;
}

double Car::getMaxFuel() const {
    return maxFuel;
}

bool Car::isRunning() const {
    return running;
}

double Car::getTotalDistance() const {
    return totalDistance;
}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    std::cout << "Car \"" << car.getModel() << "\":" << std::endl;
    std::cout << "-- fuel: " << car.getFuel() << "/" << car.getMaxFuel() << std::endl;
    std::cout << "-- consumption: " << car.getConsumption() << std::endl;
    std::cout << "-- engine: " << (car.isRunning() ? "running" : "stopped") << std::endl;
    std::cout << "-- total distance: " << car.getTotalDistance();
    
    return out;
}
