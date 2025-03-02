#include "admin.hpp"

#include <fstream>
#include <iostream>
using namespace std;

Admin::Admin() {
  ifstream fin;
  fin.open("password.txt", ios::in);
  string username, password;
  getline(fin, username);
  getline(fin, password);
  _username = username;
  _password = password;
}

Admin::Admin(string username, string password)
    : _username(username), _password(password) {
  ofstream fout;
  fout.open("password.txt", ios::out);
  fout << _username << "\n";
  fout << _password;
  cout << "Admin Created\n";
}

void Admin::setUsername(string newUsername) {
  _username = newUsername;
  ofstream fout;
  fout.open("password.txt", ios::out);
  fout << _username;
  fout << _password;
}

void Admin::changeUsername() {
  cout << "Enter new Username: ";
  string newUsername;
  cin >> newUsername;
  setUsername(newUsername);
}

void Admin::setPassword(string newPassword) {
  _password = newPassword;
  ofstream fout;
  fout.open("password.txt", ios::out);
  fout << _username;
  fout << _password;
}

void Admin::changePass() {
  cout << "Enter new Password: ";
  string newPassword;
  cin >> newPassword;
  setUsername(newPassword);
}

void Admin::displayDetails() {
  cout << "Username: " << _username << endl;
  cout << "Password: " << _password << endl;
}

bool Admin::checkCredentials(string user, string pass) {
  if (user == _username && pass == _password) return true;
  return false;
}
