#pragma once
#include <string>

using std::string;


class Clients {
public:
    Clients(string client_ID, string firstName, string lastName, string clientType);
    string getClient_ID() const;
    string getClientType() const;

    string getFullName() const;

    string getBorrowedBook_ID() const;
    void setBorrowedBook_ID(string book_ID);

private:
    string client_ID;
    string firstName;
    string lastName;
    string clientType;
    string borrowedBook_ID = "";
    // bool isBorrowed = false;
};