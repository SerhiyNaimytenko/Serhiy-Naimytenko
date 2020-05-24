#pragma once
#include"Header.h"


class  Base_class
{
public:
	 Base_class();
	 Base_class(string);
	 Base_class(const Base_class&);
	~ Base_class(); 

	virtual string getInfo() const = 0;

	virtual void input(istream& input) = 0;

	virtual stringstream getSsObj() const = 0;
	 
	Base_class& operator= (Base_class& temp);

	friend istream& operator>> (istream& input, Base_class& obj);

	friend ostream& operator<< (ostream& output, const Base_class& obj);
	 

protected:
	string name;
}; 