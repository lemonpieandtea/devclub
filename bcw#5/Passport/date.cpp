#include <iostream>
#include "date.h"

const int Date::highDays[] = {1, 3, 5, 7, 8, 10, 12};

const int Date::lowDays[] = {4, 6, 9, 11};

int Date::februaryDays(const int year) const {
    if ( year % 4 != 0 ) {
        return NOT_LEAP_DAYS;
    }
    if ( year % 100 != 0 ) {
        return LEAP_DAYS;
    }
    if ( year % 400 != 0 ) {
        return NOT_LEAP_DAYS;
    }
    return LEAP_DAYS;
}

bool Date::dayCorrect(const int day) const {
    if ( day < 1 ) {
        return false;
    }
    
    for ( int i = 0; i < HIGH_MOUNTHS_QUANTITY; i++ ) {
        if ( mounth == highDays[i] && day > HIGH_MOUNTHS_DAYS ) {
            return false;
        }
    }
    for ( int i = 0; i < LOW_MOUNTHS_QUANTITY; i++ ) {
        if ( mounth == lowDays[i] && day > LOW_MOUNTHS_DAYS ) {
            return false;
        }
    }
    if ( mounth == FEBRUARY && day > februaryDays(year) ) {
        return false;
    }
    
    return true;
}

bool Date::mounthCorrect(const int mounth) const {
    if ( mounth < 1 || mounth > 12 ) {
        return false;
    }
    
    return true;
}

bool Date::yearCorrect(const int year) const {
    if ( year == 0 ) {
        return false;
    }
    
    return true;
}

Date::Date(const int day, const int mounth, const int year) {
    if ( !yearCorrect(year) ) {
        throw WrongYearException();
    }
    this->year = year;
    
    if ( !mounthCorrect(mounth) ) {
        throw WrongMounthException();
    }
    this->mounth = mounth;
    
    if ( !dayCorrect(day) ) {
        throw WrongDayException();
    }
    this->day = day;
}

int Date::getDay() const {
    return day;
}

int Date::getMounth() const {
    return mounth;
}

int Date::getYear() const {
    return year;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    int day = date.getDay();
    int mounth = date.getMounth();
    
    if ( day < 10 ) {
        out << 0;
    }
    out << date.getDay() << ".";
    
    if ( mounth < 10 ) {
        out << 0;
    }
    out << date.getMounth() << "." << date.getYear();
    
    return out;
}
