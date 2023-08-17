#include "Function.h"
#include "Chat.h"



int main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);

	bool work{ true };
	bool check_user{ false };
	bool discussion{ true };
	int menu{ 0 };

	
	Chat chat;

	while (work)
	{
		menu = chat.logOrReg();
		if (menu == 3) // выход из аккаунта
		{
			chat.farewell();
			work = false;
			break;
		}
		else if (menu == 1) // вход в аккаунт
		{
			std::cout << " Вход \n";
			chat.registration(menu, &check_user);
			if (check_user == false)
			{
				Sleep(2500);
				system("cls");
				continue;
			}
		}
		else // регистрация нового пользоателя.
		{
			std::cout << " Ргистрация:\n";
			chat.registration(menu, &check_user);
		}
		if (chat.sizeList() == 1)
		{
			cout << " вы пока единственный пользователь. \n Зайдите попозже, когда ещё кто ни будь зарегестрируется.\n";
			chat.out_user();
			Sleep(2500);
			system("cls");
			continue;
		}
		

		do
		{
			menu = chat.menu_chat();
			discussion = true;
			switch (menu)
			{
			case 1:
				chat.showListUsers();
				cout << " ID собеседника: ";
				chat.get_recipient(menu);
				chat.show_massege_list();
				chat.send_massage();
				break;
			case 2:
				chat.get_recipient(menu);
				chat.send_massage();
				break;
			case 3:
				chat.out_user();
				discussion = false;
				break;

			default:
				break;
			}

		} while (discussion);


	}

	
}
