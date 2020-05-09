/**
 * @file C_List.cpp
 * ��������� ����� C_List
 * @author Naimytenko Serhiy
 * @version 1.0
 * @date 2020.04.05
 */
#include "C_List.h" /**< ���������� ����� C_List.h*/
#include"C_Library.h" /**< ���������� ����� C_Library.h*/

void C_List::setSize_array(const int size)
{
    this->size = size;
}

int C_List::getSize_array()const
{
    return this->size;
}
/**
 * ����� Read_file
 *
 * �������� ���� ������:
 * <ul>
 * <li> ������� ���������� � �����, ���� ������� ���������� �� ������ Distribution ��� ��������� ��</li>
 * </ul>
 * @return ������� ��������� �������� �����
 */
int C_List::Read_file(string file_name, string file_name2)
{

    ifstream file(file_name);  /**< �������� �����*/
    if (!file)  /**< �������� �� �������� ����*/
    {
        cout << "������!!! ���� �� �������." << endl;
        return 1;
    }
    ifstream file2(file_name2);  /**< �������� �����*/
    if (!file) /**< �������� �� �������� ����*/
    {
        cout << "������!!! ���� �� �������." << endl;
        return 1;
    }
    string line;
    string line2;
    for (size_t i = 0; i < size; i++)
    {
        getline(file, line); /**< ������� ����� � ����������� */
        getline(file2, line2);  /**< ������� ����� � ����������� */
        Distribution(line, line2, i);  /**< ������ ������ Distribution*/
    }
    file.close();  /**< �������� �����*/
    return 0;
}
/**
 * ����� Count_line
 *
 * �������� ���� ������:
 * <ul>
 * <li> �� ��������� ������� getline ���������� ������� �����</li>
 * </ul>
 * @return ������� ��������� �������� �����
 */
int C_List::Count_line(string file_name)
{
    size = 0;   /**< ��������� �������� ������ ������*/
    ifstream file(file_name);  /**< �������� �����*/
    if (!file)  /**< �������� �� �������� ����*/
    {
        cout << "������!!! ���� �� �������." << endl;
        return 1;
    }
    string  line;
    while (getline(file, line))  /**< ������� ������ �����, ���� ������� �� ��������� �� �����*/
    {
        size++; /**< ������� ���� �������� �������� */
    }
    file.close();  /**< �������� �����*/
    return 0;
}
/**
 * ����� Distribution
 *
 * �������� ���� ������:
 * <ul>
 * <li> ��������� ����� ��������� �� ��������� ����������� ������ � ���� �� ��� ���������� � ����� ��������� ������ </li>
 * </ul>
 * @return ����� ������� ���� void
 */
