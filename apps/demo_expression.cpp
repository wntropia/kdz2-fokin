#include <ratexpr/expression.hpp>

#include <iostream>
#include <memory>
#include <stdexcept>

int main() {
    using namespace ratexpr;

    auto e = std::make_unique<Mul>(
        std::make_unique<Add>(std::make_unique<Const>(Fraction(1, 2)),std::make_unique<Const>(Fraction(1, 3))),
        std::make_unique<Sub>(std::make_unique<Const>(Fraction(3)),std::make_unique<Const>(Fraction(1, 4))));
    std::cout << *e << " = " << e->evaluate() << '\n';


    auto n = std::make_unique<Negative>(
        std::make_unique<Div>(std::make_unique<Const>(Fraction(2)),
                              std::make_unique<Const>(Fraction(3))));
    std::cout << *n << " = " << n->evaluate() << '\n';

    std::unique_ptr<Expression> c = std::make_unique<Const>(Fraction(-3, 4));
    std::cout << *c << " = " << c->evaluate() << '\n';

    std::unique_ptr<Expression> nn = std::make_unique<Negative>(
        std::make_unique<Negative>(std::make_unique<Const>(Fraction(5))));
    std::cout << *nn << " = " << nn->evaluate() << '\n';

    auto z = std::make_unique<Div>(std::make_unique<Const>(Fraction(1)),std::make_unique<Const>(Fraction(0)));
    try {
        std::cout << *z << " = " << z->evaluate() << '\n';
    } catch (const std::invalid_argument& ex) {
        std::cout << "exception: " << ex.what() << '\n';
    }
}