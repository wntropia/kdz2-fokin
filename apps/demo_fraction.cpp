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



    Fraction half(1, 2);
    Fraction third(1, 3);


    std::cout << "1/2 + 1/3 = " << half + third << '\n';
    std::cout << "1/2 - 1/3 = " << half - third << '\n';
    std::cout << "1/2 * 1/3 = " << half * third << '\n';
    std::cout << "1/2 / 1/3 = " << half / third << '\n';


    std::cout << "1/2 + 2u = " << half + 2u << '\n';
    std::cout << "2u + 1/2 = " << 2u + half << '\n';
    std::cout << "1/2 - 2u = " << half - 2u << '\n';
    std::cout << "2u - 1/2 = " << 2u - half << '\n';
    std::cout << "1/2 * 4u = " << half * 4u << '\n';
    std::cout << "4u * 1/2 = " << 4u * half << '\n';
    std::cout << "1/2 / 2u = " << half / 2u << '\n';
    std::cout << "2u / 1/2 = " << 2u / half << '\n';


    Fraction acc;
    acc += half;
    acc += third;
    acc *= 6u;
    std::cout << "acc = 0; acc += 1/2; acc += 1/3; acc *= 6u -> " << acc << '\n';

    Fraction x1 = half;
    x1 += x1;
    std::cout << "x = 1/2; x += x -> " << x1 << '\n';

    Fraction x2 = half;
    x2 /= x2;
    std::cout << "x = 1/2; x /= x -> " << x2 << '\n';

    Fraction x3 = half;
    (x3 += 1u) *= 2u;
    std::cout << "x = 1/2; (x += 1u) *= 2u -> " << x3 << '\n';


    try {
        std::cout << "1/2 / 0u = " << half / 0u << '\n';
    } catch (const std::invalid_argument& e) {
        std::cout << "exception: " << e.what() << '\n';
    }
    try {
        std::cout << "1/2 / Fraction(0) = " << half / Fraction(0) << '\n';
    } catch (const std::invalid_argument& e) {
        std::cout << "exception: " << e.what() << '\n';
    }
    try {
        std::cout << "2u / Fraction(0) = " << 2u / Fraction(0) << '\n';
    } catch (const std::invalid_argument& e) {
        std::cout << "exception: " << e.what() << '\n';
    }


    std::cout << "half = " << half << '\n';

}