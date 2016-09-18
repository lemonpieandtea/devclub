#include <iostream>

using namespace std;

template <class Temp>
Temp max2(Temp a, Temp b) {
    return (a > b) ? a : b;
}

int main() {
    cout << 'A' << " & " << 'C' << " = " << max2('A', 'C') << endl;
    cout << 10 << " & " << 15 << " = " << max2(10, 15) << endl;
    cout << (1<<25) << " & " << (1<<26) << " = " << max2((1<<25), (1<<26)) << endl;
    cout << 123456789012345 << " & " << 321654987098765 << " = " << max2(123456789012345, 321654987098765) << endl;
    cout << 15.15 << " & " << 18.18 << " = " << max2(15.15, 18.18) << endl;
    
    return 0;
}
