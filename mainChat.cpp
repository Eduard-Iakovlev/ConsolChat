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
		if (menu == 3) // выход из аккаунта
		{
			chat.farewell();
			work = false;
			break;
		}
		else if (menu == 1) // вход в аккаунт
		{
			if (chat.sizeList() == 1)
			{
				chat.no_users();
				continue;
			}
			std::cout << " ¬ход \n";
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
		else // регистраци€ нового пользоател€.
		{
			std::cout << " –гистраци€:\n";
			chat.registration(menu, &check_user);
		}
		if (chat.sizeList() == 2)
		{
			chat.one_user();
			continue;
		}
		

		do // работа аккаунта
		{
			menu = chat.menu_chat();
			discussion = true;
			switch (menu)
			{
			case 1: // лична€ беседа
				chat.showListUsers();
				cout << " ID собеседника: ";
				chat.get_recipient(menu);
				chat.show_massege_list();
				chat.send_massage();
				break;
			case 2: // сообщение всем
				chat.get_recipient(menu);
				chat.send_massage();
				break;
			case 3: // выход
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
