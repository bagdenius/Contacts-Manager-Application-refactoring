#pragma once
#include <string>
using namespace std;

class Contact {
 private:
  string _name;
  string _number;
  string _address;
  string _email;

 public:
  Contact(string name, string number, string address, string email);
  void display();
  void add();
};