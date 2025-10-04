#include "book.h"

Book::Book(string book_ID, double pricePerDay, string title)
: book_ID(book_ID), pricePerDay(pricePerDay), title(title) {}

string Book::getBook_ID() const{
    return book_ID;
}

double Book::getPricePerDay() const{
    return pricePerDay;
}

string Book::getBorrowedClient_ID() const {
    return borrowedClient_ID;
}

void Book::setBorrowedClient_ID(string client_ID){
    this->borrowedClient_ID = client_ID;
}

void Book::setNumOfDay(int numOfDay){
    this->numOfDay = numOfDay;
}

int Book::getNumOfDay() const {
    return numOfDay;
}

string Book::getTitle() const{
    return title;
}
