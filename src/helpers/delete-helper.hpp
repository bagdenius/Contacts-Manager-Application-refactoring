#pragma once
#include <string>
using namespace std;

class DeleteHelper {
 private:
  string _name;

 public:
  DeleteHelper(string name);
  void deleting();
  void temporaryToOriginal();
  void deleteFromContactbook();
};
