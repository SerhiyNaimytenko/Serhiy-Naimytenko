
#include"First_Heir.h"


 

stringstream C_Expansion::getSsObj() const
{
    stringstream temp;
    temp << ID << " " << year_creating << " " << number_of_functions << " " << dynamically << " " << name << " " << function << " " << lang << " " << expansion_file;
    return temp;
}

string C_Expansion::getInfo() const
{
    stringstream temp;
    temp << setw(13) << ID << setw(10) << number_of_functions << setw(10) << year_creating << setw(13) << dynamically << setw(9) << name << setw(10) << function << setw(15) << lang << expansion_file;
    return temp.str();
}

C_Expansion& C_Expansion::operator= (C_Expansion& temp)
{
    if (this == &temp)
        return *this;
    C_Library::operator=(temp);
    string expansion = temp.expansion_file;
    return *this;
}

bool C_Expansion::operator==(const int ID) const
{
    return this->ID == ID;
}
 
void* C_Expansion::operator new(std::size_t size)
{
    std::cout << "Выделение памяти с помощью переопределенного оператора new\n";
    return ::operator new(size);
}

void C_Expansion::operator delete(void* ptr)
{
    std::cout << "Освобождения памяти с помощью оператора delete\n";
    ::operator delete(ptr);
}

void* C_Expansion::operator new[](std::size_t size)
{
    std::cout << "Выделение памяти с помощью переопределенного оператора new[]\n";
    return ::operator new[](size);
}

void C_Expansion::operator delete[](void* ptr)
{
    std::cout << "Освобождения памяти с помощью оператора delete[]\n";
    ::operator delete[](ptr);
}


C_Expansion::C_Expansion() : expansion_file("Default"), C_Library()/**< Реалізація конструктора по замовчуванням*/
{}
C_Expansion::C_Expansion(string expansion_file, string dynamically, string name, const int ID, const int year_creating, const int number_of_functions, string func, string lang) : expansion_file(expansion_file), C_Library(dynamically, name, ID, year_creating, number_of_functions, func, lang)/**< Реалізація конструктора з параметрами*/
{}
C_Expansion::C_Expansion(const C_Expansion& elem) : expansion_file(elem.expansion_file), C_Library(elem)
{}
C_Expansion::~C_Expansion()/**< Реалізація деструктора */
{}

