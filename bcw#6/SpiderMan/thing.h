#ifndef THING_H
#define THING_H

#include <iostream>

class Thing {
    private:
        std::string name;
        
    public:
        Thing();
        virtual ~Thing();
        virtual const std::string& getName() const;
        void walk();
        void jump();
};

#endif // THING_H
