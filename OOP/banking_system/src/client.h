#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>

#include "account.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Client {
public:
    Client(int id, string firstName, string lastName, string phoneNumber);

     // Забраняваме копиране:
    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;

    // Позволяваме преместване:
    Client(Client&&) = default;
    Client& operator=(Client&&) = default;

    void registerAcc(std::istream &in, std::ostream &out);

    string getFullName();
    int getId();

    void pushAccount(std::unique_ptr<Account> acc);
    void printAccounts(std::ostream &out);

private:
    int id;
    string firstName;
    string lastName;
    string phoneNumber;
    vector<std::unique_ptr<Account>> accounts;
};