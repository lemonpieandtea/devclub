#ifndef CAR_H
#define CAR_H

#include <algorithm>
#include <iostream>
#include <string>

class Car {
    private:
        std::string model;
        double consumption;
        double fuel, maxFuel;
        bool running;
        double totalDistance;
        
        double getMaxDistance() const;
        
    public:
        Car(std::string model, double maxFuel, double consumption);
        ~Car();
        
        void startEngine();
        void stopEngine();
        void addFuel(double fuel);
        void travel(double distance);
        
        std::string getModel() const;
        double getConsumption() const;
        double getFuel() const;
        double getMaxFuel() const;
        bool isRunning() const;
        double getTotalDistance() const;
};

std::ostream& operator<<(std::ostream& out, const Car& car);

class FuelOverflowException {};
class NoFuelException {};
class MovementException {};

#endif // CAR_H
