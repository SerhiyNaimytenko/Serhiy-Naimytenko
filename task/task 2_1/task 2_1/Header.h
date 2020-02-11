#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#include <iostream>
#include <clocale>



class C_Library
{
private:
    int average_number_of_uses;
    int year_creating;
    int number_of_functions;
public:
    void setAverage_number_of_uses(int);
    void setYear_Creating(int);
    void setNumber_of_function(int );
    int getAverage_number_of_uses()const;
    int getYear_Creating()const;
    int getNumber_of_function()const;

};

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
