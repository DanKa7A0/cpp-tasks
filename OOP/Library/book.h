#pragma once
#include <string>

using std::string;


class Book {
public:
    Book(string book_ID, double pricePerDay, string title);
    string getBook_ID() const;
    double getPricePerDay() const;
    string getTitle() const;

    string getBorrowedClient_ID() const;
    void setBorrowedClient_ID(string client_ID);

    void setNumOfDay(int numOfDay);
    int getNumOfDay() const;

private:
    string book_ID;
    double pricePerDay;
    string title;
    string borrowedClient_ID = "";
    int numOfDay = 0;
};