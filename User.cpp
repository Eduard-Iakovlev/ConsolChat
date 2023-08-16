#include "Libraries.h"

User::User(string name, string login, string password) :
	_name{name}, _login{login}, _password{password} {}

void User::registration(int menu)
{
	if (menu == 1)
	{
		cout << "\n ������� ����� (��������� �������, �����, �������): ";
		_login = checkInput<string>(48, 126);
		cout << "\n ������� ������ (��������� �������, �����, �������): ";
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

void User::shouUser()
{
	cout << " ���:" << _name << "\n";
	cout << " �����:" << _login << "\n";
	cout << " ������:" << _password << "\n";
}

void User::showUserName()
{
	cout << _name << "\n";
}



