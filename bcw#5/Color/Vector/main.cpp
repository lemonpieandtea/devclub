#include <iostream>
#include "colorVector.h"

using namespace std;

int main() {
    ColorVector a(1, 2, "Red");
    ColorVector b(3, 4, "Blue");
    ColorVector c;
    
    cout << "ColorVector: " << a << ", length = " << a.length() << endl;
    cout << "ColorVector: " << b << ", length = " << b.length() << endl;
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " == " << b << " is " << (a == b) << endl;
    cout << a << " != " << b << " is " << (a != b) << endl;
    
    c = a + b;
    
    cout << "ColorVector: " << c << ", length = " << c.length() << endl;
    
    c -= ColorVector(10, 10, "White");
    
    cout << "ColorVector: " << c << ", length = " << c.length() << endl;
    
    return 0;
}
