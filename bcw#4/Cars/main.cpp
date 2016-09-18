#include <iostream>
#include "car.h"
#include "point.h"

using namespace std;

int main() {
    Point location1(1.5, 1.5);
    Point location2(3.7, 3.7);
    Point location3(9.7, 9.7);
    Car bmw;
    Car audi(65, 5);
    Car ford(40, 9, location1);
    
    cout << "Initial:" << endl;
    cout << "bmw  - tank: " << bmw.getTankCapacity() << "\tfuel: " << bmw.getFuel();
    cout << "\tconsumption: " << bmw.getConsumption() << "\tposition: " << bmw.getPosition() << endl;
    cout << "audi - tank: " << audi.getTankCapacity() << "\tfuel: " << audi.getFuel();
    cout << "\tconsumption: " << audi.getConsumption() << "\tposition: " << audi.getPosition() << endl;
    cout << "ford - tank: " << ford.getTankCapacity() << "\tfuel: " << ford.getFuel();
    cout << "\tconsumption: " << ford.getConsumption() << "\tposition: " << ford.getPosition() << endl;
    
    bmw.refill(30);
    audi.refill(50);
    ford.refillFull();
    
    cout << "Refill:" << endl;
    cout << "bmw  - tank: " << bmw.getTankCapacity() << "\tfuel: " << bmw.getFuel();
    cout << "\tconsumption: " << bmw.getConsumption() << "\tposition: " << bmw.getPosition() << endl;
    cout << "audi - tank: " << audi.getTankCapacity() << "\tfuel: " << audi.getFuel();
    cout << "\tconsumption: " << audi.getConsumption() << "\tposition: " << audi.getPosition() << endl;
    cout << "ford - tank: " << ford.getTankCapacity() << "\tfuel: " << ford.getFuel();
    cout << "\tconsumption: " << ford.getConsumption() << "\tposition: " << ford.getPosition() << endl;
    
    bmw.ride(location1);
    audi.ride(location2);
    ford.ride(location3);
    
    cout << "Ride:" << endl;
    cout << "bmw  - tank: " << bmw.getTankCapacity() << "\tfuel: " << bmw.getFuel();
    cout << "\tconsumption: " << bmw.getConsumption() << "\tposition: " << bmw.getPosition() << endl;
    cout << "audi - tank: " << audi.getTankCapacity() << "\tfuel: " << audi.getFuel();
    cout << "\tconsumption: " << audi.getConsumption() << "\tposition: " << audi.getPosition() << endl;
    cout << "ford - tank: " << ford.getTankCapacity() << "\tfuel: " << ford.getFuel();
    cout << "\tconsumption: " << ford.getConsumption() << "\tposition: " << ford.getPosition() << endl;
    
    cout << "Steal:" << endl;
    try {
        bmw.refill(-5);
    } catch (CarException obj) {
        cout << "CarException #" << obj.code << endl;
    }
    
    bmw.updateTankCapacity(70);
    audi.updateConsumption(2);
    ford.update(50, 7);
    
    cout << "Update:" << endl;
    cout << "bmw  - tank: " << bmw.getTankCapacity() << "\tfuel: " << bmw.getFuel();
    cout << "\tconsumption: " << bmw.getConsumption() << "\tposition: " << bmw.getPosition() << endl;
    cout << "audi - tank: " << audi.getTankCapacity() << "\tfuel: " << audi.getFuel();
    cout << "\tconsumption: " << audi.getConsumption() << "\tposition: " << audi.getPosition() << endl;
    cout << "ford - tank: " << ford.getTankCapacity() << "\tfuel: " << ford.getFuel();
    cout << "\tconsumption: " << ford.getConsumption() << "\tposition: " << ford.getPosition() << endl;
    
    cout << "Exception:" << endl;
    try {
        Car car(-5, 10);
    } catch (CarException obj) {
        cout << "CarException #" << obj.code << endl;
    }
    
    try {
        Car car(5, -10);
    } catch (CarException obj) {
        cout << "CarException #" << obj.code << endl;
    }
    
    Car car(5, 10);
    
    try {
        car.refill(100);
    } catch (CarException obj) {
        cout << "CarException #" << obj.code << endl;
    }
    
    try {
        car.refill(-100);
    } catch (CarException obj) {
        cout << "CarException #" << obj.code << endl;
    }
    
    return 0;
}
