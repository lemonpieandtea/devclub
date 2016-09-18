#include "soldier.h"

Soldier::Soldier() : Unit() {}

Soldier::Soldier(const std::string& name, const int hitPoints, const int attackPower) : Unit(name, hitPoints, attackPower) {}

Soldier::~Soldier() {}

void Soldier::attack(Unit& unit) {
    if ( unit.getHP() == 0 ) {
        throw UnitAttackException("Can't attack dead unit");
    }
    
    unit.damage(attackPower);
    
    std::cout << name << " attack " << unit.getName() << " (" << attackPower << ")" << std::endl;
    
    if ( unit.getHP() != 0 ) {
        unit.counterAttack(*this);
    }
}

void Soldier::counterAttack(Unit& unit) {
    int attackPower = this->attackPower / 2;
    
    unit.damage(attackPower);
    
    std::cout << name << " counter attack " << unit.getName() << " (" << attackPower << ")" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Soldier& soldier) {
    std::cout << "Soldier:" << std::endl;
    std::cout << "-- Name: " << soldier.getName() << std::endl;
    std::cout << "-- HP: " << soldier.getHP() << "/" << soldier.getMaxHP() << std::endl;
    std::cout << "-- AP: " << soldier.getAP();
    
    return out;
}
