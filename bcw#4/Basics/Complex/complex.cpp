#include "complex.h"
#include <iostream>
#include <cmath>

Complex::Complex() : re(0), im(0) {}
Complex::Complex(double re, double im) : re(re), im(im) {}

double Complex::getRe() const {
    return re;
};

double Complex::getIm() const {
    return im;
};

double Complex::abs() const {
    return hypot(re, im);
};

void Complex::operator+=(const Complex& other) {
    re += other.getRe();
    im += other.getIm();
};

void Complex::operator-=(const Complex& other) {
    re -= other.getRe();
    im -= other.getIm();
};

void Complex::operator*=(const Complex& other) {
    double temp = re;
    
    re = temp * other.re - im * other.im;
    im = temp * other.im + im * other.re;
};

bool Complex::operator==(const Complex& other) const {
    return re == other.re && im == other.im;
};

bool Complex::operator!=(const Complex& other) const {
    return !operator==(other);
};

Complex Complex::operator+(const Complex& other) const {
    Complex result = *this;
    
    result += other;
    
    return result;
};

Complex Complex::operator-(const Complex& other) const {
    Complex result = *this;
    
    result -= other;
    
    return result;
};

Complex Complex::operator*(const Complex& other) const {
    Complex result = *this;
    
    result *= other;
    
    return result;
};

std::ostream& operator<<(std::ostream& out, const Complex& a) {
    out << a.getRe() << (a.getIm() > 0 ? "+" : "") << a.getIm() << "i";
    return out;
};
