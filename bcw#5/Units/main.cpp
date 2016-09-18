#include <iostream>
#include "soldier.h"
#include "rogue.h"
#include "vampire.h"
#include "healer.h"
#include "wizard.h"
#include "warlock.h"

using namespace std;

int main() {
    Soldier& soldier = *(new Soldier("Soldier", 200, 35));
    Rogue& rogue = *(new Rogue("Rogue", 120, 20));
    Vampire& vampire = *(new Vampire("Vampire", 80, 25));
    Healer& healer = *(new Healer("Healer", 150, 10, 150));
    Wizard& wizard = *(new Wizard("Wizard", 100, 20, 100));
    Warlock& warlock = *(new Warlock("Warlock", 100, 20, 100));
    
    cout << "Initial:" << endl;
    cout << soldier << endl << rogue << endl << vampire << endl;
    cout << healer << endl << wizard << endl << warlock << endl;
    
    cout << endl << "Fight:" << endl;
    
    soldier.attack(rogue);
    rogue.attack(vampire);
    vampire.attack(healer);
    healer.heal(healer);
    healer.attack(wizard);
    wizard.castLight(warlock);
    wizard.attack(warlock);
    Demon& demon = warlock.summonDemon();
    warlock.attack(soldier);
    demon.attack(soldier);
    
    cout << endl << "After fight:" << endl;
    
    cout << soldier << endl << rogue << endl << vampire << endl;
    cout << healer << endl << wizard << endl << warlock << endl;
    cout << demon << endl;
    
    delete &soldier;
    delete &rogue;
    delete &vampire;
    delete &healer;
    delete &wizard;
    delete &warlock;
    delete &demon;
    
    cout << endl << "Exceptions:" << endl;
    
    try {
        Soldier& sol = *(new Soldier("Soldier", -10, 10));
    } catch (UnitSetHPException obj) {
        cout << obj.getMessage() << endl;
    }
    
    try {
        Rogue& rog = *(new Rogue("Rogue", 10, -10));
    } catch (UnitSetAPException obj) {
        cout << obj.getMessage() << endl;
    }
    
    try {
        Vampire& vam = *(new Vampire("Vampire", 0, 10));
        Healer& hea = *(new Healer("Healer", 10, 10, 10));
        hea.attack(vam);
        delete &vam;
        delete &hea;
    } catch (UnitAttackException obj) {
        cout << obj.getMessage() << endl;
    }
    
    try {
        Wizard& wiz = *(new Wizard("Wizard", 10, 10, -10));
    } catch (SpellCasterSetSPException obj) {
        cout << obj.getMessage() << endl;
    }
    
    try {
        Wizard& viz = *(new Wizard("Wizard", 10, 10, 0));
        Warlock& war = *(new Warlock("Warlock", 10, 10, 10));
        viz.castLight(war);
        delete &viz;
        delete &war;
    } catch (SpellCasterCastException obj) {
        cout << obj.getMessage() << endl;
    }
    
    return 0;
}
