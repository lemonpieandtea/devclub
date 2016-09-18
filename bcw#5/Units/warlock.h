#ifndef WARLOCK_H
#define WARLOCK_H

#include <iostream>
#include "spellCaster.h"
#include "demon.h"

#define COST_OF_WARLOCK_SPELL 100

class Warlock : public SpellCaster {
    public:
        Warlock();
        Warlock(const std::string& name, const int hitPoints, const int attackPower, const int spellPoints);
        virtual ~Warlock();
        
        void attack(Unit& unit);
        void counterAttack(Unit& unit);
        Demon& summonDemon();
};

std::ostream& operator<<(std::ostream& out, const Warlock& warlock);

#endif // WARLOCK_H
