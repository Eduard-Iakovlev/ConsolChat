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
	void shouUser();
	void showUserName();

	string user_login(int);


private:
	string _name;
	string _login;
	string _password;
};

