#include <iostream>
#include <cmath>
#include "vector.h"

Vector::Vector() : x(0), y(0) {}
Vector::Vector(double x, double y) : x(x), y(y) {}

double Vector::getX() const {
    return x;
}

double Vector::getY() const {
    return y;
}

double Vector::length() const {
    return hypot(x, y);
}

void Vector::operator+=(const Vector& other) {
    x += other.getX();
    y += other.getY();
}

void Vector::operator-=(const Vector& other) {
    x -= other.getX();
    y -= other.getY();
}

bool Vector::operator==(const Vector& other) const {
    return (x == other.getX() && y == other.getY());
}

bool Vector::operator!=(const Vector& other) const {
    return !operator==(other);
}

Vector Vector::operator+(const Vector& other) const {
    Vector result = *this;
    
    result += other;
    
    return result;
}

Vector Vector::operator-(const Vector& other) const {
    Vector result = *this;
    
    result -= other;
    
    return result;
}

std::ostream& operator<<(std::ostream& out, const Vector& vector) {
    out << "(" << vector.getX() << ", " << vector.getY() << ")";
    return out;
}
