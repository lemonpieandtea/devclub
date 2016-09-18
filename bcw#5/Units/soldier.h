#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "unit.h"

class Soldier : public Unit {
    public:
        Soldier();
        Soldier(const std::string& name, const int hitPoints, const int attackPower);
        virtual ~Soldier();
        
        void attack(Unit& unit);
        void counterAttack(Unit& unit);
};

std::ostream& operator<<(std::ostream& out, const Soldier& soldier);

#endif // SOLDIER_H
