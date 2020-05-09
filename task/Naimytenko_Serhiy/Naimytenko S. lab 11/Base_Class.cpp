#include "Base_Class.h"
Book::Book() : name("TOP_BOOK"), author("Pushkin"),year_creating(1999) {}

Book::Book(string name, string author, int year_creating) : name(name), author(author), year_creating(year_creating) {}

Book::Book(const Book& obj) : name(obj.name), author(obj.author), year_creating(obj.year_creating) {}

Book:: ~Book() {}

string Book::getInfo() const 
{
	stringstream temp; 
	temp << setw(15) << name << setw(20) << author << setw(6) << year_creating << endl;
	return temp.str();
}

ostream& operator<<(ostream& output, const Book& obj)   noexcept
{
	output.setf(std::ios::left);
	output << obj.getInfo();
	return output;
}

istream& operator>>(istream& input, Book& obj)  noexcept
{
	input >> obj.year_creating;
	return input;
}

bool Book::operator==(const Book obj) const   noexcept
{
	return this->year_creating == obj.year_creating;
}

bool Book::operator<(const Book obj) const   noexcept
{
	return this->year_creating < obj.year_creating;
}

bool Book::operator>(const Book obj) const  noexcept
{
	return this->year_creating > obj.year_creating;
}