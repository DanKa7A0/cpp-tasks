#pragma once
#include <memory>
#include "Account.h"
#include <string>

enum class TransactionStatus { PENDING, APPROVED, DECLINED };

class Transaction {
private:
    std::shared_ptr<Account> src;
    std::shared_ptr<Account> dest;
    double amount;
    TransactionStatus status;
    size_t id;

public:
    Transaction(size_t id, std::shared_ptr<Account> src, std::shared_ptr<Account> dest, double amount);
    void approve();
    void decline();
    TransactionStatus getStatus() const;
    size_t getId() const;
    friend std::ostream& operator<<(std::ostream& os, const Transaction& tx);
};