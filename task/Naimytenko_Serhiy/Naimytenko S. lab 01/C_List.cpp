#include "C_Library.h"
#include "C_List.h"
#include "Builder.h"

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
    printf("Введите данные об библиотеках. Их всего %i\n", size);
    for (int i = 0; i < a; i++)
        list[i] = New_Library();
    return list;
}


C_Library* C_List::Add(C_Library new_lib,int order)  // 3
{
    int size = getSize_array();
    size++;
    setSize_array(size);
    C_Library* new_list = new C_Library[size];

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

C_Library* C_List::Delete(int order) // 4
{
    int size = getSize_array();
    size--;
    setSize_array(size);
    C_Library* new_list = new C_Library[size];
    printf("Елемент который вы удалили\n");
    Index_output(list[order-1]);

    for (int i = 0; i < order - 1; i++)
        new_list[i] = list[i];
    for (int i = order - 1; i < size; i++)
        new_list[i] = list[i + 1];
    delete[] list;
    return new_list;
}

C_Library C_List::Index_return(const int index)
{
    return list[index];
}

void C_List::Index_output(const C_Library lib)const // 5
{
    int a;
    a = lib.getAverage_number_of_uses();
    printf("%-23i \t\t", a);
    a = lib.getYear_Creating();
    printf("%-4i \t\t", a);
    a = lib.getNumber_of_function();
    printf("%i\n", a);
}

void C_List::Output()const // 6
{
    printf("Вивод на экран\n");
    printf("Среднее количество использований\tГод создания\tКоличество функций в библиотеке\n");
    for (int i = 0; i < size; i++)
        Index_output(list[i]);
}