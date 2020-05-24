#pragma once
#include"C_Library.h"

class C_Expansion final : public C_Library/**< Оголошення класа спадкоемця C_Expansion*/
{
private:
    string expansion_file;/**< поле класу C_Expansion - розширення файлу*/
public:
 
    string getInfo() const override final;

    stringstream getSsObj() const override final;

    C_Expansion& operator= (C_Expansion& temp);
     

    void* operator new(std::size_t size);
    void operator delete(void* ptr);

    void* operator new[](std::size_t size);
    void operator delete[](void* ptr);

    bool operator==(const int) const override final;

    C_Expansion();/**< Оголошення конструктора по замовчуваннням*/

    C_Expansion(string, string, string, const int, const int, const int, string, string);/**< Оголошення конструктора з параметрами*/

    C_Expansion(const C_Expansion&);/**< Оголошення конструктора копіювання*/

    ~C_Expansion();/**< Оголошення деструктора*/
};
