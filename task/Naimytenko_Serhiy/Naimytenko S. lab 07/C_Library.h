/**
 * @file C_Library.h
 * Оголошення класу C_Library класу що зовбражуе відношення композиція - C_Function та класів спадкоемців C_Expansion та Capabilities
 * @author Naimytenko Serhiy
 * @version 1.0
 * @date 2020.04.05
 */

#pragma once
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#include <iostream>
#include <clocale>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <regex>
#include <Windows.h>
#include <stddef.h>
#include <cstddef> 
#include "C_Language.h" 

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::setw;
using std::setprecision;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::stringstream;
using std::getline;
using std::istringstream;
using std::regex;
using std::regex_match;
using std::regex_search;

typedef bool (func)(int, int);


class C_Library /**< Оголошення базового класу C_Library*/
{
protected: 
    string dynamically; /**< поле класу C_Library - чи динамічна функція*/
    string name; /**< поле класу C_Library - ім'я бібліоткеи*/
    int ID; /**< поле класу C_Library - идентифікатор бібліотеки*/
    int year_creating; /**< поле класу C_Library - рік створення*/
    int number_of_functions; /**< поле класу C_Library - кількість функцій*/

    class C_Function  /**< Оголошення класу C_Function*/
    {
    private: 
        string function; /**< поле класу C_Function - одна з функцій в цій бібліотеці*/
    public:
        void setFunction(string); 
        
        string What_function_is_in_this_library(); 

        C_Function();/**< Оголошення конструктора по замовчуваннням*/

        C_Function(string);/**< Оголошення конструктора з параметрами*/

        C_Function(const C_Function&);/**< Оголошення конструктора копіювання*/

        ~C_Function();/**< Оголошення деструктора*/
    };

    C_Function function;/**< поле класу C_Library - обьект класу C_Function*/
    C_Language lang;/**< поле класу C_Library - обьект класу C_Language*/

public:

    virtual void setDynamically(string) =0; 

    virtual void setName(string) = 0;

    virtual void setID(const int) = 0;

    virtual  void setYear_Creating(const int) = 0;

    virtual void setNumber_of_function(const int) = 0;

    virtual void setLanguage_programming(string) = 0;

    virtual void setFunction(string) = 0;

    virtual string getDynamically()const = 0;

    virtual string getName()const = 0;

    virtual int getID()const = 0;

    virtual int getYear_Creating()const = 0;

    virtual int getNumber_of_function()const = 0;

    virtual string getFunction() = 0;

    virtual string getLanguage_programming() = 0;

    C_Library();/**< Оголошення конструктора по замовчуваннням*/

    C_Library(string, string, const int, const int, const int, C_Function, C_Language);/**< Оголошення конструктора з параметрами*/

    C_Library(const C_Library&);/**< Оголошення конструктора копіювання*/

    ~C_Library();/**< Оголошення деструктора*/
};
 

class C_Expansion : public C_Library/**< Оголошення класа спадкоемця C_Expansion*/
{
private:
    string expansion_file;/**< поле класу C_Expansion - розширення файлу*/
public: 
    void setExpansion_file(string);

    string getExpansion_file();

    void setDynamically(string)override;

    void setName(string)override;

    void setID(const int) override;

    void setYear_Creating(const int)override;

    void setNumber_of_function(const int)override;

    void setLanguage_programming(string)override;

    void setFunction(string)override;

    string getDynamically()const override;

    string getName()const override;

    int getID()const override;

    int getYear_Creating()const override;

    int getNumber_of_function()const override;

    string getFunction()override;

    string getLanguage_programming()override;

    C_Expansion();/**< Оголошення конструктора по замовчуваннням*/

    C_Expansion(string, string, string, const int, const int, const int, string, string);/**< Оголошення конструктора з параметрами*/

    C_Expansion(const C_Expansion&);/**< Оголошення конструктора копіювання*/

    ~C_Expansion();/**< Оголошення деструктора*/
};

class Capabilities : public C_Library/**< Оголошення класа спадкоемця Capabilities */
{
private:
    string capabilities;/**< поле класу Capabilities - одна з можливостей функції*/

    C_Expansion obj;/**< поле класу Capabilities - обьект класу  C_Expansion*/

public: 
    C_Expansion getExpansion();

    void setExpansion(C_Expansion);

    string getExpansion_file();

    void setExpansion_file(string);

    void setCapabilities(string);

    string getCapabilities();

    void setDynamically(string)override;

    void setName(string)override;

    void setID(const int) override;

    void setYear_Creating(const int)override;

    void setNumber_of_function(const int)override;

    void setLanguage_programming(string)override;

    void setFunction(string)override;

    string getDynamically()const override;

    string getName()const override;

    int getID()const override;

    int getYear_Creating()const override;

    int getNumber_of_function()const override;

    string getFunction()override;

    string getLanguage_programming()override;

    Capabilities();/**< Оголошення конструктора по замовчуваннням*/

    Capabilities(string, string, string, const int, const int, const int, string, string ,C_Expansion);/**< Оголошення конструктора з параметрами*/

    Capabilities(const Capabilities&);/**< Оголошення конструктора копіювання*/

    ~Capabilities();/**< Оголошення деструктора*/
};