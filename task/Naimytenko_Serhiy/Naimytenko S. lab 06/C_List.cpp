#include "C_List.h"
#include "Builder.h" 
#include"C_Language.h"
#include"C_Library.h"

void C_List::setSize_array(const int size)
{
    this->size = size;
}

int C_List::getSize_array()const
{
    return this->size;
}

int C_List::Read_file(string file_name, string file_name2)
{

    ifstream file(file_name);
    if (!file)
    {
        cout << "Ошибка!!! Файл не открыто." << endl;
        return 1;
    }
    ifstream file2(file_name2);
    if (!file2)
    {
        cout << "Ошибка!!! Файл не открыто." << endl;
        return 1;
    }
    string line;
    string line2;
    for (size_t i = 0; i < size; i++)
    {
        getline(file, line);
        getline(file2, line2);
        list[i] = Distribution(line, line2);
    }
    file.close();
    return 0;
}

void C_List::Count_line(string file_name)
{
    int size2 = 0;
    size = size2;
    ifstream file(file_name);
    if (!file)
    {
        cout << "Ошибка!!! Файл не открыто." << endl;
        return;
    }
    string  line;
    while (getline(file, line))
    {
        size2++;
    }
    size = size2;

    file.close();
}

C_Library C_List::Distribution(string line, string line2)
{
    regex regular("([\\d]* [\\d]* [\\d]* (Yes|No) [A-ZА-Я]+[\\wА-Яа-я\-|_|:|;|\.]* ([A-ZА-Я]+[\\wА-Яа-я\-|_|:|;|\.]*)?)");
    regex replace_reg1("([;]{2,})");
    regex replace_reg2("([_]{2,})");
    regex replace_reg3("([-]{2,})");
    regex replace_reg4("([:]{2,})");
    regex replace_reg5("([\.]{2,})");
    C_Library new_l;
    int id, number_of_function, year_creating;
    string dynamically, name = " ", name2 = " ", line_res;
    string name_f, name_l;
    auto res = regex_match(line, regular);
    if (res)
    {

        if (regex_search(line, replace_reg1))
        {
            line = regex_replace(line, replace_reg1, ";");
        }
        if (regex_search(line, replace_reg2))
        {
            line = regex_replace(line, replace_reg2, "_");
        }
        if (regex_search(line, replace_reg3))
        {
            line = regex_replace(line, replace_reg3, "-");
        }
        if (regex_search(line, replace_reg4))
        {
            line = regex_replace(line, replace_reg4, ":");
        }
        if (regex_search(line, replace_reg5))
        {
            line = regex_replace(line, replace_reg5, ".");
        }

        istringstream str(line);
        str >> id >> number_of_function >> year_creating >> dynamically >> name >> name2;
        if (name2 != " " && name != " ")
            name = name + " " + name2;

        istringstream str2(line2);
        str2 >> name_f >> name_l;

        new_l.setFunction(name_f);
        new_l.setLanguage_programming(name_l);

        C_Library new_el(dynamically, name, id, year_creating, number_of_function, new_l);

        return new_el;
    }
    C_Library new_el;
    return new_el;
}

C_Expansion* C_List::Create() // 1
{
    cout << "Происходит заполнеие масива данными" << endl;
    C_Expansion* list_e = new C_Expansion[size];
    for (size_t i = 0; i < size; i++)
    {
        list_e[i] = New_Lib(i + 1);
        list[i].setDynamically(list_e[i].getDynamically());
        list[i].setID(list_e[i].getID());
        list[i].setName(list_e[i].getName());
        list[i].setLanguage_programming(list_e[i].Which_language_programming());
        list[i].setFunction(list_e[i].What_function_is_in_this_library());
        list[i].setYear_Creating(list_e[i].getYear_Creating());
        list[i].setNumber_of_function(list_e[i].getNumber_of_function());
    }
    return list_e;
}

void C_List::Add(C_Library lib, const int order)  // 3
{
    size++;
    arr_Lib new_list = new C_Library[size];
    

    for (size_t i = 0, j = 0; i < size; i++)
    {
        if (i != order - 1)
        {
            new_list[i] = list[j];
            j++;
        }
        else
            new_list[i] = lib;
    }
    delete[] list;
    list = new C_Library[size];
    for (size_t i = 0; i < size; i++)
        list[i] = new_list[i];
    delete[] new_list;
}

void C_List::Delete(const int order,C_Expansion* list_e) // 4
{
    size--;
    arr_Lib new_list = new C_Library[size];

    cout << "Елемент который вы удалили" << endl;
    stringstream str = Str_return(list[order - 1]);
    Str_output(str, 0);
    obj.Output_index(list_e[order-1]);
    for (size_t i = 0; i < order - 1; i++)
        new_list[i] = list[i];
    for (size_t i = order - 1; i < size; i++)
        new_list[i] = list[i + 1];
    delete[] list;
    list = new C_Library[size];
    for (size_t i = 0; i < size; i++)
        list[i] = new_list[i];
    delete[] new_list;

}

