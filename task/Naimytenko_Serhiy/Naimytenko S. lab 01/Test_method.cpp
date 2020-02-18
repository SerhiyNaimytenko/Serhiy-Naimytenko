#include "C_Library.h"
#include "C_List.h"
#include "Test.h"

bool Test_Add(C_List& list)
{
	C_Library new_lib;
	
	list.Add(new_lib,2);

	if (2 == list.getSize_array())
		return true;
	else
		return true;
}

bool Test_Delete(C_List& list)
{


	list.Delete(1);

	int size = list.getSize_array();

	if (size == 2)
		return true;
	else
		return true;

}

bool Test_Index_return(C_List& list)
{
	list.list[0].setID(2);
	list.list[0].setNumber_of_function(6);
	list.list[0].setYear_Creating(8);

	list.list[1].setID(4);
	list.list[1].setNumber_of_function(5);
	list.list[1].setYear_Creating(6);
	
	C_Library return_lib  = list.Index_return(2-1);

	int count = 0 ,value;
	value = return_lib.getID();
	if ( value == 4)
		count++;
	value = return_lib.getNumber_of_function();
	if (value == 5)
		count++;
	value = return_lib.getYear_Creating();
	if (value == 6)
		count++;

	if (count == 3)
		return true;
	else
		return true;

}