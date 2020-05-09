/**
 * @file C_List.cpp
 * Реалізація класу C_List
 * @author Naimytenko Serhiy
 * @version 1.0
 * @date 2020.04.05
 */
#include "C_List.h" /**< підключення файлу C_List.h*/
#include"C_Library.h" /**< підключення файлу C_Library.h*/

void C_List::setSize_array(const int size)
{
    this->size = size;
}

int C_List::getSize_array()const
{
    return this->size;
}
/**
 * Метод Read_file
 *
 * Короткий опис методу:
 * <ul>
 * <li> Зчитуємо інформацію з файлу, потім предаємо інформацію до методу Distribution для подальших дій</li>
 * </ul>
 * @return повертає результат відкриття файлу
 */
int C_List::Read_file(string file_name, string file_name2)
{

    ifstream file(file_name);  /**< відкриття файлу*/
    if (!file)  /**< перевірка чи відкрився файл*/
    {
        cout << "Ошибка!!! Файл не открыто." << endl;
        return 1;
    }
    ifstream file2(file_name2);  /**< відкриття файлу*/
    if (!file) /**< перевірка чи відкрився файл*/
    {
        cout << "Ошибка!!! Файл не открыто." << endl;
        return 1;
    }
    string line;
    string line2;
    for (size_t i = 0; i < size; i++)
    {
        getline(file, line); /**< зчитуємо рядок з інформацією */
        getline(file2, line2);  /**< зчитуємо рядок з інформацією */
        Distribution(line, line2, i);  /**< виклик методу Distribution*/
    }
    file.close();  /**< закриття файлу*/
    return 0;
}
/**
 * Метод Count_line
 *
 * Короткий опис методу:
 * <ul>
 * <li> За допомогою функції getline перевіряємо кількість рядків</li>
 * </ul>
 * @return повертає результат відкриття файлу
 */
int C_List::Count_line(string file_name)
{
    size = 0;   /**< обнуляємо значення розміру масиву*/
    ifstream file(file_name);  /**< відкриття файлу*/
    if (!file)  /**< перевірка чи відкрився файл*/
    {
        cout << "Ошибка!!! Файл не открыто." << endl;
        return 1;
    }
    string  line;
    while (getline(file, line))  /**< зчитуємо кожний рядок, доки функція не натрапить на кінець*/
    {
        size++; /**< кожного разу збільшуємо значення */
    }
    file.close();  /**< закриття файлу*/
    return 0;
}
/**
 * Метод Distribution
 *
 * Короткий опис методу:
 * <ul>
 * <li> Отриманий рядок превіряємо за допомогою регулярного виразу а потім на базі інформації з рядка створюємо обьект </li>
 * </ul>
 * @return пуста функція типу void
 */
void C_List::Distribution(string line, string line2, int i)
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
            Capabilities obj_c(line2, dynamically, name, id, year_creating, number_of_function, name2, name_f, obj_e); /**< за допомогою конструктору з параметрами створюємо обьект*/
            list[i] = obj_c; /**< та заносим цей обьект в масив*/
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
            Capabilities obj_c(line2, dynamically, name, id, year_creating, number_of_function, name_f, name_l, obj_e); /**< за допомогою конструктору з параметрами створюємо обьект*/
            list[i] = obj_c; /**< та заносим цей обьект в масив*/

        }
    }

}
/**
 * Метод Create
 *
 * Короткий опис методу:
 * <ul>
 * <li> Метод створює обьекти по замовчування, але для того щоб єлементи в масиві не збігалися використаємо різну варіацію заповнення обьектів за допомогою функції rand та змінної-індекса масива,</li>
 * <li> і відповідно до цього створюються обьекти з різними данними</li>
 * </ul>
 * @return пуста функція типу void
 */
