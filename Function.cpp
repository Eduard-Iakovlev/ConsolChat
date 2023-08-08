#include "Function.h"

void greeting()
{
	cout << "\n          Добро пожаловать! \n        нажмите люую клавишу \n\n";
	_getch();
}

int login()
{
	cout << " Вход - 1\n Регистрация - 2 \n -> ";
	return checkDigit('1', '2');
}

int checkDigit(const char begin, const char end)
{
	char str[256];
	int counter{ 0 };

	while (true)
	{
		str[counter] = _getch();
		if ((str[counter] >= begin && str[counter] <= end))
		{
			cout << str[counter];
			counter++;
		}
		else if (str[counter] == 8)
		{
			if (counter == 0)
			{
				continue;
			}
			else
			{
				cout << "\b" << " " << "\b";
				counter--;
			}
		}
		else if (str[counter] == 13) break;
		else
		{
			cout << " " << "\b";
		}
	}

	return atoi(str);
}
