/**
 * @file C_Library.cpp
 * Реалізація класу C_Library
 * @author Naimytenko Serhiy
 * @version 1.0
 * @date 2020.04.05
 */
#include "C_Library.h"/**< підключення файлу C_Library.h*/

void C_Library::C_Function::setFunction(string name)
{
    this->function = name;
}

string C_Library::C_Function::What_function_is_in_this_library()  
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

string C_Library::getFunction()  
{
    return function.What_function_is_in_this_library();
}

string C_Library::getLanguage_programming()
{
    return lang.Which_language_programming();
}

C_Library::C_Function::C_Function() : function("Default") /**< Реалізація конструктора по замовчуванням*/
{
}
C_Library::C_Function::C_Function(string function) : function(function) /**< Реалізація конструктора з параметрами*/
{
} 
C_Library::C_Function::C_Function(const C_Function& func) : function(func.function)/**< Реалізація конструктора копіювання*/
{
}
C_Library::C_Function::~C_Function()/**< Реалізація деструктора */
{
}


C_Library::C_Library() :dynamically("yes"), name("Default"), ID(10), year_creating(1999), number_of_functions(50), function("default"), lang("default")
{
}
C_Library::C_Library(string dynamically, string name, const int ID, const int year_creating, const int number_of_functions, C_Function func, C_Language lang) : dynamically(dynamically), name(name), ID(ID), year_creating(year_creating), number_of_functions(number_of_functions), function(func), lang(lang)/**< Реалізація конструктора з параметрами*/
{
}
C_Library::C_Library(const C_Library& lib) : dynamically(lib.dynamically), name(lib.name), ID(lib.ID), year_creating(lib.year_creating), number_of_functions(lib.number_of_functions), function(lib.function), lang(lib.lang)/**< Реалізація конструктора копіювання*/
{
}
C_Library::~C_Library()/**< Реалізація деструктора */
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

void C_Expansion::setDynamically(string dynamically)
{
    this->dynamically = dynamically;
}

void C_Expansion::setName(string name)
{
    this->name=name;
}

void C_Expansion::setID(const int ID)
{
    this->ID = ID;
}

void C_Expansion::setYear_Creating(const int year_creating)
{
    this->year_creating = year_creating;
}

void C_Expansion::setNumber_of_function(const int number_of_functions)
{
    this->number_of_functions = number_of_functions;
}

void C_Expansion::setLanguage_programming(string lang)
{
    this->lang.setLanguage_programming(lang);
}

void C_Expansion::setFunction(string func)
{
    this->function.setFunction(func);
}

string C_Expansion::getDynamically()const 
{
    return this->dynamically;
}

string C_Expansion::getName()const
{
    return this->name;
}

int C_Expansion::getID()const
{
    return this->ID;
}

int C_Expansion::getYear_Creating()const
{
    return this->year_creating;
}

int C_Expansion::getNumber_of_function()const
{
    return this->number_of_functions;
}

string C_Expansion::getFunction()
{
    return this->function.What_function_is_in_this_library();
}

string C_Expansion::getLanguage_programming()
{
    return this->lang.Which_language_programming();
}

C_Expansion::C_Expansion() : expansion_file("Default"), C_Library()/**< Реалізація конструктора по замовчуванням*/
{}
C_Expansion::C_Expansion(string expansion_file, string dynamically, string name, const int ID, const int year_creating, const int number_of_functions, string func, string lang) : expansion_file(expansion_file), C_Library(dynamically, name, ID, year_creating, number_of_functions, func, lang)/**< Реалізація конструктора з параметрами*/
{}
C_Expansion::C_Expansion(const C_Expansion& elem) : expansion_file(elem.expansion_file),C_Library(elem.dynamically,elem.name,elem.ID,elem.year_creating,elem.number_of_functions,elem.function,elem.lang)/**< Реалізація конструктора копіювання*/
{}
C_Expansion::~C_Expansion()/**< Реалізація деструктора */
{}






C_Expansion Capabilities::getExpansion()
{
    return this->obj;
}

void Capabilities::setExpansion(C_Expansion obj)
{
    this->obj = obj;
}

string Capabilities::getExpansion_file()
{
    return obj.getExpansion_file();
}

void Capabilities::setExpansion_file(string expansion)
{
    obj.setExpansion_file(expansion);
}

void Capabilities::setCapabilities(string capabilities)
{
    this->capabilities = capabilities;
}

string Capabilities::getCapabilities()
{
    return this->capabilities;
}

void Capabilities::setDynamically(string dynamically)
{
    this->dynamically = dynamically;
}

void  Capabilities::setName(string name)
{
    this->name = name;
}

void  Capabilities::setID(const int ID)
{
    this->ID = ID;
}

void  Capabilities::setYear_Creating(const int year_creating)
{
    this->year_creating = year_creating;
}

void Capabilities::setNumber_of_function(const int number_of_function)
{
    this->number_of_functions = number_of_functions;
}

void  Capabilities::setLanguage_programming(string lang)
{
    this->lang.setLanguage_programming(lang);
}

void  Capabilities::setFunction(string func)
{
    this->function.setFunction(func);
}

string  Capabilities::getDynamically()const
{
    return this->dynamically;
}

string  Capabilities::getName()const
{
    return this->name;
}

int  Capabilities::getID()const
{
    return this->ID;
}

int  Capabilities::getYear_Creating()const
{
    return this->year_creating;
}

int  Capabilities::getNumber_of_function()const
{
    return this->number_of_functions;
}

string  Capabilities::getFunction()
{
    return this->function.What_function_is_in_this_library();
}

string Capabilities::getLanguage_programming()
{
    return this->lang.Which_language_programming();
}

Capabilities::Capabilities():capabilities("the library can do something"),C_Library(),obj()/**< Реалізація конструктора по замовчуванням*/
{}
Capabilities::Capabilities(string capabilities, string dynamically, string name, const int ID, const int year_creating, const int number_of_functions, string func, string lang,C_Expansion obj):capabilities(capabilities),C_Library(dynamically,name,ID,year_creating,number_of_functions, func,lang),obj(obj)/**< Реалізація конструктора з параметрами*/
{}
Capabilities::Capabilities(const Capabilities& el):capabilities(el.capabilities),C_Library(el.dynamically,el.name,el.ID,el.year_creating,el.number_of_functions,el.function,el.lang),obj(el.obj)/**< Реалізація конструктора копіювання*/
{}
Capabilities::~Capabilities()/**< Реалізація деструктора */
{}