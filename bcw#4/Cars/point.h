#ifndef POINT_H
#define POINT_H

#define DEFAULT_START_X 0
#define DEFAULT_START_Y 0

class Point {
    private:
        double x;
        double y;
        
    public:
        Point();
        Point(const double, const double);
        double getX() const;
        double getY() const;
        void setX(const double);
        void setY(const double);
        double distance(const Point&) const;
};

std::ostream& operator<<(std::ostream&, const Point&);

#endif // POINT_H
