#include "Function.h"
#include "Chat.h"



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
		else if (menu == 1)
		{
			std::cout << " ���� \n";
			chat.registration(menu);
		}
		else
		{
			std::cout << " ����������:\n";
			chat.registration(menu);
		}
		if (chat.sizeList() == 1)
		{
			cout << " �� ���� ������������ ������������. \n ������� �������, ����� ��� ��� �� ���� ����������������.\n";
			chat.out_user();
			Sleep(3000);
			system("cls");
			continue;
		}
		else
		{
			menu = chat.menu_chat();
		}

	}

	
}
