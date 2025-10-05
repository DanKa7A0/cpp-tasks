#include "book.h"

Book::Book(string title, string publisher, unsigned short int pubYear, string author)
: Edition(title, publisher, pubYear), author(author){}