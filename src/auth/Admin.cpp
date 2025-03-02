#include "admin.hpp"

#include <fstream>
#include <iostream>

#include "../config.hpp"
using namespace std;

Admin::Admin() {
  ifstream fin;
  fin.open(ADMIN_DATA_PATH, ios::in);
  string username, password;
  getline(fin, username);
  getline(fin, password);
  _username = username;
  _password = password;
}

Admin::Admin(string username, string password)
    : _username(username), _password(password) {
  ofstream fout;
  fout.open(ADMIN_DATA_PATH, ios::out);
  fout << _username << "\n";
  fout << _password;
  cout << "Admin Created\n";
}

void Admin::setUsername(string newUsername) {
  _username = newUsername;
  ofstream fout;
  fout.open(ADMIN_DATA_PATH, ios::out);
  fout << _username;
  fout << _password;
}

void Admin::setPassword(string newPassword) {
  _password = newPassword;
  ofstream fout;
  fout.open(ADMIN_DATA_PATH, ios::out);
  fout << _username;
  fout << _password;
}

bool Admin::checkCredentials(string username, string password) {
  if (username == _username && password == _password) return true;
  return false;
}

string Admin::getDetails() {
  return "Username: " + _username + "\nPassword: " + _password;
}