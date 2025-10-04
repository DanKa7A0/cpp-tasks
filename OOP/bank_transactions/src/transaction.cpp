#include "Transaction.h"

Transaction::Transaction(size_t id, std::shared_ptr<Account> src, std::shared_ptr<Account> dest, double amount)
    : id(id), src(std::move(src)), dest(std::move(dest)), amount(amount), status(TransactionStatus::PENDING) {}

void Transaction::approve() {
    *src -= amount;
    *dest += amount;
    status = TransactionStatus::APPROVED;
}

void Transaction::decline() {
    status = TransactionStatus::DECLINED;
}

TransactionStatus Transaction::getStatus() const {
    return status;
}

size_t Transaction::getId() const {
    return id;
}

std::ostream& operator<<(std::ostream& os, const Transaction& tx) {
    os << tx.src->get_ID() << " -> " << tx.dest->get_ID() << ": $" << tx.amount;
    switch (tx.status) {
        case TransactionStatus::PENDING: os << " (Pending)"; break;
        case TransactionStatus::APPROVED: os << " (Approved)"; break;
        case TransactionStatus::DECLINED: os << " (Declined)"; break;
    }
    return os;
}
