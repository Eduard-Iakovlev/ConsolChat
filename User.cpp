#include "Libraries.h"

User::User(string name, string login, string password) :
	_name{name}, _login{login}, _password{password} {}

void User::registration(int menu)
{
	if (menu == 1)
	{
		cout << "\n ¬ведите логин (латинский алфавит, цифры, символы): ";
		_login = checkInput<string>(48, 126);
		cout << "\n ¬ведите пароль (латинский алфавит, цифры, символы): ";
		_password = checkInput<string>(48, 126);
	}
	else
	{
		cout << " ¬ведите им€ (только русский алфавит): ";
		_name = checkInput<string>(192, 255);
		cout << "\n ¬ведите логин (латинский алфавит, цифры, символы): ";
		_login = checkInput<string>(48, 126);
		cout << "\n ¬ведите пароль (латинский алфавит, цифры, символы): ";
		_password = checkInput<string>(48, 126);
	}
}

void User::shouUser()
{
	cout << " »м€:" << _name << "\n";
	cout << " Ћогин:" << _login << "\n";
	cout << " ѕароль:" << _password << "\n";
}

void User::showUserName()
{
	cout << _name << "\n";
}



