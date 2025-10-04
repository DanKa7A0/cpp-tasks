#include "account.h"
#include "client.h"
#include "standartAccount.h"
#include "premiumAccount.h"

#include <iostream>
#include <fstream> // Added for std::ifstream
#include <map>
#include <memory>

using namespace std;

int main(int argc, char const *argv[]){
    map<string, std::unique_ptr<Account>> accounts;
    map<int, Client> clients;

    // make input stream
    string command;    
    istream* input = &std::cin; // Default to std::cin
    ifstream testInput;
    if (argc > 1) { // if a test file is provided read from it
        testInput.open(argv[1]);
        if (!testInput) {
            cerr << "Could not open test file." << endl;
            return 1;
        }
        input = &testInput; // Use file if provided

    }

    cout << "[1] Register Client:" << endl;
    cout << "[2] Open Account" << endl;
    cout << "[3] List Client Accounts" << endl;
    cout << "[4] Deposit" << endl;
    cout << "[5] Withdraw" << endl;
    cout << "[6] Transfer" << endl;
    cout << "[7] Show Account" << endl;
    cout << "[8] Exit" << endl << endl;

    string cmd;
    while (*input >> cmd) {
        // cout << cmd << endl;
        // continue;
        if (cmd == "1") { // register client
            int client_ID;
            string firstName;
            string lastName;
            string phoneNumber;

            cout << "Client ID (4 digits): ";
            *input >> client_ID;

            cout << endl << "First Name: ";
            *input >> firstName;

            cout << endl << "Last name: ";
            *input >> lastName;

            cout << endl << "Phone Number: ";
            *input >> phoneNumber;
            
            Client client(client_ID, firstName, lastName, phoneNumber);
            clients.insert({client_ID, std::move(client)});
        
            cout << endl << "Client Registered!" << endl << endl;
        }

        if (cmd == "2") { // open account
            int client_ID;
            string account_ID;
            string accountType;
            
            cout << "Client ID: ";
            *input >> client_ID;
            // cout << client_ID;

            cout << endl << "Accout number: ";
            *input >> account_ID;
            // cout << account_ID;

            cout << endl << "Type (standart/premium): ";
            *input >> accountType;
            // cout << accountType << endl;
                
            if (accountType == "standart") {
                std::unique_ptr<Account> account = std::make_unique<StandartAccount>(client_ID, account_ID);
                cout << account_ID << endl;
                accounts.insert({account_ID, std::move(account)});
                // clients.at(client_ID).pushAccount(std::make_unique<StandartAccount>(*account));
                // std::unique_ptr<Account> newAccount = account->clone();
                clients.at(client_ID).pushAccount(std::move(account));
                cout << endl << "Account created! Balance: " << account->getBalance() << endl;
            }

            if (accountType == "premium") {
                std::unique_ptr<Account> account = std::make_unique<StandartAccount>(client_ID, account_ID);
                accounts.insert({account_ID, std::move(account)});
                clients.at(client_ID).pushAccount(std::move(account));
                cout << endl << "Account created! Balance: " << account->getBalance() << endl << endl;
            }                        
        }

        if (cmd == "3") { // show client accounts
            int client_ID;            
            cout << "Client ID: ";
            *input >> client_ID;
            cout << endl;
            clients.at(client_ID).printAccounts(cout);            
        }

        if (cmd == "4") { // deposit in account
            string account_ID;
            cout << endl << "Accout number: ";
            *input >> account_ID;
            std::unique_ptr<Account> targetAcc = std::move(accounts.at(account_ID));

            double deposit;
            cout << endl << "Enter amount to deposit: ";
            *input >> deposit;

            targetAcc->depositMoney(deposit);
            targetAcc->addTransaction("Deposit: +", deposit);
            cout << endl << "Deposit successful. New balance: " << targetAcc->getBalance() << endl << endl;
        }

        if (cmd == "5") { // withdraw
            string account_ID;
            cout << endl << "Accout number: ";
            *input >> account_ID;
            // Account* targetAcc = accounts.at(account_ID);
            std::unique_ptr<Account> targetAcc = std::move(accounts.at(account_ID));

            double withdraw;
            cout << endl << "Enter amount to withdraw: ";
            *input >> withdraw;

            targetAcc->withdrawMoney(withdraw);
            targetAcc->addTransaction("Withdraw: -", withdraw);
            cout << endl << "Withdrawal successful. Fee: " << targetAcc->getWithdrawFee() << ". New balance: " << targetAcc->getBalance() << endl << endl;
        }

        if (cmd == "6") { // transfer
            string sourceAccount_ID;
            cout << endl << "Enter source account number: ";
            *input >> sourceAccount_ID;
            // Account* sourceAcc = accounts.at(sourceAccount_ID);
            std::unique_ptr<Account> sourceAcc = std::move(accounts.at(sourceAccount_ID));

            string destinationAccount_ID;
            cout << endl << "Enter destination  account number: ";
            *input >> destinationAccount_ID;
            // Account* destinationAcc = accounts.at(destinationAccount_ID);
            std::unique_ptr<Account> destinationAcc = std::move(accounts.at(destinationAccount_ID));

            double transfer;
            cout << endl << "Enter amount to transfer: ";
            *input >> transfer;

            sourceAcc->transferMoney(destinationAccount_ID, transfer, std::move(accounts));
            sourceAcc->addTransaction("Transfer: -", transfer);
            destinationAcc->addTransaction("Transfer: +", transfer);

            cout << endl << "Transfer successful." << endl;
            cout << "Source account. Fee: " <<  sourceAcc->getTransferFee() << "%. New balance: " <<  sourceAcc->getBalance() << endl;
            cout << "Destination account." << " New balance: " <<  destinationAcc->getBalance() << endl;
        }

        if (cmd == "7") { // show account
            string account_ID;
            cout << endl << "Accout number: ";
            *input >> account_ID;
            if (accounts.find(account_ID) == accounts.end()) {
                cout << "Accout number didn't exist" << endl;
                continue;
            }
            // Account* targetAcc = accounts.at(account_ID);
            std::unique_ptr<Account> targetAcc = std::move(accounts.at(account_ID));
            
            int client_ID = targetAcc->getClient_ID();
            if (clients.find(client_ID) == clients.end()){
                cout << "Client account didn't exist" << endl;
                continue;
            }
            Client client = std::move(clients.at(client_ID));

            cout << endl << "Owner: " << client.getFullName() << " (ID: " << client_ID << ")" << endl;
            cout << "Type: " << targetAcc->getAccountType() << endl;
            cout << "Balance: $" << targetAcc->getBalance() << endl;
            cout << "Last transactions: " << endl;
            targetAcc->printLastTransactions(cout);
            

        }

        if (cmd == "8") { // end 
            break;
        }
    }

    return 0;
}
