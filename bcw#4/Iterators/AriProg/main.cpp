#include <iostream>
#include "ariProg.h"

using namespace std;

int main() {
    AriProg prog1(0, 5, 10);
    AriProg prog2(30, -3, 10);

    for ( ; !prog1.over() || !prog2.over(); ++prog1, ++prog2 ) {
        cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << endl;
    }
    cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << endl;

    for ( ; !prog1.first() || !prog2.first(); prog1--, prog2-- ) {
        cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << endl;
    }
    cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << endl;
}
