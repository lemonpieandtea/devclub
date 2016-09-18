#ifndef UNIT_H
#define UNIT_H

#include <string>
#include "exception.h"

#define HP 100
#define AP 10

class Unit {
    protected:
        std::string name;
        int hitPoints;
        int maxHitPoints;
        int attackPower;
        
    public:
        Unit();
        Unit(const std::string& name, const int hitPoints, const int attackPower);
        virtual ~Unit();
        
        const std::string& getName() const;
        int getHP() const;
        int getMaxHP() const;
        int getAP() const;
        
        virtual void attack(Unit& unit) = 0;
        void damage(const int damage);
        virtual void counterAttack(Unit& unit) = 0;
};

#endif // UNIT_H
