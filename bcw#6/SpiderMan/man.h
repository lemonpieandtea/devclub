#ifndef MAN_H
#define MAN_H

#include "thing.h"
#include <iostream>

class Man : virtual public Thing {
    private:
        std::string name;
        
    public:
        Man();
        virtual ~Man();
        const std::string& getName() const;
        void walk();
        void jump();
};

#endif // MAN_H
