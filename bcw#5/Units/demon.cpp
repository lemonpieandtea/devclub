#include "demon.h"

Demon::Demon() : Soldier("Diablo", DEMON_HP, DEMON_AP) {}

Demon::~Demon() {}

std::ostream& operator<<(std::ostream& out, const Demon& demon) {
    std::cout << "Demon:" << std::endl;
    std::cout << "-- Name: " << demon.getName() << std::endl;
    std::cout << "-- HP: " << demon.getHP() << "/" << demon.getMaxHP() << std::endl;
    std::cout << "-- AP: " << demon.getAP();
    
    return out;
}
