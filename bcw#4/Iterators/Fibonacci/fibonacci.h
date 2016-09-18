#ifndef FIBONACCI_H
#define FIBONACCI_H

#define DEVISOR 2

class Fibonacci {
    private:
        int start;
        int index;
        int currentValue;
        int limit;
        int fibonacci(int);
        
    public:
        Fibonacci(const int, const int);
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

std::ostream& operator<<(std::ostream&, Fibonacci&);

#endif // FIBONACCI_H
