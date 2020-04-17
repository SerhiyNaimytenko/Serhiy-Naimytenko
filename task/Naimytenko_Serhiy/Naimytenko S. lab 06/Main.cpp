#include "C_List.h"
#include"C_Heir_list.h"
#include"C_Library.h"


typedef bool (func)(int, int);

bool A_more(int a, int b) { return a > b; }
bool B_more(int a, int b) { return b > a; }




int Menu();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    int res = Menu();
    if (res == 0)
        return 0;
    if (_CrtDumpMemoryLeaks())
        cout << endl << "Есть утечка памяти" << endl;
    else
        cout << endl << "Нет утечки памяти" << endl;
    return 0;
}


int Menu()
{
    C_List list_lib;
    C_Heir_list list_exp;
    cout << "Cоздание масива" << endl;
    int command;
    cout << "Введите вариант заполнения масива 1- из файла 2-конструктором" << endl;
    cin >> command;

    string file_read1 = "file_read.txt";
    string file_read2 = "expansion.txt";
    string file_func = "All_func.txt";
    string file_write = "file_write.txt";
    int res;

    if (command == 1)
    {
        list_lib.Count_line(file_read1);
        int size = list_lib.getSize_array();
        list_exp.setSize_array(size);
        list_lib.list = new C_Library[size];
        list_exp.list = new C_Expansion[size];
        res = list_lib.Read_file(file_read1, file_func);
        if (res == 1)
            return 1;
        res = list_exp.Read_file(file_read2);
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
        list_exp.list = new C_Expansion[size];
        list_exp.list = list_lib.Create();
    }



    list_lib.Output(list_exp.list);
    int order = 0;

    cout << "Введите порядковый номер который вы хотите присвоить новому елементу" << endl;
    cin >> order;

    C_Library new_lib;
    C_Expansion new_exp;

    cout << "Добавления нового елемента" << endl;
    list_lib.Add(new_lib, order);
    list_exp.Add(new_exp, order);

    list_lib.Output(list_exp.list);

    cout << "Удаления елемента" << endl;

    cout << "Введите номер елемента которого вы хотите удалить" << endl;
    cin >> order;

    cout << "Элемент который вы удалили" << endl;
    list_lib.Delete(order, list_exp.list);

    list_lib.Output(list_exp.list);

    cout << "Введите индекс елемента данные которого вы хотите получить " << endl;
    cin >> order;



    C_Library index_lib = list_lib.Index_return(order);

    cout << "Вывод полученого элемента на екран" << endl;
    stringstream str = list_lib.Str_return(index_lib);
    list_lib.Str_output(str, 0);

    list_lib.Sort(A_more,list_exp.list);

    list_lib.Output(list_exp.list);

    list_lib.Sort(B_more, list_exp.list);

    list_lib.Output(list_exp.list);

    cout << "Вывод на экран библиотек, в которых в названии 2 слова " << endl;
    list_lib.Check(list_exp.list);

    float diff = list_lib.Difference();

    cout << "Проверка. Какие библиотеки сейчас подключены." << endl;

    list_lib.If_lib_connected(list_exp.list);

    res = list_lib.Write_file(file_write, list_exp.list);
    if (res == 1)
        return 1;


}