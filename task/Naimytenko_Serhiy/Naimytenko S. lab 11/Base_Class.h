#pragma once
#include"MyClass.h"
class Book
{
protected:
	string name;
	string author;
	int year_creating;
public:
	Book();

	Book(string name, string surname, int age);

	Book(const Book& obj);

	virtual ~Book();

	friend ostream& operator<<(ostream& output, const Book& obj) noexcept;

	friend istream& operator>>(istream& input, Book& obj) noexcept;

	bool operator==(const Book obj) const noexcept;

	bool operator<(const Book obj) const noexcept;

	bool operator>(const Book obj) const noexcept;

	virtual string getInfo() const ;
};