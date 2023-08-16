#include"User.h"
#include "Libraries.h"

User::User(string name, string login, string password) :
	_name{name}, _login{login}, _password{password} {}

void User::registration(int menu)
{
	if (menu == 1)
	{
			cout << "\n ������� �����: ";
			_login = checkInput<string>(48, 126);
			cout << "\n ������� ������: ";
			_password = checkInput<string>(48, 126);
	}
	else
	{
		cout << " ������� ��� (������ ������� �������): ";
		_name = checkInput<string>(192, 255);
		cout << "\n ������� ����� (��������� �������, �����, �������): ";
		_login = checkInput<string>(48, 126);
		cout << "\n ������� ������ (��������� �������, �����, �������): ";
		_password = checkInput<string>(48, 126);
	}
}

void User::showUser()
{
	cout << " ���:" << _name << "\n";
	cout << " �����:" << _login << "\n";
	cout << " ������:" << _password << "\n";
}

void User::showUser(string login)
{
	cout << " ���:" << _name << "\n";
	cout << " �����:" << _login << "\n";
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



