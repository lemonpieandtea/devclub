#include <iostream>

using namespace std;

class Parent {
    private:
        int value;
    public:
        Parent() : value(9) {
            cout << "Parent::Parent()" << endl;
        }
        Parent(int value) : value(value) {
            cout << "Parent::Parent(int)" << endl;
        }
        virtual ~Parent() {
            cout << "Parent::~Parent()" << endl;
        }
        int getValue() {
            return value;
        }
};

class Child : public Parent {
    private:
        int value;
    public:
        Child() : value(99) {
            cout << "Child::Child()" << endl;
        }
        Child(int value) : value(value) {
            cout << "Child::Child(int)" << endl;
        }
        ~Child() {
            cout << "Child::~Child()" << endl;
        }
        int getValue() {
            return value;
        }
};

int main() {
    Child* child = new Child(25);
    
    cout << "Child:  " << child->getValue() << endl;
    cout << "Parent: " << child->Parent::getValue() << endl;
    
    delete child;
    
    return 0;
}
