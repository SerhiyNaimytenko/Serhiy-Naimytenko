#pragma once
#include "C_Library.h"

class C_List
{
private:
    int size;
public:

    C_Library* list;
    void setSize_array(const int size);
    int  getSize_array()const;
    void Create();
    void Add(C_Library&, const int);
    void Delete(const int);
    void Index_output(const C_Library,int)const;
    C_Library Index_return(const int index);
    void Output()const;
    float Difference();
};