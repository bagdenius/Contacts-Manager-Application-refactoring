#pragma once
#include <string>
using namespace std;

class Admin
{
private:
    string Username;
    string Password;

public:
    Admin();
    Admin(string Username_, string Password_);
    void setUser(string newUsername);
    void changeUsername();
    void setPass(string newPassword);
    void changePassword();
    void display_mydetails();
    bool checkCredentials(string user, string pass);
};
