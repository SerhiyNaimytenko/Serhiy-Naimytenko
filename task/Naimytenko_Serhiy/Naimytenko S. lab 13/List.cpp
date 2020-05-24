#include "Conteiner.h" 
list<Capabilities>  Read_file(string file_name, string file_name2, int size);
list<Capabilities> Distribution(string line, string line2, int i, list<Capabilities>);
list<Capabilities>  Add(list<Capabilities>);
list<Capabilities>  Delete(list<Capabilities>);
Capabilities Index_return(const int index, list<Capabilities>);
void  Output(list<Capabilities>); 
float Difference(list<Capabilities>);
void  Info_about_lib(list<Capabilities>);
int  Write_file(list<Capabilities>, string file_name);
void  Check(list<Capabilities>);
void Criterion(list<Capabilities>);
void Search(list<Capabilities>);
 
int List()
{
    list<Capabilities>  conteiner;
    string file_read = "file_read.txt";
    string file_read2 = "file_read2.txt";
    string file_write = "file_write.txt";
    int size = Count_line(file_read);
    if (size == 0)
        return 404;
    conteiner = Read_file(file_read, file_read2, size);
    if (conteiner.size() == 0)
        return 404;
    Output(conteiner);
    conteiner = Add(conteiner);
    Output(conteiner);
    conteiner = Delete(conteiner);
    Output(conteiner); 
    float diff = Difference(conteiner);
    int id;
    cout << "Введите айди элемента которого хотите получить" << endl;
    cin >> id;
    Capabilities res_id = Index_return(id, conteiner); 
    Str_return(res_id);
    cout << "Вывод объектов в названии которых 2 слова" << endl;
    Check(conteiner);
    Info_about_lib(conteiner);
    Criterion(conteiner);
    Search(conteiner);
    int res = Write_file(conteiner, file_write);
    if (res == 1)
        return 404;
    conteiner.clear();
    return 0;
}

list<Capabilities>  Read_file(string file_name, string file_name2, int size)
{
    list<Capabilities> cont;
    ifstream file(file_name);  /**< відкриття файлу*/
    if (!file)  /**< перевірка чи відкрився файл*/
    {
        cout << "Ошибка!!! Файл не открыто." << endl;
        return cont;
    }
    ifstream file2(file_name2);  /**< відкриття файлу*/
    if (!file) /**< перевірка чи відкрився файл*/
    {
        cout << "Ошибка!!! Файл не открыто." << endl;
        return cont;
    }
    string line;
    string line2;
    for (size_t i = 0; i < size; i++)
    {
        getline(file, line); /**< зчитуємо рядок з інформацією */
        getline(file2, line2);  /**< зчитуємо рядок з інформацією */
        cont = Distribution(line, line2, i, cont);  /**< виклик методу Distribution*/
    }
    file.close();  /**< закриття файлу*/
    return cont;
}
list<Capabilities>  Distribution(string line, string line2, int i, list<Capabilities> cont)
{
    regex regular("[\\d]* [\\d]* [\\d]* (Yes|No) [A-ZА-Я]+[\\wА-Яа-я\-|_|:|;|\.]*[ ]?([A-ZА-Я]+[\\wА-Яа-я\-|_|:|;|\.]*)? [\\w][_]?([\\w]*)? C[\+]{0,} [.][\\w]*"); /**< основний регулярний вираз*/
    regex replace_reg1("([;]{2,})"); /**< оголошення регулярних виразів що допоможуть уникнути повторення деяких символів*/
    regex replace_reg2("([_]{2,})");
    regex replace_reg3("([-]{2,})");
    regex replace_reg4("([:]{2,})");
    regex replace_reg5("([\.]{2,})");
    C_Expansion obj_e;

    int id, number_of_function, year_creating;
    string dynamically, name, name2, line_res;
    string name_f, name_l, expansion, capabilities;
    auto res = regex_match(line, regular); /**< перевірка рядку основним виразом*/
    if (res)
    {

        if (regex_search(line, replace_reg1)) /**< якщо виявилося повторення заміняемо символи одним таким же символом*/
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
        istringstream str(line); /**< преретворюємо рядок у потік з інформацією*/
        str >> id >> number_of_function >> year_creating >> dynamically >> name >> name2 >> name_f >> name_l >> expansion; /**< зчитуємо інформацію у відповідні змінні*/
        if (expansion == "") /**< якщо ім'я данної бібліотеки складається з одного слова то остання змінна залишається пустою */
        {
            obj_e.setName(name);
            obj_e.setDynamically(dynamically);
            obj_e.setFunction(name2);
            obj_e.setLanguage_programming(name_f);
            obj_e.setID(id);
            obj_e.setNumber_of_function(number_of_function);
            obj_e.setYear_Creating(year_creating);
            obj_e.setExpansion_file(name_l);

            cont.push_back(Capabilities(line2, dynamically, name, id, year_creating, number_of_function, name2, name_f, obj_e));
        }
        else /**< якщо ім'я данної бібліотеки складається з двух слів то відповідність ззмінних та інформації зберігається */
        {
            name = name + " " + name2; /**< складаємо назву бібліотеки в одну змінну*/
            obj_e.setName(name);
            obj_e.setDynamically(dynamically);
            obj_e.setFunction(name_f);
            obj_e.setLanguage_programming(name_l);
            obj_e.setID(id);
            obj_e.setNumber_of_function(number_of_function);
            obj_e.setYear_Creating(year_creating);
            obj_e.setExpansion_file(expansion);

            cont.push_back(Capabilities(line2, dynamically, name, id, year_creating, number_of_function, name2, name_f, obj_e));
        }
    }
    return cont;
}
list<Capabilities> Add(list<Capabilities> cont)
{
    int index_el;
    cout << "Введите порядковый индекс елемента которого хотите удалить" << endl;
    cin >> index_el;
    auto it = cont.begin();
    advance(it, index_el - 1);
    Capabilities add_el;
    cont.insert(it, add_el);
    return cont;
}
list<Capabilities>  Delete(list<Capabilities> cont)
{
    auto it = cont.begin();
    int index_el;
    cout << "Введите порядковый индекс елемента которого хотите удалить" << endl;
    cin >> index_el;
    advance(it, index_el - 1);
    cont.erase(it);
    return cont;
}
Capabilities Index_return(const int index, list<Capabilities> cont)
{
    int id;
    Capabilities value;
    for (auto var : cont)
    {
        id = var.getID(); /**< дізнаємося ідентифікатор кожного елементу*/
        if (id == index)/**< порівнюємо значення*/
        {
            value = var;
        }
    }
    return value;
}

