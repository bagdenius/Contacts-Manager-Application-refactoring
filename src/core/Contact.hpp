#pragma once
#include <string>
using namespace std;

class Contact
{
private:
    string contactName;
    string contactNumber;
    string contactAddress;
    string contactEmail;

public:
    Contact(string name, string number, string address, string mail);
    void display();
    void add();
};