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
		printf("Test_Add не пройден!\n");
		cout << "Test_Add не пройден!"<<endl;
	result = Test_Delete(list);

	if (result)

		printf("Test_Delete пройден успешно!\n");
	else
		printf("Test_Delete не пройден!\n");

	result = Test_Index_return(list);

	if (result)
		printf("Test_Index_return пройден успешно!\n");
	else
		printf("Test_Index_return не пройден!\n");

	result = Test_Difference(list);
	if (result)
		printf("Test_Difference пройден успешно!\n");
	else
		printf("Test_Difference не пройден!\n");



	return 0;

}