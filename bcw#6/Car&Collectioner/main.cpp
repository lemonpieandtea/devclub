#include <iostream>
#include "Collectioner.h"
#include "Car.h"

using namespace std;

int main() {
    Collectioner* anonymous = new Collectioner("Anonymous");
    
    Car* toyota = new Car(anonymous, "Toyota");
    Car* bmw = new Car(anonymous, "BMW");
    Car* chevrolet = new Car(anonymous, "Chevrolet");
    
    anonymous->removeCar(chevrolet);
    
    cout << anonymous->getName() << " collection: " << endl;
    cout << anonymous->getCollection() << endl;
    
    return 0;
}
