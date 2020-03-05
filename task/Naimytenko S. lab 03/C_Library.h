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


class C_Library
{
private:
    string dynamically;
    int ID;
    int year_creating;
    int number_of_functions;
public:
    void setDynamically(string);
    void setID(const int);
    void setYear_Creating(const int);
    void setNumber_of_function(const int);
    string getDynamically()const;
    int getID()const;
    int getYear_Creating()const;
    int getNumber_of_function()const;
    C_Library();
    C_Library(string,const int,const int,const int );
    C_Library(const C_Library& );
    ~C_Library();
};