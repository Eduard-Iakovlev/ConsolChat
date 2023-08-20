#include"User.h"
#include "Libraries.h"

User::User(string name, string login, string password) :
	_name{name}, _login{login}, _password{password} {}

void User::showUser()
{
	cout << " Имя:" << _name << " / ";
	cout << " Логин:" << _login << "\n";
}
void User::showUserName()
{
	cout << _name;
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

void User::get_user_name(string name)
{
	_name = name;
}
void User::get_user_login(string login)
{
	_login = login;
}
void User::get_user_password(string password)
{
	_password = password;
}

void User::clear_login()
{
	_login.clear();
}




