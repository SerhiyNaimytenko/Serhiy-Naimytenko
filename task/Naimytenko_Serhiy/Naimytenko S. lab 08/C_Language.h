#pragma once
#include "C_Library.h" 
using std::string;
using std::istream;
using std::ostream;
class C_Language /**< ���������� ����� C_Language*/
{
private:
    string language;/**< ���� ����� C_Language - ���� �������������*/
public:

    void setLanguage_programming(string) ;
    string Which_language_programming()const;


    friend istream& operator>> (istream& input, C_Language& obj);

    friend ostream& operator<< (ostream& output, const C_Language& obj);

    C_Language(); /**< ���������� ������������ �� ��������������*/

    C_Language(string);/**< ���������� ������������ � �����������*/

    C_Language(const C_Language&);/**< ���������� ������������ ���������*/

    ~C_Language();/**< ���������� �����������*/
};