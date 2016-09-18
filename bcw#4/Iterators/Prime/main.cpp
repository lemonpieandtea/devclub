#include <iostream>
#include "prime.h"

using namespace std;

int main() {
    Prime prog1(1, 5);
    Prime prog2(6, 5);
    
    cout << "Initial:" << endl;
    
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
        Prime prog2(-5, 5);
    } catch (PrimeException obj) {
        cout << "PrimeException #" << obj.code << endl;
    }
    
    return 0;
}
