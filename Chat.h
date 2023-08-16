#pragma once
#include "User.h"
#include "Massage.h"
#include "Libraries.h"

class Chat
{
public:
	Chat();
	Chat(string, string, int);
	void greeting();
	void farewell();
	int logOrReg();
	int menu_chat();

	void registration(int, bool*);

	void showListUsers();
	string activ_user_login();
	

	void get_user(int, string, string);
	void out_user();

	int sizeList();

private:
	std::vector<User> _users;
	std::vector<Massage> _massages;
	string _active_user_login;
	string _active_user_name;
	int _active_user_ID;
};

