#include "Builder.h"
#include "C_Library.h"

C_Library New_Library() // 2
{
    int a = 0;
    C_Library new_lib;
    printf("������� ������ � ����� ����������\n");

    printf("ID ����������\n");
    scanf("%i", &a);
    new_lib.setID(a);

    printf("��� �������� ����������\n");
    scanf("%i", &a);
    new_lib.setYear_Creating(a);

    printf("���������� ������� � ����������\n");
    scanf("%i", &a);
    new_lib.setNumber_of_function(a);
    return new_lib;

}