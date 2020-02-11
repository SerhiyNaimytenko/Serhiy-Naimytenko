#pragma once
#include "Header.h"

class C_List
{
private:
    int size;
public:

    C_Library* list;
    void setSize_array(int size);
    int getSize_array()const;
    C_Library* Create(); // 1
    C_Library New_Library(); // 2
    C_Library* Add();  // 3
    C_Library* Delete(); // 4
    void Index_output(int index)const; // 5
    void Output()const; // 6
};