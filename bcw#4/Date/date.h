#ifndef DATE_H
#define DATE_H

#include <iostream>

#define FEBRUARY 2
#define NOT_LEAP_DAYS 28
#define LEAP_DAYS 29
#define HIGH_MOUNTHS_DAYS 31
#define LOW_MOUNTHS_DAYS 30
#define HIGH_MOUNTHS_QUANTITY 7
#define LOW_MOUNTHS_QUANTITY 4

class DateException {
    public:
        std::string text;
        DateException(const std::string&);
};

class Date {
    private:
        const int highDays[HIGH_MOUNTHS_QUANTITY] = {1, 3, 5, 7, 8, 10, 12};
        const int lowDays[LOW_MOUNTHS_QUANTITY] = {4, 6, 9, 11};
        int day;
        int mounth;
        int year;
        int februaryDays(const int) const;
        bool dayCorrect(const int) const;
        bool mounthCorrect(const int) const;
        bool yearCorrect(const int) const;

    public:
        Date(const int, const int, const int);
        int getDay() const;
        int getMounth() const;
        int getYear() const;
};

std::ostream& operator<<(std::ostream&, const Date&);

#endif // DATE_H
