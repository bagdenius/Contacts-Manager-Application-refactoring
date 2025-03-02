#pragma once
#include <string>
using namespace std;

class ContactBook
{
private:
    string details[5] = {"Name", "Phone(Mobile)", "Address", "Email", ""};

public:
    void adding();
    void listing();
    void searching();
    void editing();
    void deleting();
};