void C_List::Distribution(string line, string line2, int i)
{

    regex regular("[\\d]* [\\d]* [\\d]* (Yes|No) [A-Z�-�]+[\\w�-��-�\-|_|:|;|\.]*[ ]?([A-Z�-�]+[\\w�-��-�\-|_|:|;|\.]*)? [\\w][_]?([\\w]*)? C[\+]{0,} [.][\\w]*"); /**< �������� ���������� �����*/
    regex replace_reg1("([;]{2,})"); /**< ���������� ���������� ������ �� ���������� �������� ���������� ������ �������*/
    regex replace_reg2("([_]{2,})");
    regex replace_reg3("([-]{2,})");
    regex replace_reg4("([:]{2,})");
    regex replace_reg5("([\.]{2,})");
    C_Expansion obj_e;
    int id, number_of_function, year_creating;
    string dynamically, name, name2, line_res;
    string name_f, name_l, expansion, capabilities;
    auto res = regex_match(line, regular); /**< �������� ����� �������� �������*/
    if (res)
    {

        if (regex_search(line, replace_reg1)) /**< ���� ��������� ���������� �������� ������� ����� ����� �� ��������*/
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
        istringstream str(line); /**< ������������� ����� � ���� � �����������*/
        str >> id >> number_of_function >> year_creating >> dynamically >> name >> name2 >> name_f >> name_l >> expansion; /**< ������� ���������� � ������� ����*/
        if (expansion == "") /**< ���� ��'� ����� �������� ���������� � ������ ����� �� ������� ����� ���������� ������ */
        {
            obj_e.setName(name);
            obj_e.setDynamically(dynamically);
            obj_e.setFunction(name2);
            obj_e.setLanguage_programming(name_f);
            obj_e.setID(id);
            obj_e.setNumber_of_function(number_of_function);
            obj_e.setYear_Creating(year_creating);
            obj_e.setExpansion_file(name_l);
            Capabilities obj_c(line2, dynamically, name, id, year_creating, number_of_function, name2, name_f, obj_e); /**< �� ��������� ������������ � ����������� ��������� ������*/
            list[i] = obj_c; /**< �� ������� ��� ������ � �����*/
        }
        else /**< ���� ��'� ����� �������� ���������� � ���� ��� �� ���������� ������� �� ���������� ���������� */
        {
            name = name + " " + name2; /**< �������� ����� �������� � ���� �����*/
            obj_e.setName(name);
            obj_e.setDynamically(dynamically);
            obj_e.setFunction(name_f);
            obj_e.setLanguage_programming(name_l);
            obj_e.setID(id);
            obj_e.setNumber_of_function(number_of_function);
            obj_e.setYear_Creating(year_creating);
            obj_e.setExpansion_file(expansion);
            Capabilities obj_c(line2, dynamically, name, id, year_creating, number_of_function, name_f, name_l, obj_e); /**< �� ��������� ������������ � ����������� ��������� ������*/
            list[i] = obj_c; /**< �� ������� ��� ������ � �����*/

        }
    }

}
/**
 * ����� Create
 *
 * �������� ���� ������:
 * <ul>
 * <li> ����� ������� ������� �� ������������, ��� ��� ���� ��� �������� � ����� �� �������� ����������� ���� ������� ���������� ������� �� ��������� ������� rand �� �����-������� ������,</li>
 * <li> � �������� �� ����� ����������� ������� � ������ �������</li>
 * </ul>
 * @return ����� ������� ���� void
 */
void C_List::Create() // 1
{
    cout << "���������� ��������� ������ �������" << endl;
    int a = 0;
    int x;
    for (size_t i = 0; i < size; i++) /**< �� ��������� ����� �������� �� ������ � �����*/
    {
        srand(static_cast<unsigned int>(time(0)));
        if (i % 2 == 0) /**< ������� �� ����� � �������� ����� � ���� �����, � ���� ������ ������� �� ������� ���������� ����������� �������*/
            x = rand() % 1;
        else
            x = 2;
        if (x == 0) /**< ������ 1*/
        {
            string dynamically = "yes"; /**< ��������� ������ � ����������*/
            string name = "math" + i;
            string func = "Default";
            string lang = "default";
            string expansion = ".dll";
            string capabilities = "using this library you can do something";
            C_Expansion new_el_e(expansion, dynamically, name, 3 + i, 1999, 20, func, lang);
            Capabilities new_el_c(capabilities, dynamically, name, 3 + i, 1999, 20, func, lang, new_el_e); /**< ��������� ������� �� ��������� ������������ � ����������� */
            list[i] = new_el_c; /**< ��������� ������� � �����*/
        }
        else if (x == 1) /**< ������ 2*/
        {
            string dynamically = "no"; /**< /**< ��������� ������ � ����������*/
            string name = "string" + i;
            string func = "Default";
            string lang = "default";
            string expansion = ".a";
            string capabilities = "using this library you can do something";
            C_Expansion new_el_e(expansion, dynamically, name, 46 + i, 1998, 10, func, lang);
            Capabilities new_el_c(capabilities, dynamically, name, 46 + i, 1998, 10, func, lang, new_el_e); /**< ��������� ������� �� ��������� ������������ � ����������� */
            list[i] = new_el_c; /**< ��������� ������� � �����*/
        }
        else if (x == 2) /**< ������ 3*/
        {
            C_Expansion new_el_e;
            int id = new_el_e.getID();
            new_el_e.setID(id + 14);
            Capabilities new_el_c; /**< ��������� ������ �� ��������� ������������ �� �������������*/
            new_el_c.setID(id + 14); /**< ������� �������� �������������� ��� ���� ��� ���� �� ��������*/
            new_el_c.setExpansion(new_el_e);
            list[i] = new_el_c; /**< ��������� ������� � �����*/
        }
    }
}
/**
 * ����� Add
 *
 * �������� ���� ������:
 * <ul>
 * <li> � ����� ����������� ����� ���������� �����, ���� � ������� ������ ������������� � ����� ����� ����� � ����� ���������, ��� ���'��� � ������� ������ ����������� � ����� ���������� ����� ������������ ��� ��� ������� �� ����������� ����������</li>
 * </ul>
 * @return ����� ������� ���� void
 */
