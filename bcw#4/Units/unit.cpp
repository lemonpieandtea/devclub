#include <iostream>
#include "unit.h"

UnitException::UnitException(const int code) : code(code) {}

Unit::Unit() : hitPoints(DEFAULT_HIT_POINTS), attackPower(DEFAULT_ATTACK_POWER) {}

Unit::Unit(const int hitPoints, const int attackPower) {
    if ( hitPoints < 0 ) {
        throw UnitException(1);
    }
    if ( attackPower < 0 ) {
        throw UnitException(2);
    }
    
    this->hitPoints = hitPoints;
    this->attackPower = attackPower;
}

int Unit::getHitPoints() const {
    return hitPoints;
}

int Unit::getAttackPower() const {
    return attackPower;
}

void Unit::takeDamage(const int damage) {
    if ( damage < hitPoints ) {
        hitPoints -= damage;
    } else {
        hitPoints = 0;
    }
}

void Unit::attack(Unit& enemy) {
    if ( hitPoints == 0 ) {
        throw UnitException(3);
    }
    if ( enemy.getHitPoints() == 0 ) {
        throw UnitException(4);
    }
    
    enemy.takeDamage(attackPower);
    
    if ( enemy.getHitPoints() > 0 ) {
        takeDamage(enemy.getAttackPower()/2);
    }
}