C_Library& C_List::Index_return(const int index)
{
    int id;
    for (size_t i = 0; i < size; i++)
    {
        id = list[i].getID();
        if (id == index)
        {
            id = i;
            i = size;
        }
    }
    return list[id];
}

stringstream C_List::Str_return(C_Library& lib)const  // 5
{
    stringstream str;
    str << " " << lib.getID() << " " << lib.getNumber_of_function() << " " << lib.getYear_Creating() << " " << lib.getDynamically() << " " << lib.getName();
    return str;
}

void C_List::Str_output(stringstream& str, int i)const
{

    int number_of_function, year_creating, id;
    string dynamically, name1, name2 = "";
    str >> id;
    str >> number_of_function;
    str >> year_creating;
    str >> dynamically;
    str >> name1;
    str >> name2;
    if (name2 == "")
        cout << i + 1 << "- " << setw(10) << id << setw(13) << number_of_function << setw(21) << year_creating << setw(20) << dynamically << setw(29) << name1;
    else
        cout << i + 1 << "- " << setw(10) << id << setw(13) << number_of_function << setw(21) << year_creating << setw(20) << dynamically << setw(23) << name1 << " " << name2;
}

void C_List::Output(C_Expansion* list_e)const // 6
{
    stringstream str;
    cout << "Вивод на экран всех объектов" << endl;
    cout.setf(std::ios::right);
    cout << "№" << setw(17) << "id библиотеки" << setw(16) << "Кол-во функций" << setw(18) << "Год её создания" << setw(30) << "Динмически ли она подключена" << setw(20) << "Название библиотеки" << setw(29) << "Расширение файла библиоткеки" << endl;
    for (size_t i = 0; i < size; i++)
    {
       
        str = Str_return(list[i]);
        Str_output(str, i);
        obj.Output_index(list_e[i]);
        
    }

}

void C_List::Sort(func condition,C_Expansion*& list_e)
{
    C_Library temp;
    C_Expansion temp_e;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (condition(list[i].getID(), list[j].getID()))
            {
                temp = list[i];
                temp_e = list_e[i];
                list[i] = list[j];
                list_e[i] = list_e[j];
                list[j] = temp;
                list_e[j] = temp_e;
            }
        }
    }
}

float C_List::Difference()
{
    int count = 0;
    string y;
    for (size_t i = 0; i < size; i++)
    {
        y = list[i].getDynamically();
        if (y == "yes")
            count++;
    }
    float dif = (float)size / (float)count;
    cout << "В " << setprecision(5) << dif << " раз количество библиотек, которые динамически подключаются, меньше чем общее количество библиотек" << endl;
    return dif;
}

void C_List::If_lib_connected(C_Expansion* list_e)

{
    for (size_t i = 0; i < size; i++)
    {
        cout << endl << "В языке програмирования \"";
        cout << list[i].Which_language_programming();
        cout << "\" используется библиотека " << list[i].getName() << endl;
        cout << "В данной библиотеке есть такая функция" << endl;
        cout << "Функция - " << list[i].What_function_is_in_this_library() << endl;
        cout << "Расширения библиотеки - " << list_e[i].getExpansion_file() << endl;
    }

}

int C_List::Write_file(string file_name, C_Expansion* list_e)
{
    ofstream file(file_name);
    if (!file)
    {
        cout << "Ошибка!!! Файл не открыто." << endl;
        return 1;
    }
    file << "№" << setw(17) << "id библиотеки" << setw(16) << "Кол-во функций" << setw(18) << "Год её создания" << setw(30) << "Динмически ли она подключена" << setw(17) << "Название библиотеки" << setw(17) << "Расширение файла библиоткеки" << endl;
    for (size_t i = 0; i < size; i++)
        file << i + 1 << "- " << setw(5) << list[i].getID() << setw(24) << list[i].getNumber_of_function() << setw(27) << list[i].getYear_Creating() << setw(23) << list[i].getDynamically() << setw(23) << list[i].getName() << setw(23) << list_e[i].getExpansion_file()<< endl;
    file.close();
}

void C_List::Check(C_Expansion* list_e)
{
    regex regular("(([A-ZА-Я]+[\\wА-Яа-я\-|_|:|;|\.]*)+( )+([A-ZА-Я]+[\\wА-Яа-я\-|_|:|;|\.]*))");
    string check;
    stringstream str;
    int k = 0;
    for (size_t i = 0; i < size; i++)
    {
        auto check_res = list[i].getName();
        if (regex_match(check_res, regular))
        {
            str = Str_return(list[i]);
            Str_output(str, k);
            obj.Output_index(list_e[i]);
            k++;
        }
    }
}

C_List:: ~C_List()
{
    delete[] list;
}