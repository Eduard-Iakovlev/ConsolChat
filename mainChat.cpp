#include "Function.h"
#include "Chat.h"



int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	bool work{ true };
	bool check_user{ false };
	bool discussion{ true };
	int menu{ 0 };

	
	Chat chat;
	chat.reg_all_user();

	while (work)
	{
		menu = chat.logOrReg();
		clear_display();
		if (menu == 3) // ����� �� ��������
		{
			chat.farewell();
			work = false;
			break;
		}
		else if (menu == 1) // ���� � �������
		{
			if (chat.sizeList() == 1)
			{
				chat.no_users();
				continue;
			}
			std::cout << " ���� \n";
			chat.registration(menu, &check_user);
			if (chat.sizeList() == 2)
			{
				chat.one_user();
				continue;
			}

			if (check_user == false)
			{
				Sleep(2500);
				clear_display();
				continue;
			}
			
		}
		else // ����������� ������ �����������.
		{
			std::cout << " ����������:\n";
			chat.registration(menu, &check_user);
		}
		if (chat.sizeList() == 2)
		{
			chat.one_user();
			continue;
		}
		

		do // ������ ��������
		{
			menu = chat.menu_chat();
			discussion = true;
			switch (menu)
			{
			case 1: // ������ ������
				chat.showListUsers();
				cout << " ID �����������: ";
				chat.get_recipient(menu);
				chat.show_massege_list();
				chat.send_massage();
				break;
			case 2: // ��������� ����
				chat.get_recipient(menu);
				chat.send_massage();
				break;
			case 3: // �����
				chat.out_user();
				clear_display();
				discussion = false;
				break;

			default:
				break;
			}

		} while (discussion);


	}

	
}
