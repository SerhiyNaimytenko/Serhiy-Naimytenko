#include "Conteiner.h"  

int Interface();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    int res = Interface();
    if (res == 1)
        return 1;
    return 0;
}

int Interface()
{

    int command;
    cout << "Введите команду котора соответствует контейнеру" << endl << "1 - vector " << endl << "2 - list " << endl << "3 - set " << endl << "4 - map " << endl << "0 - завершение роботы програмы " << endl;
    cin >> command;
    while (command != 0)
    {
        switch (command)
        {
        case 1:
            command = Vector();
            if (_CrtDumpMemoryLeaks())
                cout << endl << "Есть утечка памяти" << endl;
            else
                cout << endl << "Нет утечки памяти" << endl;
            break;
        case 2:
            command = List();
            if (_CrtDumpMemoryLeaks())
                cout << endl << "Есть утечка памяти" << endl;
            else
                cout << endl << "Нет утечки памяти" << endl;
            break;
        case 3:
            command = Set();
            if (_CrtDumpMemoryLeaks())
                cout << endl << "Есть утечка памяти" << endl;
            else
                cout << endl << "Нет утечки памяти" << endl;
            break;
        case 4:
            command = Map();
            if (_CrtDumpMemoryLeaks())
                cout << endl << "Есть утечка памяти" << endl;
            else
                cout << endl << "Нет утечки памяти" << endl;
            break;
        default:
            cout << "Вы ошиблись в выборе, попробуйте еще раз" << endl;
            break;
        }
        if (command == 404)
            return 1;

        cout << "Введите команду котора соответствует контейнеру" << endl << "1 - vector " << endl << "2 - list " << endl << "3 - set " << endl << "4 - map " << endl << "0 - завершение роботы програмы " << endl;
        cin >> command;
    }
    return 0;
}



int  Count_line(string file_name)
{
    int size = 0;   /**< обнуляємо значення розміру масиву*/
    ifstream file(file_name);  /**< відкриття файлу*/
    if (!file)  /**< перевірка чи відкрився файл*/
    {
        cout << "Ошибка!!! Файл не открыто." << endl;
        return 0;
    }
    string  line;
    while (getline(file, line))  /**< зчитуємо кожний рядок, доки функція не натрапить на кінець*/
    {
        size++; /**< кожного разу збільшуємо значення */
    }
    file.close();  /**< закриття файлу*/
    return size;
}

void  Str_output(stringstream& str, int i)
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
        cout << i << " - " << setw(10) << id << setw(13) << number_of_function << setw(21) << year_creating << setw(20) << dynamically << setw(30) << name1 << setw(26) << name2 << setw(24) << name_f << setw(20) << name_l << endl; /**< виведення на екран*/
    else /**< якщо ім'я данної бібліотеки складається з двух слів то відповідність ззмінних та інформації зберігається */
    {
        name1 = name1 + " " + name2;  /**< складаємо назву бібліотеки в одну змінну*/
        cout << i << " - " << setw(10) << id << setw(13) << number_of_function << setw(21) << year_creating << setw(20) << dynamically << setw(30) << name1 << setw(26) << name_f << setw(24) << name_l << setw(20) << expansion << endl; /**< виведення на екран*/
    }
}
void  Str_return(Capabilities obj)
{
    stringstream str;
    str << " " << obj.getID() << " " << obj.getNumber_of_function() << " " << obj.getYear_Creating() << " " << obj.getDynamically() << " " << obj.getName() << " " << obj.getFunction() << " " << obj.getLanguage_programming() << " " << obj.getExpansion_file();
    Str_output(str, 1);

}