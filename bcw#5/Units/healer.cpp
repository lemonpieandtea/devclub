#include "healer.h"

Healer::Healer() : SpellCaster() {
    delete spell;
    spell = new Spell("Heal", COST_OF_HEALER_SPELL);
}

Healer::Healer(const std::string& name, const int hitPoints, const int attackPower, const int spellPoints) : SpellCaster(name, hitPoints, attackPower, spellPoints, Spell("Heal", COST_OF_HEALER_SPELL)) {}

Healer::~Healer() {}

void Healer::attack(Unit& unit) {
    if ( unit.getHP() == 0 ) {
        throw UnitAttackException("Can't attack dead unit");
    }
    
    unit.damage(attackPower);
    
    std::cout << name << " attack " << unit.getName() << " (" << attackPower << ")" << std::endl;
    
    if ( unit.getHP() != 0 ) {
        unit.counterAttack(*this);
    }
}

void Healer::counterAttack(Unit& unit) {
    int attackPower = this->attackPower / 2;
    
    unit.damage(attackPower);
    
    std::cout << name << " counter attack " << unit.getName() << " (" << attackPower << ")" << std::endl;
}

void Healer::heal(Unit& unit) {
    if ( unit.getHP() == 0 ) {
        throw SpellCasterCastException("Can't heal dead unit");
    }
    
    cast();
    unit.damage(-HEAL_POINTS);
    
    std::cout << name << " heal " << unit.getName() << " (" << attackPower << ")" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Healer& healer) {
    std::cout << "Healer:" << std::endl;
    std::cout << "-- Name: " << healer.getName() << std::endl;
    std::cout << "-- HP: " << healer.getHP() << "/" << healer.getMaxHP();
    std::cout << " SP: " << healer.getSP() << "/" << healer.getMaxSP() << std::endl;
    std::cout << "-- AP: " << healer.getAP() << std::endl;
    std::cout << "-- Spell: " << healer.getSpell().getName() << " (Cost: " << healer.getSpell().getSP();
    std::cout << ", Heal: " << HEAL_POINTS << ")";
    
    return out;
}
