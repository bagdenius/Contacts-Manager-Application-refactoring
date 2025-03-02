#include "users.hpp"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

Users::Users(string name) : _name(name) {}

void Users::checkIn() {
  ofstream fout;
  fout.open("users.txt", ios::app);
  fout << _name << "\n" << __TIMESTAMP__ << "\n";
}
