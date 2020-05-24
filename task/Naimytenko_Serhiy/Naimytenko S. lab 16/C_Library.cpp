#include "C_Library.h"/**< ���������� ����� C_Library.h*/
 
string C_Library::C_Function::getFunction()const
{
    return function;
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

ostream& operator<< (ostream& output, const C_Library& obj)
{
    output << obj.getInfo();
    return output;
}
  
bool C_Library::operator==(const int ID) const
{
    return this->ID == ID;
}

void* C_Library::operator new(std::size_t size)
{
    std::cout << "��������� ������ � ������� ����������������� ��������� new\n";
    return ::operator new(size);
}

void C_Library::operator delete(void* ptr)
{
    std::cout << "������������ ������ � ������� ��������� delete\n";
    ::operator delete(ptr);
}

void* C_Library::operator new[](std::size_t size)
{
    std::cout << "��������� ������ � ������� ����������������� ��������� new[]\n";
    return ::operator new[](size);
}

void C_Library::operator delete[](void* ptr)
{
    std::cout << "������������ ������ � ������� ��������� delete[]\n";
    ::operator delete[](ptr);
}

C_Library& C_Library::operator= (C_Library& temp)
{
    if (this == &temp)
        return *this;
    int year_creating = temp.year_creating;
    int number_of_functions = temp.number_of_functions;
    int ID = temp.ID;
    string title = temp.name;
    C_Function function = temp.function;
    C_Language language = temp.lang;
    string dynamically = temp.dynamically; 
    return *this;
}
 
C_Library::C_Function::C_Function() : function("Default") /**< ��������� ������������ �� �������������*/
{
}
C_Library::C_Function::C_Function(string function) : function(function) /**< ��������� ������������ � �����������*/
{
}
C_Library::C_Function::C_Function(const C_Function& func) : function(func.function)/**< ��������� ������������ ���������*/
{
}
C_Library::C_Function::~C_Function()/**< ��������� ����������� */
{
}
 
C_Library::C_Library() :dynamically("yes"), name("Default"), ID(10), year_creating(1999), number_of_functions(50), function("default"), lang("default")
{
}
C_Library::C_Library(string dynamically, string name, const int ID, const int year_creating, const int number_of_functions, string func, string lang) : dynamically(dynamically), name(name), ID(ID), year_creating(year_creating), number_of_functions(number_of_functions), function(C_Function(func)), lang(C_Language(lang))/**< ��������� ������������ � �����������*/
{
}
C_Library::C_Library(const C_Library& lib) : dynamically(lib.dynamically), name(lib.name), ID(lib.ID), year_creating(lib.year_creating), number_of_functions(lib.number_of_functions), function(lib.function), lang(lib.lang)/**< ��������� ������������ ���������*/
{
}
C_Library::~C_Library()/**< ��������� ����������� */
{
}
 