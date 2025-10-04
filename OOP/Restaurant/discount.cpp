#include "discount.h"

double Discount::apply(double total) const {
    return total;
}

void Discount::print(std::ostream &out) const {
    out << "Discount: None" << std::endl;
}


Percentage::Percentage(double discount) : discount(discount) {}

double Percentage::apply(double total) const{
    return total - (total * discount / 100);
}

void Percentage::print(std::ostream &out) const {
    out << "Discount: " << discount << "%" << std::endl;
}


Flat::Flat(double discount): discount(discount) {}

double Flat::apply(double total) const{
    return total - discount;
}

void Flat::print(std::ostream &out) const {
    out << std::setprecision(2) << std::fixed;
    out << "Discount: " << discount << std::endl;
}
