

#include"MyClass.h"

bool Test_Check_index();
bool Test_Min_value();

int main()
{
	setlocale(LC_ALL, "Rus");
	bool result;
	result = Test_Check_index();
	if (result) /**< перевірка тесту*/
		cout << "Test_Check_index пройден успешно!" << endl;
	else
		cout << "Test_Check_index не пройден!" << endl;

	result = false;

	result = Test_Min_value();
	if (result) /**< перевірка тесту*/
		cout << "Test_Min_value пройден успешно!" << endl;
	else
		cout << "Test_Min_value не пройден!" << endl;

	return 0;
}

bool Test_Check_index()
{
	MyClass obj;

	int* array = new int[3];
	array[2] = 1;
	if (2 == obj.Check_index(array, 1))
	{
		delete[] array;
		return true;
	}
	else
	{
		delete[] array;
		return false;
	}
}

bool Test_Min_value()
{
	MyClass obj;
	int* array = new int[SIZE];
	array[0] = 2;
	array[1] = 5;
	array[2] = 14;
	array[3] = 1;
	array[4] = 0;
	int value = 15;
	if (0 == obj.Min_value(array, value))
	{
		delete[] array;
		return true;
	}
	else
	{
		delete[] array;
		return false;
	}
}


