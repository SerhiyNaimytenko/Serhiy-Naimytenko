#include "C_Library.h"
#include "C_List.h"
#include "Builder.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    C_List list_lib;

    printf("C������� ������\n������� ����������� �����\n");
    int size;
    scanf("%i", &size);
    list_lib.setSize_array(size);
    list_lib.list = new C_Library[size];

    list_lib.Create();

    list_lib.Output();

    int order = 0;

    printf("������� ���������� ����� ������� �� ������ ��������� ������ ��������\n");

    scanf("%i", &order);
    C_Library new_lib = New_Library();
    printf("���������� ������ ��������\n");
    list_lib.Add(new_lib, order);

    list_lib.Output();

    printf("�������� ��������\n");

    printf("������� ����� �������� �������� �� ������ �������\n");

    scanf("%i", &order);

    printf("������� ������� �� �������\n");

    list_lib.Delete(order);

    list_lib.Output();

    printf("������� ������ �������� ������ �������� �� ������ �������� \n");
    scanf("%i", &order);

    C_Library index_lib = list_lib.Index_return(order);

    printf("����� ���������� �������� �� �����\n");

    list_lib.Index_output(index_lib,1);

    delete[]  list_lib.list;

    if (_CrtDumpMemoryLeaks())
        printf("\n\n���� ������ ������\n");
    else
        printf("\n��� ������ ������\n");

    return 0;
}
