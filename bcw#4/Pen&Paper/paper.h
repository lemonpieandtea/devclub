#ifndef PAPER_H
#define PAPER_H

#include <string>

#define DEFAULT_PAPER_CAPACITY 140
#define DEFAULT_PAPER_TEXT ""

class PaperException {
    public:
        int code;
        PaperException(const int);
};

class Paper {
    private:
        int capacity;
        std::string text;
        
    public:
        Paper();
        Paper(const int);
        int getCapacity() const;
        std::string getText() const;
        void showText() const;
        void putText(const char&);
};

std::ostream& operator<<(std::ostream&, const Paper&);

#endif // PAPER_H
