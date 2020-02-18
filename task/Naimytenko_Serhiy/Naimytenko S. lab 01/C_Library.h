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
    int ID;
    int year_creating;
    int number_of_functions;
public:
    void setID(const int);
    void setYear_Creating(const int);
    void setNumber_of_function(const int);
    int getID()const;
    int getYear_Creating()const;
    int getNumber_of_function()const;

};