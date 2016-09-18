#include <iostream>
#include "gun.h"

using namespace std;

#define COLT_MAGAZINE 6
#define SHOOTS 5

int main() {
    Gun colt(COLT_MAGAZINE);
    Gun beretta;
    
    cout << "Initial:" << endl;
    cout << "colt    - capacity: " << colt.getCapacity() << " bullets: " << colt.getBullets() << endl;
    cout << "beretta - capacity: " << beretta.getCapacity() << " bullets: " << beretta.getBullets() << endl;
    
    colt.recharge(6);
    beretta.recharge(7);
    
    cout << "Recharge:" << endl;
    cout << "colt    - capacity: " << colt.getCapacity() << " bullets: " << colt.getBullets() << endl;
    cout << "beretta - capacity: " << beretta.getCapacity() << " bullets: " << beretta.getBullets() << endl;
    
    for ( int i = 0; i < COLT_MAGAZINE; i++ ) {
        colt.shoot();
    }
    for ( int i = 0; i < SHOOTS; i++ ) {
        beretta.shoot();
    }
    
    cout << "Shoot:" << endl;
    cout << "colt    - capacity: " << colt.getCapacity() << " bullets: " << colt.getBullets() << endl;
    cout << "beretta - capacity: " << beretta.getCapacity() << " bullets: " << beretta.getBullets() << endl;
    
    cout << "Exceptions:" << endl;
    try {
        Gun gun(-5);
    } catch (GunException obj) {
        cout << "Error #" << obj.code << endl;
    }
    
    Gun gun(1);
    
    try {
        gun.recharge(100);
    } catch (GunException obj) {
        cout << "Error #" << obj.code << endl;
    }
    
    try {
        gun.shoot();
    } catch (GunException obj) {
        cout << "Error #" << obj.code << endl;
    }
    
    return 0;
}
