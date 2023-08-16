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
		else if (menu == 1) std::cout << " Вход выполнен\n";
		else
		{
			std::cout << " Ргистрация:\n";
			chat.registration(menu);

		}
		if (chat.sizeList() == 1)
		{
			cout << " вы пока единственный пользователь. \n Зайдите попозже, когда ещё кто ни будь зарегестрируется.\n";
			Sleep(2000);
			system("cls");
			continue;
		}
		else chat.showLisrUsers();

	}

	
}
