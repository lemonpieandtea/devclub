#include <iostream>
#include "colorPoint.h"

ColorPoint::ColorPoint() : Point(), color("Black") {}

ColorPoint::ColorPoint(double x, double y, std::string color) : Point(x, y), color(color) {}

const std::string& ColorPoint::getColor() const {
    return color;
}

bool ColorPoint::operator==(const ColorPoint& point) const {
    if ( (Point) *this == (Point) point ) {
        return color.compare(point.getColor()) ? false : true;
    }
    
    return false;
}

bool ColorPoint::operator!=(const ColorPoint& point) const {
    return !operator==(point);
}

std::ostream& operator<<(std::ostream& out, const ColorPoint& point) {
    out << point.getColor() << " " << (Point) point;
    
    return out;
}
