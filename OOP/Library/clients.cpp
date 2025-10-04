#include "clients.h"

Clients::Clients(string client_ID, string firstName, string lastName, string clientType)
: client_ID(client_ID), firstName(firstName), lastName(lastName), clientType(clientType){}

string Clients::getClient_ID() const{
    return client_ID;
}

string Clients::getClientType() const {
    return clientType;
}

string Clients::getFullName() const{
    return firstName + " " + lastName;
}

string Clients::getBorrowedBook_ID() const {
    return borrowedBook_ID;
}
void Clients::setBorrowedBook_ID(string borrowedBook_ID){
    this->borrowedBook_ID = borrowedBook_ID;
}
