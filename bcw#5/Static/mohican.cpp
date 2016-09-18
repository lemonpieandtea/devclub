#include <iostream>

using namespace std;

class Mohican {
    private:
        int id;
        static int number;
        static int lastId;
        static Mohican* lastMohican;
        
    public:
        Mohican();
        Mohican(const Mohican& other);
        
        static int getNumber();
        int getId();
        static int getLastId();
        static Mohican& getLastMohican();
};

Mohican::Mohican() {
    number += 1;
    lastId += 1;
    id = lastId;
    lastMohican = this;
}

Mohican::Mohican(const Mohican& other) {
    number += 1;
    lastId += 1;
    id = lastId;
    lastMohican = this;
}

int Mohican::getId() {
    return id;
}

int Mohican::number = 0;

int Mohican::lastId = 900;

Mohican* Mohican::lastMohican = NULL;

int Mohican::getNumber() {
    return number;
}

int Mohican::getLastId() {
    return lastId;
}

Mohican& Mohican::getLastMohican() {
    return *lastMohican;
}

int main() {
    Mohican a;
    Mohican b;
    Mohican c = a;
    Mohican d = b;
    
    
    cout << "Total: " << Mohican::getNumber() << endl;
    cout << "Name: " << a.getId() << " " << b.getId() << " " << c.getId() << " " << d.getId() << endl;
    cout << "Last Name: " << Mohican::getLastId() << endl;
    cout << "Last Mohican: " << Mohican::getLastMohican().getId() << endl;
    
    return 0;
}
