#ifndef VECTOR_H
#define VECTOR_H

class Vector {
    private:
        double x;
        double y;
    
    public:
        Vector();
        Vector(double, double);
        double getX() const;
        double getY() const;
        double length() const;
        void operator+=(const Vector&);
        void operator-=(const Vector&);
        bool operator==(const Vector&) const;
        bool operator!=(const Vector&) const;
        Vector operator+(const Vector&) const;
        Vector operator-(const Vector&) const;
};

std::ostream& operator<<(std::ostream&, const Vector&);

#endif // VECTOR_H
