#include "C_Library.h"
#include "C_List.h"

void C_List::setSize_array(int size)
{
    this->size = size;
}

int C_List::getSize_array()const
{
    return this->size;
}

C_Library* C_List::Create() // 1
{
    int a = getSize_array();
    list = new C_Library[a];
    printf("������� ������ �� �����������. �� ����� %i\n", size);
    for (int i = 0; i < a; i++)
        list[i] = New_Library();
    return list;
}

C_Library C_List::New_Library() // 2
{
    int a = 0;
    C_Library new_lib;
    printf("������� ������ � ����� ����������\n");

    printf("������� ���������� ������������� ����������\n");
    scanf("%i", &a);
    new_lib.setAverage_number_of_uses(a);

    printf("��� �������� ����������\n");
    scanf("%i", &a);
    new_lib.setYear_Creating(a);

    printf("���������� ������� � ����������\n");
    scanf("%i", &a);
    new_lib.setNumber_of_function(a);
    return new_lib;

}

C_Library* C_List::Add()  // 3
{
    int size = getSize_array();
    size++;
    setSize_array(size);
    C_Library* new_list = new C_Library[size];

    C_Library new_lib = New_Library();

    int order = 0;

    printf("������� ���������� ����� ������� �� ������ ��������� ������ ��������\n");

    scanf("%i", &order);

    for (int i = 0, j = 0; i < size; i++)
    {
        if (i != order - 1)
        {
            new_list[i] = list[j];
            j++;
        }
        else
            new_list[i] = new_lib;
    }
    delete[] list;

    return new_list;
}

C_Library* C_List::Delete() // 4
{
    int size = getSize_array();
    size--;
    setSize_array(size);
    C_Library* new_list = new C_Library[size];

    int order = 0;

    printf("������� ����� �������� �������� �� ������ �������\n");

    scanf("%i", &order);

    printf("������� ������� �� �������\n");

    Index_output(order - 1);

    for (int i = 0; i < order - 1; i++)
        new_list[i] = list[i];
    for (int i = order - 1; i < size; i++)
        new_list[i] = list[i + 1];
    delete[] list;
    return new_list;
}

void C_List::Index_output(int index)const // 5
{
    int a;
    a = list[index].getAverage_number_of_uses();
    printf("%-2i%-23i \t\t", index + 1, a);
    a = list[index].getYear_Creating();
    printf("%-4i \t\t", a);
    a = list[index].getNumber_of_function();
    printf("%i\n", a);
}

void C_List::Output()const // 6
{
    printf("����� �� �����\n");
    printf("� ������� ���������� �������������\t��� ��������\t���������� ������� � ����������\n");
    for (int i = 0; i < size; i++)
        Index_output(i);
}