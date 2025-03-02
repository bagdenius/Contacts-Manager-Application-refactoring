#include "delete-helper.hpp"

#include <fstream>
#include <iostream>
using namespace std;

DeleteHelper::DeleteHelper(string name) : _name(name) {}

void DeleteHelper::deleting() {
  string name = _name;
  ifstream fin;
  ofstream fout;
  fin.open("contact-book.txt", ios::in);
  fout.open("contact-book-temp.txt", ios::out | ios::trunc);
  string input;
  int b = 0;
  int c = 0;
  while (!fin.eof()) {
    getline(fin >> ws, input);
    b++;
    if (input == name)
      c++;
    else {
      if (c >= 1 && c <= 3)
        c++;
      else {
        if (fin.eof() != 1)
          fout << input << "\n";
        else
          fout << input;
        if (b % 4 == 0 && fin.eof() != 1) fout << "\n";
      }
    }
  }
}

void DeleteHelper::temporaryToOriginal() {
  ofstream fout;
  ifstream fin;
  fout.open("contact-book.txt", ios::out | ios::trunc);
  fin.open("contact-book-temp.txt", ios::in);
  char reading[30];
  while (!fin.eof()) {
    fin.getline(reading, 30);
    if (fin.eof() == 0)
      fout << reading << "\n";
    else
      fout << reading;
  }
}

void DeleteHelper::deleteFromContactbook() {
  deleting();
  temporaryToOriginal();
  cout << "\nSuccessfully Deleted.\n";
}
