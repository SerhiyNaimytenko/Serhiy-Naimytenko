
#include"MyClass.h"
#include"Base_Class.h"

void arrayfloat()
{

	MyClass obj;

	float* array = obj.Create_arr();

	obj.Output_array(array);

	int min_value = 0;
	min_value = obj.Min_value(array, min_value);
	cout << "����������� ������� � ������ " << min_value << endl;

	float value;

	cout << "������� ������� ������ �������� �� ������ ������" << endl;
	int index;
	bool flag = true;
	while (flag)
	{
		try
		{
			cin >> value;

			index = obj.Check_index(array, value);
			cout << "����� �������� ������� �� ������ ������ " << index << endl;
			flag = false;
		}
		catch (const int value)
		{
			if (value == 404)
				flag = false;
			cout << "������ �������� ��� � ������, ��������� ��� ���" << endl;
		}
	}
	int res;
	cout << "������� �������� ����������, 2 - �� �������� � ��������, 1 - �� �������� � ��������" << endl;
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
	cout << "����������� ������� � ������ " << min_value << endl;

	Book value;

	cout << "������� ������� ������ �������� �� ������ ������" << endl;
	int index;
	bool flag = true;
	while (flag)
	{
		try
		{
			cin >> value;

			index = obj.Check_index(array, value);
			cout << "������ �������� ������� �� ������ ������ " << index << endl;
			flag = false;
		}
		catch (const int value)
		{
			if (value == 404)
				flag = false;
			cout << "������ �������� ��� � ������, ��������� ��� ���" << endl;
		}
	}
	int res;
	cout << "������� �������� ����������, 2 - �� �������� � ��������, 1 - �� �������� � ��������" << endl;
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
		cout << endl << "���� ������ ������" << endl;
	else
		cout << endl << "��� ������ ������" << endl;
	return 0;
}
