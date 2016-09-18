#ifndef CAR_H
#define CAR_H

#include "Collectioner.h"

class Collectioner;

class Car {
    private:
        std::string model;
        Collectioner* owner;
        
    public:
        Car(Collectioner* owner, const std::string& model);
        const std::string& getModel() const;
        Collectioner* getOwner() const;
        void changeOwner(Collectioner* newOwner);
        ~Car();
};

#endif // CAR_H