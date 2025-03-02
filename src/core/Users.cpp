#include <iostream>
#include <fstream>
#include <string>
#include "Users.hpp"
using namespace std;

Users::Users(string name_) : name(name_) {}

void Users::checkIn()
{
	ofstream fout;
	fout.open("Users.txt", ios::app);
	fout << name << "\n"
		 << __TIMESTAMP__ << "\n";
}
