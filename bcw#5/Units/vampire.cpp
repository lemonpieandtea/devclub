#include "vampire.h"

Vampire::Vampire() : Unit() {}

Vampire::Vampire(const std::string& name, const int hitPoints, const int attackPower) : Unit(name, hitPoints, attackPower) {}

Vampire::~Vampire() {}

void Vampire::attack(Unit & unit) {
    int vampireStealHP = attackPower / STEAL_HP_PART;
    
    if ( unit.getHP() == 0 ) {
        throw UnitAttackException("Can't attack dead unit");
    }
    
    unit.damage(attackPower);
    hitPoints += vampireStealHP;
    std::cout << name << " attack " << unit.getName() << " (" << attackPower << ")" << std::endl;
    std::cout << name << " steal " << vampireStealHP << " HP from " << unit.getName() << std::endl;
    
    if ( unit.getHP() != 0 ) {
        unit.counterAttack(*this);
    }
}

void Vampire::counterAttack(Unit& unit) {
    int vampireStealHP = attackPower / (2 * STEAL_HP_PART);
    
    unit.damage(attackPower/2);
    hitPoints += vampireStealHP;
    
    std::cout << name << " counter attack " << unit.getName() << " (" << attackPower << ")" << std::endl;
    std::cout << name << " steal " << vampireStealHP << " HP from " << unit.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Vampire& vampire) {
    std::cout << "Vampire:" << std::endl;
    std::cout << "-- Name: " << vampire.getName() << std::endl;
    std::cout << "-- HP: " << vampire.getHP() << "/" << vampire.getMaxHP() << std::endl;
    std::cout << "-- AP: " << vampire.getAP();
    
    return out;
}
