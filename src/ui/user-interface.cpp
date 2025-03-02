#include "user-interface.hpp"

#include <fstream>
#include <iostream>

#include "../auth/user.hpp"
#include "../core/contact-book.hpp"

using namespace std;

void UserInterface::run() {
  displayStart();
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
        cout << "\n\nThank You For Using Contact Management Application\n\n";
        return;
    }
  }
}

void UserInterface::handleUser() {
  string name;
  cout << "Enter Your Full name to make an entry into Users.txt: ";
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
  cout << "Enter Username & Password\nUsername: ";
  cin >> username;
  cout << "Password: ";
  cin >> password;

  Admin admin;
  if (!admin.checkCredentials(username, password)) {
    cout << "\nWrong Password.\nContact the Developer if you forgot the "
            "password.\n";
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

void UserInterface::displayStart() {
  cout << "\n\t\t\t\t\t**** Welcome to Contacts Manager Application ****"
       << endl;
  cout << "INSTRUCTION: YOU CAN ONLY VIEW/SEARCH FOR A CONTACT IF YOU ARE A "
          "USER. TO EDIT, DELETE AN EXISTING CONTACT OR ADD ANY NEW CONTACT, "
          "SIGN IN AS ADMINISTRATOR."
       << endl;
}

int UserInterface::displayStartMenu() {
  cout << "\nSelect your choice(1/2/3/4)\n[1]USER\n[2]EXISTING "
          "ADMIN\n[3]CREATE ADMIN (Select this only if you are starting this "
          "Application with a new start)\n[0]EXIT\nEnter the choice:";
  int choice;
  cin >> choice;
  return choice;
}

int UserInterface::displayAdminMenu() {
  cout << "\n\n\t\t\t\t\t\tMAIN "
          "MENU\n\t\t\t\t\t=====================\n\t\t\t\t\t[1] Add a new "
          "Contact\n\t\t\t\t\t[2] List all Contacts\n\t\t\t\t\t[3] Search "
          "for contact\n\t\t\t\t\t[4] Edit a Contact\n\t\t\t\t\t[5] Delete a "
          "Contact\n\t\t\t\t\t[0] Exit\n\t\t\t\t\t=================\n\t\t";
  cout << "\t\t\tEnter the choice:";
  int op;
  cin >> op;
  return op;
}

int UserInterface::displayUserMenu() {
  cout << "\n\n\t\t\t\t\t\tMAIN "
          "MENU\n\t\t\t\t\t=====================\n\t\t\t\t\t[1] List all "
          "Contacts\n\t\t\t\t\t[2] Search for contact\n\t\t\t\t\t[0] "
          "Exit\n\t\t\t\t\t=================\n\t\t";
  cout << "\t\t\tEnter the choice:";
  int op;
  cin >> op;
  return op;
}