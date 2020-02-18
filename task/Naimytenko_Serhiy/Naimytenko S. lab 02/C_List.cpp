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
    printf("Происходит заполнеие масива данными\n");
    for (int i = 0; i < size; i++)
        list[i] = New_Lib(i+1);
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
    printf("Елемент который вы удалили\n");
    Index_output(list[order - 1],1);

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
    return list[index];
}

void C_List::Index_output(const C_Library lib,int i)const  // 5
{
    int a;
    printf("%-5i", i);
    a = lib.getAverage_number_of_uses();
    printf("%-23i \t\t", a);
    a = lib.getYear_Creating();
    printf("%-4i \t\t", a);
    a = lib.getNumber_of_function();
    printf("%i\t\t", a);
    const char* b;
    b = lib.getDynamically();
    printf("%s", b );
    printf("\n");
}

void C_List::Output()const // 6
{
    printf("Вивод на экран всех библиотек\n");
    printf("     Среднее количество использований\tГод создания\tКоличество функций в библиотеке\tДинамически подключается?\n");
    for (int i = 0; i < size; i++)
        Index_output(list[i],i+1);
}

float C_List::Difference()
{
    int count = 0;
    const char* y;
    for (int i = 0; i < size; i++)
    {
        y = list[i].getDynamically();
        if (strcmp("yes", y))
            count++;
    }
    float dif = (float) size/(float) count;
    printf("В %3.3f раз количество библиотек, которые динамически подключаются, меньше чем общее количество библиотек\n",dif);
    return dif;
}