#include "C_Library.h"
#include "C_List.h"
#include "Test.h"

bool Test_Add(C_List& list)
{
	C_Library new_lib;

	list.Add(new_lib, 4);

	int size = list.getSize_array();

	if (size == 4)
		return true;
	else
		return false;
}

bool Test_Delete(C_List& list)
{

	list.Delete(1);

	int size = list.getSize_array();

	if (size == 3)
		return true;
	else
		return false;

}

bool Test_Index_return(C_List& list)
{


	static const char diff[] = "yes";
	C_Library new_el(diff, 20, 2001, 29);

	list.list[0] = new_el;

	C_Library return_lib = list.Index_return(20);

	int count = 1, value = 0;

	const char* y = return_lib.getDynamically();
	if (strcmp("yes", y))
		count++;
	value = return_lib.getID();
	if (value == 20)
		count++;
	value = return_lib.getYear_Creating();
	if (value == 2001)
		count++;
	value = return_lib.getNumber_of_function();
	if (value == 29)
		count++;
	if (count == 4)
		return true;
	else
		return false;

}

bool Test_Difference(C_List& list)
{

	static char dynamically[] = "no";
	C_Library new_lib1(dynamically, 20, 1998, 40);

	list.list[1] = new_lib1;

	C_Library new_lib2(new_lib1);

	list.list[2] = new_lib2;

	float diff = list.Difference();

	if (diff == 1.5)
		return true;
	else
		return false;
}