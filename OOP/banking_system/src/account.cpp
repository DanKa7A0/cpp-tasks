#include "account.h"

Account::Account(int client_ID, string account_ID): client_ID(client_ID), account_ID(account_ID){}

// encapsulation
double Account::getBalance() const {
    return balance;
}
string Account::getAccount_ID() const {
    return account_ID;
}
int Account::getClient_ID() const{
    return client_ID;
}
string Account::getAccountType() const
{
    return accountType;
}
double Account::getTransferFee() const{
    return transferFee;
}
double Account::getWithdrawFee() const{
    return withdrawFee;
}
vector<string> Account::getTransactions() const{
    return transactions;
}

// functional 
void Account::depositMoney(double deposit) {
    balance += deposit;
}
void Account::withdrawMoney(double withdraw) {
    balance -= (withdraw + withdrawFee);
}
void Account::transferMoney(string account_ID, int transfer, map<string, std::unique_ptr<Account>> accounts){
    balance -= (transfer * getTransferFee());

    if (accounts.find(account_ID) != accounts.end()){
        accounts.at(account_ID)->depositMoney(transfer);
    }
}
void Account::addTransaction(string type, double money){
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << money;
    transactions.push_back(type + " $" + oss.str());
}
void Account::printLastTransactions(std::ostream &out){
    for (int i = transactions.size()-1; i >= 0; i--){
        out << "   " << transactions[i] << endl;
    }
}
