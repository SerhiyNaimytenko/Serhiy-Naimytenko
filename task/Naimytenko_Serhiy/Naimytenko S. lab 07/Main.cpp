/**
 * @mainpage
 * <b> Лабораторна робота № 7. Поліморфізм </b>
 * <br/><b>Мета роботи:</b>: отримати знання про парадигму ООП – поліморфізм; навчитися застосовувати отримані знання на практиці.  <br/>
 * <b>Індивідуальне завдання:</b>
 * Модернізувати попередню лабораторну роботу шляхом:
 *  - додавання ще одного класу-спадкоємця до базового класу. Поля обрати самостійно;
 *  - базовий клас зробити абстрактним. Додати абстрактні поля;
 *  - розроблені класи-списки поєднуються до одного класу таким чином, щоб він міг працювати як з базовим класом, так і з його спадкоємцями. При цьому серед полів класу-списку повинен бути лише один масив, що містить усі типи класів ієрархії. Оновити методи, що працюють з цим масивом. <br/>
 * @author Naimytenko Serhiy
 * @date 05-april-2020
 * @version 1.0
 */
/**
* @file Main.cpp
* Головний файл програми
* @author Naimytenko Serhiy
* @version 1.0
* @date 2020.04.05
*/
#include "C_List.h" 
#include"C_Library.h"

typedef bool (func)(int, int);

bool A_more(int a, int b) { return a > b; }
bool B_more(int a, int b) { return b > a; }


int Interface(); /**< Оголошення функції де проходять основні дії програми (зроблена вона для того щоб перевіряти витоки пам'яті)*/
/**
 * Головна функція main 
 *
 * Опис дій:
 * <ul>
 * <li> Додавання російської мови в програму для діалога між програмою та користувачем</li>
 * <li> Виклик функції де проходять основні дії програми</li>
 * <li> Превірка витоків пам'яті</li>
 * </ul>
 * @return повертає результат роботи програми
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
    C_List list_lib; /**< створення обьекта класу C_List*/
    cout << "Cоздание массива" << endl;
    int command; 
    cout << "Введите вариант заполнения массива 1- из файла 2-конструктором" << endl;
    cin >> command; /**< визначення варіації заповнення масиву інформацією*/

    string file_read = "file_read.txt"; /**< створення змінних з назвою файлів*/
    string file_read2 = "file_read2.txt";
    string file_write = "file_write.txt";
    int res;

    if (command == 1) /**< якщо користувач обрав метод заповнення з файлу*/
    {
        res = list_lib.Count_line(file_read); /**< визначення кількості рядків */
        if (res == 1) /**< преревірка результату роботи методу*/
            return 1;
        int size = list_lib.getSize_array();
        list_lib.list = new Capabilities[size]; /**< виділення пам'яті */
        res = list_lib.Read_file(file_read,file_read2); /**< виклик методу Read_file*/
        if (res == 1) /**< преревірка результату роботи методу*/
            return 1;
    }
    else /**<  якщо користувач обрав метод заповнення готовими данними*/
    { 
        int size; 
        cout << "Введите размер массива" << endl;
        cin >> size; /**< визначення розміру масиву (значення вводить користувач)*/
        list_lib.setSize_array(size);
        list_lib.list = new Capabilities[size]; /**< виділення пам'яті */
        list_lib.Create(); /**< виклик методу Create*/
    }

    list_lib.Output(); /**< виклик методу Output*/
    int order = 0; 

    cout << "Введите порядковый номер который вы хотите присвоить новому элементу" << endl;
    cin >> order; /**< визначення індексу куди потрібно помістити новий елемент*/

    Capabilities new_lib; /**< створення нового обьекту*/

    cout << "Добавления нового элемента" << endl;
    list_lib.Add(new_lib, order);  /**< виклик методу*/

    list_lib.Output(); /**< виклик методу Output*/

    cout << "Удаления элемента" << endl;

    cout << "Введите номер элемента которого вы хотите удалить" << endl;
    cin >> order; /**< визначення індексу елемента що потрібно видалити*/

    list_lib.Delete(order); /**< виклик методу*/

    list_lib.Output(); /**< виклик методу Output*/

    cout << "Введите идентификатор елемента данные которого вы хотите получить " << endl;
    cin >> order; /**< визначення идентифікатора елемента що потрібно отримати*/



    Capabilities index_lib = list_lib.Index_return(order); /**< виклик методу Index_return*/

    cout << "Вывод полученого элемента на екран" << endl; 
    stringstream str = list_lib.Str_return(index_lib); /**< виводимо на екран обьект що отримали*/
    list_lib.Str_output(str, 0); 

    list_lib.Sort(A_more); /**< виклик методу Sort де число А більше*/
    list_lib.Output(); /**< виклик методу Output*/

    list_lib.Sort(B_more); /**< виклик методу Sort де число В більше*/
    list_lib.Output(); /**< виклик методу Output*/

    cout << "Вывод на экран библиотек, в которых в названии 2 слова " << endl;
    list_lib.Check(); /**< */

    float diff = list_lib.Difference(); /**< виклик методу Difference*/

    cout << "Вывод на екран полной информации про каждую библиотеку" << endl;

    list_lib.Info_about_lib(); /**< виклик методу Info_about_lib*/

    res = list_lib.Write_file(file_write ); /**< виклик методу Write_file*/
    if (res == 1)
        return 1;

    return 0;
}