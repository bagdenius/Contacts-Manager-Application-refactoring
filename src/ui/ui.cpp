#include "ui.hpp"

#include <fstream>
#include <iostream>

using namespace std;

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
          "Contact\n\t\t\t\t\t[2] List all Contacts\n\t\t\t\t\t[3] Search for "
          "contact\n\t\t\t\t\t[4] Edit a Contact\n\t\t\t\t\t[5] Delete a "
          "Contact\n\t\t\t\t\t[0] Exit\n\t\t\t\t\t=================\n\t\t";
  cout << "\t\t\tEnter the choice:";
  int choice;
  cin >> choice;
  return choice;
}

int UserInterface::displayUserMenu() {
  cout << "\n\n\t\t\t\t\t\tMAIN "
          "MENU\n\t\t\t\t\t=====================\n\t\t\t\t\t[1] List all "
          "Contacts\n\t\t\t\t\t[2] Search for contact\n\t\t\t\t\t[0] "
          "Exit\n\t\t\t\t\t=================\n\t\t";
  cout << "\t\t\tEnter the choice:";
  int choice;
  cin >> choice;
  return choice;
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