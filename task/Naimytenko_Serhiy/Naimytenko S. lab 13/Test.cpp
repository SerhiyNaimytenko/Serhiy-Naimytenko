#include "C_Library.h" /**< ���������� ����� C_Library.h*/ 
#include "C_List.h" /**< ���������� ����� C_List.h*/
#include "Test.h" /**< ���������� ����� Test.h*/
/**
 * ������� ������� main
 *
 * ���� ��:
 * <ul>
 * <li> ��������� �������� ���� � �������� ��� ������ �� ��������� �� ������������</li>
 * <li> ������ ������� ���� ���������� ������ ������</li>
 * <li> ������� ������ ���'��</li>
 * </ul>
 * @return ������� ��������� ������ ��������
 */
int main()
{
    setlocale(LC_ALL, "Rus");
    bool result;

    C_List list; /**< ��������� ������� ����� C_List*/

    list.list = new Capabilities[3]; /**< �������� ���'�� ��� ������*/

    list.setSize_array(3);

    result = Test_Add(list); /**< ������ �������-����� Test_Add*/
    if (result) /**< �������� �����*/
        cout << "Test_Add ������� �������!" << endl;
    else
        cout << "Test_Add �� �������!" << endl;

    result = Test_Delete(list); /**< ������ �������-����� Test_Delete*/
    if (result) /**< �������� �����*/
        cout << "Test_Delete ������� �������!" << endl;
    else
        cout << "Test_Delete �� �������!" << endl;

    result = Test_Index_return(list);/**< ������ �������-����� Test_Index_return*/
    if (result)/**< �������� �����*/
        cout << "Test_Index_return ������� �������!" << endl;
    else
        cout << "Test_Index_return �� �������!" << endl;

    result = Test_Difference(list);/**< ������ �������-����� Test_Difference*/
    if (result)/**< �������� �����*/
        cout << "Test_Difference ������� �������!" << endl;
    else
        cout << "Test_Difference �� �������!" << endl;

    result = Test_Sort(list);/**< ������ �������-����� Test_Sort*/
    if (result)/**< �������� �����*/
        cout << "Test_Sort ������� �������!" << endl;
    else
        cout << "Test_Sort �� �������!" << endl;

    return 0;

}