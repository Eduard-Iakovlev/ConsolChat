#include "Libraries.h"

User::User(string name, string login, string password) :
	_name{name}, _login{login}, _password{password}
{

}

void User::registration(int menu)
{
	if (menu == 1)
	{
		cout << "\n Введите логин (латинский алфавит, цифры, символы): ";
		_login = checkInput<string>(48, 126);
		cout << "\n Введите пароль (латинский алфавит, цифры, символы): ";
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

void User::shouUser()
{
	cout << " Имя:" << _name << "\n";
	cout << " Логин:" << _login << "\n";
	cout << " Пароль:" << _password << "\n";
}

void User::showUserName()
{
	cout << " Имя:" << _name << "\n";
}



