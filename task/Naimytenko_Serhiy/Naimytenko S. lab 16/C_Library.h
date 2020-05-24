/**
 * @file C_Library.h
 * ���������� ����� C_Library �� ����� �� ��������� ��������� ���������� - C_Function �� ����� ����������� C_Expansion �� Capabilities
 * @author Naimytenko Serhiy
 * @version 1.0
 * @date 2020.04.05
 */
#pragma once
#include"C_Language.h" 

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

        string getFunction()const;
         
        friend ostream& operator<< (ostream& output, const C_Function& obj)
        {
            output << obj.function;
            return output;
        }

         
        C_Function();/**< ���������� ������������ �� ��������������*/

        C_Function(string);/**< ���������� ������������ � �����������*/

        C_Function(const C_Function&);/**< ���������� ������������ ���������*/
         
        ~C_Function();/**< ���������� �����������*/
    };

    C_Function function;/**< ���� ����� C_Library - ������ ����� C_Function*/
    C_Language lang;/**< ���� ����� C_Library - ������ ����� C_Language*/

public: 

    string getDynamically()const;

    string getName()const;

    int getID()const;  

    virtual string getInfo() const = 0;
     

    virtual stringstream getSsObj() const = 0;
      
    friend ostream& operator<< (ostream&, const C_Library&);
     

    virtual bool operator==(const int) const;

    C_Library& operator= (C_Library&); 
     
    void* operator new(std::size_t size);
    void operator delete(void* ptr);

    void* operator new[](std::size_t size);
    void operator delete[](void* ptr);


    C_Library();/**< ���������� ������������ �� ��������������*/

    C_Library(string, string, const int, const int, const int, string, string);/**< ���������� ������������ � �����������*/

    C_Library(const C_Library&);/**< ���������� ������������ ���������*/

    ~C_Library();/**< ���������� �����������*/
}; 