#pragma once
#include "C_Library.h"

class C_List
{
private:
    int size;
public:

    arr_Lib list;
    void setSize_array(const int size);
    int  getSize_array()const;
    int Read_file(string);
    void Count_line(string);
    C_Library Distribution(string);
    void Create();
    void Add(C_Library, const int);
    void Delete(const int);
    stringstream Str_return(C_Library&)const;
    void Str_output(stringstream&, int)const;
    C_Library& Index_return(const int index);
    void Output()const;
    void Sort(func);
    float Difference();
    int Write_file(string);
    void Check();
    ~C_List();
};