#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>

using namespace std;

class C_Library
{
private:    
    int average_number_of_uses;
    int year_creating;
    int number_of_functions;
public:
    void setAverage_number_of_uses(int average_number_of_uses)
    {
        this->average_number_of_uses = average_number_of_uses;
    }
    void setYear_Creating(int year_creating)
    {
        this->year_creating = year_creating;
    }
    void setNumber_of_function(int number_of_functions)
    {
        this->number_of_functions = number_of_functions;
    }
    int getAverage_number_of_uses()const
    {
        return this->average_number_of_uses;
    }
    int getYear_Creating()const
    {
        return this->year_creating;
    }
    int getNumber_of_function()const
    {
        return this->number_of_functions;
    }
 };

class C_List
{
private:
    int size;
public:

    C_Library* list;

    void setSize_array(int size)
    {
        this->size = size;
    }

    int getSize_array()const
    {
       return this->size;
    }

    C_Library* Create() // 1
    {
        int a = getSize_array();
        list = new C_Library[a];
        printf("Введите данные об библиотеках. Их всего %i \n",size);
        for (int i = 0; i < a; i++)
           list[i] = New_Library();
        return list;
    }

    C_Library New_Library() // 2
    {
        int a = 0;
        C_Library new_lib;
        printf("Введите данные о новой библиотеке\n");

        printf("среднее количество использований библиотеки\n");
        scanf("%i", &a);
        new_lib.setAverage_number_of_uses(a);

        printf("Год создания библиотеки\n");
        scanf("%i", &a);
        new_lib.setYear_Creating(a);

        printf("Количество функций в библиотеке\n");
        scanf("%i", &a);
        new_lib.setNumber_of_function(a);
        return new_lib;
         
    }

    C_Library* Add()  // 3
    {
        size++;
        C_Library* new_list = new C_Library[size];

        C_Library new_lib = New_Library();

        int order = 0;

        printf("Введите порядковый нормер который вы хотите присвоить новому елементу\n");

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


        return new_list;
    } 

    C_Library* Delete() // 4
    {
        size--;
        C_Library* new_list = new C_Library[size];

        int order = 0;

        printf("Введите номер елемента которого вы хотите удалить\n");

        scanf("%i", &order);

        printf("Элемент который вы удалили\n");

        Index_output(order-1);
        
        for (int i = 0; i < order - 1; i++)
            new_list[i] = list[i];
        for (int i = order - 1; i < size; i++)
            new_list[i] = list[i+1];
        return new_list;
    }

    void Index_output(int index)const // 5
    {
        int a;
        a = list[index].getAverage_number_of_uses();
        printf("%i \t", a);
        a = list[index].getYear_Creating();
        printf("%i \t", a);
        a = list[index].getNumber_of_function();
        printf("%i\n",a);
    }

    void Output()const // 6
    {
        printf("Вивод на экран\n");
        printf("Среднее количество использований\tГод создания\tКоличество функций в библиотеке\n");
        for (int i = 0; i < size; i++)
            Index_output(i);
    }
    
};

int main()
{
    setlocale(LC_ALL, "Rus");
    C_List list_lib;

    printf("Cоздание масива\n Введите размерность масва\n");
    int a;
    scanf("%i", &a);
    list_lib.setSize_array(a);

    list_lib.list  = list_lib.Create();

    list_lib.Output();

    printf("Добавления нового елемента\n");
    list_lib.list = list_lib.Add();

    list_lib.Output();

    printf("Удаления елемента\n");
    list_lib.list = list_lib.Delete();

    list_lib.Output();

    printf("Введите индекс елемента данные которого вы хотите получить\n");
    scanf("%i", &a);

    list_lib.Index_output(a-1);

    return 0;
}
