#include "Header.h"
#include "Functions.h"



int* Size_array(string name_file,int &size_s)
{
	ifstream file(name_file);
	if (!file)
		throw exception("Внимание, файл не открылся!!!");
	string line;
	if (!getline(file, line))
		throw "Внимание, файл пустой";
	istringstream str(line);
	str >> size_s;
	int* size_str = new int[size_s];
	for (int i = 0; i < size_s; i++)
	{
		getline(file, line);
		istringstream str(line);
		str>>size_str[i];
	}
	file.close();
	return size_str;
}

int** Read_File(string file_name,int size_s,int* size_str,int** array)
{
	ifstream file(file_name);
	if (!file)
		throw 2.1;
	string line;
	int temp;
	getline(file, line);
	istringstream str(line);
	str >> temp;
	
	cout << "Происходит заполение масива данными" << endl;

	for (int i = 0; getline(file, line); i++)
	{
		istringstream str(line);
		str >> temp;
		for (int j = 0; j < size_str[i]; j++)
			str >> array[i][j];
	}
	file.close();

	return array;
}

void Output_array(int** array, int count_s, int *count_str)
{

	cout << "Происходит вывод на екран" << endl;
	for (int i = 0; i < count_s; i++)
	{
		for (int j = 0; j < count_str[i]; j++)
			cout << setw(3) << array[i][j];
		cout << endl;
	}

}

int* Max_value(int** array, int count_s, int* count_str)
{
	int* array_max_value = new int[count_s];

	cout << "Происходит поиск максимальных значений в масиве" << endl;

	for (int i = 0; i < count_s; i++)
	{
		array_max_value[i] = array[i][0];
		for (int j = 0; j < count_str[i]; j++)
			if (array_max_value[i] < array[i][j])
				array_max_value[i] = array[i][j];
	}

	return array_max_value;
}

int Return_elements(int** array, int count_s, int* count_str, int ind_i, int ind_j)
{
	if (ind_i > count_s || ind_i <= 0 || count_str[ind_i] < ind_j || ind_j <= 0)
		throw "Ошибка введения индексов";
	int return_el;

	cout << "Происходит поиск нужного елемента масива" << endl;

	for (int i = 0; i < count_s; i++)
	{
		for(int j=0;j<count_str[i];j++)
			if (i == ind_i && j == ind_j)
			{
				return_el = array[i][j];
				i = count_s;
				j = count_str[i];
			}
	}

	return return_el;
}

void Write_File(string file_name, int count_s, int* count_str,int** array)
{
	ofstream file(file_name);
	if (!file)
		throw exception("Внимание, файл не открылся!!!");
	cout << "Происходит заполение файла данными" << endl;
	for (int i = 0; i < count_s; i++)
	{
		for (int j = 0; j < count_str[i]; j++)
			file << array[i][j] << " ";
		file << endl;
	}

	file.close();

}