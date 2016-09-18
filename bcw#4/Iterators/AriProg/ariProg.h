#ifndef ARIPROG_H
#define ARIPROG_H

class AriProg {
    private:
        int index;
        int currentValue;
        int step;
        int limit;
        
    public:
        AriProg(const int, const int, const int);
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

std::ostream& operator<<(std::ostream&, AriProg&);

#endif // ARIPROG_H
