#ifndef COLOR_POINT_H
#define COLOR_POINT_H

#include <string>
#include "point.h"

class ColorPoint : public Point {
    private:
        std::string color;
    
    public:
        ColorPoint();
        ColorPoint(double x, double y, std::string color);
        const std::string& getColor() const;
        bool operator==(const ColorPoint& point) const;
        bool operator!=(const ColorPoint& point) const;
};

std::ostream& operator<<(std::ostream& out, const ColorPoint& point);

#endif // COLOR_POINT_H
