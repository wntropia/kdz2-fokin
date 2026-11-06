#include <ratexpr/fraction.hpp>
#include <iostream>
#include <stdexcept>
int main() {
    using ratexpr::Fraction;
    std::cout << "Fraction() = " << Fraction() << '\n';
    std::cout << "Fraction(5) = " << Fraction(5) << '\n';
    std::cout << "Fraction(6, -8) = " << Fraction(6, -8) << '\n';
    std::cout << "Fraction(-6, -8) = " << Fraction(-6, -8) << '\n';
    std::cout << "Fraction(10, 4) = " << Fraction(10, 4) << '\n';
    std::cout << "Fraction(0, -7) = " << Fraction(0, -7) << '\n';
    std::cout << "Fraction(4, 2) = " << Fraction(4, 2) << '\n';
    std::cout << "-Fraction(1, 2) = " << -Fraction(1, 2) << '\n';
    std::cout << "-Fraction(-1, 2) = " << -Fraction(-1, 2) << '\n';
    std::cout << "-Fraction(0) = " << -Fraction(0) << '\n';
    try {
        std::cout << "Fraction(1, 0) = " << Fraction(1, 0) << '\n';
    } catch (const std::invalid_argument& e) {
        std::cout << "exception: " << e.what() << '\n';
    }




}