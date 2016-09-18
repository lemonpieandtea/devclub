#include "wizard.h"

Wizard::Wizard() : SpellCaster() {}

Wizard::Wizard(const std::string& name, const int hitPoints, const int attackPower, const int spellPoints) : SpellCaster(name, hitPoints, attackPower, spellPoints, Spell("Light", COST_OF_WIZARD_SPELL)) {}

Wizard::~Wizard() {}

void Wizard::attack(Unit& unit) {
    if ( unit.getHP() == 0 ) {
        throw UnitAttackException("Can't attack dead unit");
    }
    
    unit.damage(attackPower);
    std::cout << name << " attack " << unit.getName() << " (" << attackPower << ")" << std::endl;
    
    if ( unit.getHP() != 0 ) {
        unit.counterAttack(*this);
    }
}

void Wizard::counterAttack(Unit& unit) {
    int attackPower = this->attackPower / 2;
    
    unit.damage(attackPower);
    
    std::cout << name << " counter attack " << unit.getName() << " (" << attackPower << ")" << std::endl;
}

void Wizard::castLight(Unit& unit) {
    if ( unit.getHP() == 0 ) {
        throw SpellCasterCastException("Can't throw light to a dead unit");
    }
    
    cast();
    unit.damage(WIZARD_SPELL_DAMAGE);
    
    std::cout << name << " throw a light to " << unit.getName() << " (" << WIZARD_SPELL_DAMAGE << ")" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Wizard& wizard) {
    std::cout << "Wizard:" << std::endl;
    std::cout << "-- Name: " << wizard.getName() << std::endl;
    std::cout << "-- HP: " << wizard.getHP() << "/" << wizard.getMaxHP();
    std::cout << " SP: " << wizard.getSP() << "/" << wizard.getMaxSP() << std::endl;
    std::cout << "-- AP: " << wizard.getAP() << std::endl;
    std::cout << "-- Spell: " << wizard.getSpell().getName() << " (Cost: " << wizard.getSpell().getSP();
    std::cout << ", Damage: " << WIZARD_SPELL_DAMAGE << ")";
    
    return out;
}
