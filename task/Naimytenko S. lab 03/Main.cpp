#include "C_Library.h"
#include "C_List.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    C_List list_lib;

    cout << "C������� ������"<<endl<<"������� ����������� �����" << endl;
    int size;
    cin >> size;
    list_lib.setSize_array(size);
    list_lib.list = new C_Library[size];

    list_lib.Create();

    list_lib.Output();

    int order = 0;

    cout << "������� ���������� ����� ������� �� ������ ��������� ������ ��������" << endl;
    cin >> order;

    C_Library new_lib = C_Library();

    cout << "���������� ������ ��������" << endl;
    list_lib.Add(new_lib, order);

    list_lib.Output();

    cout << "�������� ��������" << endl;
   
    cout << "������� ����� �������� �������� �� ������ �������" << endl;
    cin >> order;

    cout << "������� ������� �� �������" << endl;
    list_lib.Delete(order);

    list_lib.Output();

    cout << "������� ������ �������� ������ �������� �� ������ �������� " << endl;
    cin >> order;


    C_Library index_lib = list_lib.Index_return(order);

    cout << "����� ���������� �������� �� �����" << endl;
    list_lib.Index_output(index_lib, 1);

    float diff = list_lib.Difference();

    delete[]  list_lib.list;

    if (_CrtDumpMemoryLeaks()) 
        cout <<endl<< "���� ������ ������" << endl;
    else
        cout << endl << "��� ������ ������" << endl;
    return 0;
}
