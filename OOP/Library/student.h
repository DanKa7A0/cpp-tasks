#pragma once
#include <string>

#include "clients.h"

using std::string;


class Student : public Clients {
public:
    Student(string client_ID, string firstName, string lastName, string clientType);

private:
};