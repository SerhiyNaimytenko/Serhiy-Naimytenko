#include "C_Heir_list.h"

void C_Heir_list::setSize_array(const int size)
{
    this->size = size;
}

int C_Heir_list::getSize_array()const
{
    return this->size;
}

int C_Heir_list::Read_file(string file_name)
{
    ifstream file(file_name);
    if (!file)
    {
        cout << "Ошибка!!! Файл не открыто." << endl;
        return 1;
    }
    string line;

    for (int i = 0; i < size; i++)
    {
        file >> line;
        list[i].setExpansion_file(line);
    }
    file.close();
    return 0;
}

void C_Heir_list::Output_index(C_Expansion el)const 
{
    cout << setw(17)<< el.getExpansion_file() << endl;
}

void C_Heir_list::Output()const
{
    cout << "Вывод на экран разширений файлов" << endl;
    for (int i = 0; i < size; i++)
        Output_index(list[i]);
}

void C_Heir_list::Add(C_Expansion new_el,int order)
{
    size++;
    C_Expansion* new_list = new C_Expansion[size];

    for (size_t i = 0, j = 0; i < size; i++)
    {
        if (i != order - 1)
        {
            new_list[i] = list[j];
            j++;
        }
        else
            new_list[i] = new_el;
    }
    delete[] list;
    list = new C_Expansion[size];
    for (size_t i = 0; i < size; i++)
        list[i] = new_list[i];
    delete[] new_list;
}

void C_Heir_list::Delete(int order)
{
    size--;
    C_Expansion* new_list = new C_Expansion[size];
    for (size_t i = 0; i < order; i++)
        new_list[i] = list[i];
    for (size_t i = order; i < size; i++)
        new_list[i] = list[i + 1];
    delete[] list;
    list = new C_Expansion[size];
    for (size_t i = 0; i < size; i++)
        list[i] = new_list[i];
    delete[] new_list;
}