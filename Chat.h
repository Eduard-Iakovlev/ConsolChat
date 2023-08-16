#pragma once
#include "Libraries.h"



class Chat
{
public:
	Chat();
	void greeting();
	void farewell();
	int logOrReg();

	void registration(int);

	void showLisrUsers();

	int sizeList();

private:
	std::vector<User> _users;
	std::vector<Massage> _massages;

};

