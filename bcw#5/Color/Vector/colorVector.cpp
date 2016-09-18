#include <iostream>
#include "colorVector.h"

ColorVector::ColorVector() : Vector(), color("Black") {}

ColorVector::ColorVector(double x, double y, const std::string& color) : Vector(x, y), color(color) {}

const std::string& ColorVector::getColor() const {
    return color;
}

bool ColorVector::operator==(const ColorVector& other) const {
    if ( (Vector) *this == (Vector) other ) {
        return color.compare(other.getColor()) ? false : true;
    }
    
    return false;
}

bool ColorVector::operator!=(const ColorVector& other) const {
    return !operator==(other);
}

void ColorVector::operator+=(const ColorVector& other) {
    Vector::operator+=(other);
    color += "+" + other.getColor();
}

void ColorVector::operator-=(const ColorVector& other) {
    Vector::operator-=(other);
    color += "-" + other.getColor();
}

ColorVector ColorVector::operator+(const ColorVector& other) const {
    ColorVector result = *this;
    
    result += other;
    
    return result;
}

ColorVector ColorVector::operator-(const ColorVector& other) const {
    ColorVector result = *this;
    
    result -= other;
    
    return result;
}

std::ostream& operator<<(std::ostream& out, const ColorVector& vector) {
    out << vector.getColor() << " " << (Vector) vector;
    
    return out;
}
