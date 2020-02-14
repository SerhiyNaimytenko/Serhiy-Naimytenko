#include "C_Library.h"
#include "C_List.h"
#include "Test.h"

bool Test_Add()
{
	C_List list;

	list.setSize_array(1);

	list.list = new C_Library[1];

	C_Library new_lib;
	
	list.Add(new_lib,2);

	int size = list.getSize_array();

	if (size == 2)
		return true;
	else 
		return false;

}

bool Test_Delete()
{
	C_List list;

	list.setSize_array(2);

	list.list = new C_Library[2];

	C_Library new_lib;
	list.Delete(2);

	int size = list.getSize_array();

	if (size == 1)
		return true;
	else 
		return false;

}

bool Test_Index_return()
{
	C_List list;

	list.setSize_array(2);

	list.list = new C_Library[2];

	list.list[0].setAverage_number_of_uses(1);
	list.list[0].setNumber_of_function(2);
	list.list[0].setYear_Creating(3);

	list.list[1].setAverage_number_of_uses(4);
	list.list[1].setNumber_of_function(5);
	list.list[1].setYear_Creating(6);
	
	C_Library return_lib  = list.Index_return(2-1);

	int count = 0 ,value;
	value = return_lib.getAverage_number_of_uses();
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
		return false;


}