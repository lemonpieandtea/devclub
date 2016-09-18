#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
    private:
        double re;
        double im;
    
    public:
        Complex();
        Complex(double, double);
        double getRe() const;
        double getIm() const;
        double abs() const;
        void operator+=(const Complex&);
        void operator-=(const Complex&);
        void operator*=(const Complex&);
        bool operator==(const Complex&) const;
        bool operator!=(const Complex&) const;
        Complex operator+(const Complex&) const;
        Complex operator-(const Complex&) const;
        Complex operator*(const Complex&) const;
};

std::ostream& operator<<(std::ostream&, const Complex&);

#endif // COMPLEX_H
