#include "C_Library.h"


void C_Library::setAverage_number_of_uses(const int average_number_of_uses)
{
    this->average_number_of_uses = average_number_of_uses;
}
void  C_Library::setYear_Creating(const int year_creating)
{
    this->year_creating = year_creating;
}
void  C_Library::setNumber_of_function(const int number_of_functions)
{
    this->number_of_functions = number_of_functions;
}
int  C_Library::getAverage_number_of_uses()const
{
    return this->average_number_of_uses;
}
int  C_Library::getYear_Creating()const
{
    return this->year_creating;
}
int C_Library::getNumber_of_function()const
{
    return this->number_of_functions;
}