#ifndef POINT_H
#define POINT_H

class Point {
    private:
        double x;
        double y;
    
    public:
        Point();
        Point(double, double);
        double getX() const;
        double getY() const;
        double distance(const Point&) const;
        bool operator==(const Point&) const;
        bool operator!=(const Point&) const;
};

std::ostream& operator<<(std::ostream&, const Point&);

#endif // POINT_H
