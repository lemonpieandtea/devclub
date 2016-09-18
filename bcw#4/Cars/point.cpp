#include <cmath>
#include <iostream>
#include "point.h"

Point::Point() : x(DEFAULT_START_X), y(DEFAULT_START_Y) {}

Point::Point(const double x, const double y) : x(x), y(y) {}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::setX(const double x) {
    this->x = x;
}

void Point::setY(const double y) {
    this->y = y;
}

double Point::distance(const Point& other) const {
    Point temp = other;
    
    return hypot(other.x-x, other.y-y);
}

std::ostream& operator<<(std::ostream& out, const Point& a) {
    out << "(" << a.getX() << ", " << a.getY() << ")";
    return out;
}
