#ifndef HEALER_H
#define HEALER_H

#include <iostream>
#include "spellCaster.h"

#define COST_OF_HEALER_SPELL 50
#define HEAL_POINTS COST_OF_HEALER_SPELL

class Healer : public SpellCaster {
    public:
        Healer();
        Healer(const std::string& name, const int hitPoints, const int attackPower, const int spellPoints);
        virtual ~Healer();
        
        void attack(Unit& unit);
        void counterAttack(Unit& unit);
        void heal(Unit& unit);
};

std::ostream& operator<<(std::ostream& out, const Healer& healer);

#endif // HEALER_H
