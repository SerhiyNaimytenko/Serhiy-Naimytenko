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
    C_Library()
    {
        static const char dynamic[] = "yes";
        dynamically = dynamic;
        ID = 10;
        year_creating = 1999;
        number_of_functions = 50;
    }
    C_Library(const char* dynamically,const int ID,const int year_creating,const int number_of_functions)
    {

        this->dynamically = dynamically;
        this->ID = ID;
        this->year_creating = year_creating;
        this->number_of_functions = number_of_functions;
    }
    C_Library(const C_Library& lib)
    {
        this->dynamically = lib.dynamically;
        this->ID = lib.ID;
        this->year_creating = lib.year_creating;
        this->number_of_functions = lib.number_of_functions;
    }
    ~C_Library()
    {
    }
};