#include <iostream>

using namespace std;

class Countable {
    private:
        static int number;
        
    public:
        Countable();
        static int getNumber();
};

int Countable::number = 0;

Countable::Countable() {
    number += 1;
}

int Countable::getNumber() {
    return number;
}

int main() {
    Countable a;
    Countable b;
    Countable c;
    Countable d;
    
    cout << "Total: " << Countable::getNumber() << endl;
    
    return 0;
}
