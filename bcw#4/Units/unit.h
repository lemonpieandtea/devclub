#ifndef UNIT_H
#define UNIT_H

#define DEFAULT_HIT_POINTS 100
#define DEFAULT_ATTACK_POWER 1

class UnitException {
    public:
        int code;
        UnitException(const int);
};

class Unit {
    private:
        int hitPoints;
        int attackPower;
        
    public:
        Unit();
        Unit(const int, const int);
        int getHitPoints() const;
        int getAttackPower() const;
        void takeDamage(const int);
        void attack(Unit&);
};

#endif // UNIT_H
