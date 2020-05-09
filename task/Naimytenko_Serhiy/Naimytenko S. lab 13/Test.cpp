#include "C_Library.h" /**< підключення файлу C_Library.h*/ 
#include "C_List.h" /**< підключення файлу C_List.h*/
#include "Test.h" /**< підключення файлу Test.h*/
/**
 * Головна функція main
 *
 * Опис дій:
 * <ul>
 * <li> Додавання російської мови в програму для діалога між програмою та користувачем</li>
 * <li> Виклик функції котрі перевіряють роботу методів</li>
 * <li> Превірка витоків пам'яті</li>
 * </ul>
 * @return повертає результат роботи програми
 */
int main()
{
    setlocale(LC_ALL, "Rus");
    bool result;

    C_List list; /**< створення обьекта класу C_List*/

    list.list = new Capabilities[3]; /**< виділення пам'яті для масиву*/

    list.setSize_array(3);

    result = Test_Add(list); /**< виклик функціі-тесту Test_Add*/
    if (result) /**< перевірка тесту*/
        cout << "Test_Add пройден успешно!" << endl;
    else
        cout << "Test_Add не пройден!" << endl;

    result = Test_Delete(list); /**< виклик функціі-тесту Test_Delete*/
    if (result) /**< перевірка тесту*/
        cout << "Test_Delete пройден успешно!" << endl;
    else
        cout << "Test_Delete не пройден!" << endl;

    result = Test_Index_return(list);/**< виклик функціі-тесту Test_Index_return*/
    if (result)/**< перевірка тесту*/
        cout << "Test_Index_return пройден успешно!" << endl;
    else
        cout << "Test_Index_return не пройден!" << endl;

    result = Test_Difference(list);/**< виклик функціі-тесту Test_Difference*/
    if (result)/**< перевірка тесту*/
        cout << "Test_Difference пройден успешно!" << endl;
    else
        cout << "Test_Difference не пройден!" << endl;

    result = Test_Sort(list);/**< виклик функціі-тесту Test_Sort*/
    if (result)/**< перевірка тесту*/
        cout << "Test_Sort пройден успешно!" << endl;
    else
        cout << "Test_Sort не пройден!" << endl;

    return 0;

}