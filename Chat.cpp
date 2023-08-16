#include "Libraries.h"


Chat::Chat()
{
	greeting();
}


void Chat::greeting()
{
		cout << "\n          Добро пожаловать!\n\n";
}

void Chat::farewell()
{
	cout << "\n\n          Всего хорошего.\n";
}

int Chat::logOrReg()
{
	cout << " Вход - 1\n";
	cout << " Регистрация - 2 \n";
	cout << " Выход - 3 \n -> ";
	return checkInput<int>('1', '3');
}

void Chat::registration(int menu)
{
	User user;
	user.registration(menu);
	users.push_back(user);
	cout << "\n Вы зарегестрированы как:\n";
	user.shouUser();	
}


void Chat::shouLisrUsers()
{
	for (User i : users)
	{
		cout << " 1 - ";
		i.showUserName();
		cout << "\n";
	}
}

int Chat::sizeList()
{
	return users.size();
}



