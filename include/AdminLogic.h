#pragma once
#include <string>

class AdminLogin
{
public:
    AdminLogin();
    bool checkCredentials(const std::string &user, const std::string &pass) const;

private:
    std::string username_;
    std::string password_;
};
