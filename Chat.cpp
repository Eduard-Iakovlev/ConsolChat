#include "Chat.h"
#include "Libraries.h"
#include "Massage.h"
#include "Function.h"


Chat::Chat()
{
	greeting();
}

Chat::Chat(string active_user_login, string active_recipient_login, string active_user_name, int active_user_ID, int active_recipirnt_ID) :
	_active_user_login(active_user_login), _active_recipient_login(active_recipient_login), _active_user_name(active_user_name), _active_user_ID(active_user_ID), _active_recipient_ID(active_recipirnt_ID) {}


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
		user.get_user_login(checkInput<string>(48, 126));
		cout << "\n Введите пароль: ";
		user.get_user_password(checkInput<string>(48, 126));
		int counter = 0;

		for (User i : _users)
		{
			if (user.user_login() == i.user_login() && user.user_password() == i.user_password())
			{
				get_user(counter, i.user_login(), i.user_name());
				clear_display();
				cout << "\n\n Вы вошли как:\n\n";
				_users.at(counter).showUser();
				*check_user = true;
			}
			counter++;
		}
		if (*check_user == false)
		{
			cout << "\n Не верный логин или пароль!";
			Sleep(2000);
			return;
		}

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
		int size = _users.size() - 1;
		get_user(size, _users.at(size).user_login(), _users.at(size).user_name());
		clear_display();
		cout << "\n\n Вы зарегестрированы как:\n\n";
		_users.at(size).showUser();
	}
}

void Chat::showListUsers()
{
	int counter{ 0 };
	clear_show_user();
	cout << "\n Участники чата:\n\n";

	for (User user : _users)
	{
		counter++;
		if ((counter - 1) == _active_user_ID) continue;
		cout << counter << " - ";
		user.showUser();
	}
}

string Chat::active_user_login()
{
	return _active_user_login;
}

string Chat::active_user_name()
{
	return _active_user_name;
}

string Chat::active_recipient_login()
{
	return _active_recipient_login;
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

void Chat::get_recipient(int menu)
{
	if (menu == 2) _active_recipient_login = "ALL_USERS";
	else
	{
		int id{ 0 };
		do
		{
			id = checkInput<int>(48, 57);
			if (id < 1 || id > _users.size())
			{
				cout << "\n Не верный ID, повторите выбор: ";
			}
			else break;

		} while (true);
		id -= 1;
		_active_recipient_login = _users.at(id).user_login();
		_active_recipient_ID = id;
	}
}

int Chat::sizeList()
{
	return _users.size();
}

void Chat::send_massage()
{
	Massage massage;
	string mess;
	char menu{ '\0' };
	cout << " Написать - \"Enter\", Выход - \"Esc\" -> ";
	while (true)
	{
		menu = _getch();
		if (menu == 27)
		{
			clear_show_user();
			break;
		}
		else if (menu == 13)
		{
			cout << "\n ";
			getline(cin, mess);
			massage.create_massage(mess, _active_user_name, _active_user_login, _active_recipient_login);
			_massages.push_back(massage);
			clear_show_user();
			cout << " Сообщение для ";
			if (_active_recipient_login == "ALL_USERS") cout << " всем";
			else _users.at(_active_recipient_ID).showUserName();
			cout << " отправлно \n";
			break;
		}
		else cout << " хм, можно повторить: ";
	}
}

void Chat::show_massege_list()
{
	clear_show_user();
	cout << "\n Беседа с \n";
	_users.at(_active_recipient_ID).showUser();
	for (Massage i : _massages)
	{
		if (_active_user_login == i.login_sender() && _active_recipient_login == i.login_recipient()
			|| _active_user_login == i.login_recipient() && _active_recipient_login == i.login_sender())
		{
			i.show_massage();
		}
		if (i.login_recipient() == "ALL_USERS") i.show_massage();
	}
}

void Chat::one_user()
{
	cout << " вы пока единственный пользователь. \n Зайдите попозже, когда ещё кто ни будь зарегестрируется.\n";
	out_user();
	Sleep(2500);
	clear_display();

}

void Chat::no_users()
{
	cout << "\n Зарегистрированных пользователей пока нет. \n Пожалуйста сначала зарегистрируйтесь.\n ";
	Sleep(2000);
	clear_display();
}

void Chat::clear_show_user()
{
	clear_display();
	_users.at(_active_user_ID).showUser();
}





