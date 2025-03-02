#pragma once
#include <iostream>

#include "../auth/admin.hpp"

class UserInterface {
 public:
  void run();

 private:
  void handleUser();
  void handleAdmin();
  void createNewAdmin();
  void displayStart();
  int displayStartMenu();
  int displayAdminMenu();
  int displayUserMenu();
  void changeAdminUsername(Admin user);
  void changeAdminPassword(Admin user);
  void displayAdminDetails(Admin user);
};
