#ifndef AUTOPEN_H
#define AUTOPEN_H

#include "pen.h"

class ClickAutoPenException {};

class AutoPen : public Pen {
    private:
        bool open;
        bool isOpen() const;
        
    public:
        AutoPen();
        AutoPen(const int);
        virtual ~AutoPen();
        void click();
        void write(Paper& paper, const std::string& text);
};

#endif // AUTOPEN_H
