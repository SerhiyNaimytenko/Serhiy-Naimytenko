#include "C_Library.h"
#include "C_List.h"
#include "Builder.h" 

void C_List::setSize_array(const int size)
{
    this->size = size;
}

int C_List::getSize_array()const
{
    return this->size;
}

int C_List::Read_file(string file_name)
{

    ifstream file(file_name);
    if (!file)
    {
        cout << "������!!! ���� �� �������." << endl;
        return 1;
    }
    string line;
    for (int i = 0; i < size; i++)
    {
        getline(file, line);
        istringstream str(line);
        list[i] = Distribution(line);
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
        cout << "������!!! ���� �� �������." << endl;
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
 
C_Library C_List::Distribution(string line)
{
    regex regular("([\\d]* [\\d]* [\\d]* (Yes|No) [A-Z�-�]+[\\w�-��-�\-|_|:|;|\.]*[ ]?([A-Z�-�]+[\\w�-��-�\-|_|:|;|\.]*)?)");
    regex replace_reg1("([;]{2,})");
    regex replace_reg2("([_]{2,})");
    regex replace_reg3("([-]{2,})");
    regex replace_reg4("([:]{2,})");
    regex replace_reg5("([\.]{2,})");
    int id, number_of_function, year_creating;
     string dynamically, name=" ", name2=" ",line_res;
    int res = regex_match(line, regular);
    if ( res )
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
            name = name + "_" + name2;
        C_Library new_el(dynamically, name, id, year_creating, number_of_function);
        return new_el;
    }
    C_Library new_el;
    return new_el;

}

void C_List::Create() // 1
{
    cout << "���������� ��������� ������ �������" << endl;
    for (int i = 0; i < size; i++)
        list[i] = New_Lib(i + 1);
}

void C_List::Add(C_Library lib, const int order)  // 3
{
    size++;
    C_Library* new_list = new C_Library[size];

    for (int i = 0, j = 0; i < size; i++)
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
    for (int i = 0; i < size; i++)
        list[i] = new_list[i];
    delete[] new_list;
}

void C_List::Delete(const int order) // 4
{
    size--;
    C_Library* new_list = new C_Library[size];

    cout << "������� ������� �� �������" << endl;
    stringstream str = Str_return(list[order - 1]);
    Str_output(str, 0);
    for (int i = 0; i < order - 1; i++)
        new_list[i] = list[i];
    for (int i = order - 1; i < size; i++)
        new_list[i] = list[i + 1];
    delete[] list;
    list = new C_Library[size];
    for (int i = 0; i < size; i++)
        list[i] = new_list[i];
    delete[] new_list;

}

C_Library& C_List::Index_return(const int index)
{
    int id;
    for (int i = 0; i < size; i++)
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
    string dynamically,name;
    str >> id;
    str >> number_of_function;
    str >> year_creating;
    str >> dynamically;
    str >> name;
    cout << i + 1 << "- " << setw(10) << id << setw(13) << number_of_function << setw(21) << year_creating << setw(20) << dynamically << setw(29) << name << endl;
}

void C_List::Output()const // 6
{
    stringstream str;
    cout << "����� �� ����� ���� ��������" << endl;
    cout.setf(std::ios::right);
    cout << "�" << setw(17) << "id ����������" << setw(16) << "���-�� �������" << setw(18) << "��� � ��������" << setw(30) << "���������� �� ��� ����������" << setw(20) << "�������� ����������" << endl;
    for (int i = 0; i < size; i++)
    {
        str = Str_return(list[i]);
        Str_output(str, i);
    }

}

float C_List::Difference()
{
    int count = 0;
    string y;
    for (int i = 0; i < size; i++)
    {
        y = list[i].getDynamically();
        if (y == "yes")
            count++;
    }
    float dif = (float)size / (float)count;
    cout << "� " << setprecision(5) << dif << " ��� ���������� ���������, ������� ����������� ������������, ������ ��� ����� ���������� ���������" << endl;
    return dif;
}

int C_List::Write_file(string file_name)
{
    ofstream file(file_name);
    if (!file)
    {
        cout << "������!!! ���� �� �������." << endl;
        return 1;
    }
    file << "�" << setw(17) << "id ����������" << setw(16) << "���-�� �������" << setw(18) << "��� � ��������" << setw(30) << "���������� �� ��� ����������" << setw(17) <<"�������� ����������" <<endl;
    for (int i = 0; i < size; i++)
        file << i + 1 << "- " << setw(5) << list[i].getID() << setw(24) << list[i].getNumber_of_function() << setw(27) << list[i].getYear_Creating() << setw(23) << list[i].getDynamically() << setw(23) << list[i].getName() << endl;
    file.close();
}

void C_List::Check()
{
    regex regular ("(([A-Z�-�]+[\\w�-��-�\-|_|:|;|\.]*)+(_)+([A-Z�-�]+[\\w�-��-�\-|_|:|;|\.]*))"); 
    string check;
    stringstream str;
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        check = list[i].getDynamically() + " " + list[i].getName();
            if (regex_search(check, regular))
            {
                  str = Str_return(list[i]);
                  Str_output(str,k);
                  cout << endl;
                  k++;

            }

                
    }
}

C_List:: ~C_List()
{
    delete[] list;
}