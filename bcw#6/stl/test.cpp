#include <set>
#include <list>
#include <map>
#include <iostream>

using namespace std;

#define SIZE 100

int main() {
    set<int> myset;
    list<int> mylist(5,99);
    map<char,int> mymap;
    
    mymap['a']=10;
    mymap['b']=30;
    mymap['c']=50;
    mymap['d']=70;
    
    for ( int i = 0; i < SIZE; i++ ) {
        myset.insert(i);
    }
    
    for ( set<int>::iterator it = myset.begin(); it != myset.end(); it++ ) {
        cout << *it << ' ';
    }
    cout << endl << endl;
    for ( list<int>::iterator it = mylist.begin(); it != mylist.end(); it++ ) {
        cout << *it << ' ';
    }
    cout << endl << endl;
    
    for ( map<char,int>::iterator it = mymap.begin(); it != mymap.end(); it++ ) {
        cout << it->first << " = " << it->second << endl;
    }
    cout << endl;
    
    return 0;
}
