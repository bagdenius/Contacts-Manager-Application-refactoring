#include "./include/auth/Admin.h"
#include <iostream>
#include <fstream>
using namespace std;

Admin::Admin()
{
	ifstream fin;
	fin.open("password.txt", ios::in);
	string user, pass;
	getline(fin, user);
	getline(fin, pass);
	Username = user;
	Password = pass;
}

Admin::Admin(string Username_, string Password_) : Username(Username_), Password(Password_)
{
	ofstream fout;
	fout.open("password.txt", ios::out);
	fout << Username << "\n";
	fout << Password;
	cout << "Admin Created\n";
}

void Admin::setUser(string newUsername)
{
	Username = newUsername;
	ofstream fout;
	fout.open("password.txt", ios::out);
	fout << Username;
	fout << Password;
}

void Admin::changeUsername()
{
	cout << "Enter new Username: ";
	string newUsername;
	cin >> newUsername;
	setUser(newUsername);
}

void Admin::setPass(string newPassword)
{
	Password = newPassword;
	ofstream fout;
	fout.open("password.txt", ios::out);
	fout << Username;
	fout << Password;
}

void Admin::changePassword()
{
	cout << "Enter new Password: ";
	string newPassword;
	cin >> newPassword;
	setUser(newPassword);
}

void Admin::display_mydetails()
{
	cout << "Username: " << Username << endl;
	cout << "Password: " << Password << endl;
}
