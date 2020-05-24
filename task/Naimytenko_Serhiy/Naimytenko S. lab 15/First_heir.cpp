#include"First_heir.h"


First_heir::First_heir() :Base_class(), mother_name("empty")
{
}

First_heir::First_heir(string name,string name_m):Base_class(name),mother_name(name_m)
{
}

First_heir::First_heir(const First_heir& obj) : Base_class(obj),mother_name(obj.mother_name)
{
}

First_heir::~First_heir()
{
}

string First_heir::getInfo() const
{
	stringstream temp;
	temp << setw(10) << name << setw(10) << mother_name;
	return temp.str();
}

void First_heir::input(istream& input)
{
	input >> name >> mother_name;
}

stringstream First_heir::getSsObj() const
{
	stringstream temp;
	temp << setw(10) << name << setw(10) << mother_name;
	return temp;
}

First_heir& First_heir::operator= (First_heir& temp)
{
	if (this == &temp)
		return *this;
	Base_class::operator=(temp);
	string name_f = temp.mother_name;
	return *this;
}