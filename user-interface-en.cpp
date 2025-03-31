#include "user-interface.hpp"

#include <fstream>
#include <iostream>

#include "../auth/user.hpp"
#include "../core/contact-book.hpp"

using namespace std;

void UserInterface::run() {
  while (true) {
    int choice = displayStartMenu();
    switch (choice) {
      case 1:
        handleUser();
        break;
      case 2:
        handleAdmin();
        break;
      case 3:
        createNewAdmin();
        break;
      case 0:
        cout << "\n\n Exiting the application...\n\n";
        return;
    }
  }
}

void UserInterface::handleUser() {
  string name;
  cout << " - Enter your name: ";
  getline(cin >> ws, name);

  User user(name);
  user.checkIn();

  ContactBook contactBook;
  while (true) {
    int choice = displayUserMenu();
    if (choice == 0) break;

    switch (choice) {
      case 1:
        contactBook.listing();
        break;
      case 2:
        contactBook.searching();
        break;
    }
  }
}

void UserInterface::handleAdmin() {
  string username, password;
  cout << "\n - Authorize -"
          "\n Username: ";
  cin >> username;
  cout << " Password: ";
  cin >> password;

  Admin admin;
  if (!admin.checkCredentials(username, password)) {
    cout << "\n Wrong Password!";
    return;
  }

  ContactBook contactBook;
  while (true) {
    int choice = displayAdminMenu();
    if (choice == 0) break;

    switch (choice) {
      case 1:
        contactBook.adding();
        break;
      case 2:
        contactBook.listing();
        break;
      case 3:
        contactBook.searching();
        break;
      case 4:
        contactBook.editing();
        break;
      case 5:
        contactBook.deleting();
        break;
    }
  }
}

void UserInterface::createNewAdmin() {
  string username, password;
  cout << "Enter the username for new Admin: ";
  cin >> username;
  cout << "Enter(Create) the Password: ";
  cin >> password;

  Admin admin(username, password);
  cout << "Admin successfully created!\n";
}

void UserInterface::changeAdminUsername(Admin user) {
  cout << "Enter new Username: ";
  string newUsername;
  cin >> newUsername;
  user.setUsername(newUsername);
}

void UserInterface::changeAdminPassword(Admin user) {
  cout << "Enter new Password: ";
  string newPassword;
  cin >> newPassword;
  user.setPassword(newPassword);
}

void UserInterface::displayAdminDetails(Admin user) {
  cout << user.getDetails();
}

int UserInterface::displayStartMenu() {
  cout << "\n\t--- Contactify ---"
          "\n\n [1] USER"
          "\n [2] ADMIN"
          "\n [3] CREATE ADMIN"
          "\n [0] EXIT"
          "\n\n - Enter the choice: ";
  int choice;
  cin >> choice;
  return choice;
}

int UserInterface::displayAdminMenu() {
  cout << "\n\n\t- MAIN MENU- "
          "\n\n [1] Add a new Contact"
          "\n [2] List all Contacts"
          "\n [3] Search for contact"
          "\n [4] Edit a Contact"
          "\n [5] Delete a Contact"
          "\n [0] Exit"
          "\n\n - Enter the choice: ";
  int op;
  cin >> op;
  return op;
}

int UserInterface::displayUserMenu() {
  cout << "\n\n\t- MAIN MENU- "
          "\n\n [1] List all Contacts"
          "\n [2] Search for contact"
          "\n [0] Exit"
          "\n\n - Enter the choice: ";
  int op;
  cin >> op;
  return op;
}