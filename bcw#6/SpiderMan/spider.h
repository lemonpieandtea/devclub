#ifndef SPIDER_H
#define SPIDER_H

#include "thing.h"
#include <iostream>

class Spider : virtual public Thing {
    private:
        std::string name;
        
    public:
        Spider();
        virtual ~Spider();
        const std::string& getName() const;
        void walk();
        void jump();
};

#endif // SPIDER_H
