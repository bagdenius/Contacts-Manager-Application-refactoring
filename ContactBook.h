#pragma once
#include <string>

class ContactBook
{
public:
    void adding() const;
    void listing() const;
    void searching() const;
    void editing() const;
    void deleting() const;

private:
    std::string details_[5] = {"Name", "Phone(Mobile)", "Address", "Email", ""};
};