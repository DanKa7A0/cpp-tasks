#include "standartAccount.h"

StandartAccount::StandartAccount(int client_ID, string account_ID) : Account(client_ID, account_ID){
    transferFee = 1.01;
    withdrawFee = 0.50;
    balance += 200;
    accountType = "Standart";
}

// double StandartAccount::getBalance() const {
//     return balance;
// }
