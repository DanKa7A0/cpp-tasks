#include "bank_system.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

void Bank::loadAccounts(const std::string& path) {
    std::ifstream file(path);
    if (!file) throw std::runtime_error("Failed to open account file.");

    std::string id, fname, lname;
    double balance;
    while (file >> id >> fname >> lname >> balance) {
        accounts[id] = std::make_shared<Account>(id, fname + " " + lname, balance);
    }
}

void Bank::reloadAccounts(const std::string& path) {
    loadAccounts(path);
    std::cout << "Accounts reloaded.\n";
}

void Bank::submitTransaction(const std::string& srcId, const std::string& destId, double amount) {
    auto srcIt = accounts.find(srcId);
    auto destIt = accounts.find(destId);

    if (srcIt == accounts.end() || destIt == accounts.end()) {
        // std::cerr << "Error: Account " << (srcIt == accounts.end() ? srcId : destId) << " does not exist.\n";
        throw std::runtime_error("Account " + (srcIt == accounts.end() ? srcId : destId) + " does not exist.");
        return;
    }

    auto tx = std::make_unique<Transaction>(transactionCounter++, srcIt->second, destIt->second, amount);
    std::cout << "Transaction " << tx->getId() << " submitted (Pending).\n";
    pendingTransactions.push_back(std::move(tx));
}

void Bank::approveTransaction() {
    if (pendingTransactions.empty()) {
        std::cerr << "No pending transactions.\n";
        return;
    }

    auto tx = std::move(pendingTransactions.front());
    pendingTransactions.pop_front();

    try {
        tx->approve();
        std::cout << "Transaction " << tx->getId() << " approved. Balances updated.\n";
        transactionHistory.push_back(std::move(tx));
    } catch (const InsufficientFundsException& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    if (transactionHistory.size() > 10) transactionHistory.pop_front();
}

void Bank::declineTransaction() {
    if (pendingTransactions.empty()) {
        std::cerr << "No pending transactions.\n";
        return;
    }
    auto tx = std::move(pendingTransactions.front());
    pendingTransactions.pop_front();
    tx->decline();
    transactionHistory.push_back(std::move(tx));
    if (transactionHistory.size() > 10) transactionHistory.pop_front();
    std::cout << "Transaction declined.\n";
}

void Bank::printPending() const {
    for (const auto& tx : pendingTransactions) std::cout << *tx << "\n";
}

void Bank::printHistory() const {
    int index = 1;
    for (const auto& tx : transactionHistory) {
        std::cout << index++ << ". [" << (tx->getStatus() == TransactionStatus::APPROVED ? "APPROVED" : "DECLINED") << "] " << *tx << "\n";
    }
}

void Bank::printAccount(const std::string& id) const {
    auto it = accounts.find(id);
    if (it != accounts.end()) {
        std::cout << *it->second << "\n";
    } else {
        std::cerr << "Error: Account " << id << " does not exist.\n";
    }
}