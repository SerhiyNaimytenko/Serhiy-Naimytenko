#pragma once
#include "C_Library.h"
#include"C_Heir_list.h"

class C_List
{
private:
    int size;
public:

    arr_Lib list;
    C_Heir_list obj;
    void setSize_array(const int size);
    int  getSize_array()const;
    int Read_file(string, string);//
    void Count_line(string);//
    C_Library Distribution(string, string);//
    C_Expansion* Create();//
    void Add(C_Library, const int);//
    void Delete(const int, C_Expansion*);//
    stringstream Str_return(C_Library&)const;//
    void Str_output(stringstream&, int)const;//
    C_Library& Index_return(const int index);//
    void Output(C_Expansion*)const;//
    void Sort(func,C_Expansion*&);
    float Difference();
    void If_lib_connected(C_Expansion*);
    int Write_file(string,C_Expansion*);
    void Check(C_Expansion*);
    ~C_List();
};