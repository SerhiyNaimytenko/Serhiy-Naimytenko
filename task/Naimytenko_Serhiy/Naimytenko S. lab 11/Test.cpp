

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

	int** array = new int*[SIZE];
	int nums[SIZE] = { 2, 3, 1, -4, 0 };
	for (size_t i = 0; i < SIZE; i++)
	{
		array[i] = &nums[i]; 
	}

	MyClass<int> obj(array);

	if (2 == obj.Check_index(1))
	{ 
		return true;
	}
	else
	{ 
		return false;
	}
}

bool Test_Min_value()
{	
	int** array = new int* [SIZE];
	int nums[SIZE] = { 1, 4, 13, 23, 0 };
	for (size_t i = 0; i < SIZE; i++)
	{
		array[i] = &nums[i];
	}

	MyClass<int> obj(array);
	

	int value = 15;
	if (0 == obj.Min_value())
	{ 
		return true;
	}
	else
	{ 
		return false;
	}
}


