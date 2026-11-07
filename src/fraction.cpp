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


    Fraction& Fraction::operator+=(const Fraction& o) {
        std::int64_t numik = num_ * o.den_ + den_ * o.num_;
        std::int64_t denik = den_ * o.den_;
        num_ = numik;
        den_ = denik;
        normalize();
        return *this;
    }
    Fraction& Fraction::operator*=(const Fraction& o) {
        std::int64_t numik = num_ * o.num_;
        std::int64_t denik = den_ * o.den_;
        num_ = numik;
        den_ = denik;
        normalize();
        return *this;
    }
    Fraction& Fraction::operator-=(const Fraction& o) {
        return *this += -o;
    }
    Fraction& Fraction::operator/=(const Fraction& o) {
        return *this *= Fraction(o.den_, o.num_);
    }


    Fraction& Fraction::operator+=(std::uint32_t k) {
        return *this += Fraction(k);
    }
    Fraction& Fraction::operator-=(std::uint32_t k) {
        return *this -= Fraction(k);
    }
    Fraction& Fraction::operator*=(std::uint32_t k) {
        return *this *= Fraction(k);
    }
    Fraction& Fraction::operator/=(std::uint32_t k) {
        return *this /= Fraction(k);
    }


    Fraction operator+(const Fraction& a, const Fraction& b) {
        Fraction r = a;
        r += b;
        return r;
    }
    Fraction operator-(const Fraction& a, const Fraction& b) {
        Fraction r = a;
        r -= b;
        return r;
    }
    Fraction operator*(const Fraction& a, const Fraction& b) {
        Fraction r = a;
        r *= b;
        return r;
    }
    Fraction operator/(const Fraction& a, const Fraction& b) {
        Fraction r = a;
        r /= b;
        return r;
    }


    Fraction operator+(const Fraction& a, std::uint32_t k) {
        Fraction r = a;
        r += k;
        return r;
    }
    Fraction operator-(const Fraction& a, std::uint32_t k) {
        Fraction r = a;
        r -= k;
        return r;
    }
    Fraction operator*(const Fraction& a, std::uint32_t k) {
        Fraction r = a;
        r *= k;
        return r;
    }
    Fraction operator/(const Fraction& a, std::uint32_t k) {
        Fraction r = a;
        r /= k;
        return r;
    }

    Fraction operator+(std::uint32_t k, const Fraction& b) {
        Fraction r = b;
        r += k;
        return r;
    }
    Fraction operator-(std::uint32_t k, const Fraction& b) {
        Fraction r = Fraction(k);
        r -= b;
        return r;
    }
    Fraction operator*(std::uint32_t k, const Fraction& b) {
        Fraction r = b;
        r *= k;
        return r;
    }
    Fraction operator/(std::uint32_t k, const Fraction& b) {
        Fraction r = Fraction(k);
        r /= b;
        return r;
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