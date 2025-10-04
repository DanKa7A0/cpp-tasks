#pragma once
#include <string>
#include <iostream>
#include <stdexcept>

class InsufficientFundsException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Insufficient funds in account.";
    }
};

class Account {
private:
    std::string id;
    std::string owner;
    double balance;

public:
    Account(const std::string& id, const std::string& owner, double balance);
    const std::string& get_ID() const;
    const std::string& getOwner() const;
    double getBalance() const;
    void operator+=(double amount);
    void operator-=(double amount);
    friend std::ostream& operator<<(std::ostream& os, const Account& account);
};