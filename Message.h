#pragma once
# include "Libraries.h"
class Message
{
public:
	Message() = default;
	Message(string, string, string, string);

	void create_message(string, string, string, string);
	void show_message();

	string login_sender();
	string login_recipient();

private:
	string _mass;
	string _name_sender;
	string _login_sender;
	string _login_recipient;
};

