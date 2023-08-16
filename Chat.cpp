#include "Chat.h"
#include "Libraries.h"


Chat::Chat()
{
	greeting();
}

Chat::Chat(string active_user_login, string active_user_name, int active_user_ID) :
	_active_user_login(active_user_login), _active_user_name(active_user_name), _active_user_ID(active_user_ID) {}


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
	cout << "\n Вход - 1\n";
	cout << " Регистрация - 2 \n";
	cout << " Выход - 3 \n -> ";
	return checkInput<int>('1', '3');
}

int Chat::menu_chat()
{
	cout << "\n Выбрать беседу - 1\n";
	cout << " Создать сообщение всем - 2 \n";
	cout << " Выход из аккаунта - 3 \n ";
	showListUsers();
	cout << " -> ";
	return checkInput<int>('1', '3');
}

void Chat::registration(int menu)
{
	User user;
	user.registration(menu);
	if (menu == 1)
	{
		cout << "\n\n Вы вошли как:\n\n";
		user.showUser(activ_user_login());
	}
	else
	{
		_users.push_back(user);
		int size = _users.size()-1;
		get_user(size, _users.at(size).user_login(), _users.at(size).user_name());
		cout << "\n\n Вы зарегестрированы как:\n\n";
		_users.at(size).showUser();
	}
}


void Chat::showListUsers()
{
	int counter{ 0 };

	cout << "\n Участники чата:\n\n";

	for (User user : _users)
	{
		counter++;
		cout << counter << " - ";
		user.showUserName();
	}
}

string Chat::activ_user_login()
{
	return _active_user_login;
}

void Chat::get_user(int id, string login, string name)
{
	_active_user_ID = id;
	_active_user_login = login;
	_active_user_name = name;
}

void Chat::out_user()
{
	_active_user_ID = 0;
	_active_user_login = '\0';
	_active_user_name = '\0';

}

int Chat::sizeList()
{
	return _users.size();
}



