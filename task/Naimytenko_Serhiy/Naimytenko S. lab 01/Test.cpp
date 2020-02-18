#include "C_Library.h"
#include "C_List.h"
#include "Test.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	bool result;

	C_List list;
	
	list.list = new C_Library[2];
	list.setSize_array(2);

	result = Test_Add(list);

	if (result)
		printf("Test_Add пройден успешно!\n");
	else
		printf("Test_Add не пройден!\n");

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


	return 0;
}