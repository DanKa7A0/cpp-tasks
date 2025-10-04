#pragma once
#include <string>

#include "clients.h"

using std::string;


class Teacher : public Clients {
public:
    Teacher(string client_ID, string firstName, string lastName, string clientType);

private:
};