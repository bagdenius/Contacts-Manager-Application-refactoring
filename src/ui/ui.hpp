#include "../auth/admin.hpp"

class UserInterface {
 public:
  void displayStart();
  int displayStartMenu();
  int displayAdminMenu();
  int displayUserMenu();
  void changeAdminUsername(Admin user);
  void changeAdminPassword(Admin user);
  void displayAdminDetails(Admin user);
};
