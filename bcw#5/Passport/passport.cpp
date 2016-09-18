#include <iostream>
#include "passport.h"

std::string Passport::lastSeries = "AA";

int Passport::lastNumber = 0;

void Passport::updateSeries() {
    lastSeries[1] += 1;
    
    if ( lastSeries[1] > 'Z' ) {
        lastSeries[0] += 1;
    }
    
    if ( lastSeries[0] > 'Z' ) {
        throw LastSeriesException();
    }
}

void Passport::updateNumber() {
    lastNumber += 1;
    
    if ( lastNumber > MAX_NUMBERS ) {
        lastNumber = 0;
        
        updateSeries();
    }
}

Passport::Passport(std::string firstName, std::string lastName, Date date) : firstName(firstName), lastName(lastName), date(date), series(lastSeries), number(lastNumber) {
    updateNumber();
}

Passport::Passport(std::string firstName, std::string lastName, Date date, std::string series) : firstName(firstName), lastName(lastName), date(date) {
    bool wrongSeries = (series[0] < 'A' || series[0] > 'Z') && (series[1] < 'A' || series[1] > 'Z');
    if ( wrongSeries == true || series.length() != 2 ) {
        throw WrongSeriesException();
    }
    
    if ( lastSeries.compare(series) ) {
        lastSeries = series;
        lastNumber = 0;
    }
    
    this->series = lastSeries;
    number = lastNumber;
    
    updateNumber();
}

const std::string& Passport::getSeries() const {
    return series;
}

int Passport::getNumber() const {
    return number;
}

const std::string& Passport::getFirstName() const {
    return firstName;
}

const std::string& Passport::getLastName() const {
    return lastName;
}

const Date& Passport::getDate() const {
    return date;
}

std::ostream& operator<<(std::ostream& out, const Passport& passport) {
    std::streamsize size = std::cout.width();
    
    std::cout << "Passport:" << std::endl;
    std::cout << "-- ID: " << passport.getSeries() << " ";
    std::cout.width(ZEROSS_FILL);
    std::cout.fill('0');
    std::cout << passport.getNumber() << std::endl;
    std::cout.width(size);
    std::cout << "-- Person: " << passport.getFirstName() << " " << passport.getLastName() << std::endl;
    std::cout << "-- Date of birth: " << passport.getDate();
    
    return out;
}
