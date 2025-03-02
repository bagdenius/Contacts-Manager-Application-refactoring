#include "include/core/Contact.h"
#include <iostream>
#include <fstream>
using namespace std;

Contact::Contact(string name, string number, string address, string mail) : contactName(name), contactNumber(number), contactAddress(address), contactEmail(mail) {}

void Contact::display()
{
	cout << "\nName: " << contactName;
	cout << "\nNumber: " << contactNumber;
	cout << "\nAddress: " << contactAddress;
	cout << "\nEmail: " << contactEmail;
}

void Contact::add()
{
	ofstream fout;
	fout.open("ContactBook.txt", ios::app);
	fout << "\n";
	fout << contactName << "\n";
	fout << contactNumber << "\n";
	fout << contactAddress << "\n";
	fout << contactEmail << "\n";
}
