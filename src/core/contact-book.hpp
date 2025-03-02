#pragma once
#include <string>
using namespace std;

class ContactBook {
 private:
  string _details[5] = {"Name", "Phone", "Address", "Email", ""};

 public:
  void adding();
  void listing();
  void searching();
  void editing();
  void deleting();
};