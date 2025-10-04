#include <iostream>
#include <memory>

#include "edition.h"
#include "book.h"

using namespace std;

int main(int argc, char const *argv[]){
    unique_ptr<Edition> edition = make_unique<Book>("Test", "Pub Ltd", 2000, "John V");

    // cout << edition->title;

    // system("pause");
    return 0;
}
