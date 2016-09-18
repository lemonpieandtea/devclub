#ifndef DEMON_H
#define DEMON_H

#include <iostream>
#include "soldier.h"

#define DEMON_HP 100
#define DEMON_AP 15

class Demon : public Soldier {
    public:
        Demon();
        virtual ~Demon();
};

std::ostream& operator<<(std::ostream& out, const Demon& demon);

#endif // DEMON_H
