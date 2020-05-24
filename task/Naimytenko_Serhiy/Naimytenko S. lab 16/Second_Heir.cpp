
#include"Second_Heir.h"

 

stringstream Capabilities::getSsObj() const
{
    stringstream temp;
    temp << ID << " " << year_creating << " " << number_of_functions << " " << dynamically << " " << name << " " << function << " " << lang << " " << capabilities;
    return temp;
}

string Capabilities::getInfo() const
{
    stringstream temp;
    temp << setw(13) << ID << setw(10) << number_of_functions << setw(10) << year_creating << setw(13) << dynamically << setw(9) << name << setw(10) << function << setw(15) << lang << capabilities;
    return temp.str();
}

Capabilities& Capabilities::operator= (Capabilities& temp)
{
    if (this == &temp)
        return *this;
    C_Library::operator=(temp);
    string capabilities = temp.capabilities;
    return *this;
}

bool Capabilities::operator==(const int ID) const
{
    return this->ID == ID;
}
 

void* Capabilities::operator new(std::size_t size)
{
    std::cout << "Выделение памяти с помощью переопределенного оператора new\n";
    return ::operator new(size);
}

void Capabilities::operator delete(void* ptr)
{
    std::cout << "Освобождения памяти с помощью оператора delete\n";
    ::operator delete(ptr);
}

void* Capabilities::operator new[](std::size_t size)
{
    std::cout << "Выделение памяти с помощью переопределенного оператора new[]\n";
    return ::operator new[](size);
}

void Capabilities::operator delete[](void* ptr)
{
    std::cout << "Освобождения памяти с помощью оператора delete[]\n";
    ::operator delete[](ptr);
}


Capabilities::Capabilities() :capabilities("the library can do something"), C_Library()/**< Реалізація конструктора по замовчуванням*/
{}
Capabilities::Capabilities(string capabilities, string dynamically, string name, const int ID, const int year_creating, const int number_of_functions, string func, string lang ) : capabilities(capabilities), C_Library(dynamically, name, ID, year_creating, number_of_functions, func, lang)/**< Реалізація конструктора з параметрами*/
{}
Capabilities::Capabilities(const Capabilities& el) : capabilities(el.capabilities), C_Library(el)/**< Реалізація конструктора копіювання*/
{}
Capabilities::~Capabilities()/**< Реалізація деструктора */
{}
