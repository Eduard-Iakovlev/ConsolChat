#pragma once
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


private:
	string _name;
	string _login;
	string _password;
};

