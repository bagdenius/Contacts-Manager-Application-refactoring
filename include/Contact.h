#pragma once
#include <string>

class Contact
{
public:
    Contact();
    Contact(std::string name, std::string number, std::string address, std::string mail);
    void display() const;
    void add() const;
    void adding() const;
    void listing() const;
    void searching() const;
    void editing() const;
    void deleting() const;
    static void temporaryToOriginal();
    static void exiting();

private:
    std::string name_;
    std::string number_;
    std::string address_;
    std::string email_;
    std::string details_[5] = {"Name", "Phone(Mobile)", "Address", "Email", ""};
};