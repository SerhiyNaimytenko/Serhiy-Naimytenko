
#include "Test.h" 

int main()
{
    setlocale(LC_ALL, "Rus");
    bool result;

    result = Testvector(); /**< ������ �������-����� Test_Add*/
    if (result) /**< �������� �����*/
        cout << "Testvector ������� �������!" << endl;
    else
        cout << "Testvector �� �������!" << endl;

    result = Testlist(); /**< ������ �������-����� Test_Delete*/
    if (result) /**< �������� �����*/
        cout << "Testlist ������� �������!" << endl;
    else
        cout << "Testlist �� �������!" << endl;

    result = Testset();/**< ������ �������-����� Test_Index_return*/
    if (result)/**< �������� �����*/
        cout << "Testset ������� �������!" << endl;
    else
        cout << "Testset �� �������!" << endl;

    result = Testmap();/**< ������ �������-����� Test_Index_return*/
    if (result)/**< �������� �����*/
        cout << "Testmap ������� �������!" << endl;
    else
        cout << "Testmap �� �������!" << endl;

    return 0;
}