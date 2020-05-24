#include"Second_heir.h"


Second_heir::Second_heir():Base_class(),father_name("empty")
{
}

Second_heir::Second_heir(string name, string name_f):Base_class(name),father_name(name_f)
{
}

Second_heir::Second_heir(const Second_heir& obj):Base_class(obj),father_name(obj.father_name)
{
}


Second_heir::~Second_heir()
{
}

string Second_heir::getInfo()const
{
	stringstream temp;
	temp << setw(10) << name << setw(10) << father_name;
	return temp.str();
}

void Second_heir::input(istream& input)
{
	input >> name >> father_name;
}

stringstream Second_heir::getSsObj()const
{
	stringstream temp;
	temp << setw(20) << name << setw(20) << father_name;
	return temp;
}

Second_heir& Second_heir::operator= (Second_heir& temp)
{
	if (this == &temp)
		return *this;
	Base_class::operator=(temp);
	string name_f = temp.father_name;
	return *this;
}