
#include"MyClass.h"
#include"Base_Class.h"

void arrayfloat()
{

	MyClass obj;

	float* array = obj.Create_arr();

	obj.Output_array(array);

	int min_value = 0;
	min_value = obj.Min_value(array, min_value);
	cout << "Минимальный елемент в масиве " << min_value << endl;

	float value;

	cout << "Введите елемент индекс которого вы хотите узнать" << endl;
	int index;
	bool flag = true;
	while (flag)
	{
		try
		{
			cin >> value;

			index = obj.Check_index(array, value);
			cout << "Индех елемента который вы хотели узнать " << index << endl;
			flag = false;
		}
		catch (const int value)
		{
			if (value == 404)
				flag = false;
			cout << "Такого елемента нет в масиве, поробуйте еще раз" << endl;
		}
	}
	int res;
	cout << "Выберте вариацию сортировки, 2 - от меньшего к боьлшему, 1 - от большего к меньшему" << endl;
	cin >> res;

	array = obj.Sort(array, res);

	obj.Output_array(array);

	delete[] array;

}

Book* createArray()
{
	Book* array = new Book[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		if (i == 0)
		{
			array[i] = Book();
		}
		else if (i == 1)
		{
			array[i] = Book("voina_i_mir", "Kto_to", 18);
		}
		else if (i == 2)
		{
			array[i] = Book("Elisey", "Leonidovich", 45);
		}
		else if (i == 3)
		{
			array[i] = Book("Dmitry", "Aleksandrovich", 23);
		}
		else if (i == 4)
		{
			array[i] = Book("Oliver", "Lvovich", 32);
		}
	}
	return array;
}

void arrayclass()
{

	MyClass obj;

	Book* array = createArray();

	obj.Output_array(array);

	Book min_value;
	min_value = obj.Min_value(array, min_value);
	cout << "Минимальный елемент в масиве " << min_value << endl;

	Book value;

	cout << "Введите елемент индекс которого вы хотите узнать" << endl;
	int index;
	bool flag = true;
	while (flag)
	{
		try
		{
			cin >> value;

			index = obj.Check_index(array, value);
			cout << "Индекс елемента который вы хотели узнать " << index << endl;
			flag = false;
		}
		catch (const int value)
		{
			if (value == 404)
				flag = false;
			cout << "Такого елемента нет в масиве, поробуйте еще раз" << endl;
		}
	}
	int res;
	cout << "Выберте вариацию сортировки, 2 - от меньшего к боьлшему, 1 - от большего к меньшему" << endl;
	cin >> res;
	
	array = obj.Sort(array,res);

	obj.Output_array(array);

	delete[] array;

}

int main()
{
	setlocale(LC_ALL, "Rus");
	arrayfloat();
	arrayclass();
	if (_CrtDumpMemoryLeaks())
		cout << endl << "Есть утечка памяти" << endl;
	else
		cout << endl << "Нет утечки памяти" << endl;
	return 0;
}
