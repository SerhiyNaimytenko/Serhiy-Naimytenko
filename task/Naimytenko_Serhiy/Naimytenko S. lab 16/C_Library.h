/**
 * @file C_Library.h
 * Оголошення класу C_Library та класу що зовбражуе відношення композиція - C_Function та класів спадкоемців C_Expansion та Capabilities
 * @author Naimytenko Serhiy
 * @version 1.0
 * @date 2020.04.05
 */
#pragma once
#include"C_Language.h" 

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

        string getFunction()const;
         
        friend ostream& operator<< (ostream& output, const C_Function& obj)
        {
            output << obj.function;
            return output;
        }

         
        C_Function();/**< Оголошення конструктора по замовчуваннням*/

        C_Function(string);/**< Оголошення конструктора з параметрами*/

        C_Function(const C_Function&);/**< Оголошення конструктора копіювання*/
         
        ~C_Function();/**< Оголошення деструктора*/
    };

    C_Function function;/**< поле класу C_Library - обьект класу C_Function*/
    C_Language lang;/**< поле класу C_Library - обьект класу C_Language*/

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


    C_Library();/**< Оголошення конструктора по замовчуваннням*/

    C_Library(string, string, const int, const int, const int, string, string);/**< Оголошення конструктора з параметрами*/

    C_Library(const C_Library&);/**< Оголошення конструктора копіювання*/

    ~C_Library();/**< Оголошення деструктора*/
}; 