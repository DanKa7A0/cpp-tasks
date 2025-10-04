#include "menu.h"

Menu::Menu(std::istream &in) {
    std::string name;
    double price;
    while (in >> name >> price) {
        Item item(name, price);
        items.push_back(item);
    } 
}

void Menu::print(std::ostream &out){
    int i = 0;
    for (const auto& item : items) {
        out << "Id: " << i+1 << ", Item: " << item.getName() << ", Price: " << item.getPrice() << std::endl;
        i++;
    }

}

Item Menu::getItem(int id){
    return items[id-1]; // id is 0-based index
}
