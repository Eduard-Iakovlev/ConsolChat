#pragma once
# include "Libraries.h"
class Massage
{
public:
	Massage() = default;
	Massage(string, string, string);



private:
	string _mass;
	string _sender;
	string _recipient;
};

