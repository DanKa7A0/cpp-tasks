#pragma once
#include <iostream>
#include <vector>

#include "item.h"

class Menu {
public:
    Menu(std::istream &in);

    void print(std::ostream &out);
    Item getItem(int id);

private:
    std::vector<Item> items;
};