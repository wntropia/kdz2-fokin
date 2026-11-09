#include <ratexpr/expression.hpp>
#include <iostream>

#include <utility>
#include <numeric>
#include <ostream>
#include <stdexcept>

namespace ratexpr {
    Const::Const(const Fraction &value): value_(value) {}

    Fraction Const::evaluate() const {
        return value_;
    }
    void Const::print(std::ostream &os) const {
        os << value_;
    }

    std::ostream& operator<<(std::ostream& os, const Expression& e) {
        e.print(os);
        return os;
    }

    Negative::Negative(std::unique_ptr<Expression> operand): operand_(std::move(operand)) {}

    Fraction Negative::evaluate() const {
        return -(operand_->evaluate());
    }

    void Negative::print(std::ostream& os) const {
        os << "(-" << *operand_ << ")";
    }

    BinaryExpression::BinaryExpression(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs) : lhs_(std::move(lhs)), rhs_(std::move(rhs)) {}


    Fraction Add::evaluate() const {
        return lhs_->evaluate() + rhs_->evaluate();
    }

    void Add::print(std::ostream& os) const {
        os << "(" << *lhs_ << " + " << *rhs_ << ")";
    }

    Fraction Sub::evaluate() const {
        return lhs_->evaluate() - rhs_->evaluate();
    }

    void Sub::print(std::ostream& os) const {
        os << "(" << *lhs_ << " - " << *rhs_ << ")";
    }

    Fraction Mul::evaluate() const {
        return lhs_->evaluate() * rhs_->evaluate();
    }

    void Mul::print(std::ostream& os) const {
        os << "(" << *lhs_ << " * " << *rhs_ << ")";
    }

    Fraction Div::evaluate() const {
        return lhs_->evaluate() / rhs_->evaluate();
    }

    void Div::print(std::ostream& os) const {
        os << "(" << *lhs_ << " / " << *rhs_ << ")";
    }
}
