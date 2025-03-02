#pragma once
#include <string>
using namespace std;

class User {
 private:
  string _name;

 public:
  User(string name);
  void checkIn();
};
