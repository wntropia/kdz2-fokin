#include <iostream>
#include <ratexpr/fraction.hpp>

#include <numeric>
#include <ostream>
#include <stdexcept>

namespace ratexpr {
    std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        if (f.den_ == 1) {os << f.num_;}
        else{os << f.num_ << "/" << f.den_;}
        return os;
    }
    Fraction Fraction::operator-() const {
        std::int64_t numik = -num_;
        return Fraction(numik, den_);
    }
    Fraction::Fraction() {
        den_ = 1;
        num_= 0;
    }
    Fraction::Fraction(std::int64_t numerator, std::int64_t denominator) {
        if (denominator == 0) {throw std::invalid_argument("denominator cannot be zero");}
        num_ = numerator;
        den_ = denominator;
        normalize();
    }
    void Fraction::normalize() {
        if (den_<0) {
            den_ = -den_;
            num_ = -num_;
        }
        std::int64_t gcd1 = std::gcd(num_, den_);
        den_ = den_/gcd1;
        num_ = num_/gcd1;
        if (num_ == 0) {den_ = 1;}
    }
}