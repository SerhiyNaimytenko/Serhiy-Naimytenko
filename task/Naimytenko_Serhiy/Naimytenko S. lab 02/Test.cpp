#include "C_Library.h"
#include "Test.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	bool result;


	result = Test_Add();

	if (result)
		printf("Test_Add ������� �������!\n");
	else
		printf("Test_Add �� �������!\n");

	result = Test_Delete();

	if (result)
		printf("Test_Delete ������� �������!\n");
	else
		printf("Test_Delete �� �������!\n");

	result = Test_Index_return();

	if (result)
		printf("Test_Index_return ������� �������!\n");
	else
		printf("Test_Index_return �� �������!\n");


	return 0;
}