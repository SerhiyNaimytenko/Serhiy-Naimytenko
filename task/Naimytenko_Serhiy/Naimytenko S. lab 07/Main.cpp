/**
 * @mainpage
 * <b> ����������� ������ � 7. ���������� </b>
 * <br/><b>���� ������:</b>: �������� ������ ��� ��������� ��� � ����������; ��������� ������������� ������� ������ �� ��������.  <br/>
 * <b>������������ ��������:</b>
 * ������������ ��������� ����������� ������ ������:
 *  - ��������� �� ������ �����-��������� �� �������� �����. ���� ������ ���������;
 *  - ������� ���� ������� �����������. ������ ��������� ����;
 *  - ��������� �����-������ ���������� �� ������ ����� ����� �����, ��� �� �� ��������� �� � ������� ������, ��� � � ���� �����������. ��� ����� ����� ���� �����-������ ������� ���� ���� ���� �����, �� ������ �� ���� ����� ��������. ������� ������, �� �������� � ��� �������. <br/>
 * @author Naimytenko Serhiy
 * @date 05-april-2020
 * @version 1.0
 */
/**
* @file Main.cpp
* �������� ���� ��������
* @author Naimytenko Serhiy
* @version 1.0
* @date 2020.04.05
*/
#include "C_List.h" 
#include"C_Library.h"

typedef bool (func)(int, int);

bool A_more(int a, int b) { return a > b; }
bool B_more(int a, int b) { return b > a; }


int Interface(); /**< ���������� ������� �� ��������� ������ 䳿 �������� (�������� ���� ��� ���� ��� ��������� ������ ���'��)*/
/**
 * ������� ������� main 
 *
 * ���� ��:
 * <ul>
 * <li> ��������� �������� ���� � �������� ��� ������ �� ��������� �� ������������</li>
 * <li> ������ ������� �� ��������� ������ 䳿 ��������</li>
 * <li> ������� ������ ���'��</li>
 * </ul>
 * @return ������� ��������� ������ ��������
 */
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus"); 

    int res = Interface();
    if (res == 0)
        return 1;
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
    C_List list_lib; /**< ��������� ������� ����� C_List*/
    cout << "C������� �������" << endl;
    int command; 
    cout << "������� ������� ���������� ������� 1- �� ����� 2-�������������" << endl;
    cin >> command; /**< ���������� ������� ���������� ������ �����������*/

    string file_read = "file_read.txt"; /**< ��������� ������ � ������ �����*/
    string file_read2 = "file_read2.txt";
    string file_write = "file_write.txt";
    int res;

    if (command == 1) /**< ���� ���������� ����� ����� ���������� � �����*/
    {
        res = list_lib.Count_line(file_read); /**< ���������� ������� ����� */
        if (res == 1) /**< ��������� ���������� ������ ������*/
            return 1;
        int size = list_lib.getSize_array();
        list_lib.list = new Capabilities[size]; /**< �������� ���'�� */
        res = list_lib.Read_file(file_read,file_read2); /**< ������ ������ Read_file*/
        if (res == 1) /**< ��������� ���������� ������ ������*/
            return 1;
    }
    else /**<  ���� ���������� ����� ����� ���������� �������� �������*/
    { 
        int size; 
        cout << "������� ������ �������" << endl;
        cin >> size; /**< ���������� ������ ������ (�������� ������� ����������)*/
        list_lib.setSize_array(size);
        list_lib.list = new Capabilities[size]; /**< �������� ���'�� */
        list_lib.Create(); /**< ������ ������ Create*/
    }

    list_lib.Output(); /**< ������ ������ Output*/
    int order = 0; 

    cout << "������� ���������� ����� ������� �� ������ ��������� ������ ��������" << endl;
    cin >> order; /**< ���������� ������� ���� ������� �������� ����� �������*/

    Capabilities new_lib; /**< ��������� ������ �������*/

    cout << "���������� ������ ��������" << endl;
    list_lib.Add(new_lib, order);  /**< ������ ������*/

    list_lib.Output(); /**< ������ ������ Output*/

    cout << "�������� ��������" << endl;

    cout << "������� ����� �������� �������� �� ������ �������" << endl;
    cin >> order; /**< ���������� ������� �������� �� ������� ��������*/

    list_lib.Delete(order); /**< ������ ������*/

    list_lib.Output(); /**< ������ ������ Output*/

    cout << "������� ������������� �������� ������ �������� �� ������ �������� " << endl;
    cin >> order; /**< ���������� �������������� �������� �� ������� ��������*/



    Capabilities index_lib = list_lib.Index_return(order); /**< ������ ������ Index_return*/

    cout << "����� ���������� �������� �� �����" << endl; 
    stringstream str = list_lib.Str_return(index_lib); /**< �������� �� ����� ������ �� ��������*/
    list_lib.Str_output(str, 0); 

    list_lib.Sort(A_more); /**< ������ ������ Sort �� ����� � �����*/
    list_lib.Output(); /**< ������ ������ Output*/

    list_lib.Sort(B_more); /**< ������ ������ Sort �� ����� � �����*/
    list_lib.Output(); /**< ������ ������ Output*/

    cout << "����� �� ����� ���������, � ������� � �������� 2 ����� " << endl;
    list_lib.Check(); /**< */

    float diff = list_lib.Difference(); /**< ������ ������ Difference*/

    cout << "����� �� ����� ������ ���������� ��� ������ ����������" << endl;

    list_lib.Info_about_lib(); /**< ������ ������ Info_about_lib*/

    res = list_lib.Write_file(file_write ); /**< ������ ������ Write_file*/
    if (res == 1)
        return 1;

    return 0;
}