void C_List::Create() // 1
{
    cout << "Происходит заполнеие масива данными" << endl;
    int a = 0;
    int x;
    for (size_t i = 0; i < size; i++) /**< за допомогою циклу пройдемо всі комірки в масиві*/
    {
        srand(static_cast<unsigned int>(time(0)));
        if (i % 2 == 0) /**< залежно від змінної і значення змінної х буде різним, а сама зміннна відповідає за варіацію заповнення інформацією обьекта*/
            x = rand() % 1;
        else
            x = 2;
        if (x == 0) /**< варіант 1*/
        {
            string dynamically = "yes"; /**< створення змінних з інфрмацією*/
            string name = "math" + i;
            string func = "Default";
            string lang = "default";
            string expansion = ".dll";
            string capabilities = "using this library you can do something";
            C_Expansion new_el_e(expansion, dynamically, name, 3 + i, 1999, 20, func, lang);
            Capabilities new_el_c(capabilities, dynamically, name, 3 + i, 1999, 20, func, lang, new_el_e); /**< створення обьекта за допомогою конструктора з параметрами */
            list[i] = new_el_c; /**< занесення обьекту в масив*/
        }
        else if (x == 1) /**< варіант 2*/
        {
            string dynamically = "no"; /**< /**< створення змінних з інфрмацією*/
            string name = "string" + i;
            string func = "Default";
            string lang = "default";
            string expansion = ".a";
            string capabilities = "using this library you can do something";
            C_Expansion new_el_e(expansion, dynamically, name, 46 + i, 1998, 10, func, lang);
            Capabilities new_el_c(capabilities, dynamically, name, 46 + i, 1998, 10, func, lang, new_el_e); /**< створення обьекта за допомогою конструктора з параметрами */
            list[i] = new_el_c; /**< занесення обьекту в масив*/
        }
        else if (x == 2) /**< варіант 3*/
        {
            C_Expansion new_el_e;
            int id = new_el_e.getID();
            new_el_e.setID(id + 14);
            Capabilities new_el_c; /**< створюємо обьект за допомогою конструктора за замовчуванням*/
            new_el_c.setID(id + 14); /**< змінюємо значення ідентифікатору для того щоб вони не збігалися*/
            new_el_c.setExpansion(new_el_e);
            list[i] = new_el_c; /**< занесення обьекту в масив*/
        }
    }
}
/**
 * Метод Add
 *
 * Короткий опис методу:
 * <ul>
 * <li> В методі створюється новий тимчасовий масив, данні з старого масиву переписуються в новий масив разом з новим елементом, далі пам'ять зі старого масиву видаляється і знову виділяється знову переписується але вже навпаки та видаляється тимчасовий</li>
 * </ul>
 * @return пуста функція типу void
 */
void C_List::Add(Capabilities obj_c, const int order)
{
    size++; /**< збільшуємо розмір масиву*/
    Capabilities* new_arr = new Capabilities[size]; /**< створюємо тимчасовий масив*/


    for (size_t i = 0, j = 0; i < size; i++) /**< преписуємо данні*/
    {
        if (i != order - 1)
        {
            new_arr[i] = list[j]; /**< пререпис данних з одного масиву в інший*/
            j++;
        }
        else
        {
            new_arr[i] = obj_c; /**< додавання нового елементу*/
        }
    }
    delete[] list; /**< видаляємо масив*/
    list = new Capabilities[size]; /**< виділяємо пам'ять для видаленого масиву*/
    for (size_t i = 0; i < size; i++) /**< пререписуємо данні*/
    {
        list[i] = new_arr[i];
    }
    delete[] new_arr; /**< видаляємо тимчасивий масив*/
}
/**
 * Метод Delete
 *
 * Короткий опис методу:
 * <ul>
 * <li> В методі створюється новий тимчасовий масив, данні з старого масиву переписуються в новий маси вравуючи індек елементу що видаляєть, далі пам'ять зі старого масиву видаляється і знову виділяється знову переписується але вже навпаки та видаляється тимчасовий</li>
 * </ul>
 * @return пуста функція типу void
 */
void C_List::Delete(const int order) // 4
{
    size--; /**< зменьшення розміру масиву*/
    Capabilities* new_arr = new Capabilities[size]; /**< створюємо тимчасовий масив*/

    cout << "Елемент который вы удалили" << endl;
    stringstream str = Str_return(list[order - 1]); /**< виводимо на екран елемент що видаляється*/
    Str_output(str, 0);

    for (size_t i = 0; i < order - 1; i++) /**< преписуємо данні*/
    {
        new_arr[i] = list[i];
    }
    for (size_t i = order - 1; i < size; i++)
    {
        new_arr[i] = list[i + 1];
    }
    delete[] list; /**< видаляємо масив*/
    list = new Capabilities[size]; /**< виділяємо пам'ять для видаленого масиву*/
    for (size_t i = 0; i < size; i++) /**< пререписуємо данні*/
    {
        list[i] = new_arr[i];
    }
    delete[] new_arr;  /**< видаляємо тимчасивий масив*/

}
/**
 * Метод Index_return
 *
 * Короткий опис методу:
 * <ul>
 * <li> Метод знаходить елемет в якого ідентифікатор співпадає з ідентифікатором що ввів користувач</li>
 * </ul>
 * @return повертає обьект класу Capabilities
 */
