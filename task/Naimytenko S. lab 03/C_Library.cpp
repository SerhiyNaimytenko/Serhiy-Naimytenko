#include "C_Library.h"

void C_Library::setDynamically(string dynamically)
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

string C_Library::getDynamically()const
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

C_Library:: C_Library() :dynamically("yes"), ID(10), year_creating(1999), number_of_functions(50)
{
}
C_Library::C_Library(string dynamically, const int ID, const int year_creating, const int number_of_functions) :dynamically(dynamically), ID(ID), year_creating(year_creating), number_of_functions(number_of_functions)
{ 
}
C_Library::C_Library(const C_Library& lib):dynamically(lib.dynamically),ID(lib.ID),year_creating(lib.year_creating),number_of_functions(lib.number_of_functions)
{ 
}
C_Library::~C_Library()
{
}
