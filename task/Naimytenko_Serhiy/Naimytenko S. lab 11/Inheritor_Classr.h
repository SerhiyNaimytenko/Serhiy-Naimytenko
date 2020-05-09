#pragma once
#include"Base_Class.h"
class Info final : public Book
{
private:
	int size;
public:
	Info();

	Info(string name, string surname, int age, int course);

	Info(const Info& obj);

	~Info() override final;

	string getInfo() const override final;
};