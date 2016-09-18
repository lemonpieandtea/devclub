#include <iostream>
#include "date.h"

using namespace std;

int main() {
    Date today(29, 8, 2013);
    Date happybirthday(17, 1, 1989);
    Date blackDay(29, 2, 1600);
    
    cout << today << endl << happybirthday << endl << blackDay << endl;
    
    try {
        Date date(99, 8, 2013);
    } catch (DateException obj) {
        cout << "DateException #" << obj.code << endl;
    }
    try {
        Date date(29, 99, 2013);
    } catch (DateException obj) {
        cout << "DateException #" << obj.code << endl;
    }
    try {
        Date date(29, 8, 0);
    } catch (DateException obj) {
        cout << "DateException #" << obj.code << endl;
    }
    try {
        Date date(29, 2, 1700);
    } catch (DateException obj) {
        cout << "DateException #" << obj.code << endl;
    }
    
    return 0;
}