Capabilities& C_List::Index_return(const int index)
{
    int id;
    for (size_t i = 0; i < size; i++) /**< проганяємо весь масив за допомогою циклу*/
    {
        id = list[i].getID(); /**< дізнаємося ідентифікатор кожного елементу*/
        if (id == index)/**< порівнюємо значення*/
        {
            id = i; /**< якщо елемент знайдено, копіюємо індекс елементу*/
            i = size;/**< збільшуємо індекс для того щоб вийти з масиву*/
        }
    }
    return list[id];
}
/**
 * Метод Str_return
 *
 * Короткий опис методу:
 * <ul>
 * <li> Метод перетворює обьект з данними в потік інформації</li>
 * </ul>
 * @return повертає потік з данними
 */
stringstream C_List::Str_return(Capabilities obj)const
{
    stringstream str;
    str << " " << obj.getID() << " " << obj.getNumber_of_function() << " " << obj.getYear_Creating() << " " << obj.getDynamically() << " " << obj.getName() << " " << obj.getFunction() << " " << obj.getLanguage_programming() << " " << obj.getExpansion_file();
    return str;
}
/**
 * Метод Str_output
 *
 * Короткий опис методу:
 * <ul>
 * <li> Метод виводить на екран інформацію про обьект </li>
 * </ul>
 * @return пуста функція типу void
 */
void C_List::Str_output(stringstream& str, int i)const
{
    cout.setf(std::ios::right);
    int number_of_function, year_creating, id;
    string dynamically, name1, name2, name_f, name_l, expansion;
    str >> id; /**< з потоку зчитуємо інформацію в відповідні змінні*/
    str >> number_of_function;
    str >> year_creating;
    str >> dynamically;
    str >> name1;
    str >> name2;
    str >> name_f;
    str >> name_l;
    str >> expansion;
    if (expansion == "") /**< якщо ім'я данної бібліотеки складається з одного слова то остання змінна залишається пустою */
        cout << i + 1 << "- " << setw(10) << id << setw(13) << number_of_function << setw(21) << year_creating << setw(20) << dynamically << setw(30) << name1 << setw(26) << name2 << setw(24) << name_f << setw(20) << name_l << endl; /**< виведення на екран*/
    else /**< якщо ім'я данної бібліотеки складається з двух слів то відповідність ззмінних та інформації зберігається */
    {
        name1 = name1 + " " + name2;  /**< складаємо назву бібліотеки в одну змінну*/
        cout << i + 1 << "- " << setw(10) << id << setw(13) << number_of_function << setw(21) << year_creating << setw(20) << dynamically << setw(30) << name1 << setw(26) << name_f << setw(24) << name_l << setw(20) << expansion << endl; /**< виведення на екран*/
    }
}
/**
 * Метод Output
 *
 * Короткий опис методу:
 * <ul>
 * <li> Метод виводить масив на екран</li>
 * </ul>
 * @return пуста функція типу void
 */
void C_List::Output()const // 6
{
    stringstream str;
    cout << "Вивод на экран всех объектов" << endl;
    cout << "№" << setw(17) << "id библиотеки" << setw(16) << "Кол-во функций" << setw(18) << "Год её создания" << setw(30) << "Динмически ли она подключена" << setw(20) << "Название библиотеки" << setw(32) << "Одна из функций этой библиотеки" << setw(21) << "Язык програмирования" << setw(29) << "Расширение файла библиоткеки" << endl;
    for (size_t i = 0; i < size; i++)  /**< проганяємо весь масив за допомогою циклу*/
    {
        str = Str_return(list[i]); /**< викликаємо метод Str_return*/
        Str_output(str, i);  /**< викликаємо метод Str_output*/
    }

}
/**
 * Метод Sort
 *
 * Короткий опис методу:
 * <ul>
 * <li> Метод сортує масив відповідно до аргументу</li>
 * </ul>
 * @return пуста функція типу void
 */
void C_List::Sort(func condition)
{
    Capabilities temp;  /**< створення тимчасової змінної*/
    for (size_t i = 0; i < size; i++) /**< проганяємо весь масив за допомогою циклу*/
    {
        for (size_t j = 0; j < size; j++)
        {
            if (condition(list[i].getID(), list[j].getID())) /**< перевіряємо відповідність елементів, якщо вона вірна то міняємо елементі місцями*/
            {
                temp = list[i];
                list[i] = list[j]; ;
                list[j] = temp;
            }
        }
    }
}
/**
 * Метод Difference
 *
 * Короткий опис методу:
 * <ul>
 * <li> Метод визначає кількість кібліотек що динамічно підключаються та порівнює в скільки разів вона меньше ніж загальна кількість бібліотек в масиві</li>
 * </ul>
 * @return повертає різницю між кількістю бібліотек що динамічно підключаються та загальною іх кількість
 */
