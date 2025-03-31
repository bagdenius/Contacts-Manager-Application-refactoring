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
        cout << "\n\n Завершення роботи програми...\n\n";
        return;
    }
  }
}

void UserInterface::handleUser() {
  string name;
  cout << " - Введіть своє ім'я: ";
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
  cout << "\n - Вхід в акаунт -"
          "\n - Логін: ";
  cin >> username;
  cout << " - Пароль: ";
  cin >> password;

  Admin admin;
  if (!admin.checkCredentials(username, password)) {
    cout << "\n Введено невірний пароль!\n";
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
  cout << " - Задайте ім'я користувача: ";
  cin >> username;
  cout << " - Задайте пароль: ";
  cin >> password;

  Admin admin(username, password);
  cout << " Адміна було успішно створено!\n";
}

void UserInterface::changeAdminUsername(Admin user) {
  cout << " - Введіть нове ім'я користувача: ";
  string newUsername;
  cin >> newUsername;
  user.setUsername(newUsername);
}

void UserInterface::changeAdminPassword(Admin user) {
  cout << " - Введіть новий пароль: ";
  string newPassword;
  cin >> newPassword;
  user.setPassword(newPassword);
}

void UserInterface::displayAdminDetails(Admin user) {
  cout << user.getDetails();
}

int UserInterface::displayStartMenu() {
  cout << "\n\t--- CONTACTIFY ---"
          "\n\n [1] Увійти як користувач"
          "\n [2] Увійти як адміністратор"
          "\n [3] Створити адміністратора"
          "\n [0] Вихід"
          "\n\n - Оберіть пункт меню: ";
  int choice;
  cin >> choice;
  return choice;
}

int UserInterface::displayAdminMenu() {
  cout << "\n\n\t- Головне меню - "
          "\n\n [1] Додати контакт"
          "\n [2] Список всіх контактів"
          "\n [3] Пошук контакту"
          "\n [4] Оновити контакт"
          "\n [5] Видалити контакт"
          "\n [0] Вихід"
          "\n\n - Оберіть пункт меню: ";
  int op;
  cin >> op;
  return op;
}

int UserInterface::displayUserMenu() {
  cout << "\n\n\t- Головне меню -"
          "\n\n [1] Список всіх контактів"
          "\n [2] Пошук контакту"
          "\n [0] Вихід"
          "\n\n - Оберіть пункт меню: ";
  int op;
  cin >> op;
  return op;
}