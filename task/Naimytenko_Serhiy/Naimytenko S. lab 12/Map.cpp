
#include "Conteiner.h" 
map<int, Capabilities>  Read_file(string file_name, string file_name2, int size);
int  Count_line(string file_name);
map<int, Capabilities> Distribution(string line, string line2, int i, map<int, Capabilities>);
map<int, Capabilities>  Add(map<int, Capabilities>);
map<int, Capabilities>  Delete(map<int, Capabilities>);
Capabilities Index_return(const int index, map<int, Capabilities>);
stringstream  Str_return(Capabilities obj);
void  Str_output(stringstream& str, int i);
void  Output(map<int, Capabilities>);
map<int, Capabilities> Sort(func condition, map<int, Capabilities>);
float Difference(map<int, Capabilities>);
void  Info_about_lib(map<int, Capabilities>);
int  Write_file(map<int, Capabilities>, string file_name);
void  Check(map<int, Capabilities>);

int Map()
{
    map<int, Capabilities>  conteiner;
    string file_read = "file_read.txt";
    string file_read2 = "file_read2.txt";
    string file_write = "file_write.txt";
    int size = Count_line(file_read);
    conteiner = Read_file(file_read, file_read2, size);
    if (conteiner.size() == 0)
        return 404;
    Output(conteiner);
    conteiner = Add(conteiner);
    Output(conteiner);
    conteiner = Delete(conteiner);
    Output(conteiner);
    conteiner = Sort(A_more, conteiner);
    Output(conteiner);
    conteiner = Sort(B_more, conteiner);
    Output(conteiner);
    float diff = Difference(conteiner);
    int id;
    cout << "������� ���� �������� �������� ������ ��������" << endl;
    cin >> id;
    Capabilities res_id = Index_return(id, conteiner);
    stringstream str = Str_return(res_id);
    Str_output(str, 1);
    Check(conteiner);
    Info_about_lib(conteiner);
    int res = Write_file(conteiner, file_write);
    if (res == 1)
        return 404;
    conteiner.clear();
    return 0;
}

