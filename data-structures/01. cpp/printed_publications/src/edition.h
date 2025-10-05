#pragma once

#include <string>
using std::string;

class Edition {
public:
    Edition(string title, string publisher, unsigned short int pubYear);
    
    
private:
    string title;
    string publisher;
    unsigned short int pubYear;
};