#include"First_Heir.h"
#include"Second_Heir.h"

int Interface(); /**< ���������� ������� �� ��������� ������ 䳿 �������� (�������� ���� ��� ���� ��� ��������� ������ ���'��)*/
 
int main()
{ 
    setlocale(LC_ALL, "Rus");

    int res = Interface(); 
    if (_CrtDumpMemoryLeaks())
        cout << endl << "���� ������ ������" << endl;
    else
        cout << endl << "��� ������ ������" << endl;
    return 0;
}
/**
 * ������� Interface
 *
 * �������� ���� ��:
 * <ul>
 * <li> ��������� ������� ����� �_List �� ����������� ��� ���� ������</li>
 * </ul>
 * @return ����� ������� ���� void
 */
int Interface()
{ 
    int size = 5; 
    Capabilities* pointer1 = new Capabilities();
    C_Expansion* pointer2 = new C_Expansion();
    Capabilities* array1 = new Capabilities[size];
    Capabilities* array2 = new Capabilities[size];  

    delete pointer1;
    delete pointer2;
    delete[] array1;
    delete[] array2; 
    return 0;
}