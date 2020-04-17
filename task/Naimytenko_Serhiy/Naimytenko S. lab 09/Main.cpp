#include "Header.h"
#include "Functions.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	string name_file,write_file;
	int size_s = 0, *size_str=0;
	int** array=0; 

	bool Flag = true;
	while (Flag)
	{
		try
		{
			cout << "Введите название файла, с которого нужно считать данные" << endl;
			cin >> name_file;
			if (name_file == "\exit")
				throw name_file;
			size_str = Size_array(name_file,size_s);
			array = new int* [size_s];
			for (int i = 0; i < size_s; i++)
				array[i] = new int[size_str[i]];
			array = Read_File(name_file, size_s, size_str,array);
			if (size_s == 0)
				throw size_s;

			Flag = false;
		}
		catch (const exception & ex)
		{
			cout << ex.what() << endl << "Возможно вы ввели не верное название файла" << endl;
		}
		catch (const float ex)
		{
			cout  << endl << "Что пошло не так, кажется файл стал не доступен!!! Завершение роботы." << endl;
			return 1;
		}
		catch (const char* ex)
		{
			cout << "ОШИБКА!!!" << endl << ex << endl;
			Flag = false;
		}
		catch (int ex)
		{
			cout << "Переменные size_s,size_t oказались не заполнеными!!!" << endl;
			return 1;
		}
		catch (string ex)
		{
			cout << "Введена команда завершение работы програмы!!!" << endl << ex << endl;
			return 0;
		}
		catch (...)
		{
			cout << "Хм, кажется непредвиденная ошибка в 1м блоке try !!!" << endl;
			return 102;
		}
	}
	

	Output_array(array, size_s, size_str);
	 
	int* array_max_value = Max_value(array, size_s, size_str);
	cout << "Вывод максимальных значений каждого масива" << endl;
	for (int i = 0; i < size_s; i++)
		cout << setw(3) << array_max_value[i];

	Flag = true;
	while (Flag)
	{
		try
		{
			int i, j;
			cout<< "Введите индексы елемента (их 2) данные которого хотите получить" << endl;
			cin >> i >> j;
			int el = Return_elements(array, size_s, size_str, i-1, j-1);
			cout << "Елемент который вы искали : " << el << endl;
			Flag = false;
		
		}
		catch (const char& ex)
		{
			cout << "ОШИБКА!!!"<< ex << endl;
		}
		catch (...)
		{
			cout << "Хм, кажется непредвиденная ошибка в 2м блоке try !!!" << endl;
			for (int i = 0; i < size_s; i++)
				delete[] array[i];
			delete[] array;
			delete[] size_str;
			return 102;
		}
	}
	Flag = true;
	while (Flag)
	{
		try 
		{
			cout << "Введите название файла, с которого нужно считать данные" << endl;
			cin >> write_file;
			if (write_file == "\exit")
				throw write_file;
			Write_File(write_file, size_s, size_str,array);
			Flag = false;
		}
		catch (const exception & ex)
		{
			cout << ex.what() << endl << "Возможно вы ошиблись с названием файла, попробуйте еще раз" << endl;
		}
		catch (string ex)
		{
			cout << "Введена команда завершение работы програмы!!!" << endl << ex << endl;
			for (int i = 0; i < size_s; i++)
				delete[] array[i];
			delete[] array;
			delete[] size_str;
			return 0;
		}
		catch (...)
		{
			cout << "Хм, кажется непредвиденная ошибка в 3м блоке try !!!" << endl;
			for (int i = 0; i < size_s; i++)
				delete[] array[i];
			delete[] array;
			delete[] size_str;
			return 103;
		}

	}
	for (int i = 0; i < size_s; i++)
		delete[] array[i];
	delete[] array;
	delete[] size_str;

	return 0;
}