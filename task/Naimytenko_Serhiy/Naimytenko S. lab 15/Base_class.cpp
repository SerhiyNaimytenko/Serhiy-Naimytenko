#include"Base_class.h"

Base_class::Base_class() : name("empty")
{
}

Base_class::Base_class(string name):name(name)
{
}

Base_class::Base_class(const Base_class& obj) : name(obj.name)
{
}


Base_class::~Base_class()
{
} 

Base_class& Base_class::operator= (Base_class& temp)
{
	if (this == &temp)
		return *this;
	string name = temp.name;
	return *this;
}

istream& operator>> (istream& input, Base_class& obj)
{
	obj.input(input);
	return input;
}

ostream& operator<< (ostream& output, const Base_class& obj)
{
	output << obj.getInfo();
	return output;
}
 