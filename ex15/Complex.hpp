#ifndef COMPLEX_HPP
# define COMPLEX_HPP

# include <iostream>
# include "Vector.hpp"
# include "Matrix.hpp"
# include "functions.hpp"

class Complex {
    public:
        typedef double value_type;

    Complex() {}
    Complex(value_type r, value_type im) : _r(r), _im(im) {}
    Complex(const Complex& x) : _r(x._r), _im(x._im) {}
    Complex(const value_type& r) : _r(r), _im(0) {}
    ~Complex() {}
    Complex&    operator=(const Complex& c) {
        this->_r = c._r;
        this->_im = c._im;
        return *this;
    }

    value_type  module(void) {
        return pow(pow(this->_r, 2) + pow(this->_im, 2), 0.5);
    }

    Complex&    operator=(const value_type& r) {
        this->_r = r;
        this->_im = 0;
        return *this;
    }

    Complex&    operator+=(const Complex& c) {
        this->_r += c._r;
        this->_im += c._im;
        return *this;
    }

    Complex&    operator-=(const Complex& c) {
        this->_r -= c._r;
        this->_im -= c._im;
        return *this;
    }

    Complex&    operator*=(const Complex& c) {
        value_type r = (this->_r * c._r) - (this->_im * c._im);
        this->_im = (this->_r * c._im) + (this->_im * c._r);
        this->_r = r;
        return *this;
    }

    Complex&    operator/=(const Complex& c) {
        value_type d = c._r * c._r + c._im * c._im;
        value_type r = (this->_r * c._r + this->_im * c._im) / d;
        this->_im = (this->_im * c._r - this->_r * c._im) / d;
        this->_r = r;
        return *this;
    }

    friend Complex    operator+(const Complex& c1, const Complex& c2) {
        return (Complex(c1._r + c2._r, c1._im + c2._im));
    }

    friend Complex    operator-(const Complex& c1, const Complex& c2) {
        return (Complex(c1._r - c2._r, c1._im - c2._im));
    }

    friend Complex    operator*(const Complex& c1, const Complex& c2) {
        Complex x;
        x._r = (c1._r * c2._r) - (c1._im * c2._im);
        x._im = (c1._r * c2._im) + (c1._im * c2._r);
        return x;
    }

    friend Complex    operator/(const Complex& c1, const Complex& c2) {
        Complex x;
        value_type d = c2._r * c2._r + c2._im * c2._im;
        x._r = (c1._r * c2._r + c1._im * c2._im) / d;
        x._im = (c1._im * c2._r - c1._r * c2._im) / d;
        return x;
    }

    friend bool        operator==(const Complex& c1, const Complex& c2) {
        return (c1._r == c2._r) && (c1._im == c2._im);
    }

    friend bool        operator!=(const Complex& c1, const Complex& c2) {
        return !(c1 == c2);
    }

    friend std::ostream& operator << (std::ostream& os, const Complex &c) {
        os << c._r;
        if (c._im < 0 )
            os << " - " << -c._im << "i";
        else
            os << " + " << c._im << "i";
        return os;
    }

    private:
        value_type _r;
        value_type _im;
};

#endif
