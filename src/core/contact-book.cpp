#include "contact-book.hpp"

#include <fstream>
#include <iostream>

#include "../config.hpp"
#include "../helpers/delete-helper.hpp"
#include "contact.hpp"

using namespace std;

void ContactBook::adding() {
  string values[4];
  for (int i = 0; i < 4; i++) {
    cout << _details[i] << ": ";
    getline(cin >> ws, values[i]);
  }
  Contact contact(values[0], values[1], values[2], values[3]);
  contact.add();
}

void ContactBook::listing() {
  ifstream fin;
  fin.open(CONTACT_BOOK_PATH, ios::in);
  char input[30];
  int i = 0;
  cout << "\n";
  while (fin) {
    fin.getline(input, 30);
    if (i != 4)
      cout << " " << _details[i] << ": " << input << endl;
    else
      cout << " " << _details[i] << input << endl;
    i++;
    if (i == 5) i = 0;
  }
}

void ContactBook::searching() {
  string name;
  cout << "\n - Введіть ім'я контакта, якого шукаєте: ";
  getline(cin >> ws, name);
  ifstream fin;
  fin.open(CONTACT_BOOK_PATH, ios::in);
  string input;
  int c = 0;
  cout << "\n";
  while (fin) {
    getline(fin >> ws, input);
    if (input == name) {
      c++;
      for (int i = 0; i < 4; i++) {
        cout << " " << _details[i] << ": " << input << endl;
        getline(fin >> ws, input);
      }
    }
    if (c > 0) break;
  }
}

void ContactBook::editing() {
  string name;
  cout << "\n - Введіть ім'я контакта, якого бажаєте оновити: ";
  getline(cin >> ws, name);
  ifstream fin;
  ofstream fout;
  fin.open(CONTACT_BOOK_PATH, ios::in);
  fout.open(CONTACT_BOOK_TEMP_PATH, ios::out | ios::trunc);
  string input;
  int b = 0;
  int c = 0;
  while (!fin.eof()) {
    getline(fin >> ws, input);
    b++;
    if (input == name) {
      c++;
      cout << "\n Введіть нову інформацію: \n";
      for (int i = 0; i < 4; i++) {
        string newDetail;
        cout << " Новий(а) " << _details[i] << ": ";
        getline(cin >> ws, newDetail);
        b++;
        fout << newDetail << "\n";
      }
      for (int i = 0; i <= 3; i++, b++) getline(fin >> ws, input);
      fout << "\n" << input << "\n";
    } else {
      if (fin.eof() != 1)
        fout << input << "\n";
      else
        fout << input;
      if (b % 4 == 0 && fin.eof() != 1) fout << "\n";
    }
  }
}

void ContactBook::deleting() {
  string name;
  cout << "\n - Введіть ім'я контакта, якого бажаєте видалити: ";
  getline(cin >> ws, name);
  DeleteHelper deleteHelper(name);
  deleteHelper.deleteFromContactbook();
}
