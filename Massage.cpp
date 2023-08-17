#include "Massage.h"
#include "Libraries.h"
#include "Function.h"

Massage::Massage(string mass, string name, string sender, string recipient) : 
	_mass(mass), _name_sender(name), _login_sender(sender), _login_recipient(recipient) {}

void Massage::create_massage(string name ,string login_sender, string login_recipient)
{
	_mass = checkInput<string>(21, 255);
	_name_sender = name;
	_login_sender = login_sender;
	_login_recipient = login_recipient;
}

void Massage::show_massage()
{
	cout << "\n " << _login_sender << " / " << _name_sender << "\n";
	cout << _mass << "\n";
}

string Massage::login_sender()
{
	return _login_sender;
}

string Massage::login_recipient()
{
	return _login_recipient;
}


