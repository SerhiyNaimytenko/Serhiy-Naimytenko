#include "C_Library.h"
#include "C_List.h"

void Menu(C_List);

int main()
{
    setlocale(LC_ALL, "Rus");
    C_List list_lib;

    cout << "Cоздание масива"<<endl;
    int command;
    cout << "Введите вариант заполнения масива 1- из файла 2-конструктором"<<endl;
    cin >> command;

    string file_read = "file_read.txt";
    string file_write = "file_write.txt";
    int res;

    if (command == 1)
    {
        list_lib.setSize_array(5);
        list_lib.list = new C_Library[5];
       res = list_lib.Read_file(file_read);
       if (res == 1)
        return 1;
    }

    else
    {
        int size;
        cout << "Введите размер масива" << endl;
        cin >> size;
        list_lib.setSize_array(size);
        list_lib.list = new C_Library[size];
        list_lib.Create();
    }

   

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
    stringstream str = list_lib.Str_return(index_lib);
    list_lib.Str_output(str,0);

    float diff = list_lib.Difference();

    res = list_lib.Write_file(file_write);
    if (res == 1)
        return 1;


    if (_CrtDumpMemoryLeaks()) 
        cout <<endl<< "Есть утечка памяти" << endl;
    else
        cout << endl << "Нет утечки памяти" << endl;
    return 0;
}


void Menu(C_List list_lib)
{

}