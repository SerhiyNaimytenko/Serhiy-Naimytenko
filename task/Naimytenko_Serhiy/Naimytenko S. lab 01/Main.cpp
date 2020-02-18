#include "C_Library.h"
#include "C_List.h"
#include "Builder.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    C_List list_lib;

    printf("Cоздание масива\nВведите размерность масва\n");
    int size;
    scanf("%i", &size);
    list_lib.setSize_array(size);
    list_lib.list = new C_Library[size];

    list_lib.Create();

    list_lib.Output();

    int order = 0;

    printf("Введите порядковый номер который вы хотите присвоить новому елементу\n");

    scanf("%i", &order);
    C_Library new_lib = New_Library();
    printf("Добавления нового елемента\n");
    list_lib.Add(new_lib, order);

    list_lib.Output();

    printf("Удаления елемента\n");

    printf("Введите номер елемента которого вы хотите удалить\n");

    scanf("%i", &order);

    printf("Элемент который вы удалили\n");

    list_lib.Delete(order);

    list_lib.Output();

    printf("Введите индекс елемента данные которого вы хотите получить \n");
    scanf("%i", &order);

    C_Library index_lib = list_lib.Index_return(order);

    printf("Вывод полученого элемента на екран\n");

    list_lib.Index_output(index_lib,1);

    delete[]  list_lib.list;

    if (_CrtDumpMemoryLeaks())
        printf("\n\nЕсть утечка памяти\n");
    else
        printf("\nНет утечки памяти\n");

    return 0;
}
