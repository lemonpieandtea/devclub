#include "complex.h"
#include <iostream>

using namespace std;

int main() {
    Complex a(1, 1);
    Complex b(2, 2);
    Complex c;
    
    cout << "Complex: " << a << " Abs: " << a.abs() << endl;
    cout << "Complex: " << b << " Abs: " << b.abs() << endl;
    cout << a << " + "  << b << " = " << a + b << endl;
    cout << a << " - "  << b << " = " << a - b << endl;
    cout << a << " * "  << b << " = " << a * b << endl;
    cout << a << " == "  << b << " = " << (a == b) << endl;
    cout << a << " != "  << b << " = " << (a != b) << endl;
    
    c = a + b;
    
    cout << "Complex: " << c << " Abs: " << c.abs() << endl;
    
    c *= Complex(10, 10);
    
    cout << "Complex: " << c << " Abs: " << c.abs() << endl;
    
    return 0;
}
