#pragma once
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#include <iostream>
#include <clocale>
#include <ctime>
#include <cstring>
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


class C_Library  
{
protected:
    string dynamically;
    string name;
    int ID;
    int year_creating;
    int number_of_functions;

    class C_Function final
    {
    private:
        string function;
    public:
        void setFunction(string);
        string What_function_is_in_this_library();
        C_Function();

        C_Function(string);

        C_Function(const C_Function&);

        ~C_Function();
    };

    C_Function function;
    C_Language lang;

public:

    void setDynamically(string);

    void setName(string);

    void setID(const int);

    void setYear_Creating(const int);

    void setNumber_of_function(const int);

    void setLanguage_programming(string);

    void setFunction(string);

    string getDynamically()const;

    string getName()const;

    int getID()const;

    int getYear_Creating()const;

    int getNumber_of_function()const;

    string What_function_is_in_this_library();

    string Which_language_programming();

    C_Library();

    C_Library(string, string, const int, const int, const int, C_Library);

    C_Library(const C_Library&);

    ~C_Library();
};

typedef C_Library* arr_Lib;

class C_Expansion final : public C_Library
{
private:
    string expansion_file;
public:
    void setExpansion_file(string);

    string getExpansion_file();

    C_Expansion();

    C_Expansion(string, C_Library);

    C_Expansion(const C_Expansion&);

    ~C_Expansion();
};
