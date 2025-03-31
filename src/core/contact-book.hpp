#pragma once
#include <string>
using namespace std;

class ContactBook {
 private:
  string _details[5] = {"Ім'я", "Телефон", "Адреса", "Електронна адреса", ""};

 public:
  void adding();
  void listing();
  void searching();
  void editing();
  void deleting();
};