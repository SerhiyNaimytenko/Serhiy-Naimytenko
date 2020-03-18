#include "C_Library.h"
#include "C_List.h"
#include "Test.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	bool result;

	C_List list;

	list.list = new C_Library[3];

	list.setSize_array(3);

	result = Test_Add(list);

	if (result)
		cout << "Test_Add пройден успешно!" << endl;
	else
		cout << "Test_Add не пройден!" << endl;
	result = Test_Delete(list);

	if (result)
		cout << "Test_Delete пройден успешно!" << endl;
	else
		cout << "Test_Delete не пройден!" << endl;

	result = Test_Index_return(list);

	if (result)
		cout << "Test_Index_return пройден успешно!" << endl;
	else
		cout << "Test_Index_return не пройден!" << endl;

	result = Test_Difference(list);
	if (result)
		cout << "Test_Difference пройден успешно!" << endl;
	else
		cout << "Test_Difference не пройден!" << endl;



	return 0;

}