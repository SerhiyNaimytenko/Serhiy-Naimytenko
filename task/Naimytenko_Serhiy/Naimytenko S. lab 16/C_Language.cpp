/**
 * @file C_Language.cpp
 * ��������� ����� C_Language
 * @author Naimytenko Serhiy
 * @version 1.0
 * @date 2020.04.05
 */
#include"C_Library.h"/**< ���������� ����� C_Library.h*/

void C_Language::setLanguage_programming(string name)
{
    language = name;
}

string C_Language::Which_language_programming()const
{
    return language;
}
 
ostream& operator<< (ostream& output, const C_Language& obj)
{
    output << obj.language;
    return output;
}


C_Language::C_Language() :language("Default")/**< ��������� ������������ �� �������������*/
{
}
C_Language::C_Language(string language) : language(language)/**< ��������� ������������ � �����������*/
{
}
C_Language::C_Language(const C_Language& lang) : language(lang.language)/**< ��������� ������������ ���������*/
{
}
C_Language::~C_Language()/**< ��������� ����������� */
{
}
