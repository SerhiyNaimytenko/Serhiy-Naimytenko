#include "C_Library.h"
#include "C_List.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    C_List list_lib;

    cout << "Cоздание масива"<<endl<<"Введите размерность масва" << endl;
    int size;
    cin >> size;
    list_lib.setSize_array(size);
    list_lib.list = new C_Library[size];

    list_lib.Create();

    list_lib.Output();

    int order = 0;

    cout << "Введите порядковый номер который вы хотите присвоить новому елементу" << endl;
    cin >> order;

    C_Library new_lib = C_Library();

    cout << "Добавления нового елемента" << endl;
    list_lib.Add(new_lib, order);

    list_lib.Output();

    cout << "Удаления елемента" << endl;
   
    cout << "Введите номер елемента которого вы хотите удалить" << endl;
    cin >> order;

    cout << "Элемент который вы удалили" << endl;
    list_lib.Delete(order);

    list_lib.Output();

    cout << "Введите индекс елемента данные которого вы хотите получить " << endl;
    cin >> order;


    C_Library index_lib = list_lib.Index_return(order);

    cout << "Вывод полученого элемента на екран" << endl;
    list_lib.Index_output(index_lib, 1);

    float diff = list_lib.Difference();

    delete[]  list_lib.list;

    if (_CrtDumpMemoryLeaks()) 
        cout <<endl<< "Есть утечка памяти" << endl;
    else
        cout << endl << "Нет утечки памяти" << endl;
    return 0;
}
