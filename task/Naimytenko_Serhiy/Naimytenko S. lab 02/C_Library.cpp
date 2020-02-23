#include "C_Library.h"

void C_Library::setDynamically(const char* dynamically)
{
    this->dynamically = dynamically;
}

void C_Library::setID(const int ID)
{
    this->ID = ID;
}

void  C_Library::setYear_Creating(const int year_creating)
{
    this->year_creating = year_creating;
}

void  C_Library::setNumber_of_function(const int number_of_functions)
{
    this->number_of_functions = number_of_functions;
}

const char* C_Library::getDynamically()const
{
    return dynamically;
}

int  C_Library::getID()const
{
    return this->ID;
}

int  C_Library::getYear_Creating()const
{
    return this->year_creating;
}

int C_Library::getNumber_of_function()const
{
    return this->number_of_functions;
}
