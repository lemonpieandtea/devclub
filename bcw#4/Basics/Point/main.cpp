#include <iostream>
#include "point.h"

using namespace std;

int main() {
    Point a(1, 2);
    Point b(3, 4);
    Point c;
    
    cout << "Point: " << a << " Point: " << b <<  ", distance = " << a.distance(b) << endl;
    cout << "Point: " << a << " == " << b << " is " << (a == b) << endl;
    cout << "Point: " << a << " != " << b << " is " << (a != b) << endl;
    
    c = a;
    
    cout << "Point: " << c << " == " << a << " is " << (c == a) << endl;
    cout << "Point: " << c << " != " << a << " is " << (c != a) << endl;
    
    return 0;
}
