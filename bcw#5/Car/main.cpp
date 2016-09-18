#include <iostream>
#include "Car.h"

using namespace std;

int main() {
    Car audi(string("Audi"), 40.5, 4);
    Car bmw(string("BMW"), 60.9, 5);
    Car vaz(string("VAZ"), 120.0, 9);
    
    cout << "---> Initial <---" << endl;
    cout << audi << endl << bmw << endl << vaz << endl;
    
    audi.addFuel(39);
    bmw.addFuel(58);
    vaz.addFuel(120);
    
    cout << endl << "---> Add Fuel <---" << endl;
    cout << audi << endl << bmw << endl << vaz << endl;
    
    cout << endl;
    
    audi.startEngine();
    bmw.startEngine();
    vaz.startEngine();
    
    cout << endl << "---> Start engine <---" << endl;
    cout << audi << endl << bmw << endl << vaz << endl;
    
    audi.travel(2.1);
    bmw.travel(3.2);
    vaz.travel(4.3);
    
    cout << endl << "---> Travel <---" << endl;
    cout << audi << endl << bmw << endl << vaz << endl;
    
    audi.stopEngine();
    bmw.stopEngine();
    vaz.stopEngine();
    
    cout << endl << "---> Stop engine <---" << endl;
    cout << audi << endl << bmw << endl << vaz << endl << endl;
    
    audi.startEngine();
    bmw.startEngine();
    vaz.startEngine();
    
    audi.travel(100);
    bmw.travel(100);
    vaz.travel(100);
    
    cout << endl << "---> Travel Far Avay <---" << endl;
    cout << audi << endl << bmw << endl << vaz << endl;
    
    cout << endl << "---> Exceptions <---" << endl;
    Car car("car", 5, 1);
    
    try {
        car.startEngine();
    } catch (NoFuelException obj) {
        cout << "No Fuel!" << endl;
    }
    
    try {
        car.addFuel(100);
    } catch (FuelOverflowException obj) {
        cout << "Too much fuel!" << endl;
    }
    
    car.addFuel(5);
    
    try {
        car.travel(50);
    } catch (MovementException obj) {
        cout << "Turn engine first!" << endl;
    }
    
    return 0;
}
