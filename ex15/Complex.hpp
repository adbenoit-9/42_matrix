#ifndef COMPLEX_HPP
# define COMPLEXE_HPP

# include <iostream>

class Complex {
    public:
        typedef double value_type;

    Complex() {}
    Complex(value_type r, value_type im) : _r(r), _im(im) {}
    Complex(const Complex& x) : _r(x._r), _im(x._im) {}
    ~Complex() {}
    Complex&    operator=(const Complex& c) {
        this->_r = c._r;
        this->_im = c._im;
    }

    Complex&    operator+(const Complex& c) {
        this->_r += c._r;
        this->_im += c._im;
        return *this;
    }

    Complex&    operator-(const Complex& c) {
        this->_r -= c._r;
        this->_im -= c._im;
        return *this;
    }

    Complex&    operator*(const Complex& c) {
        this->_r = (this->_r * c._r) - (this->_im * c._im);
        this->_im = (this->_r * c._im) + (this->_im * c._r);
        return *this;
    }

    Complex&    operator/(const Complex& c) {
        value_type d = c._r * c._r + c._im * c._im;
        this->_r = (this->_r * c._r + this->_im * c._im) / d;
        this->_im = (this->_im * c._r - this->_r * c._im) / d;
        return *this;
    }

    friend Complex&    operator+(const Complex& c1, const Complex& c2) {
        return (Complex(c1._r + c2._r, c1._im + c2._im));
    }

    friend Complex&    operator-(const Complex& c1, const Complex& c2) {
        return (Complex(c1._r - c2._r, c1._im - c2._im));
    }

    friend Complex&    operator*(const Complex& c1, const Complex& c2) {
        Complex x;
        x._r = (c1._r * c2._r) - (c1._im * c2._im);
        x._im = (c1._r * c2._im) + (c1._im * c2._r);
        return x;
    }

    friend Complex&    operator/(const Complex& c1, const Complex& c2) {
        Complex x;
        value_type d = c2._r * c2._r + c2._im * c2._im;
        x._r = (c1._r * c2._r + c1._im * c2._im) / d;
        x._im = (c1._im * c2._r - c1._r * c2._im) / d;
        return x;
    }

    private:
        value_type _im;
        value_type _r;
}

std::ostream& operator << (std::ostream& os, const Complex &c) {
    os << r << " + " << im << "i";
    return os;
}

#endif
