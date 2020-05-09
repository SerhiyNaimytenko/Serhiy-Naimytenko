#include"MyClass.h"
#include"Inheritor_Classr.h"
void arrayint();
void arrayclass();
Book** createArray( );
int main()
{
	setlocale(LC_ALL, "Rus");
	arrayint();
	arrayclass(); 
	return 0;
}

void arrayint()
{ 
	int** array = new int*[SIZE];
	MyClass<int> obj(array);

	obj.Create_arr();

	obj.Output_array();

	obj.Min_value();


	int value;

	cout << "Введите елемент индекс которого вы хотите узнать" << endl;
	int index;
	bool flag = true;
	while (flag)
	{
		try
		{
			cin >> value;
			index = obj.Check_index(value);
			cout << "Индех елемента который вы хотели узнать " << index << endl;
			flag = false;
		}
		catch (const int)
		{
			cout << "Такого елемента нет в масиве, поробуйте еще раз" << endl;
		}
	}
	obj.Sort(A_more);

	obj.Output_array(); 
  
	
}

void arrayclass()
{
	Book object;
	Book** array = createArray();
	MyClass<Book> obj(array);
	 

	obj.Output_array();

	obj.Min_value();


	int value;

	cout << "Введите елемент индекс которого вы хотите узнать" << endl;
	int index;
	bool flag = true;
	while (flag)
	{
		try
		{
			cin >> object;

			index = obj.Check_index(object);
			cout << "Индех елемента который вы хотели узнать " << index << endl;
			flag = false;
		}
		catch (const int)
		{
			cout << "Такого елемента нет в масиве, поробуйте еще раз" << endl;
		}
	}
	obj.Sort(B_more);

	obj.Output_array();

	for (int i = 0; i < SIZE; i++)
	{
		delete array[i];
	} 

}
Book** createArray()
{
	Book** array = new Book * [SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		if (i == 0)
		{
			array[i] = new Book();
		}
		else if (i == 1)
		{
			array[i] = new Info("voina_i_mir", "Kto_to", 18, 100);
		}
		else if (i == 2)
		{
			array[i] = new Book("Elisey", "Leonidovich", 45);
		}
		else if (i == 3)
		{
			array[i] = new Info("Dmitry", "Aleksandrovich", 23, 4);
		}
		else if (i == 4)
		{
			array[i] = new Book("Oliver", "Lvovich", 32);
		}
	}
	return array;
}