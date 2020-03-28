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

	string dynamically = "yes";
	string name = "Default", func = "func", lang = "lang";
	C_Library n_el;
	n_el.setFunction(func);
	n_el.setLanguage_programming(lang);
	C_Library new_el(dynamically, name, 20, 2001, 29, n_el);

	list.list[0] = new_el;

	C_Library return_lib = list.Index_return(20);

	int count = 0, value = 0;

	string y1 = return_lib.getDynamically();
	string y2 = "yes";
	if (y1 == y2)
		count++;
	y1 = return_lib.getName();
	y2 = "Default";
	if (y1 == y2)
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
	y1 = return_lib.What_function_is_in_this_library();
	y2 = "func";
	if (y1 == y2)
		count++;
	y1 = return_lib.Which_language_programming();
	y2 = "lang";
	if (y1 == y2)
		count++;
	if (count == 7)
		return true;
	else
		return false;

}

bool Test_Difference(C_List& list)
{
	string dynamically = "yes";
	string name = "Default", func = "Default", lang = "Default";
	C_Library n_el;
	n_el.setFunction(func);
	n_el.setLanguage_programming(lang);
	C_Library new_lib1(dynamically, name, 20, 1998, 40, n_el);

	list.list[1] = new_lib1;

	C_Library new_lib2;

	list.list[2] = new_lib2;

	float diff = list.Difference();

	if (diff == 1.5)
		return true;
	else
		return false;
}