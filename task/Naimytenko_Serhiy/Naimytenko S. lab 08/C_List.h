#pragma once
#include "C_Library.h"
/**
 * @file C_List.h
 * Оголошення класу C_List
 * @author Naimytenko Serhiy
 * @version 1.0
 * @date 2020.04.05
 */

class C_List /**< Оголошення класу списку*/
{
private:
    float size; /**< поле класу C_List - розмір масиву*/
public:
    Capabilities* list; /**< оголошення масиву класу Capabilities*/
    void setSize_array(const int size);
    int  getSize_array()const;
    int Read_file(string, string);/**< Оголошення методу зчитування інформації з файлу*/
    int Count_line(string);/**< Оголошення методу визначення розміру масиву*/
    void Distribution(string, string, int);/**< Оголошення методу створення обьекту із інформації зчитаної з файлу*/
    void Create();/**< Оголошення методу заповнення масиву данними*/
    void Add(Capabilities, const int);/**< Оголошення методу додавання нового елементу в масив*/
    void Delete(const int);/**< Оголошення методу видалення елементу з масиву*/
    stringstream Str_return(Capabilities)const;/**< Оголошення методу зчитування інформації з обьекту та перетворення її в потік*/
    void Str_output(stringstream&, int)const;/**< Оголошення методу виведення на екран одного єлементу*/
    Capabilities& Index_return(const int);/**< Оголошення методу що повертає обьект визначивши його по дентифікатору*/
    void Output()const;/**< Оголошення методу виведення всього масиву на екран*/
    void Sort(func);/**< Оголошення методу сортування масиву */
    float Difference();/**< Оголошення методу що визначає відношення кількості бібліотек що динамічно підключаються до загальної кількості елементів*/
    void Info_about_lib();/**< Оголошення методу виведення на екран інформації про бібліотеки*/
    int Write_file(string);/**< Оголошення методу зчитування в файл*/
    void Check();/**< Оголошення методу виведення на екран обьектів в ім'ї яких 2 слова*/
    Capabilities operator[] (int);
    
    friend ostream& operator<< (ostream&, const Capabilities&);
    friend ofstream& operator<< (ofstream&, const Capabilities);
    friend istream& operator>> (istream&, Capabilities);

    ~C_List();/**< Оголошення деструктора*/
};