void C_List::Add(Capabilities obj_c, const int order)
{
    size++; /**< �������� ����� ������*/
    Capabilities* new_arr = new Capabilities[size]; /**< ��������� ���������� �����*/


    for (size_t i = 0, j = 0; i < size; i++) /**< ��������� ����*/
    {
        if (i != order - 1)
        {
            new_arr[i] = list[j]; /**< �������� ������ � ������ ������ � �����*/
            j++;
        }
        else
        {
            new_arr[i] = obj_c; /**< ��������� ������ ��������*/
        }
    }
    delete[] list; /**< ��������� �����*/
    list = new Capabilities[size]; /**< �������� ���'��� ��� ���������� ������*/
    for (size_t i = 0; i < size; i++) /**< ����������� ����*/
    {
        list[i] = new_arr[i];
    }
    delete[] new_arr; /**< ��������� ���������� �����*/
}
/**
 * ����� Delete
 *
 * �������� ���� ������:
 * <ul>
 * <li> � ����� ����������� ����� ���������� �����, ���� � ������� ������ ������������� � ����� ���� �������� ����� �������� �� ���������, ��� ���'��� � ������� ������ ����������� � ����� ���������� ����� ������������ ��� ��� ������� �� ����������� ����������</li>
 * </ul>
 * @return ����� ������� ���� void
 */
void C_List::Delete(const int order) // 4
{
    size--; /**< ���������� ������ ������*/
    Capabilities* new_arr = new Capabilities[size]; /**< ��������� ���������� �����*/

    cout << "������� ������� �� �������" << endl;
    stringstream str = Str_return(list[order - 1]); /**< �������� �� ����� ������� �� �����������*/
    Str_output(str, 0);

    for (size_t i = 0; i < order - 1; i++) /**< ��������� ����*/
    {
        new_arr[i] = list[i];
    }
    for (size_t i = order - 1; i < size; i++)
    {
        new_arr[i] = list[i + 1];
    }
    delete[] list; /**< ��������� �����*/
    list = new Capabilities[size]; /**< �������� ���'��� ��� ���������� ������*/
    for (size_t i = 0; i < size; i++) /**< ����������� ����*/
    {
        list[i] = new_arr[i];
    }
    delete[] new_arr;  /**< ��������� ���������� �����*/

}
/**
 * ����� Index_return
 *
 * �������� ���� ������:
 * <ul>
 * <li> ����� ��������� ������ � ����� ������������� ������� � ��������������� �� ��� ����������</li>
 * </ul>
 * @return ������� ������ ����� Capabilities
 */
Capabilities& C_List::Index_return(const int index)
{
    int id;
    for (size_t i = 0; i < size; i++) /**< ���������� ���� ����� �� ��������� �����*/
    {
        id = list[i].getID(); /**< �������� ������������� ������� ��������*/
        if (id == index)/**< ��������� ��������*/
        {
            id = i; /**< ���� ������� ��������, ������� ������ ��������*/
            i = size;/**< �������� ������ ��� ���� ��� ����� � ������*/
        }
    }
    return list[id];
}
/**
 * ����� Str_return
 *
 * �������� ���� ������:
 * <ul>
 * <li> ����� ���������� ������ � ������� � ���� ����������</li>
 * </ul>
 * @return ������� ���� � �������
 */
