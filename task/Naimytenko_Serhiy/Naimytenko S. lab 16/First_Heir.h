#pragma once
#include"C_Library.h"

class C_Expansion final : public C_Library/**< ���������� ����� ���������� C_Expansion*/
{
private:
    string expansion_file;/**< ���� ����� C_Expansion - ���������� �����*/
public:
 
    string getInfo() const override final;

    stringstream getSsObj() const override final;

    C_Expansion& operator= (C_Expansion& temp);
     

    void* operator new(std::size_t size);
    void operator delete(void* ptr);

    void* operator new[](std::size_t size);
    void operator delete[](void* ptr);

    bool operator==(const int) const override final;

    C_Expansion();/**< ���������� ������������ �� ��������������*/

    C_Expansion(string, string, string, const int, const int, const int, string, string);/**< ���������� ������������ � �����������*/

    C_Expansion(const C_Expansion&);/**< ���������� ������������ ���������*/

    ~C_Expansion();/**< ���������� �����������*/
};
