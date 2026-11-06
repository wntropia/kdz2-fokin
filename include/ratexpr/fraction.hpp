#pragma once
#include <ostream>
#include <cstdint>

namespace ratexpr {
    class Fraction {
    public:
        Fraction();
        Fraction(std::int64_t numerator, std::int64_t denominator = 1);

        Fraction operator-() const;

        friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    private:

        std::int64_t num_;
        std::int64_t den_;

        void normalize();
    };
}