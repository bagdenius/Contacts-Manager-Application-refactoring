#pragma once
#include <string>
using namespace std;

class Admin {
 private:
  string _username;
  string _password;

 public:
  Admin();
  Admin(string username, string password);
  void setUsername(string newUsername);
  void setPassword(string newPassword);
  bool checkCredentials(string username, string password);
  string getDetails();
};
