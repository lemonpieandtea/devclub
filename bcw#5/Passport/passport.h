#ifndef PASSPORT_H
#define PASSPORT_H

#include <string>
#include "date.h"

#define MAX_NUMBERS 10000000
#define ZEROSS_FILL 6

class LastSeriesException {};
class WrongSeriesException {};

class Passport {
    private:
        std::string series;
        int number;
        std::string firstName;
        std::string lastName;
        Date date;
        
        static std::string lastSeries;
        static int lastNumber;
        
        void updateSeries();
        void updateNumber();
        
    public:
        Passport(std::string firstName, std::string lastName, Date date);
        Passport(std::string firstName, std::string lastName, Date date, std::string series);
        
        const std::string& getSeries() const;
        int getNumber() const;
        const std::string& getFirstName() const;
        const std::string& getLastName() const;
        const Date& getDate() const;
};

std::ostream& operator<<(std::ostream&, const Passport& passport);

#endif // PASSPORT_H
