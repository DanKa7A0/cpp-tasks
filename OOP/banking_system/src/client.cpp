#include "client.h"

Client::Client(int id, string firstName, string lastName, string phoneNumber) :
id(id), firstName(firstName), lastName(lastName), phoneNumber(phoneNumber) {}

void Client::registerAcc(std::istream &in, std::ostream &out){
    out << "Client ID (4 digits): ";
    in >> id;

    out << endl << "First Name: ";
    in >> firstName;

    out << endl << "Last name: ";
    in >> lastName;

    out << "Phone Number: +359";
    in >> phoneNumber;

    out << endl << "Client Registered!" << endl;
}

string Client::getFullName() {
    return firstName + " " + lastName;
}

int Client::getId(){
    return id;
}

void Client::pushAccount(std::unique_ptr<Account> acc) {
    accounts.push_back(std::move(acc));
}

void Client::printAccounts(std::ostream &out) {
    // Anna Petrova's accounts:
    // X9Y8 (Premium) - $100.00
    out << std::setprecision(2) << std::fixed;
    out << getFullName() << "'s accounts" << endl;    
    // for (int i = 0; i < accounts.size(); i++) {
    for (const auto& acc : accounts) {
        // Account* acc = accounts[i];
        out << acc->getAccount_ID() << " (" << acc->getAccountType() << ") " << "- $" << acc->getBalance() << endl;
    }    
}
