#include <iostream>
#include "vector.h"

using namespace std;

int main() {
    Vector a(1, 2);
    Vector b(3, 4);
    Vector c;
    
    cout << "Vector: " << a << ", length = " << a.length() << endl;
    cout << "Vector: " << b << ", length = " << b.length() << endl;
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " == " << b << " is " << (a == b) << endl;
    cout << a << " != " << b << " is " << (a != b) << endl;
    
    c = a + b;
    
    cout << "Vector: " << c << ", length = " << c.length() << endl;
    
    c += Vector(10, 10);
    
    cout << "Vector: " << c << ", length = " << c.length() << endl;
    
    return 0;
}
