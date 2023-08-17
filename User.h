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

	void showUser();
	void showUser(string);
	void showUserName();

	string user_name();
	string user_login();
	string user_password();

	void get_user_name(string);
	void get_user_login(string);
	void get_user_password(string);
	void clear_login();



private:
	string _name;
	string _login;
	string _password;
};

