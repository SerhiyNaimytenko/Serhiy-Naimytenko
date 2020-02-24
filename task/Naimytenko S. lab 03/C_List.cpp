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
    ifstream file (file_name);
    if (!file)
    {
        cout << "������!!! ���� �� �������." << endl;
        return 1;
    }
    int id, number_of_function, year_creating;
    string dynamically;

    for (int i = 0; i < size;i++)
    {
        file >> id >> number_of_function >>year_creating >> dynamically;
        list[i].setID(id);
        list[i].setNumber_of_function(number_of_function);
        list[i].setYear_Creating(year_creating);
        list[i].setDynamically(dynamically);
    }
    file.close();
}

void C_List::Create() // 1
{
    cout<<"���������� ��������� ������ �������" <<endl;
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
    stringstream str = Str_return(list[order-1]);
    Str_output(str,0);
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
    for (int i=0; i < size; i++)
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
    str << " " << lib.getID() << " " << lib.getNumber_of_function() << " " << lib.getYear_Creating() << " " << lib.getDynamically();
    return str;
}

void C_List::Str_output(stringstream& str,int i)const
{
    int number_of_function, year_creating, id;
    string dynamically;
    str >> id;
    str >> number_of_function;
    str >> year_creating;
    str >> dynamically;
    cout << i + 1 << "- "<< setw(3) << id << setw(15) << number_of_function << setw(19) << year_creating << setw(16) << dynamically <<endl;
}

void C_List::Output()const // 6
{
    stringstream str;
    cout << "����� �� ����� ���� ���������"<<endl;
    cout.setf(std::ios::right);
    cout <<"�" << setw(16) << "id ����������" << setw(16) << "���-�� �������" << setw(18) << "��� � ��������" << setw(30) << "���������� �� ��� ����������" << endl;
    for (int i = 0; i < size; i++)
    {
        str = Str_return(list[i]);
        Str_output(str,i);
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
    cout << "� "<< setprecision(5) << dif << " ��� ���������� ���������, ������� ����������� ������������, ������ ��� ����� ���������� ���������" << endl;
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
    file << "�" << setw(17) << "id ����������" << setw(16) << "���-�� �������" << setw(18) << "��� � ��������" << setw(30) << "���������� �� ��� ����������" << endl;
    for (int i = 0; i < size;i++)
       file << i + 1 << "- " <<setw(5) << list[i].getID() <<  setw(24) << list[i].getNumber_of_function() <<  setw(27) << list[i].getYear_Creating() <<  setw(23) << list[i].getDynamically() << endl;
    file.close();
}
 
