#include "order.h"
#include <iostream>
#include <iomanip>

void Order::addItem(Item item){
    items.push_back(item);
}

void Order::printOrder(std::ostream &out) const {
    double totalSum = 0.0;
    out << std::setprecision(2) << std::fixed;

    for (const auto& item : items) {
        out << "Item: " << item.getName() << ", Price: " << item.getPrice() << std::endl;
        totalSum += item.getPrice();
    }

    if (discount) {
        discount->print(std::cout);
        totalSum = discount->apply(totalSum);
    }

    out << "Total Sum: " << totalSum << std::endl;
}

void Order::printWelcomeMessage(std::ostream &out) const {
    out << "Welcome to the restaurant!" << std::endl;
    out << "Please place your order." << std::endl;
}

void Order::setDiscount(Discount *discount) {
    this->discount = discount;
}
