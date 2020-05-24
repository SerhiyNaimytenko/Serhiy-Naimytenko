#pragma once
#include"Base_class.h"

class First_heir:public Base_class
{
public:
	First_heir();
	First_heir(string,string);
	First_heir(const First_heir&);
	~First_heir();

	string getInfo() const;

	void input(istream& input);

	stringstream getSsObj() const;

	First_heir& operator= (First_heir& temp);

private:
	string mother_name;
};
 