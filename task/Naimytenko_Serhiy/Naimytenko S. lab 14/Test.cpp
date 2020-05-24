
#include "Test.h" 

int main()
{
    setlocale(LC_ALL, "Rus");
    bool result;

    result = Testvector(); /**< виклик функціі-тесту Test_Add*/
    if (result) /**< перевірка тесту*/
        cout << "Testvector пройден успешно!" << endl;
    else
        cout << "Testvector не пройден!" << endl;

    result = Testlist(); /**< виклик функціі-тесту Test_Delete*/
    if (result) /**< перевірка тесту*/
        cout << "Testlist пройден успешно!" << endl;
    else
        cout << "Testlist не пройден!" << endl;

    result = Testset();/**< виклик функціі-тесту Test_Index_return*/
    if (result)/**< перевірка тесту*/
        cout << "Testset пройден успешно!" << endl;
    else
        cout << "Testset не пройден!" << endl;

    result = Testmap();/**< виклик функціі-тесту Test_Index_return*/
    if (result)/**< перевірка тесту*/
        cout << "Testmap пройден успешно!" << endl;
    else
        cout << "Testmap не пройден!" << endl;

    return 0;
}