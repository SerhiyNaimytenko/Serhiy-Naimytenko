#include "C_Library.h"
#include "C_List.h"

int Menu();

int main()
{
    setlocale(LC_ALL, "Rus");

    int res = Menu();
    if (res == 0)
        return 0;
    if (_CrtDumpMemoryLeaks()) 
        cout <<endl<< "���� ������ ������" << endl;
    else
        cout << endl << "��� ������ ������" << endl;
    return 0;
}


int Menu()
{
    C_List list_lib;
    cout << "C������� ������" << endl;
    int command;
    cout << "������� ������� ���������� ������ 1- �� ����� 2-�������������" << endl;
    cin >> command;

    string file_read = "file_read.txt";
    string file_write = "file_write.txt";
    int res;

    if (command == 1)
    {
        list_lib.Count_line(file_read);
        int size = list_lib.getSize_array();
        list_lib.list = new C_Library[size];
        res = list_lib.Read_file(file_read);
        if (res == 1)
            return 1;
    }

    else
    {
        int size;
        cout << "������� ������ ������" << endl;
        cin >> size;
        list_lib.setSize_array(size);
        list_lib.list = new C_Library[size];
        list_lib.Create();
    }



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
    stringstream str = list_lib.Str_return(index_lib);
    list_lib.Str_output(str, 0);

    float diff = list_lib.Difference();

    res = list_lib.Write_file(file_write);
    if (res == 1)
        return 1;

    return 0;
}