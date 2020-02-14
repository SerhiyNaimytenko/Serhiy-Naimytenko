#include "C_Library.h"
#include "C_List.h"
#include "Builder.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    C_List list_lib;

    printf("C������� ������\n������� ����������� �����\n");
    int a;
    scanf("%i", &a);
    list_lib.setSize_array(a);

    list_lib.list = list_lib.Create();

    list_lib.Output();

    C_Library new_lib = New_Library();


    int order = 0;

    printf("������� ���������� ����� ������� �� ������ ��������� ������ ��������\n");

    scanf("%i", &order);

    printf("���������� ������ ��������\n");
    list_lib.list = list_lib.Add(new_lib,order);

    list_lib.Output();

    printf("�������� ��������\n");

    int order; 

    printf("������� ����� �������� �������� �� ������ �������\n");

    scanf("%i", &order);

    printf("������� ������� �� �������\n");

    list_lib.list = list_lib.Delete(order);

    list_lib.Output();

    printf("������� ������ �������� ������ �������� �� ������ �������� \n");
    scanf("%i", &a);

    C_Library index_lib = list_lib.Index_return(a - 1);
    
    printf("����� ���������� �������� �� �����\n");

    list_lib.Index_output(index_lib);

    delete[]  list_lib.list;

    if (_CrtDumpMemoryLeaks())
        printf("\n\n���� ������ ������\n");
    else
        printf("\n��� ������ ������\n");

    return 0;
}
