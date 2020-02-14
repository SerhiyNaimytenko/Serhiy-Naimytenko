#pragma once
#include "C_Library.h"

class C_List
{
private:
    int size;
public:

    C_Library* list;
    void setSize_array(const int size);
    int getSize_array()const;
    C_Library* Create(); 
    C_Library*Add(C_Library,int);  
    C_Library* Delete(const int); 
    void Index_output(const C_Library)const ;
    C_Library Index_return(const int index) ; 
    void Output()const; 
};