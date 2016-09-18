#ifndef COLOR_VECTOR_H
#define COLOR_VECTOR_H

#include <string>
#include "vector.h"

class ColorVector : public Vector {
    private:
        std::string color;
    
    public:
        ColorVector();
        ColorVector(double x, double y, const std::string& color);
        const std::string& getColor() const;
        bool operator==(const ColorVector& other) const;
        bool operator!=(const ColorVector& other) const;
        void operator+=(const ColorVector& other);
        void operator-=(const ColorVector& other);
        ColorVector operator+(const ColorVector& other) const;
        ColorVector operator-(const ColorVector& other) const;
};

std::ostream& operator<<(std::ostream& out, const ColorVector& vector);

#endif // COLOR_VECTOR_H
