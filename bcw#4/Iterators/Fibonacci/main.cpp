#include <iostream>
#include "fibonacci.h"

using namespace std;

int main() {
    Fibonacci prog1(1, 5);
    Fibonacci prog2(-6, 5);
    
    for ( ; !prog1.over() || !prog2.over(); prog1++, prog2++ ) {
        cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << endl;
    }
    cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << endl;
    
    for ( ; !prog1.first() || !prog2.first(); prog1--, prog2-- ) {
        cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << endl;
    }
    cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << endl;
    
    return 0;
}
