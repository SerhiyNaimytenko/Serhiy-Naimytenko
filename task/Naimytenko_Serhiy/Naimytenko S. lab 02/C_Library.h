#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#include <iostream>
#include <clocale>
#include <ctime>

class C_Library
{
private:
    const char* dynamically;
    int ID;
    int year_creating;
    int number_of_functions;
public:
    void setDynamically(const char*);
    void setID(const int);
    void setYear_Creating(const int);
    void setNumber_of_function(const int);
    const char* getDynamically()const;
    int getID()const;
    int getYear_Creating()const;
    int getNumber_of_function()const;
    C_Library();
    C_Library(char*, const int, const int, const int);
    C_Library(const C_Library&);
    ~C_Library();
};