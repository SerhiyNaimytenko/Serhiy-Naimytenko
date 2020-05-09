#include"Inheritor_Classr.h"
Info::Info() : Book(), size(2) {}

Info::Info(string name, string author, int year_creating, int size) : Book(name, author, year_creating), size(size) {}

Info::Info(const Info& obj) : Book(obj),size(obj.size) {}

Info::~Info() {}

string Info::getInfo() const
{
	stringstream temp; 
	temp << setw(15) << name << setw(20) << author << setw(6) << year_creating << setw(6) << size<<endl;
	return temp.str();
}