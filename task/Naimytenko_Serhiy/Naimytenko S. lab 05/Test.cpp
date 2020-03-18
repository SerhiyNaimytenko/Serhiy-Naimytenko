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
		cout << "Test_Add ������� �������!" << endl;
	else
		cout << "Test_Add �� �������!" << endl;
	result = Test_Delete(list);

	if (result)
		cout << "Test_Delete ������� �������!" << endl;
	else
		cout << "Test_Delete �� �������!" << endl;

	result = Test_Index_return(list);

	if (result)
		cout << "Test_Index_return ������� �������!" << endl;
	else
		cout << "Test_Index_return �� �������!" << endl;

	result = Test_Difference(list);
	if (result)
		cout << "Test_Difference ������� �������!" << endl;
	else
		cout << "Test_Difference �� �������!" << endl;



	return 0;

}