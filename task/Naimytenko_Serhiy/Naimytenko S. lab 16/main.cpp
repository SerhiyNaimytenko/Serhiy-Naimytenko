#include"First_Heir.h"
#include"Second_Heir.h"

int Interface(); /**< Оголошення функції де проходять основні дії програми (зроблена вона для того щоб перевіряти витоки пам'яті)*/
 
int main()
{ 
    setlocale(LC_ALL, "Rus");

    int res = Interface(); 
    if (_CrtDumpMemoryLeaks())
        cout << endl << "Есть утечка памяти" << endl;
    else
        cout << endl << "Нет утечки памяти" << endl;
    return 0;
}
/**
 * Функція Interface
 *
 * Короткий опис дій:
 * <ul>
 * <li> Створення обьекту класу С_List та проходження всіх його методів</li>
 * </ul>
 * @return пуста функція типу void
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