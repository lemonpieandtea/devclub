#ifndef PRIME_H
#define PRIME_H

#define DEVISOR 2

class PrimeException {
    public:
        int code;
        PrimeException(int);
};

class Prime {
    private:
        int start;
        int index;
        int currentValue;
        int limit;
        int* cache;
        bool isPrime(int);
        int prime(int);
        
    public:
        Prime(const int, const int);
        ~Prime();
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

std::ostream& operator<<(std::ostream&, Prime&);

#endif // PRIME_H
