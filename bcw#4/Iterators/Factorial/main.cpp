#include <iostream>
#include "factorial.h"

using namespace std;

int main() {
    Factorial prog1(1, 5);
    Factorial prog2(6, 5);
    
    cout << "Test:" << endl;
    
    for ( ; !prog1.over() || !prog2.over(); prog1++, prog2++ ) {
        cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << endl;
    }
    cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << endl;
    
    for ( ; !prog1.first() || !prog2.first(); prog1--, prog2-- ) {
        cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << endl;
    }
    cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << endl;
    
    cout << "Exception:" << endl;
    try {
        Factorial bad(-5, 10);
    } catch (FactorialException obj) {
        cout << "FactorialException #" << obj.code << endl;
    }
    
    return 0;
}
