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

void Chat::registration(int menu, bool* check_user) 
{
	User user;
	*check_user = false;
	if (menu == 1)
	{
		cout << "\n Введите логин: ";
		user.get_user_name(checkInput<string>(48, 126));
		cout << "\n Введите пароль: ";
		user.get_user_password(checkInput<string>(48, 126));
		int counter = 0;

		for (User i: _users)
		{
			if (user.user_login() == i.user_login() && user.user_password() == i.user_password())
			{
				get_user(counter, user.user_login(), user.user_name());
				*check_user = true;
			}
		}
		if (*check_user == false)
		{
			cout << "\n Не верный логин или пароль!";
			Sleep(2000);
			return;
		}

		cout << "\n\n Вы вошли как:\n\n";
		user.showUser(activ_user_login());
	}
	else
	{
		*check_user = true;
		cout << " Введите имя (только русский алфавит): ";
		user.get_user_name(checkInput<string>(192, 255));
			cout << "\n Введите логин (латинский алфавит, цифры, символы): ";
		bool check_login;
		do
		{
			check_login = true;
			user.get_user_login(checkInput<string>(48, 126));
			for (User i : _users)
			{
				if (user.user_login() == i.user_login())
				{
					user.clear_login();
					cout << "\n Данный логин занят, выбрите другой: ";
					check_login = false;
					break;
				}
			}
		} while (!check_login);
			cout << "\n Введите пароль (латинский алфавит, цифры, символы): ";
			user.get_user_password(checkInput<string>(48, 126));
		
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



