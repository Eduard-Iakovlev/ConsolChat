#pragma once
#include "User.h"
#include "Massage.h"
#include "Libraries.h"

class Chat
{
public:
	Chat();
	void greeting();
	void farewell();
	int logOrReg();

	void registration(int);

	void showListUsers();

	int sizeList();

private:
	std::vector<User> _users;
	std::vector<Massage> _massages;

};

