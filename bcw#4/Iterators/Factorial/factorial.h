#ifndef FACTORIAL_H
#define FACTORIAL_H

class FactorialException {
    public:
        int code;
        FactorialException(int);
};

class Factorial {
    private:
        int start;
        int index;
        int currentValue;
        int limit;
        int factorial(int);
        
    public:
        Factorial(const int, const int);
        int getIndex() const;
        void next();
        void prev();
        int value();
        bool over() const;
        bool first() const;
        int operator++();
        int operator++(int);
        int operator--();
        int operator--(int);
        int operator*();
};

std::ostream& operator<<(std::ostream&, Factorial&);

#endif // FACTORIAL_H
