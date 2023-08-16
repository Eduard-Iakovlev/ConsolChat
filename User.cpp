#include"User.h"
#include "Libraries.h"

User::User(string name, string login, string password) :
	_name{name}, _login{login}, _password{password} {}

void User::registration(int menu)
{
	if (menu == 1)
	{
			cout << "\n Введите логин: ";
			_login = checkInput<string>(48, 126);
			cout << "\n Введите пароль: ";
			_password = checkInput<string>(48, 126);
	}
	else
	{
		cout << " Введите имя (только русский алфавит): ";
		_name = checkInput<string>(192, 255);
		cout << "\n Введите логин (латинский алфавит, цифры, символы): ";
		_login = checkInput<string>(48, 126);
		cout << "\n Введите пароль (латинский алфавит, цифры, символы): ";
		_password = checkInput<string>(48, 126);
	}
}

void User::showUser()
{
	cout << " Имя:" << _name << "\n";
	cout << " Логин:" << _login << "\n";
	cout << " Пароль:" << _password << "\n";
}

void User::showUser(string login)
{
	cout << " Имя:" << _name << "\n";
	cout << " Логин:" << _login << "\n";
}

void User::showUserName()
{
	cout << _name << "\n";
}

string User::user_name()
{
	return _name;
}

string User::user_login()
{
	return _login;
}

string User::user_password()
{
	return _password;
}



