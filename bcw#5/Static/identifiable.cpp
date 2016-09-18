#include <iostream>

using namespace std;

class Identifiable {
    private:
        int id;
        static int number;
        static int lastId;
        
    public:
        Identifiable();
        Identifiable(const Identifiable& other);
        
        static int getNumber();
        int getId();
};

Identifiable::Identifiable() {
    number += 1;
    lastId += 1;
    id = lastId;
}

Identifiable::Identifiable(const Identifiable& other) {
    number += 1;
    lastId += 1;
    id = lastId;
}

int Identifiable::getId() {
    return id;
}

int Identifiable::number = 0;

int Identifiable::lastId = 100500;

int Identifiable::getNumber() {
    return number;
}

int main() {
    Identifiable a;
    Identifiable b;
    Identifiable c = a;
    Identifiable d = b;
    
    cout << "Total: " << Identifiable::getNumber() << endl;
    cout << "ID: " << a.getId() << " " << b.getId() << " " << c.getId() << " " << d.getId() << endl;
    
    return 0;
}
