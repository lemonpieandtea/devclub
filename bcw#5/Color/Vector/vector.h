#ifndef VECTOR_H
#define VECTOR_H

class Vector {
    private:
        double x;
        double y;
    
    public:
        Vector();
        Vector(double x, double y);
        double getX() const;
        double getY() const;
        double length() const;
        void operator+=(const Vector& other);
        void operator-=(const Vector& other);
        bool operator==(const Vector& other) const;
        bool operator!=(const Vector& other) const;
        Vector operator+(const Vector& other) const;
        Vector operator-(const Vector& other) const;
};

std::ostream& operator<<(std::ostream& out, const Vector& vector);

#endif // VECTOR_H
