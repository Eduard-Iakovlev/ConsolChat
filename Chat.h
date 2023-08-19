#pragma once
#include "User.h"
#include "Massage.h"
#include "Libraries.h"

class Chat
{
public:
	Chat();
	Chat(string, string, string, int, int);
	void greeting();
	void farewell();
	int logOrReg();
	int menu_chat();

	void registration(int, bool*);

	void showListUsers();
	string active_user_login();
	string active_user_name();
	string active_recipient_login();
	

	void get_user(int, string, string);
	void out_user();
	void get_recipient(int);


	int sizeList();

	void send_massage();
	void show_massege_list();

	void one_user();
	void no_users();


private:
	std::vector<User> _users;
	std::vector<Massage> _massages;
	string _active_user_login;
	string _active_recipient_login;
	string _active_user_name;
	int _active_user_ID;
	int _active_recipient_ID;
};

