#pragma once
#include"C_Library.h"

class C_Heir_list
{
private:
	int size;
public:
	 C_Expansion* list;

	void setSize_array(const int size);

	int  getSize_array()const;

	int Read_file(string);

	void Output_index(C_Expansion)const;

	void Output()const;

	void Add(C_Expansion,int);

	void Delete(int);

};