#pragma once

#include <memory>
#include <ostream>

#include <ratexpr/fraction.hpp>


namespace ratexpr {

    class Expression {
    public:
        virtual ~Expression() = default;
        virtual Fraction evaluate() const = 0;
        virtual void print(std::ostream& os) const = 0;
    };

    std::ostream& operator<<(std::ostream& os, const Expression& e);

    class Const: public Expression {
    public:
        explicit Const(const Fraction & value);
        Fraction evaluate() const override;
        void print(std::ostream& os) const override;
    private:
        Fraction value_;
    };

    class Negative : public Expression {
    public:
        explicit Negative(std::unique_ptr<Expression> operand);
        Fraction evaluate() const override;
        void print(std::ostream& os) const override;
    private:
        std::unique_ptr<Expression> operand_;
    };


    class BinaryExpression : public Expression {
    public:
        BinaryExpression(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs);\
    protected:
        std::unique_ptr<Expression> lhs_;
        std::unique_ptr<Expression> rhs_;
    };


    class Add : public BinaryExpression {
    public:
        using BinaryExpression::BinaryExpression;
        Fraction evaluate() const override;
        void print(std::ostream& os) const override;
    };

    class Sub : public BinaryExpression {
    public:
        using BinaryExpression::BinaryExpression;
        Fraction evaluate() const override;
        void print(std::ostream& os) const override;
    };

    class Mul : public BinaryExpression {
    public:
        using BinaryExpression::BinaryExpression;
        Fraction evaluate() const override;
        void print(std::ostream& os) const override;
    };

    class Div : public BinaryExpression {
    public:
        using BinaryExpression::BinaryExpression;
        Fraction evaluate() const override;
        void print(std::ostream& os) const override;
    };
}