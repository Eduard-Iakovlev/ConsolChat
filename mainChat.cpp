#include "Function.h"



int main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);

	bool work{ true };
	int menu{ 0 };

	
	Chat chat;

	while (work)
	{
		menu = chat.logOrReg();
		if (menu == 3)
		{
			chat.farewell();
			work = false;
			break;
		}
		else if (menu == 1) std::cout << " ���� ��������\n";
		else
		{
			std::cout << " ����������:\n";
			chat.registration(menu);

		}
		if (chat.sizeList() == 1)
		{
			cout << " �� ���� ������������ ������������. \n ������� �������, ����� ��� ��� �� ���� ����������������.\n";
			Sleep(2000);
			system("cls");
			continue;
		}
		else chat.showLisrUsers();

	}

	
}
