#pragma once
#include "Libraries.h"

using std::cout;


template<typename t> t checkInput(const char first, const char last)
{
	char str[256]{};
	int counter{ 0 };

	while (true)
	{
		str[counter] = _getch();
		if ((str[counter] >= first && str[counter] <= last))
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
		else if (str[counter] == 13)
		{
			if (str[0] == 13) continue;
			else
			{
				str[counter] = '\0';
				break;
			}
		}
		else
		{
			str[counter] = '\0';
			cout << " " << "\b";
		}
	}

	if constexpr (std::is_same_v<t, int>)  return atoi(str);
	else return string(str);
			
}

