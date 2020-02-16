#include "C_Library.h"
#include "Test.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	bool result;


	result = Test_Add();

	if (result)
		printf("Test_Add пройден успешно!\n");
	else
		printf("Test_Add не пройден!\n");

	result = Test_Delete();

	if (result)
		printf("Test_Delete пройден успешно!\n");
	else
		printf("Test_Delete не пройден!\n");

	result = Test_Index_return();

	if (result)
		printf("Test_Index_return пройден успешно!\n");
	else
		printf("Test_Index_return не пройден!\n");


	return 0;
}