stringstream C_List::Str_return(Capabilities obj)const
{
    stringstream str;
    str << " " << obj.getID() << " " << obj.getNumber_of_function() << " " << obj.getYear_Creating() << " " << obj.getDynamically() << " " << obj.getName() << " " << obj.getFunction() << " " << obj.getLanguage_programming() << " " << obj.getExpansion_file();
    return str;
}
/**
 * ����� Str_output
 *
 * �������� ���� ������:
 * <ul>
 * <li> ����� �������� �� ����� ���������� ��� ������ </li>
 * </ul>
 * @return ����� ������� ���� void
 */
void C_List::Str_output(stringstream& str, int i)const
{
    cout.setf(std::ios::right);
    int number_of_function, year_creating, id;
    string dynamically, name1, name2, name_f, name_l, expansion;
    str >> id; /**< � ������ ������� ���������� � ������� ����*/
    str >> number_of_function;
    str >> year_creating;
    str >> dynamically;
    str >> name1;
    str >> name2;
    str >> name_f;
    str >> name_l;
    str >> expansion;
    if (expansion == "") /**< ���� ��'� ����� �������� ���������� � ������ ����� �� ������� ����� ���������� ������ */
        cout << i + 1 << "- " << setw(10) << id << setw(13) << number_of_function << setw(21) << year_creating << setw(20) << dynamically << setw(30) << name1 << setw(26) << name2 << setw(24) << name_f << setw(20) << name_l << endl; /**< ��������� �� �����*/
    else /**< ���� ��'� ����� �������� ���������� � ���� ��� �� ���������� ������� �� ���������� ���������� */
    {
        name1 = name1 + " " + name2;  /**< �������� ����� �������� � ���� �����*/
        cout << i + 1 << "- " << setw(10) << id << setw(13) << number_of_function << setw(21) << year_creating << setw(20) << dynamically << setw(30) << name1 << setw(26) << name_f << setw(24) << name_l << setw(20) << expansion << endl; /**< ��������� �� �����*/
    }
}
/**
 * ����� Output
 *
 * �������� ���� ������:
 * <ul>
 * <li> ����� �������� ����� �� �����</li>
 * </ul>
 * @return ����� ������� ���� void
 */
void C_List::Output()const // 6
{
    stringstream str;
    cout << "����� �� ����� ���� ��������" << endl;
    cout << "�" << setw(17) << "id ����������" << setw(16) << "���-�� �������" << setw(18) << "��� � ��������" << setw(30) << "���������� �� ��� ����������" << setw(20) << "�������� ����������" << setw(32) << "���� �� ������� ���� ����������" << setw(21) << "���� ���������������" << setw(29) << "���������� ����� �����������" << endl;
    for (size_t i = 0; i < size; i++)  /**< ���������� ���� ����� �� ��������� �����*/
    {
        str = Str_return(list[i]); /**< ��������� ����� Str_return*/
        Str_output(str, i);  /**< ��������� ����� Str_output*/
    }

}
/**
 * ����� Sort
 *
 * �������� ���� ������:
 * <ul>
 * <li> ����� ����� ����� �������� �� ���������</li>
 * </ul>
 * @return ����� ������� ���� void
 */
void C_List::Sort(func condition)
{
    Capabilities temp;  /**< ��������� ��������� �����*/
    for (size_t i = 0; i < size; i++) /**< ���������� ���� ����� �� ��������� �����*/
    {
        for (size_t j = 0; j < size; j++)
        {
            if (condition(list[i].getID(), list[j].getID())) /**< ���������� ���������� ��������, ���� ���� ���� �� ������ ������� ������*/
            {
                temp = list[i];
                list[i] = list[j]; ;
                list[j] = temp;
            }
        }
    }
}
/**
 * ����� Difference
 *
 * �������� ���� ������:
 * <ul>
 * <li> ����� ������� ������� ������� �� �������� ������������ �� ������� � ������ ���� ���� ������ �� �������� ������� ������� � �����</li>
 * </ul>
 * @return ������� ������ �� ������� ������� �� �������� ������������ �� ��������� �� �������
 */
