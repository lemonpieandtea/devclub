#include <iostream>
#include "geoProg.h"

using namespace std;

int main() {
    GeoProg prog1(1, 2, 10);
    GeoProg prog2(256, 2, 10);
    
    for ( ; !prog1.over() || !prog2.over(); prog1++, prog2++ ) {
        cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << endl;
    }
    cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << endl;
    
    for ( ; !prog1.first() || !prog2.first(); prog1--, prog2-- ) {
        cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << endl;
    }
    cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << endl;
}
