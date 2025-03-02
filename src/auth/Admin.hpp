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
  void changeUsername();
  void setPassword(string newPassword);
  void changePassword();
  void displayDetails();
  bool checkCredentials(string username, string password);
};
