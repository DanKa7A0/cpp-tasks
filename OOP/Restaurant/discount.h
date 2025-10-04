#pragma once
#include <ostream>
#include <iomanip>

class Discount {
public:
    virtual double apply(double total) const;
    virtual void print(std::ostream &out) const;
};


class Percentage : public Discount {
public:
    Percentage(double discount);
    double apply(double total) const override;
    void print(std::ostream &out) const override;

private:
    double discount = 0.0;
};


class Flat : public Discount {
public:
    Flat(double discount);
    double apply(double total) const override;
    void print(std::ostream &out) const override;

private:
    double discount = 0.0;
};