#pragma once 
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using std::ostream;
using std::istream;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::exception;
using std::istringstream;
using std::stringstream;
#define SIZE   5
 
template <typename T1>
bool A_more(T1 a, T1 b) { return a > b; }
template <typename T1>
bool B_more(T1 a, T1 b) { return b > a; }

class MyClass
{
private:

public:

	float* Create_arr()
	{
		float* array = new float[SIZE];
		cout << "Заполните масив данными. Пожалуйста, не повторяйтесь." << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cin >> array[i];
		}

		int pr;
		int j = 0;
		do
		{
			pr = 0;

			for (int i = 1; i < SIZE; i++)
			{
				if (array[j] == array[i])
				{
					cout << "Обнаружен елемент который повторяется, введите пожалуйста новый" << endl;
					cin >> array[i];
					pr = 1;
				}

			}
			j++;
		} while (pr == 1);
		return array;
	}
	template <typename T1>
	void Output_array(T1 array)
	{
		cout << "Вывод масива на экран" << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cout << setw(3) << array[i];
		}
		cout << endl;
	}
	template <typename T1>
	int Check_index(T1* array, T1 value)
	{
		int index = SIZE + 1;
		for (int i = 0; i < SIZE; i++)
		{
			if (array[i] == value)
			{
				index = i;
				i = SIZE;
			}
		}
		if (index == SIZE + 1)
			throw 1;
		return index;
	}
	template <typename T1 >
	T1 Sort(T1 array, int choice)
	{
		auto temp = array[0];
		bool sort = false;
		cout << "Проиходит сортировка масива" << endl;

		for (size_t i = 0; i < SIZE; i++) /**< проганяємо весь масив за допомогою циклу*/
		{
			for (size_t j = 0; j < SIZE; j++)
			{
				if (choice == 1)
				{
					sort = A_more(array[i], array[j]);
				}
				else if (choice == 2)
				{
					sort = B_more(array[i], array[j]);
				}
				if (sort) /**< перевіряємо відповідність елементів, якщо вона вірна то міняємо елементі місцями*/
				{
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
			}
		}

		return array;
	}
	template <typename T1, typename T2>
	T2 Min_value(T1 array, T2 min_value)
	{
		min_value = array[0];
		for (int i = 1; i < SIZE; i++)
		{
			if (min_value > array[i])
				min_value = array[i];
		}
		return min_value;
	}

};
