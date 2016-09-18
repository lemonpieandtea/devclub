#include "unit.h"
#include <iostream>

Unit::Unit() : name("Unit"), hitPoints(HP), maxHitPoints(HP), attackPower(AP) {}

Unit::Unit(const std::string& name, int hitPoints, int attackPower) : name(name) {
    if ( hitPoints < 0 ) {
        throw UnitSetHPException("Hit points less than zero");
    }
    this->hitPoints = hitPoints;
    this->maxHitPoints = hitPoints;
    
    if ( attackPower < 0 ) {
        throw UnitSetAPException("Attack points less than zero");
    }
    this->attackPower = attackPower;
}

Unit::~Unit() {}

const std::string& Unit::getName() const {
    return name;
}

int Unit::getHP() const {
    return hitPoints;
}

int Unit::getMaxHP() const {
    return maxHitPoints;
}

int Unit::getAP() const {
    return attackPower;
}

void Unit::damage(const int damage) {
    if ( hitPoints > damage ) {
        hitPoints -= damage;
    } else {
        hitPoints = 0;
    }
    
    if ( hitPoints > maxHitPoints ) {
        hitPoints = maxHitPoints;
    }
}
