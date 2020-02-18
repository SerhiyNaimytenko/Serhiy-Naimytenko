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
		printf("Test_Add ������� �������!\n");
	else
		printf("Test_Add �� �������!\n");

	result = Test_Delete(list);

	if (result)
		printf("Test_Delete ������� �������!\n");
	else
		printf("Test_Delete �� �������!\n");

	result = Test_Index_return(list);

	if (result)
		printf("Test_Index_return ������� �������!\n");
	else
		printf("Test_Index_return �� �������!\n");


	return 0;
}