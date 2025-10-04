#include <iostream>
#include <fstream> // Added for std::ifstream

#include "order.h"
#include "discount.h"
#include "menu.h"

int main(int argc, char const *argv[]){
    // pre conditions
    Order order;
    order.printWelcomeMessage(std::cout);

    // create menu
    std::ifstream menuFile("menu.txt");
    if (!menuFile) {
        std::cerr << "Could not open menu file." << std::endl;
        return 1;
    }
    Menu menu(menuFile);
    menuFile.close();
    
    // make input stream
    std::string command;    
    std::istream* input = &std::cin; // Default to std::cin
    std::ifstream testInput;
    if (argc > 1) { // if a test file is provided read from it
        testInput.open(argv[1]);
        if (!testInput) {
            std::cerr << "Could not open test file." << std::endl;
            return 1;
        }
        input = &testInput; // Use file if provided
    }

    // main logic
    while (*input >> command) {
        if (command == "end") {
            break;
        }

        if (command == "menu") {            
            menu.print(std::cout);
            continue;
        }

        if (command == "add") {
            int id;
            *input >> id;
            order.addItem(menu.getItem(id));
            continue;
        }

        if (command == "discount") {
            std::string type;
            double discountValue;
            *input >> type >> discountValue;

            if (type == "percentage") {
                order.setDiscount(new Percentage(discountValue));
                continue;
            }
            if (type == "flat") {
                order.setDiscount(new Flat(discountValue));
                continue;
            }

            std::cout << "Unknown discount type: " << type << std::endl;            
            continue;
        }

        if (command == "print") {
            order.printOrder(std::cout);
            order = Order(); // Reset the order after printing
            continue;
        }

        std::cout << "Unknown command: " << command << std::endl;    
    }

    // clean up
    if (testInput.is_open()) {
        testInput.close();
    }

    
    return 0;
}
