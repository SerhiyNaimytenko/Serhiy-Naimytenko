#include "Header.h"
#include "Functions.h"

bool Test_Max_value()
{
	int size_s = 3;
	int size_str[3] = { 3,3,3 };
	int** array = new int* [3];
	for (int i = 0; i < 3; i++)
		array[i] = new int[3];
	int* max_value = new int[3];

	for(int i=0;i<3;i++)
		for (int j = 0; j < 3; j++)
		{
			if (i == 0)
			{
				array[i][j] = j;
				max_value[i] = j;
			}
			else if (i == 1)
			{
				array[i][j] = i + j;
				max_value[i] = i+j;
			}
			else
			{
				array[i][j] = 2 * j;
				max_value[i] = 2 * j;
			}
		}
	int* check = Max_value(array,size_s, size_str);
	
	
	int count_true_result = 0;
	for (int i = 0; i < size_s; i++)
		if (max_value[i] == check[i])
			count_true_result++;
	if (count_true_result == 3)
		return true;
	else
		return false;
}


bool Test_Return_elements()
{
	int size_s = 3;
	int size_str[3] = { 3,3,3 };
	int** array = new int* [3];
	for (int i = 0; i < 3; i++)
		array[i] = new int[3];
	int* max_value = new int[3];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (i == 0)
			{
				array[i][j] = j;
				max_value[i] = j;
			}
			else if (i == 1)
			{
				array[i][j] = i + j;
				max_value[i] = i + j;
			}
			else
			{
				array[i][j] = 2 * j;
				max_value[i] = 2 * j;
			}
		}
	int check;
	try {
		check = Return_elements(array, size_s, size_str, 2, 2);
	}
	catch (const char& ex)
	{
		cout << "ОШИБКА!!!" << ex << endl;
	}
	catch (...)
	{
		cout << "Хм, кажется непредвиденная ошибка в блоке try !!!" << endl;
		for (int i = 0; i < size_s; i++)
			delete[] array[i];
		delete[] array;
		delete[] size_str;
		return 102;
	}
	int count_true_result = 0;
		if (check == 4)
			count_true_result++;
	if (count_true_result == 1)
		return true;
	else
		return false;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	bool result;

	result = Test_Max_value();
	if (result) /**< перевірка тесту*/
		cout << "Test_Max_value пройден успешно!" << endl;
	else
		cout << "Test_Max_value не пройден!" << endl;

	result = Test_Return_elements();
	if (result) /**< перевірка тесту*/
		cout << "Test_Max_value пройден успешно!" << endl;
	else
		cout << "Test_Max_value не пройден!" << endl;
}

