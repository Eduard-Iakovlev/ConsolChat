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

	void shouLisrUsers();

	int sizeList();

private:
	std::vector<User> users;
};

