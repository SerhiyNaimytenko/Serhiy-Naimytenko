#pragma once
#include "C_Library.h"
/**
 * @file C_List.h
 * ���������� ����� C_List
 * @author Naimytenko Serhiy
 * @version 1.0
 * @date 2020.04.05
 */

class C_List /**< ���������� ����� ������*/
{
private:
    float size; /**< ���� ����� C_List - ����� ������*/
public:
    Capabilities* list; /**< ���������� ������ ����� Capabilities*/
    void setSize_array(const int size);
    int  getSize_array()const;
    int Read_file(string, string);/**< ���������� ������ ���������� ���������� � �����*/
    int Count_line(string);/**< ���������� ������ ���������� ������ ������*/
    void Distribution(string, string, int);/**< ���������� ������ ��������� ������� �� ���������� ������� � �����*/
    void Create();/**< ���������� ������ ���������� ������ �������*/
    void Add(Capabilities, const int);/**< ���������� ������ ��������� ������ �������� � �����*/
    void Delete(const int);/**< ���������� ������ ��������� �������� � ������*/
    stringstream Str_return(Capabilities)const;/**< ���������� ������ ���������� ���������� � ������� �� ������������ �� � ����*/
    void Str_output(stringstream&, int)const;/**< ���������� ������ ��������� �� ����� ������ ��������*/
    Capabilities& Index_return(const int);/**< ���������� ������ �� ������� ������ ���������� ���� �� �������������*/
    void Output()const;/**< ���������� ������ ��������� ������ ������ �� �����*/
    void Sort(func);/**< ���������� ������ ���������� ������ */
    float Difference();/**< ���������� ������ �� ������� ��������� ������� ������� �� �������� ������������ �� �������� ������� ��������*/
    void Info_about_lib();/**< ���������� ������ ��������� �� ����� ���������� ��� ��������*/
    int Write_file(string);/**< ���������� ������ ���������� � ����*/
    void Check();/**< ���������� ������ ��������� �� ����� ������� � ��'� ���� 2 �����*/
    Capabilities operator[] (int);
    
    friend ostream& operator<< (ostream&, const Capabilities&);
    friend ofstream& operator<< (ofstream&, const Capabilities);
    friend istream& operator>> (istream&, Capabilities);

    ~C_List();/**< ���������� �����������*/
};