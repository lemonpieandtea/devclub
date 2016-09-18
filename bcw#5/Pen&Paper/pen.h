#ifndef PEN_H
#define PEN_H

#include <string>
#include "paper.h"

#define DEFAULT_PEN_CAPACITY 140

class CapacityPenException {};
class OverflowPenException {};
class NoInkPenException {};

class Pen {
    private:
        int capacity;
        int ink;
        
    public:
        Pen();
        Pen(const int);
        virtual ~Pen();
        int getCapacity() const;
        int getInk() const;
        void fillInk(const int);
        void write(Paper& paper, const std::string& text);
};

#endif // PEN_H
