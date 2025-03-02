#include "contact.hpp"

#include <fstream>
#include <iostream>
using namespace std;

Contact::Contact(string name, string number, string address, string mail)
    : _name(name), _number(number), _address(address), _email(mail) {}

void Contact::display() {
  cout << "\nName: " << _name;
  cout << "\nNumber: " << _number;
  cout << "\nAddress: " << _address;
  cout << "\nEmail: " << _email;
}

void Contact::add() {
  ofstream fout;
  fout.open("contact-book.txt", ios::app);
  fout << "\n";
  fout << _name << "\n";
  fout << _number << "\n";
  fout << _address << "\n";
  fout << _email << "\n";
}
