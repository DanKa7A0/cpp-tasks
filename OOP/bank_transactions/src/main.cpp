#include "bank_system.h"
#include <iostream>
#include <sstream>


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Set bank accounts file as arg[1]";
        return 1;
    }

    Bank bank;
    try {
        bank.loadAccounts(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    std::string command;
    while (std::getline(std::cin, command)) {
        std::istringstream iss(command);
        std::string cmd;
        iss >> cmd;

        if (cmd == "submit") {
            std::string src, dest;
            double amount;
            iss >> src >> dest >> amount;
            try {
                bank.submitTransaction(src, dest, amount);
            }
            catch(const std::runtime_error& err){ 
                std::cerr << "Error: " << err.what() << "\n";
            }
            continue;    
        }

        if (cmd == "pending") {
            bank.printPending();
            continue;
        }

        if (cmd == "approve") {
            bank.approveTransaction();
            continue;
        }
        
        if (cmd == "decline") {
            bank.declineTransaction();
            continue;
        }
        if (cmd == "history") {
            bank.printHistory();
            continue;
        }
        if (cmd == "reload") {
            bank.reloadAccounts(argv[1]);
            continue;
        }
        if (cmd == "account") {
            std::string acc;
            iss >> acc;
            bank.printAccount(acc);
            continue;
        }

        std::cerr << "Unknown command.\n";
    }
    return 0;
}