map<int, Capabilities>  Read_file(string file_name, string file_name2, int size)
{
    map<int, Capabilities> cont;
    ifstream file(file_name);  /**< �������� �����*/
    if (!file)  /**< �������� �� �������� ����*/
    {
        cout << "������!!! ���� �� �������." << endl;
        return cont;
    }
    ifstream file2(file_name2);  /**< �������� �����*/
    if (!file) /**< �������� �� �������� ����*/
    {
        cout << "������!!! ���� �� �������." << endl;
        return cont;
    }
    string line;
    string line2;
    for (size_t i = 0; i < size; i++)
    {
        getline(file, line); /**< ������� ����� � ����������� */
        getline(file2, line2);  /**< ������� ����� � ����������� */
        cont = Distribution(line, line2, i, cont);  /**< ������ ������ Distribution*/
    }
    file.close();  /**< �������� �����*/
    return cont;
} 
map<int, Capabilities>  Distribution(string line, string line2, int i, map<int, Capabilities> cont)
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
        str >> id >> number_of_function >> year_creating >> dynamically >> name >> name2 >> name_f >> name_l >> expansion; /**< ������� ���������� � �������� �����*/
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

            cont.emplace(i, Capabilities(line2, dynamically, name, id, year_creating, number_of_function, name2, name_f, obj_e));
        }
        else /**< ���� ��'� ����� �������� ���������� � ���� ��� �� ����������� ������� �� ���������� ���������� */
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

            cont.emplace(i, Capabilities(line2, dynamically, name, id, year_creating, number_of_function, name2, name_f, obj_e));
        }
    }
    return cont;
}
map<int, Capabilities>  Add(map<int, Capabilities> cont)
{
    int index_el;
    cout << "������� ���������� ������ �������� �������� ������ �������" << endl;
    cin >> index_el;
    Capabilities add_el;
    cont.emplace(index_el, add_el);
    return cont;
}
map<int, Capabilities>  Delete(map<int, Capabilities> cont)
{
    auto it = cont.begin();
    int index_el;
    cout << "������� ���������� ������ �������� �������� ������ �������" << endl;
    cin >> index_el;
    advance(it, index_el - 1);
    cont.erase(it);
    return cont;
}
Capabilities Index_return(const int index, map<int, Capabilities> cont)
{
    int id;
    Capabilities value;
    for (auto var : cont)
    {
        id = var.second.getID(); /**< �������� ������������� ������� ��������*/
        if (id == index)/**< ��������� ��������*/
        {
            value = var.second;
        }
    }
    return value;
} 
void  Output(map<int, Capabilities> cont)
{
    stringstream str;
    int i = 0;
    cout << "����� �� ����� ���� ��������" << endl;
    cout << "�" << setw(17) << "id ����������" << setw(16) << "���-�� �������" << setw(18) << "��� � ��������" << setw(30) << "���������� �� ��� ����������" << setw(20) << "�������� ����������" << setw(32) << "���� �� ������� ���� ����������" << setw(21) << "���� ���������������" << setw(29) << "���������� ����� �����������" << endl;
    for (auto var : cont)
    {
        str = Str_return(var.second); /**< ��������� ����� Str_return*/
        Str_output(str, i);  /**< ��������� ����� Str_output*/
        i++;
    }
}
map<int, Capabilities> Sort(func condition, map<int, Capabilities> cont)
{
    Capabilities temp;  /**< ��������� ��������� �����*/
    auto it = cont.begin();
    auto it1 = cont.begin();
    for (auto var : cont)
    {
        for (auto var1 : cont)
        {
            it1 = cont.begin();
            if (condition(var.second.getID(), var1.second.getID())) /**< ���������� ����������� ��������, ���� ���� ���� �� ������ ������� ������*/
            {
                temp = var.second;
                var.second = var1.second;
                var1.second = temp;
            }
        }
    }
    return cont;
}
float Difference(map<int, Capabilities> cont)
{
    float count = 0;
    string y;
    for (auto var : cont)
    {
        y = var.second.getDynamically();
        if (y == "yes") /**< �������� �� �������� ���������� ��������, ���� ��� �������� �������� �����*/
            count++;
    }
    float dif = cont.size() / count; /**< ��������� ������ �� ������ */
    cout << "� " << setw(5) << dif << " ��� ���������� ���������, ������� ����������� ������������, ������ ��� ����� ���������� ���������" << endl;/**< ����������� ��������� �������� ���������� �� �����*/
    return dif;
}
void  Info_about_lib(map<int, Capabilities> cont)
{
    for (auto var : cont)
    {
        cout << endl << "� ����� ��������������� \"";
        cout << var.second.getLanguage_programming();
        cout << "\" ������������ ���������� " << var.second.getName() << endl;
        cout << "� ������ ���������� ���� ����� �������" << endl;
        cout << "������� - " << var.second.getFunction() << endl;
        cout << "����������� ������ ����������" << endl << var.second.getCapabilities() << endl;
    }
}
int  Write_file(map<int, Capabilities> cont, string file_name)
{
    ofstream file(file_name); /**< �������� �����*/
    if (!file) /**< �������� �� �������� ����*/
    {
        cout << "������!!! ���� �� �������." << endl;
        return 1;
    }
    int i = 0;
    file << "�" << setw(17) << "id ����������" << setw(16) << "���-�� �������" << setw(18) << "��� � ��������" << setw(30) << "���������� �� ��� ����������" << setw(20) << "�������� ����������" << setw(32) << "���� �� ������� ���� ����������" << setw(21) << "���� ���������������" << setw(29) << "���������� ����� �����������" << endl;
    for (auto var : cont)
    {
        file << i + 1 << "- " << setw(10) << var.second.getID() << setw(13) << var.second.getNumber_of_function() << setw(21) << var.second.getYear_Creating() << setw(20) << var.second.getDynamically() << setw(30) << var.second.getName() << setw(26) << var.second.getFunction() << setw(24) << var.second.getLanguage_programming() << setw(20) << endl << var.second.getCapabilities() << endl;
        i++;
    }
    file.close(); /**< �������� �����*/
    return 0;
}
void  Check(map<int, Capabilities> cont)
{
    regex regular("(([A-Z�-�]+[\\w�-��-�\-|_|:|;|\.]*)+( )+([A-Z�-�]+[\\w�-��-�\-|_|:|;|\.]*))");  /**< ��������� ����������� ������ ��� ���������� ����� � ����� �������*/
    string check;
    stringstream str;
    int k = 0;
    for (auto var : cont)
    {
        auto check_res = var.second.getName();
        if (regex_match(check_res, regular))  /**< ����������� �� ������ ����� 2 �����*/
        {
            str = Str_return(var.second);
            Str_output(str, k); /**< ���� ����������� �������� �������� �� ����� ������ �������*/
            k++;
        }
    }
}