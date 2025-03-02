#include <iostream>
#include <string>

#include "auth/admin.hpp"
#include "auth/users.hpp"
#include "core/contact-book.hpp"
#include "ui/ui.hpp"
using namespace std;

enum Identity { user = 1, admin, newAdmin };

int main() {
  UserInterface ui;
  ui.displayStart();
  while (1) {
    int choice = ui.displayStartMenu();
    switch (choice) {
      case user: {
        string name;
        cout << "Enter Your Full name to make an entry into Users.txt: ";
        getline(cin >> ws, name);
        Users user(name);
        user.checkIn();
        ContactBook contactBook;
        int flag = 0;
        while (1) {
          int choice = ui.displayUserMenu();
          switch (choice) {
            case 1: {
              contactBook.listing();
              break;
            }
            case 2: {
              contactBook.searching();
              break;
            }
            case 0: {
              flag = 1;
              break;
            }
          }
          if (flag == 1) break;
        }
        break;
      }
      case admin: {
        string username, password;
        cout << "Enter Username & Password\n";
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        Admin admin;
        bool isLoggedIn = admin.checkCredentials(username, password);
        if (isLoggedIn) {
          ContactBook contactBook;
          int flag = 0;
          while (1) {
            int choice = ui.displayAdminMenu();
            switch (choice) {
              case 1: {
                contactBook.adding();
                break;
              }
              case 2: {
                contactBook.listing();
                break;
              }
              case 3: {
                contactBook.searching();
                break;
              }
              case 4: {
                contactBook.editing();
                break;
              }
              case 5: {
                contactBook.deleting();
                break;
              }
              case 0: {
                flag = 1;
                break;
              }
            }
            if (flag == 1) break;
          }
        } else {
          cout << "\nWrong Password.\nContact the Developer if you forgot the "
                  "password.\n";
        }
        break;
      }
      case newAdmin: {
        string username, password;
        cout << "Enter the username for new Admin: ";
        cin >> username;
        cout << "Enter(Create) the Password: ";
        cin >> password;
        Admin admin(username, password);
        admin.displayDetails();
        break;
      }
      case 0: {
        cout << "\n\nThank You For Using Contact Management Application\n\n";
        exit(0);
      }
    }
  }
}
