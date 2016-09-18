#include <iostream>
#include "colorPoint.h"

using namespace std;

int main() {
    ColorPoint a(1, 2, "Green");
    ColorPoint b(3, 4, "Red");
    ColorPoint c;
    
    cout << "Point: " << a << " Point: " << b <<  ", distance = " << a.distance(b) << endl;
    cout << "Point: " << a << " == " << b << " is " << (a == b) << endl;
    cout << "Point: " << a << " != " << b << " is " << (a != b) << endl;
    
    c = a;
    
    cout << "Point: " << c << " == " << a << " is " << (c == a) << endl;
    cout << "Point: " << c << " != " << a << " is " << (c != a) << endl;
    
    return 0;
}
