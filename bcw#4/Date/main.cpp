#include <iostream>
#include "date.h"

using namespace std;

int main() {
    Date today(15, 5, 2016);
    Date happybirthday(17, 1, 1989);
    Date blackDay(29, 2, 1600);

    cout << today << endl << happybirthday << endl << blackDay << endl;

    try {
        Date date(99, 8, 2013);
    } catch (DateException obj) {
        cout << obj.text << endl;
    }
    try {
        Date date(29, 99, 2013);
    } catch (DateException obj) {
        cout << obj.text << endl;
    }
    try {
        Date date(29, 8, 0);
    } catch (DateException obj) {
        cout << obj.text << endl;
    }
    try {
        Date date(29, 2, 1700);
    } catch (DateException obj) {
        cout << obj.text << endl;
    }
    try {
        Date date(29, 2, 1900);
    } catch (DateException obj) {
        cout << obj.text << endl;
    }

    return 0;
}
