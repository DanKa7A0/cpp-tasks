#pragma once
#include <unordered_map>
#include <deque>
#include <vector>
#include <memory>
#include <string>
#include "Account.h"
#include "Transaction.h"

class Bank {
private:
    std::unordered_map<std::string, std::shared_ptr<Account>> accounts;
    std::deque<std::unique_ptr<Transaction>> pendingTransactions;
    std::deque<std::unique_ptr<Transaction>> transactionHistory;
    size_t transactionCounter = 1;

public:
    void loadAccounts(const std::string& path);
    void reloadAccounts(const std::string& path);
    void submitTransaction(const std::string& srcId, const std::string& destId, double amount);
    void approveTransaction();
    void declineTransaction();
    void printPending() const;
    void printHistory() const;
    void printAccount(const std::string& number) const;
};