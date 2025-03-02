#include "include/auth/AdminLogin.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

AdminLogin::AdminLogin()
{
	ifstream fin;
	fin.open("password.txt", ios::in);
	string user, pass;
	getline(fin, user);
	getline(fin, pass);
	Username = user;
	Password = pass;
}

bool AdminLogin::checkCredentials(string user, string pass)
{
	if (user == Username && pass == Password)
		return true;
	else
		return false;
}
