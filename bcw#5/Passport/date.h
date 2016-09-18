#ifndef DATE_H
#define DATE_H

#define FEBRUARY 2
#define NOT_LEAP_DAYS 28
#define LEAP_DAYS 29
#define HIGH_MOUNTHS_DAYS 31
#define LOW_MOUNTHS_DAYS 30
#define HIGH_MOUNTHS_QUANTITY 7
#define LOW_MOUNTHS_QUANTITY 4

class WrongDayException {};
class WrongMounthException {};
class WrongYearException {};

class Date {
    private:
        int day;
        int mounth;
        int year;
        
        static const int highDays[];
        static const int lowDays[];
        
        int februaryDays(const int year) const;
        bool dayCorrect(const int day) const;
        bool mounthCorrect(const int mounth) const;
        bool yearCorrect(const int year) const;
        
    public:
        Date(const int day, const int mounth, const int year);
        
        int getDay() const;
        int getMounth() const;
        int getYear() const;
};

std::ostream& operator<<(std::ostream&, const Date& date);

#endif // DATE_H
