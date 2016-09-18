#ifndef ROGUE_H
#define ROGUE_H

#include <iostream>
#include "unit.h"

class Rogue : public Unit {
    public:
        Rogue();
        Rogue(const std::string& name, const int hitPoints, const int attackPower);
        virtual ~Rogue();
        
        void attack(Unit& unit);
        void counterAttack(Unit& unit);
};

std::ostream& operator<<(std::ostream& out, const Rogue& warrior);

#endif // ROGUE_H
