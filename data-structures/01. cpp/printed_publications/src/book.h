#pragma once

#include <string>
#include "edition.h"
using std::string;

class Book : public Edition{
public:
    Book(string title, string publisher, unsigned short int pubYear, string author);

private:
    string author;
};