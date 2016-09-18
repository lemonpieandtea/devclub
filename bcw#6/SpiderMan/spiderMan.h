#ifndef SPIDERMAN_H
#define SPIDERMAN_H

#include "man.h"
#include "spider.h"
#include <iostream>

class SpiderMan : public Man, public Spider {
    private:
        std::string name;
        
    public:
        SpiderMan();
        virtual ~SpiderMan();
        const std::string& getName() const;
        void walk();
        void jump();
};

#endif // SPIDERMAN_H
