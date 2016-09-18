#include <iostream>
#include "myList.h"

ListError::ListError(int code) : code(code) {}

void MyList::arrayCopy(int destination[], int lo, int hi, int shift = 0) {
    for ( int i = lo, j = lo + shift; i < hi; i++, j++ ) {
        destination[j] = array[i];
    }
}

MyList::MyList() : size(0) {};

MyList::MyList(int target[], int value) {
    if ( value < 0 ) {
        throw ListError(1);
    }
    
    size = value;
    
    if ( size > 0 ) {
        array = new int[size];
    }
    
    for ( int i = 0; i < value; i++ ) {
        array[i] = target[i];
    }
}

MyList::~MyList() {
    if ( size > 0 ) {
        delete array;
    }
}

int MyList::getSize() const {
    if ( size < 0 ) {
        throw ListError(2);
    }
    
    return size;
}

int MyList::getValue() const {
    if ( size < 0 ) {
        throw ListError(2);
    }
    
    return array[size-1];
}

int MyList::getValue(const int position) const {
    int length = size - 1;
    
    if ( size < 0 ) {
        throw ListError(2);
    }
    if ( position < 0 || position > length ) {
        throw ListError(3);
    }
    
    return array[position];
}

void MyList::putValue(const int& value) {
    int* temp;
    int oldSize = size;
    
    size += 1;
    
    temp = new int[size];
    
    arrayCopy(temp, 0, oldSize);
    temp[oldSize] = value;
    
    delete array;
    array = temp;
}

void MyList::putValue(const int& value, const int position ) {
    int* temp;
    int oldSize = size;
    
    size += 1;
    
    temp = new int[size];
    
    arrayCopy(temp, 0, position);
    temp[position] = value;
    arrayCopy(temp, position+1, oldSize, 1);
    
    delete array;
    array = temp;
}

void MyList::putMultiple(const int value[], const int length) {
    int* temp;
    int oldSize = size;
    
    size += length;
    
    temp = new int[size];
    
    arrayCopy(temp, 0, oldSize);
    for ( int i = oldSize, j = 0; j < length; i++, j++ ) {
        temp[i] = value[j];
    }
    
    delete array;
    array = temp;
}

void MyList::remove() {
    int* temp;
    
    if ( size < 1 ) {
        throw ListError(4);
    }
    
    size -= 1;
    
    temp = new int[size];
    arrayCopy(temp, 0, size);
    
    delete array;
    array = temp;
}

void MyList::remove(const int length) {
    int* temp;
    
    if ( size < length ) {
        throw ListError(5);
    }
    
    size -= length;
    
    temp = new int[size];
    arrayCopy(temp, 0, size);
    
    delete array;
    array = temp;
}

void MyList::trimm(const int length) {
    if ( length > size ) {
        throw ListError(6);
    }
    
    remove(size-length);
}

void MyList::operator+=(const int& other) {
    putValue(other);
}

void MyList::operator-=(const int& length) {
    remove(length);
}

std::ostream& operator<<(std::ostream& out, const MyList& a) {
    int length = a.getSize() - 1;
    
    if ( length < 0 ) {
        throw ListError(2);
    }
    
    for ( int i = 0; i < length; i++ ) {
        out << a.getValue(i) << " ";
    }
    out << a.getValue(length);
    
    return out;
}
