#ifndef POINT_H
#define POINT_H

class Point {
    private:
        double x;
        double y;
    
    public:
        Point();
        Point(double x, double y);
        double getX() const;
        double getY() const;
        double distance(const Point& point) const;
        bool operator==(const Point& point) const;
        bool operator!=(const Point& point) const;
};

std::ostream& operator<<(std::ostream& out, const Point& point);

#endif // POINT_H
