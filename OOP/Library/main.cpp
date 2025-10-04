#include <iostream>
#include <map>
#include <iomanip>

#include "book.h"
#include "clients.h"
#include "student.h"
#include "teacher.h"

using namespace std;

int main(int argc, char const *argv[]){
    map<string, Book> books;
    map<string, Clients*> clients;
    int day = 1;

    string cmd;
    while (cin >> cmd){
        if (cmd == "book"){
            string book_ID;
            double pricePerDay;
            string title;
            cin >> book_ID >> pricePerDay;
            cin.ignore();
            getline(cin, title);

            Book book(book_ID, pricePerDay, title);
            books.insert({book_ID, book});

            // cout << setprecision(2) << fixed << "Book added with num " << book_ID << " name " << title << " and price per day $" << pricePerDay << endl;
        }

        if (cmd == "student"){
            string client_ID;
            string firstName;
            string lastName;
            cin >> client_ID >> firstName >> lastName;

            Clients* client = new Student(client_ID, firstName, lastName, "student");
            clients.insert({client_ID, client});

            // cout << "Student added with num " << client_ID << " and name " << firstName << lastName << endl;
        }

        if (cmd == "teacher"){
            string client_ID;
            string firstName;
            string lastName;
            cin >> client_ID >> firstName >> lastName;

            Clients* client = new Teacher(client_ID, firstName, lastName, "student");
            clients.insert({client_ID, client});

            // cout << "Teacher added with num " << client_ID << " and name " << firstName << " " << lastName << endl;
        }

        if (cmd == "lend") {
            string book_ID, client_ID;
            cin >> book_ID >> client_ID;

            auto client = clients.find(client_ID);
            if (client == clients.end()) {
                cout << "Client not found" << endl;
                continue;
                // cout << "Key " << client->first << " found with";
                // cout << " value: " << client->second->getClientType() << endl;
            }
            if (client->second->getBorrowedBook_ID() != "") {
                cout << client->second->getFullName() << " already borrowed " << books.at(client->second->getBorrowedBook_ID()).getTitle() << endl;
                continue;
            }

            auto book = books.find(book_ID);
            if (book == books.end()) {
                cout << "Book not found" << endl;
                continue;
            }
            if (book->second.getBorrowedClient_ID() != "") {
                cout << book->second.getTitle() << " is already borrowed by" << clients.at(book->second.getBorrowedClient_ID())->getFullName() << endl;
                continue;
            }

            client->second->setBorrowedBook_ID(book_ID);
            book->second.setBorrowedClient_ID(client_ID);
            book->second.setNumOfDay(day);
            // cout << client->second->getFullName() << " borrowed " << book->second.getTitle() << endl;

        }

        if (cmd == "return") {
            string book_ID;
            cin >> book_ID;

            auto book = books.find(book_ID);
            auto client = clients.find(book->second.getBorrowedClient_ID());
            client->second->setBorrowedBook_ID("");
            book->second.setBorrowedClient_ID("");            
            cout << book->second.getTitle() << " is returned" << endl;

            if (client->second->getClientType() == "student") {
                double price = book->second.getPricePerDay();
                int numOfDay = day - book->second.getNumOfDay()+1;
                double totalPrice = price * numOfDay;
                cout << setprecision(2) << fixed << client->second->getFullName() << " owes $" << totalPrice << endl;
                continue;
            }

            cout << client->second->getFullName() << " does not own anyting "<< endl;
            continue;
        }

        if (cmd == "next") {
            day++;
            continue;
        }

        if (cmd == "check") {
            string book_ID;
            cin >> book_ID;

            auto book = books.find(book_ID);
            string client_ID = book->second.getBorrowedClient_ID();
            if (client_ID == "") {
                cout << book->second.getTitle() << " is available" << endl;
                continue;
            }

            cout << book->second.getTitle() << " is borrowed by " << clients.at(client_ID)->getFullName() << " since " << day - book->second.getNumOfDay()+1 << " days" << endl;
        }

        if (cmd == "exit") {
            cout << "Bye" << endl;
            break;
        }
    }

    return 0;
}
