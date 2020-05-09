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
 

template <typename T>
bool A_more(T a, T b) { return a > b; }
template <typename T>
bool B_more(T a, T b) { return b > a; }

template <typename T>
class MyClass
{
protected:
	T** array;
public:
	typedef bool (func)(T, T);
	void Create_arr()
	{
		typedef bool (func)(T, T);
		cout << "Заполните масив данными. Пожалуйста, не повторяйтесь." << endl;
		T* arr = new T[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			cin >> arr[i];
		}
		for (size_t i = 0; i < SIZE; i++)
		{
			array[i] = &arr[i];
		}
		
	}
	 
	void Output_array()
	{
		cout << "Вывод масива на экран" << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cout << setw(3) << *array[i];
		}
		cout << endl;
	} 
	int Check_index(T value)
	{
		int index = SIZE + 1;
		for (int i = 0; i < SIZE; i++)
		{
			if (*array[i] == value)
			{
				index = i;
				i = SIZE;
			}
		}
		if (index == SIZE + 1)
			throw 1;
		return index;
	}
	
	void Sort (func condition)
	{
		auto temp = array[0];

		cout << "Проиходит сортировка масива" << endl;

		for (size_t i = 0; i < SIZE; i++)
		{
			for (size_t j = 0; j < SIZE; j++)
			{
				if (condition(*array[i], *array[j])) 
				{
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
			}
		}
	}
	T Min_value()
	{
		T min_value = *array[0];
		for (int i = 1; i < SIZE; i++)
		{
			if (*array[i] <  min_value)
				min_value = *array[i];
		}
		cout << "Минимальный елемент в масиве " << min_value << endl;
		return min_value;
	}
	

	MyClass(T** array)
	{
		this->array = array;
	}
	~MyClass()
	{ 
		delete[] array;
	}
};
 