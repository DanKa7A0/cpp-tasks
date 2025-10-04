#include "account.h"

Account::Account(const std::string& id, const std::string& owner, double balance)
    : id(id), owner(owner), balance(balance) {}

const std::string& Account::get_ID() const {
    return id;
}

const std::string& Account::getOwner() const {
    return owner;
}

double Account::getBalance() const {
    return balance;
}

void Account::operator+=(double amount) {
    balance += amount;
}

void Account::operator-=(double amount) {
    if (balance < amount) throw InsufficientFundsException();
    balance -= amount;
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "Account: " << account.id << "\nOwner: " << account.owner << "\nBalance: $" << account.balance;
    return os;
}