#include "premiumAccount.h"

PremiumAccount::PremiumAccount(int client_ID, string account_ID) : Account(client_ID, account_ID) {
    balance += 300;
    accountType = "Premium";
}

// double PremiumAccount::getBalance() const {
//     return balance;
// }
