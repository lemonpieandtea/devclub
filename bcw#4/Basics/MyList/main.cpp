#include <iostream>
#include "myList.h"

using namespace std;

#define SIZE 10

int main() {
    int array1[SIZE] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int array2[SIZE-5] = {0, 1, 2, 3, 4};
    MyList a(array1, SIZE);
    MyList b(array2, SIZE-5);
    
    cout << "Constructor:" << endl;
    cout << "a: " << "size - " << a.getSize() << endl << a << endl;
    cout << "b: " << "size - " << b.getSize() << endl << b << endl;
    
    cout << "a(last): " << a.getValue() << endl;
    cout << "b(2): " << b.getValue(2) << endl;
    
    a.putValue(99);
    b.putValue(199, 0);
    
    cout << "Put:" << endl;
    cout << "a: " << "size - " << a.getSize() << endl << a << endl;
    cout << "b: " << "size - " << b.getSize() << endl << b << endl;
    
    a.trimm(2);
    b.putMultiple(array2, SIZE-5);
    
    cout << "Trim, Put Multiple:" << endl;
    cout << "a: " << "size - " << a.getSize() << endl << a << endl;
    cout << "b: " << "size - " << b.getSize() << endl << b << endl;
    
    a.remove();
    b.remove(3);
    
    cout << "Remove:" << endl;
    cout << "a: " << "size - " << a.getSize() << endl << a << endl;
    cout << "b: " << "size - " << b.getSize() << endl << b << endl;
    
    a += 5;
    b -= 1;
    
    cout << "Overload:" << endl;
    cout << "a: " << "size - " << a.getSize() << endl << a << endl;
    cout << "b: " << "size - " << b.getSize() << endl << b << endl;
    
    cout << "Try:" << endl;
    try {
        MyList c(array1, -5);
    } catch (ListError obj) {
        cout << "Error # " << obj.code << endl;
    }
    
    MyList c;
    
    try {
        cout << c << endl;
    } catch (ListError obj) {
        cout << "Error # " << obj.code << endl;
    }
    
    try {
        a.getValue(100);
    } catch (ListError obj) {
        cout << "Error # " << obj.code << endl;
    }
    
    try {
        c.remove();
    } catch (ListError obj) {
        cout << "Error # " << obj.code << endl;
    }
    
    try {
        a.remove(100);
    } catch (ListError obj) {
        cout << "Error # " << obj.code << endl;
    }
    
    try {
        a.trimm(100);
    } catch (ListError obj) {
        cout << "Error # " << obj.code << endl;
    }
    
    return 0;
}
