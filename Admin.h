#pragma once
#include <string>

class Administrator
{
public:
    Administrator();
    Administrator(std::string username, std::string password);
    void setUser(const std::string &newUsername);
    void changeUsername();
    void setPassword(const std::string &newPassword);
    void changePassword();
    void displayMyDetails() const;

private:
    std::string username_;
    std::string password_;
};