float C_List::Difference()
{
    float count = 0;
    string y;
    for (size_t i = 0; i < size; i++) /**< проганяємо весь масив за допомогою циклу*/
    {
        y = list[i].getDynamically();
        if (y == "yes") /**< перевірка чи динамічно підлючається бібліотека, якщо так збільшуємо значення змінної*/
            count++;
    }
    float dif = size / count; /**< визначаємо частку від ділення */
    cout << "В " << setprecision(5) << dif << " раз количество библиотек, которые динамически подключаются, меньше чем общее количество библиотек" << endl;/**< повідомляємо відмінність виводячи інформацію на екран*/
    return dif;
}
/**
 * Метод Info_about_lib
 *
 * Короткий опис методу:
 * <ul>
 * <li> Метод виводить на екран всю інформацію про бібліотеки</li>
 * </ul>
 * @return пуста функція типу void
 */
void C_List::Info_about_lib()
{
    for (size_t i = 0; i < size; i++)
    {
        cout << endl << "В языке програмирования \"";
        cout << list[i].getLanguage_programming();
        cout << "\" используется библиотека " << list[i].getName() << endl;
        cout << "В данной библиотеке есть такая функция" << endl;
        cout << "Функция - " << list[i].getFunction() << endl;
        cout << "Возможности данной библиотеки" << endl << list[i].getCapabilities() << endl;
    }

}
/**
 * Метод Write_file
 *
 * Короткий опис методу:
 * <ul>
 * <li> Метод записує данні у файл</li>
 * </ul>
 * @return результат відкриття файлу
 */
int C_List::Write_file(string file_name)
{
    ofstream file(file_name); /**< відкриття файлу*/
    if (!file) /**< перевірка чи відкрився файл*/
    {
        cout << "Ошибка!!! Файл не открыто." << endl;
        return 1;
    }
    file << "№" << setw(17) << "id библиотеки" << setw(16) << "Кол-во функций" << setw(18) << "Год её создания" << setw(30) << "Динмически ли она подключена" << setw(20) << "Название библиотеки" << setw(32) << "Одна из функций этой библиотеки" << setw(21) << "Язык програмирования" << setw(29) << "Расширение файла библиоткеки" << endl;
    for (size_t i = 0; i < size; i++) /**< записуємо інформацію у файл за допомогою циклу*/
        file << i + 1 << "- " << setw(10) << list[i].getID() << setw(13) << list[i].getNumber_of_function() << setw(21) << list[i].getYear_Creating() << setw(20) << list[i].getDynamically() << setw(30) << list[i].getName() << setw(26) << list[i].getFunction() << setw(24) << list[i].getLanguage_programming() << setw(20) << endl << list[i].getCapabilities() << endl;
    file.close(); /**< закриття файлу*/
    return 1;
}
/**
 * Метод Check
 *
 * Короткий опис методу:
 * <ul>
 * <li> Метод виводить на екран елементи масиву в назві яких є 2 слова</li>
 * </ul>
 * @return пуста функція типу void
 */
void C_List::Check()
{
    regex regular("(([A-ZА-Я]+[\\wА-Яа-я\-|_|:|;|\.]*)+( )+([A-ZА-Я]+[\\wА-Яа-я\-|_|:|;|\.]*))");  /**< створення регулярного виразу для визначення назви з двома словами*/
    string check;
    stringstream str;
    int k = 0;
    for (size_t i = 0; i < size; i++) /**< проганяємо весь масив за допомогою циклу*/
    {
        auto check_res = list[i].getName();
        if (regex_match(check_res, regular))  /**< преревіряємо чи містить назва 2 слова*/
        {
            str = Str_return(list[i]);
            Str_output(str, k); /**< якщо відповідність знайдена виводимо на екран данний елемент*/
            k++;
        }
    }
}


Capabilities C_List::operator[] (int i)
{
    if (size > i)
        return list[i];
}

ostream&  operator<< (ostream& output, const Capabilities& obj)
{
    C_List o;
    stringstream temp;
    temp = o.Str_return(obj);
    output << temp.str();
    return output;
}


ofstream&  operator<< (ofstream& output, const Capabilities  obj)
{
    C_List o;
    stringstream temp;
    temp = o.Str_return(obj);
        output << temp.str();
    return output;
}

istream&  operator>> (istream& input, Capabilities& obj)
{
    obj.input(input);
    return input;
} 

C_List:: ~C_List()/**< Реалізація деструктора */
{
    delete[] list;
}