#ifndef GEOPROG_H
#define GEOPROG_H

class GeoProg {
    private:
        int index;
        int currentValue;
        int step;
        int limit;
        
    public:
        GeoProg(const int, const int, const int);
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

std::ostream& operator<<(std::ostream&, GeoProg&);

#endif // GEOPROG_H