void  Output(list<Capabilities> cont)
{
    stringstream str;
    int i = 0;
    cout << "Вивод на экран всех объектов" << endl;
    cout << "№" << setw(17) << "id библиотеки" << setw(16) << "Кол-во функций" << setw(18) << "Год её создания" << setw(30) << "Динмически ли она подключена" << setw(20) << "Название библиотеки" << setw(32) << "Одна из функций этой библиотеки" << setw(21) << "Язык програмирования" << setw(29) << "Расширение файла библиоткеки" << endl;
    for_each(cont.begin(), cont.end(), Str_return);

} 
float Difference(list<Capabilities> cont)
{
    float count = 0;
    string y;
    for (auto var : cont)
    {
        y = var.getDynamically();
        if (y == "yes") /**< перевірка чи динамічно підлючається бібліотека, якщо так збільшуємо значення змінної*/
            count++;
    }
    float dif = cont.size() / count; /**< визначаємо частку від ділення */
    cout << "В " << setw(5) << dif << " раз количество библиотек, которые динамически подключаются, меньше чем общее количество библиотек" << endl;/**< повідомляємо відмінність виводячи інформацію на екран*/
    return dif;
}
void  Info_about_lib(list<Capabilities> cont)
{
    for (auto var : cont)
    {
        cout << endl << "В языке програмирования \"";
        cout << var.getLanguage_programming();
        cout << "\" используется библиотека " << var.getName() << endl;
        cout << "В данной библиотеке есть такая функция" << endl;
        cout << "Функция - " << var.getFunction() << endl;
        cout << "Возможности данной библиотеки" << endl << var.getCapabilities() << endl;
    }
}
int  Write_file(list<Capabilities> cont, string file_name)
{
    ofstream file(file_name); /**< відкриття файлу*/
    if (!file) /**< перевірка чи відкрився файл*/
    {
        cout << "Ошибка!!! Файл не открыто." << endl;
        return 1;
    }
    int i = 0;
    file << "№" << setw(17) << "id библиотеки" << setw(16) << "Кол-во функций" << setw(18) << "Год её создания" << setw(30) << "Динмически ли она подключена" << setw(20) << "Название библиотеки" << setw(32) << "Одна из функций этой библиотеки" << setw(21) << "Язык програмирования" << setw(29) << "Расширение файла библиоткеки" << endl;
    for (auto var : cont)
    {
        file << i + 1 << "- " << setw(10) << var.getID() << setw(13) << var.getNumber_of_function() << setw(21) << var.getYear_Creating() << setw(20) << var.getDynamically() << setw(30) << var.getName() << setw(26) << var.getFunction() << setw(24) << var.getLanguage_programming() << setw(20) << endl << var.getCapabilities() << endl;
        i++;
    }
    file.close(); /**< закриття файлу*/
    return 0;
}
void  Check(list<Capabilities> cont)
{
    regex regular("(([A-ZА-Я]+[\\wА-Яа-я\-|_|:|;|\.]*)+( )+([A-ZА-Я]+[\\wА-Яа-я\-|_|:|;|\.]*))");  /**< створення регулярного виразу для визначення назви з двома словами*/
    string check;
    stringstream str;
    int k = 0;
    for (auto var : cont)
    {
        auto check_res = var.getName();
        if (regex_match(check_res, regular))  /**< преревіряємо чи містить назва 2 слова*/
        {
            Str_return(var); 
        }
    }
}

