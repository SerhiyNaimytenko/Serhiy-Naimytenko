#pragma once
#include"Base_class.h"

class Second_heir:public Base_class
{
public:
	Second_heir();
	Second_heir(string,string);
	Second_heir(const Second_heir&);
	~Second_heir();

	string getInfo() const;

	void input(istream& input);

	stringstream getSsObj() const;

	Second_heir& operator= (Second_heir& temp);

private:
	string father_name;
};
 