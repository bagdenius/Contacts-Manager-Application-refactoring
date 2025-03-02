#include <iostream>
#include <string>
#include "auth/Admin.hpp"
#include "core/ContactBook.hpp"
#include "ui/UserInterface.hpp"
#include "core/Users.hpp"
using namespace std;

enum Identity
{
	user = 1,
	admin,
	newAdmin
};

int main()
{
	UserInterface UI;
	UI.displayStart();
	while (1)
	{
		int choice = UI.MenuDisplayStart();
		switch (choice)
		{
		case user:
		{
			string name;
			cout << "Enter Your Full name to make an entry into Users.txt: ";
			getline(cin >> ws, name);
			Users user(name);
			user.checkIn();
			ContactBook cb;
			int flag = 0;
			while (1)
			{
				int choice = UI.MenuDisplayUser();
				switch (choice)
				{
				case 1:
				{
					cb.listing();
					break;
				}
				case 2:
				{
					cb.searching();
					break;
				}
				case 0:
				{
					flag = 1;
					break;
				}
				}
				if (flag == 1)
					break;
			}
			break;
		}
		case admin:
		{
			string uname, pass;
			cout << "Enter Username & Password\n";
			cout << "Username: ";
			cin >> uname;
			cout << "Password: ";
			cin >> pass;
			Admin AL;
			bool isLoggedIn = AL.checkCredentials(uname, pass);
			if (isLoggedIn)
			{
				ContactBook cb;
				int flag = 0;
				while (1)
				{
					int choice = UI.MenuDisplayAdmin();
					switch (choice)
					{
					case 1:
					{
						cb.adding();
						break;
					}
					case 2:
					{
						cb.listing();
						break;
					}
					case 3:
					{
						cb.searching();
						break;
					}
					case 4:
					{
						cb.editing();
						break;
					}
					case 5:
					{
						cb.deleting();
						break;
					}
					case 0:
					{
						flag = 1;
						break;
					}
					}
					if (flag == 1)
						break;
				}
			}
			else
			{
				cout << "\nWrong Password.\nContact the Developer if you forgot the password.\n";
			}
			break;
		}
		case newAdmin:
		{
			string uname, pass;
			cout << "Enter the username for new Admin: ";
			cin >> uname;
			cout << "Enter(Create) the Password: ";
			cin >> pass;
			Admin A(uname, pass);
			A.display_mydetails();
			break;
		}
		case 0:
		{
			cout << "\n\nThank You For Using Contact Management Application\n\n";
			exit(0);
		}
		}
	}
}
