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
    int average_number_of_uses;
    int year_creating;
    int number_of_functions;
public:
    void setDynamically(const char*);
    void setAverage_number_of_uses(const int);
    void setYear_Creating(const int);
    void setNumber_of_function(const int);
    const char* getDynamically()const;
    int getAverage_number_of_uses()const;
    int getYear_Creating()const;
    int getNumber_of_function()const;
    C_Library()
    {
        static char dynamic[] = "yes";
        dynamically = dynamic;
        average_number_of_uses = 10;
        year_creating = 1999;
        number_of_functions = 50;
    }
    C_Library(char* dynamically, int average_number_of_uses,int year_creating,int number_of_functions)
    {

        this->dynamically = dynamically;
        this->average_number_of_uses = average_number_of_uses;
        this->year_creating = year_creating;
        this->number_of_functions = number_of_functions;
    }
    C_Library(const C_Library& lib)
    {
        this->dynamically = lib.dynamically;
        this->average_number_of_uses = lib.average_number_of_uses;
        this->year_creating = lib.year_creating;
        this->number_of_functions = lib.number_of_functions;
    }
    ~C_Library()
    {
    }
};