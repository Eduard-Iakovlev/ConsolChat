#include "Message.h"
#include "Libraries.h"
#include "Function.h"

Message::Message(string mass, string name, string sender, string recipient) : 
	_mass(mass), _name_sender(name), _login_sender(sender), _login_recipient(recipient) {}

void Message::create_message(string mass, string name ,string login_sender, string login_recipient)
{
	_mass = mass;
	_name_sender = name;
	_login_sender = login_sender;
	_login_recipient = login_recipient;
}

void Message::show_message()
{
	cout << "\n |" << _login_sender << " / " << _name_sender << "|\n";
	cout << "--------------------:\n";
	cout << _mass << "\n";
	cout << "--------------------------------------------------------\n";
}

string Message::login_sender()
{
	return _login_sender;
}

string Message::login_recipient()
{
	return _login_recipient;
}


