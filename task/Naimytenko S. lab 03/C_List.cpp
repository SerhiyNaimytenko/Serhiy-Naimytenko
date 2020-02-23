#include "C_Library.h"
#include "C_List.h"
#include "Builder.h"

void C_List::setSize_array(const int size)
{
    this->size = size;
}

int C_List::getSize_array()const
{
    return this->size;
}

void C_List::Create() // 1
{
    cout<<"���������� ��������� ������ �������" <<endl;
    for (int i = 0; i < size; i++)
        list[i] = New_Lib(i + 1);
}

void C_List::Add(C_Library& lib, const int order)  // 3
{
    size++;
    C_Library* new_list = new C_Library[size];

    for (int i = 0, j = 0; i < size; i++)
    {
        if (i != order - 1)
        {
            new_list[i] = list[j];
            j++;
        }
        else
            new_list[i] = lib;
    }
    delete[] list;
    list = new C_Library[size];
    for (int i = 0; i < size; i++)
        list[i] = new_list[i];
    delete[] new_list;
}

void C_List::Delete(const int order) // 4
{
    size--;
    C_Library* new_list = new C_Library[size];
   
    cout << "������� ������� �� �������" << endl;
    Index_output(list[order - 1], 1);

    for (int i = 0; i < order - 1; i++)
        new_list[i] = list[i];
    for (int i = order - 1; i < size; i++)
        new_list[i] = list[i + 1];
    delete[] list;
    list = new C_Library[size];
    for (int i = 0; i < size; i++)
        list[i] = new_list[i];
    delete[] new_list;

}

C_Library C_List::Index_return(const int index)
{
    int a;
    for (int i = 0; i < size; i++)
    {
        a = list[i].getID();
        if (a == index)
        {
            a = i;
            i = size;
        }
    }
    return list[a];
}


void C_List::Index_output(const C_Library lib, int i)const  // 5
{
    int a;
    cout << i;
    a = lib.getID();
    cout << a;
    a = lib.getYear_Creating();
    cout << a;
    a = lib.getNumber_of_function();
    cout << a;
    string b;
    b = lib.getDynamically();
    cout << b << endl;
}

void C_List::Output()const // 6
{
    cout << "����� �� ����� ���� ���������"<<endl;
    cout << setw (5)<<"ID ����������\t��� ��������\t���������� ������� � ����������\t����������� ������������?" << endl;
    for (int i = 0; i < size; i++)
        Index_output(list[i], i + 1);
}

float C_List::Difference()
{
    int count = 0;
    string y;
    for (int i = 0; i < size; i++)
    {
        y = list[i].getDynamically();
        if (strcmp("yes", y))
            count++;
    }
    float dif = (float)size / (float)count;
    cout << "� " << dif << " ��� ���������� ���������, ������� ����������� ������������, ������ ��� ����� ���������� ���������" << endl;
    return dif;
}