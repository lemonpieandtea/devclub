#include "warlock.h"

Warlock::Warlock() : SpellCaster() {}

Warlock::Warlock(const std::string& name, const int hitPoints, const int attackPower, const int spellPoints) : SpellCaster(name, hitPoints, attackPower, spellPoints, Spell("Summon demon", COST_OF_WARLOCK_SPELL)) {}

Warlock::~Warlock() {}

void Warlock::attack(Unit& unit) {
    if ( unit.getHP() == 0 ) {
        throw UnitAttackException("Can't attack dead unit");
    }
    
    unit.damage(attackPower);
    
    std::cout << name << " attack " << unit.getName() << " (" << attackPower << ")" << std::endl;
    
    if ( unit.getHP() != 0 ) {
        unit.counterAttack(*this);
    }
}

void Warlock::counterAttack(Unit& unit) {
    int attackPower = this->attackPower / 2;
    
    unit.damage(attackPower);
    
    std::cout << name << " counter attack " << unit.getName() << " (" << attackPower << ")" << std::endl;
}

Demon& Warlock::summonDemon() {
    cast();
    
    std::cout << name << " summon a demon" << std::endl;
    
    return *(new Demon);
}

std::ostream& operator<<(std::ostream& out, const Warlock& warlock) {
    std::cout << "Warlock:" << std::endl;
    std::cout << "-- Name: " << warlock.getName() << std::endl;
    std::cout << "-- HP: " << warlock.getHP() << "/" << warlock.getMaxHP();
    std::cout << " SP: " << warlock.getSP() << "/" << warlock.getMaxSP() << std::endl;
    std::cout << "-- AP: " << warlock.getAP() << std::endl;
    std::cout << "-- Spell: " << warlock.getSpell().getName() << " (Cost: " << warlock.getSpell().getSP() << ")";
    
    return out;
}
