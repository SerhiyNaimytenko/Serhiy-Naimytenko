#include"MyClass.h"

int main()
{
	setlocale(LC_ALL, "Rus");

	MyClass obj;
	
	int* array = obj.Create_arr();

	obj.Output_array(array);

	int min_value =0;
	min_value = obj.Min_value(array, min_value);
	cout << "����������� ������� � ������ " << min_value << endl;

	int value;

	cout << "������� ������� ������ �������� �� ������ ������"<< endl;
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
		catch (const int)
		{
			cout <<   "������ �������� ��� � ������, ��������� ��� ���" << endl;
		}
	}
	array = obj.Sort(array,A_more);

	obj.Output_array(array);

	delete[] array;

	return 0;
}
