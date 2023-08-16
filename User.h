#pragma once
#include "Function.h"
#include "Libraries.h"


using std::string;
using std::ostream;

class User
{
public:
	User() = default;
	User(string, string, string);

	void registration(int);
	void showUser();
	void showUser(string);
	void showUserName();

	string user_name();
	string user_login();
	string user_password();


private:
	string _name;
	string _login;
	string _password;
};

