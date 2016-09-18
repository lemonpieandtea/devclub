#include "rogue.h"

Rogue::Rogue() : Unit() {}

Rogue::Rogue(const std::string& name, const int hitPoints, const int attackPower) : Unit(name, hitPoints, attackPower) {}

Rogue::~Rogue() {}

void Rogue::attack(Unit& unit) {
    if ( unit.getHP() == 0 ) {
        throw UnitAttackException("Can't attack dead unit");
    }
    
    unit.damage(attackPower);
    
    std::cout << name << " attack " << unit.getName() << " (" << attackPower << ")" << std::endl;
    
    if ( unit.getHP() != 0 ) {
        std::cout << name << " escaped from " << unit.getName() << "s attack" << std::endl;
    }
}

void Rogue::counterAttack(Unit& unit) {
    int attackPower = this->attackPower / 2;
    
    unit.damage(attackPower);
    
    std::cout << name << " counter attack " << unit.getName() << " (" << attackPower << ")" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Rogue& rogue) {
    std::cout << "Rogue:" << std::endl;
    std::cout << "-- Name: " << rogue.getName() << std::endl;
    std::cout << "-- HP: " << rogue.getHP() << "/" << rogue.getMaxHP() << std::endl;
    std::cout << "-- AP: " << rogue.getAP();
    
    return out;
}
