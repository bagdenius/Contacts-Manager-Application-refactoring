#pragma once
#include <string>
using namespace std;

class AdminLogin
{
private:
    string Username;
    string Password;

public:
    AdminLogin();
    bool checkCredentials(string user, string pass);
};
