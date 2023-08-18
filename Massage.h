#pragma once
# include "Libraries.h"
class Massage
{
public:
	Massage() = default;
	Massage(string, string, string, string);

	void create_massage(string, string, string, string);
	void show_massage();

	string login_sender();
	string login_recipient();

private:
	string _mass;
	string _name_sender;
	string _login_sender;
	string _login_recipient;
};

