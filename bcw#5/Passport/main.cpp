#include <iostream>
#include "passport.h"
#include "date.h"

using namespace std;

int main() {
    Passport passport1("Vasya", "Pupkin", Date(10, 10, 1979));
    Passport passport2("Petya", "Lobin", Date(11, 9, 1982));
    Passport passport3("Nina", "Korvina", Date(12, 8, 1974));
    Passport passport4("Tamara", "Lubina", Date(13, 7, 1989));
    Passport passport5 = passport2;
    Passport passport6("Valera", "Grubin", Date(14, 7, 1985), "ZZ");
    Passport passport7("Ludmila", "Nalivayko", Date(15, 6, 1964), "ZZ");
    
    cout << passport1 << endl << passport2 << endl << passport3 << endl << passport4 << endl;
    cout << endl << passport5 << endl;
    cout << endl << passport6 << endl << passport7 << endl;
    
    cout << endl << "Exceptions:" << endl;
    try {
        Passport tmp("Name", "Surname", Date(1, 1, 2001), "AAA");
    } catch (WrongSeriesException obj) {
        cout << "WrongSeriesException" << endl;
    }
    try {
        Passport tmp("Name", "Surname", Date(1, 1, 2001), "55");
    } catch (WrongSeriesException obj) {
        cout << "WrongSeriesException" << endl;
    }
    try {
        for ( int i = 0; i < MAX_NUMBERS; i++ ) {
            Passport tmp("Name", "Surname", Date(1, 1, 2001), "ZZ");
        }
    } catch (LastSeriesException obj) {
        cout << "LastSeriesException" << endl;
    }
    
    return 0;
}
