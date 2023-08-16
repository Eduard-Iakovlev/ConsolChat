#include "Libraries.h"


Chat::Chat()
{
	greeting();
}


void Chat::greeting()
{
		cout << "\n          ����� ����������!\n\n";
}

void Chat::farewell()
{
	cout << "\n\n          ����� ��������.\n";
}

int Chat::logOrReg()
{
	cout << " ���� - 1\n";
	cout << " ����������� - 2 \n";
	cout << " ����� - 3 \n -> ";
	return checkInput<int>('1', '3');
}

void Chat::registration(int menu)
{
	User user;
	user.registration(menu);
	_users.push_back(user);
	cout << "\n �� ���������������� ���:\n";
	user.shouUser();	
}


void Chat::showLisrUsers()
{
	int counter{ 0 };

	cout << " ��������� ����:\n\n";

	for (User i : _users)
	{
		counter++;
		cout << counter << " - ";
		i.showUserName();
	}
	User user;
}

int Chat::sizeList()
{
	return _users.size();
}



