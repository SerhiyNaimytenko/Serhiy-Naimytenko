/**
 * @file C_Library.h
 * ���������� ����� C_Library ����� �� ��������� ��������� ���������� - C_Function �� ����� ����������� C_Expansion �� Capabilities
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


class C_Library /**< ���������� �������� ����� C_Library*/
{
protected: 
    string dynamically; /**< ���� ����� C_Library - �� �������� �������*/
    string name; /**< ���� ����� C_Library - ��'� ��������*/
    int ID; /**< ���� ����� C_Library - ������������� ��������*/
    int year_creating; /**< ���� ����� C_Library - �� ���������*/
    int number_of_functions; /**< ���� ����� C_Library - ������� �������*/

    class C_Function  /**< ���������� ����� C_Function*/
    {
    private: 
        string function; /**< ���� ����� C_Function - ���� � ������� � ��� ��������*/
    public:
        void setFunction(string); 
        
        string What_function_is_in_this_library(); 

        C_Function();/**< ���������� ������������ �� ��������������*/

        C_Function(string);/**< ���������� ������������ � �����������*/

        C_Function(const C_Function&);/**< ���������� ������������ ���������*/

        ~C_Function();/**< ���������� �����������*/
    };

    C_Function function;/**< ���� ����� C_Library - ������ ����� C_Function*/
    C_Language lang;/**< ���� ����� C_Library - ������ ����� C_Language*/

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

    C_Library();/**< ���������� ������������ �� ��������������*/

    C_Library(string, string, const int, const int, const int, C_Function, C_Language);/**< ���������� ������������ � �����������*/

    C_Library(const C_Library&);/**< ���������� ������������ ���������*/

    ~C_Library();/**< ���������� �����������*/
};
 

class C_Expansion : public C_Library/**< ���������� ����� ���������� C_Expansion*/
{
private:
    string expansion_file;/**< ���� ����� C_Expansion - ���������� �����*/
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

    C_Expansion();/**< ���������� ������������ �� ��������������*/

    C_Expansion(string, string, string, const int, const int, const int, string, string);/**< ���������� ������������ � �����������*/

    C_Expansion(const C_Expansion&);/**< ���������� ������������ ���������*/

    ~C_Expansion();/**< ���������� �����������*/
};

class Capabilities : public C_Library/**< ���������� ����� ���������� Capabilities */
{
private:
    string capabilities;/**< ���� ����� Capabilities - ���� � ����������� �������*/

    C_Expansion obj;/**< ���� ����� Capabilities - ������ �����  C_Expansion*/

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

    Capabilities();/**< ���������� ������������ �� ��������������*/

    Capabilities(string, string, string, const int, const int, const int, string, string ,C_Expansion);/**< ���������� ������������ � �����������*/

    Capabilities(const Capabilities&);/**< ���������� ������������ ���������*/

    ~Capabilities();/**< ���������� �����������*/
};