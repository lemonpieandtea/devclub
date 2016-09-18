#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include "spellCaster.h"

#define COST_OF_WIZARD_SPELL 50
#define WIZARD_SPELL_DAMAGE 40

class Wizard : public SpellCaster {
    public:
        Wizard();
        Wizard(const std::string& name, const int hitPoints, const int attackPower, const int spellPoints);
        virtual ~Wizard();
        
        void attack(Unit& unit);
        void counterAttack(Unit& unit);
        void castLight(Unit& unit);
};

std::ostream& operator<<(std::ostream& out, const Wizard& wizard);

#endif // WIZARD_H
