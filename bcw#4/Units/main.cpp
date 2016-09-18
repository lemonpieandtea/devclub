#include <iostream>
#include "unit.h"

using namespace std;

#define RED_HP 100
#define RED_AP 15
#define BLUE_HP 80
#define BLUE_AP 20

int main() {
    Unit red(RED_HP, RED_AP);
    Unit blue(BLUE_HP, BLUE_AP);
    Unit white;
    
    cout << "Initial:" << endl;
    cout << "Red   - HP: " << red.getHitPoints() << "\tAP: " << red.getAttackPower() << endl;
    cout << "Blue  - HP: " << blue.getHitPoints() << "\tAP: " << blue.getAttackPower() << endl;
    cout << "White - HP: " << white.getHitPoints() << "\tAP: " << white.getAttackPower() << endl;
    
    red.attack(white);
    blue.attack(white);
    red.attack(blue);
    blue.attack(red);
    white.attack(red);
    white.attack(blue);
    
    cout << "1st fight:" << endl;
    cout << "Red   - HP: " << red.getHitPoints() << endl;
    cout << "Blue  - HP: " << blue.getHitPoints() << endl;
    cout << "White - HP: " << white.getHitPoints() << endl;
    
    red.attack(white);
    blue.attack(white);
    red.attack(blue);
    blue.attack(red);
    white.attack(red);
    white.attack(blue);
    
    cout << "2nd fight:" << endl;
    cout << "Red   - HP: " << red.getHitPoints() << endl;
    cout << "Blue  - HP: " << blue.getHitPoints() << endl;
    cout << "White - HP: " << white.getHitPoints() << endl;
    
    try {
        red.attack(white);
        blue.attack(white);
        white.attack(red);
        white.attack(blue);
    } catch (UnitException obj) {
        cout << "Error #" << obj.code << endl;
    }
    red.attack(blue);
    blue.attack(red);
    
    cout << "3st fight:" << endl;
    cout << "Red   - HP: " << red.getHitPoints() << endl;
    cout << "Blue  - HP: " << blue.getHitPoints() << endl;
    
    try {
        red.attack(blue);
        blue.attack(red);
    } catch (UnitException obj) {
        cout << "Error #" << obj.code << endl;
    }
    
    cout << "3st fight:" << endl;
    cout << "Red   - HP: " << red.getHitPoints() << endl;
    cout << "Blue  - HP: " << blue.getHitPoints() << endl;
    
    try {
        Unit green(-10, 10);
    } catch (UnitException obj) {
        cout << "Error #" << obj.code << endl;
    }
    
    try {
        Unit green(10, -10);
    } catch (UnitException obj) {
        cout << "Error #" << obj.code << endl;
    }
    
    return 0;
}