void Criterion(list<Capabilities> cont)
{
    int command, count;
    bool flag = true;
    cout << "Введите номер критерия по которому хотите узнать количество элементов" << endl << "1 - Имя библиотеки состоит из 2х слов" << endl << "2 - Год создания" << endl << "3 - Язык програмирования" << endl << "4 - Количество динамически подключаемых библиотек" << "404 - завершение поиска количества по критериям" << endl;
    cin >> command;
    while (flag)
    {
        count = 0;
        switch (command)
        {
        case 1:
        {
            regex regular("(([A-ZА-Я]+[\\wА-Яа-я\-|_|:|;|\.]*)+( )+([A-ZА-Я]+[\\wА-Яа-я\-|_|:|;|\.]*))");
            for (auto var : cont)
            {
                auto check_res = var.getName();
                if (regex_match(check_res, regular))  /**< преревіряємо чи містить назва 2 слова*/
                {
                    count++;
                }
            }
            cout << "Количество бииблиотек, в названии которых 2 слова - " << count << endl;
            break;
        }
        case 2:
        {

            int year;
            cout << "Введите год создания" << endl;
            cin >> year;
            for (auto var : cont)
            {

                if (var.getYear_Creating() == year)  /**< преревіряємо чи містить назва 2 слова*/
                {
                    count++;
                }
            }

            cout << "Количество библиотеки" << year << " года создания - " << count << endl;
            break;

        }
        case 3:
        {
            cout << "1 - язык С, 2 - С++" << endl;
            cin >> command;
            if (command == 1)
            {
                for (auto var : cont)
                {

                    if (var.getLanguage_programming() == "C")  /**< преревіряємо чи містить назва 2 слова*/
                    {
                        count++;
                    }
                }
                cout << "Количество библиотек, основаных на языке програмирования С - " << count << endl;
            }
            else
            {
                for (auto var : cont)
                {

                    if (var.getLanguage_programming() == "C++")  /**< преревіряємо чи містить назва 2 слова*/
                    {
                        count++;
                    }
                }
                cout << "Количество библиотек, основаных на языке програмирования С++ - " << count << endl;
            }
            break;

        }
        case 4:
        {

            for (auto var : cont)
            {
                if (var.getDynamically() == "yes") /**< перевірка чи динамічно підлючається бібліотека, якщо так збільшуємо значення змінної*/
                    count++;
            }

            cout << "Количество динамически подключаемых библиотек - " << count << endl;
            break;

        }
        case 404:
        {
            flag = false;
            break;
        }
        default:
        {
            cout << "Вы такого критерия не существует" << endl;
            cout << "Введите номер критерия по которому хотите узнать количество элементов" << endl << "1 - Имя библиотеки состоит из 2х слов" << endl << "2 - Год создания" << endl << "3 - Язык програмирования" << endl << "4 - Количество динамически подключаемых библиотек" << endl;
            cin >> command;
            break;
        }
        }
        cout << "Введите номер критерия по которому хотите узнать количество элементов" << endl << "1 - Имя библиотеки состоит из 2х слов" << endl << "2 - Год создания" << endl << "3 - Язык програмирования" << endl << "4 - Количество динамически подключаемых библиотек" << endl;
        cin >> command;
    }
}
void Search(list<Capabilities> cont)
{
    int command;
    bool flag = true;
    cout << "Введите номер критерия поиск по которому хотите весли" << endl << "1 - Имя библиотеки" << endl << "2 - ID библиотеки" << endl << "3 - Расширение файла библиотеки" << endl;
    cin >> command;
    while (flag)
    {
        switch (command)
        {
        case 1:
        {
            string name;
            cout << "Введите имя искомого объекта" << endl;
            cin >> name;
            for (auto var : cont)
            {
                if (var.getName() == name)
                {
                    cout << "Вивод объекта которого вы искали" << endl;
                    Str_return(var);
                    flag = false;
                    break;
                }
            }
            break;
        }
        case 2:
        {
            int id;
            cout << "Введите ID искомого объекта" << endl;
            cin >> id;
            for (auto var : cont)
            {
                if (var.getID() == id)
                {
                    cout << "Вивод объекта которого вы искали" << endl;
                    Str_return(var);
                    flag = false;
                    break;
                }
            }
            break;

        }
        case 3:
        {
            string exp;
            cout << "Введите расширение искомого объекта" << endl;
            cin >> exp;
            for (auto var : cont)
            {
                if (var.getExpansion_file() == exp)
                {
                    cout << "Вивод объекта которого вы искали" << endl;
                    Str_return(var);
                    flag = false;
                    break;
                }
            }
            break;

        }
        default:
        {
            cout << "Вы такого критерия не существует" << endl;
            cout << "Введите номер критерия поиск по которому хотите весли" << endl << "1 - Имя библиотеки" << endl << "2 - ID библиотеки" << endl;
            cin >> command;
            break;
        }
        }
    }
}