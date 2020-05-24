#pragma once
#include"C_Library.h"

class Capabilities final : public C_Library/**< Оголошення класа спадкоемця Capabilities */
{
private:

    string capabilities;/**< поле класу Capabilities - одна з можливостей функції*/
      
public:  
     
    string getInfo() const override final;

    stringstream getSsObj() const override final;

    Capabilities& operator= (Capabilities& temp);
     

    bool operator==(const int) const override final;


    void* operator new(std::size_t size);
    void operator delete(void* ptr);

    void* operator new[](std::size_t size);
    void operator delete[](void* ptr);

    Capabilities();/**< Оголошення конструктора по замовчуваннням*/
     
    Capabilities(string, string, string, const int, const int, const int, string, string);/**< Оголошення конструктора з параметрами*/

    Capabilities(const Capabilities&);/**< Оголошення конструктора копіювання*/

    ~Capabilities();/**< Оголошення деструктора*/
};