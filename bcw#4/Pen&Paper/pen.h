#ifndef PEN_H
#define PEN_H

#include <string>
#include "paper.h"

#define DEFAULT_PEN_CAPACITY 140

class PenException {
    public:
        int code;
        PenException(const int);
};

class Pen {
    private:
        int capacity;
        int ink;
        
    public:
        Pen();
        Pen(const int);
        int getCapacity() const;
        int getInk() const;
        void fillInk(const int);
        void write(Paper&, const std::string&);
        void write(Paper&, const char*);
};

#endif // PEN_H
