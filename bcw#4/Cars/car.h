#ifndef CAR_H
#define CAR_H

#include "point.h"

#define DEFAULT_TANK_CAPACITY 35
#define DEFAULT_FUEL_VOLUME DEFAULT_TANK_CAPACITY
#define DEFAULT_CONSUMPTION 7

class CarException {
    public:
        int code;
        CarException(const int);
};

class Car {
    private:
        int tankCapacity;
        int fuel;
        double consumption;
        Point position;
        
    public:
        Car();
        Car(const int, const double);
        Car(const int, const double, const Point&);
        int getTankCapacity() const;
        int getFuel() const;
        double getConsumption() const;
        Point getPosition() const;
        void ride(Point&);
        void refill(const int);
        void refillFull();
        void updateTankCapacity(const int);
        void updateConsumption(const double);
        void update(const int, const double);
};

#endif // CAR_H
