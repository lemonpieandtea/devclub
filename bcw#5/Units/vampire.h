#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <iostream>
#include "unit.h"

#define STEAL_HP_PART 2

class Vampire : public Unit {
    public:
        Vampire();
        Vampire(const std::string& name, const int hitPoints, const int attackPower);
        virtual ~Vampire();
        
        void attack(Unit & unit);
        void counterAttack(Unit& unit);
};

std::ostream& operator<<(std::ostream& out, const Vampire& vampire);

#endif // VAMPIRE_H
