#include "C_Library.h"
#include "C_List.h"

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

    printf("���������� ������ ��������\n");
    list_lib.list = list_lib.Add();

    list_lib.Output();

    printf("�������� ��������\n");
    list_lib.list = list_lib.Delete();

    list_lib.Output();

    printf("������� ������ �������� ������ �������� �� ������ �������� \n");
    scanf("%i", &a);

    list_lib.Index_output(a - 1);

    delete[]  list_lib.list;

    if (_CrtDumpMemoryLeaks())
        printf("\n\n���� ������ ������\n");
    else
        printf("\n��� ������ ������\n");

    return 0;
}
