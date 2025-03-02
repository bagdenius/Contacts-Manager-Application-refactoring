#include "user.hpp"

#include <fstream>
#include <iostream>
#include <string>

#include "../config.hpp"
using namespace std;

User::User(string name) : _name(name) {}

void User::checkIn() {
  ofstream fout;
  fout.open(USERS_LOG_PATH, ios::app);
  fout << _name << "\n" << __TIMESTAMP__ << "\n";
}
