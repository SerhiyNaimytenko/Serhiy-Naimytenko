#pragma once
#include"C_Library.h"

class Capabilities final : public C_Library/**< ���������� ����� ���������� Capabilities */
{
private:

    string capabilities;/**< ���� ����� Capabilities - ���� � ����������� �������*/
      
public:  
     
    string getInfo() const override final;

    stringstream getSsObj() const override final;

    Capabilities& operator= (Capabilities& temp);
     

    bool operator==(const int) const override final;


    void* operator new(std::size_t size);
    void operator delete(void* ptr);

    void* operator new[](std::size_t size);
    void operator delete[](void* ptr);

    Capabilities();/**< ���������� ������������ �� ��������������*/
     
    Capabilities(string, string, string, const int, const int, const int, string, string);/**< ���������� ������������ � �����������*/

    Capabilities(const Capabilities&);/**< ���������� ������������ ���������*/

    ~Capabilities();/**< ���������� �����������*/
};