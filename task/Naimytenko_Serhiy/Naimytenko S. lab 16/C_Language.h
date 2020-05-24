#pragma once 
#include"Header.h" 
class C_Language /**< Оголошення класу C_Language*/
{
private:
    string language;/**< поле класу C_Language - мова програмування*/
public:

    void setLanguage_programming(string);
    string Which_language_programming()const;

      

    friend ostream& operator<< (ostream& output, const C_Language& obj);

    C_Language(); /**< Оголошення конструктора по замовчуваннням*/

    C_Language(string);/**< Оголошення конструктора з параметрами*/

    C_Language(const C_Language&);/**< Оголошення конструктора копіювання*/

    ~C_Language();/**< Оголошення деструктора*/
};