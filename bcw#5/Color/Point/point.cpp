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

double Point::distance(const Point& point) const {
    Point temp = point;
    
    return hypot(point.x-x, point.y-y);
}

bool Point::operator==(const Point& point) const {
    return (x == point.getX() && y == point.getY());
}

bool Point::operator!=(const Point& point) const {
    return !operator==(point);
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "(" << point.getX() << ", " << point.getY() << ")";
    
    return out;
}