float C_List::Difference()
{
    float count = 0;
    string y;
    for (size_t i = 0; i < size; i++) /**< ���������� ���� ����� �� ��������� �����*/
    {
        y = list[i].getDynamically();
        if (y == "yes") /**< �������� �� �������� ���������� ��������, ���� ��� �������� �������� �����*/
            count++;
    }
    float dif = size / count; /**< ��������� ������ �� ������ */
    cout << "� " << setprecision(5) << dif << " ��� ���������� ���������, ������� ����������� ������������, ������ ��� ����� ���������� ���������" << endl;/**< ����������� �������� �������� ���������� �� �����*/
    return dif;
}
/**
 * ����� Info_about_lib
 *
 * �������� ���� ������:
 * <ul>
 * <li> ����� �������� �� ����� ��� ���������� ��� ��������</li>
 * </ul>
 * @return ����� ������� ���� void
 */
void C_List::Info_about_lib()
{
    for (size_t i = 0; i < size; i++)
    {
        cout << endl << "� ����� ��������������� \"";
        cout << list[i].getLanguage_programming();
        cout << "\" ������������ ���������� " << list[i].getName() << endl;
        cout << "� ������ ���������� ���� ����� �������" << endl;
        cout << "������� - " << list[i].getFunction() << endl;
        cout << "����������� ������ ����������" << endl << list[i].getCapabilities() << endl;
    }

}
/**
 * ����� Write_file
 *
 * �������� ���� ������:
 * <ul>
 * <li> ����� ������ ���� � ����</li>
 * </ul>
 * @return ��������� �������� �����
 */
int C_List::Write_file(string file_name)
{
    ofstream file(file_name); /**< �������� �����*/
    if (!file) /**< �������� �� �������� ����*/
    {
        cout << "������!!! ���� �� �������." << endl;
        return 1;
    }
    file << "�" << setw(17) << "id ����������" << setw(16) << "���-�� �������" << setw(18) << "��� � ��������" << setw(30) << "���������� �� ��� ����������" << setw(20) << "�������� ����������" << setw(32) << "���� �� ������� ���� ����������" << setw(21) << "���� ���������������" << setw(29) << "���������� ����� �����������" << endl;
    for (size_t i = 0; i < size; i++) /**< �������� ���������� � ���� �� ��������� �����*/
        file << i + 1 << "- " << setw(10) << list[i].getID() << setw(13) << list[i].getNumber_of_function() << setw(21) << list[i].getYear_Creating() << setw(20) << list[i].getDynamically() << setw(30) << list[i].getName() << setw(26) << list[i].getFunction() << setw(24) << list[i].getLanguage_programming() << setw(20) << endl << list[i].getCapabilities() << endl;
    file.close(); /**< �������� �����*/
    return 1;
}
/**
 * ����� Check
 *
 * �������� ���� ������:
 * <ul>
 * <li> ����� �������� �� ����� �������� ������ � ���� ���� � 2 �����</li>
 * </ul>
 * @return ����� ������� ���� void
 */
void C_List::Check()
{
    regex regular("(([A-Z�-�]+[\\w�-��-�\-|_|:|;|\.]*)+( )+([A-Z�-�]+[\\w�-��-�\-|_|:|;|\.]*))");  /**< ��������� ����������� ������ ��� ���������� ����� � ����� �������*/
    string check;
    stringstream str;
    int k = 0;
    for (size_t i = 0; i < size; i++) /**< ���������� ���� ����� �� ��������� �����*/
    {
        auto check_res = list[i].getName();
        if (regex_match(check_res, regular))  /**< ����������� �� ������ ����� 2 �����*/
        {
            str = Str_return(list[i]);
            Str_output(str, k); /**< ���� ���������� �������� �������� �� ����� ������ �������*/
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

C_List:: ~C_List()/**< ��������� ����������� */
{
    delete[] list;
}