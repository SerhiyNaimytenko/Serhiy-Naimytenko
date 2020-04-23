#pragma once
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#include <iostream>
#include <clocale>
#include <ctime>
#include <iomanip> 
const int SIZE = 5;

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::setw;
using std::exception;

typedef bool (func)(int, int);

bool A_more(int a, int b) { return a > b; }
bool B_more(int a, int b) { return b > a; }

class MyClass
{
private:

public:
#include"MyClass.h"

	int* Create_arr()
	{
		int* array = new int[SIZE];
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
	template <typename T1, typename T2 >
	int Check_index(T1 array, T2 value)
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
	T1 Sort(T1 array, func condition)
	{
		auto temp = array[0];

		cout << "Проиходит сортировка масива" << endl;
	
		for (size_t i = 0; i < SIZE; i++) /**< проганяємо весь масив за допомогою циклу*/
		{
			for (size_t j = 0; j < SIZE; j++)
			{
				if (condition(array[i],array[j])) /**< перевіряємо відповідність елементів, якщо вона вірна то міняємо елементі місцями*/
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