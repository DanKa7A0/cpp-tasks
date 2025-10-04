#pragma once

#include <vector>

#include "item.h"
#include "discount.h"


class Order {    
public:
    void addItem(Item item);
    void printOrder(std::ostream &out) const;
    void printWelcomeMessage(std::ostream &out) const;
    void setDiscount(Discount *discount);

private:
    std::vector<Item> items;
    const Discount *discount = nullptr;
};