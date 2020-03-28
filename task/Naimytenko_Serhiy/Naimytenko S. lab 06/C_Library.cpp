#include "C_Library.h"

void C_Library::C_Function::setFunction(string name)
{
    this->function = name;
}

string C_Library::C_Function::What_function_is_in_this_library() //дилигирование
{
    return function;
}

void C_Library::setDynamically(string dynamically)
{
    this->dynamically = dynamically;
}

void C_Library::setName(string name)
{
    this->name = name;
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

void C_Library::setLanguage_programming(string lang)
{
    this->lang.setLanguage_programming(lang);
}

void C_Library::setFunction(string name)
{
    function.setFunction(name);
}

string C_Library::getDynamically()const
{
    return dynamically;
}

string C_Library::getName()const
{
    return name;
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

string C_Library::What_function_is_in_this_library() //дилигирование
{
    return function.What_function_is_in_this_library();
}

string C_Library::Which_language_programming()
{
    return lang.Which_language_programming();
}

C_Library::C_Function::C_Function() : function("Default")
{
}
C_Library::C_Function::C_Function(string function) : function(function)
{
}
C_Library::C_Function::C_Function(const C_Function& func) : function(func.function)
{
}
C_Library::C_Function::~C_Function()
{
}


C_Library::C_Library() :dynamically("yes"), name("Default"), ID(10), year_creating(1999), number_of_functions(50), function("default"), lang("default")
{
}
C_Library::C_Library(string dynamically, string name, const int ID, const int year_creating, const int number_of_functions, C_Library lib) : dynamically(dynamically), name(name), ID(ID), year_creating(year_creating), number_of_functions(number_of_functions), function(lib.function), lang(lib.lang)
{
}
C_Library::C_Library(const C_Library& lib) : dynamically(lib.dynamically), name(lib.name), ID(lib.ID), year_creating(lib.year_creating), number_of_functions(lib.number_of_functions), function(lib.function), lang(lib.lang)
{
}
C_Library::~C_Library()
{
}




void C_Expansion::setExpansion_file(string expansion)
{
    this->expansion_file = expansion;
}

string C_Expansion::getExpansion_file()
{
    return this->expansion_file;
}

C_Expansion::C_Expansion() : expansion_file("Default"), C_Library::C_Library()
{
}
C_Expansion::C_Expansion(string expansion_file, C_Library cop_el) : expansion_file(expansion_file), C_Library::C_Library(cop_el.getDynamically(), cop_el.getName(), cop_el.getID(), cop_el.getYear_Creating(), cop_el.getNumber_of_function(), cop_el)
{
}
C_Expansion::C_Expansion(const C_Expansion& elem) : expansion_file(elem.expansion_file), C_Library::C_Library(elem.getDynamically(), elem.getName(), elem.getID(), elem.getYear_Creating(), elem.getNumber_of_function(), elem)
{
}
C_Expansion::~C_Expansion()
{
}