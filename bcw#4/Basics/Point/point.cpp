#include <iostream>
#include <cmath>
#include "point.h"

Point::Point() : x(0), y(0) {}
Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::distance(const Point& other) const {
    Point temp = other;
    
    return hypot(other.x-x, other.y-y);
}

bool Point::operator==(const Point& other) const {
    return (x == other.getX() && y == other.getY());
}

bool Point::operator!=(const Point& other) const {
    return !operator==(other);
}

std::ostream& operator<<(std::ostream& out, const Point& a) {
    out << "(" << a.getX() << ", " << a.getY() << ")";
    return out;
}
