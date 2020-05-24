
#include "Conteiner.h" 

class Funct
{
private:

public:
    bool operator()(Capabilities& obj1, Capabilities& obj2)
    {
        return obj1 < obj2;
    }
};

map<int, vector<Capabilities>>  Read_file(string file_name, string file_name2, int size);
map<int, vector<Capabilities>> Distribution(string line, string line2, int i, map<int, vector<Capabilities>>);
map<int, vector<Capabilities>>  Add(map<int, vector<Capabilities>>);
map<int, vector<Capabilities>>  Delete(map<int, vector<Capabilities>>);
Capabilities Index_return(const int index, map<int, vector<Capabilities>>);
void  Output(map<int, vector<Capabilities>>);
float Difference(map<int, vector<Capabilities>>);
void  Info_about_lib(map<int, vector<Capabilities>>);
int  Write_file(map<int, vector<Capabilities>>, string file_name);
void  Check(map<int, vector<Capabilities>>);
void Criterion(map<int, vector<Capabilities>>);
void Search(map<int, vector<Capabilities>>);
map<int, vector<Capabilities>> Merger_map(map<int, vector<Capabilities>>);
map<int, vector<Capabilities>> Sort(map<int, vector<Capabilities>> cont);

int Map()
{

    map<int, vector<Capabilities>>  conteiner;
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
    float diff = Difference(conteiner);
    int id;
    cout << "������� ���� �������� �������� ������ ��������" << endl;
    cin >> id;
    Capabilities res_id = Index_return(id, conteiner);
    cout << "����� �������� ������� �� �����" << endl;
    Str_return(res_id);
    cout << "����� �������� � �������� ������� 2 �����" << endl;
    Check(conteiner);

    Info_about_lib(conteiner);
    Criterion(conteiner);
    Search(conteiner);
    conteiner = Merger_map(conteiner);
    Output(conteiner);
    conteiner = Sort(conteiner);
    Output(conteiner);
    int res = Write_file(conteiner, file_write);
    if (res == 1)
        return 404;
    conteiner.clear();
    return 0;
}

map<int, vector<Capabilities>>  Read_file(string file_name, string file_name2, int size)
{
    map<int, vector<Capabilities>> cont;
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
map<int, vector<Capabilities>>  Distribution(string line, string line2, int i, map<int, vector<Capabilities>> cont)
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
            vector<Capabilities> arr;
            arr.emplace_back(Capabilities(line2, dynamically, name, id, year_creating, number_of_function, name2, name_f, obj_e));
            cont.emplace(i, arr);
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
            vector<Capabilities> arr;
            arr.emplace_back(Capabilities(line2, dynamically, name, id, year_creating, number_of_function, name2, name_f, obj_e));
            cont.emplace(i, arr);
        }
    }
    return cont;
}
map<int, vector<Capabilities>>  Add(map<int, vector<Capabilities>> cont)
{
    int index_el;
    cout << "������� ���������� ������ �������� �������� ������ ��������" << endl;
    cin >> index_el;
    Capabilities add_el;
    index_el--;
    if (index_el < cont.size())
    {
        auto It = cont.begin();

        advance(It, index_el);
        pair<int, vector<Capabilities>> cop;
        cop = *It;
        vector<Capabilities> new_c;
        int size = cop.second.size();
        for (int i = 0; i < size; i++)
        {
            new_c.emplace_back(cop.second[i]);
        }
        new_c.emplace_back(add_el);
        cont.at(index_el) = new_c;
    }
    else
    {
        vector<Capabilities> new_c;
        new_c.emplace_back(add_el);
        cont.emplace(index_el, new_c);
    }

    return cont;
}
map<int, vector<Capabilities>>  Delete(map<int, vector<Capabilities>> cont)
{
    auto it = cont.begin();
    int index_el;
    cout << "������� ���������� ������ �������� �������� ������ �������" << endl;
    cin >> index_el;
    advance(it, index_el - 1);
    cont.erase(it);
    return cont;
}
Capabilities Index_return(const int index, map<int, vector<Capabilities>> cont)
{
    int id;
    Capabilities value;
    for (auto var : cont)
    {
        int size = var.second.size();
        for (int i = 0; i < size; i++)
        {
            id = var.second[i].getID(); /**< �������� ������������� ������� ��������*/
            if (id == index)/**< ��������� ��������*/
            {
                value = var.second[i];
            }
        }
    }
    return value;
}
void  Output(map<int, vector<Capabilities>> cont)
{
    stringstream str;
    int i = 0;
    cout << "����� �� ����� ���� ��������" << endl;
    cout << "�" << setw(17) << "id ����������" << setw(16) << "���-�� �������" << setw(18) << "��� � ��������" << setw(30) << "���������� �� ��� ����������" << setw(20) << "�������� ����������" << setw(32) << "���� �� ������� ���� ����������" << setw(21) << "���� ���������������" << setw(29) << "���������� ����� �����������" << endl;
    for_each(cont.begin(), cont.end(), [](pair<int, vector<Capabilities>> obj)
        {
            int size = obj.second.size();
            for (int i = 0; i < size; i++)
            {
                stringstream str;
                str << " " << obj.second[i].getID() << " " << obj.second[i].getNumber_of_function() << " " << obj.second[i].getYear_Creating() << " " << obj.second[i].getDynamically() << " " << obj.second[i].getName() << " " << obj.second[i].getFunction() << " " << obj.second[i].getLanguage_programming() << " " << obj.second[i].getExpansion_file();
                Str_output(str, obj.first);
            }
        });

}
float Difference(map<int, vector<Capabilities>> cont)
{
    float count = 0;
    string y;
    for (auto var : cont)
    {
        int size = sizeof(var.second) / sizeof(Capabilities);
        for (int i = 0; i < size; i++)
        {
            y = var.second[i].getDynamically();
            if (y == "yes") /**< �������� �� �������� ���������� ��������, ���� ��� �������� �������� �����*/
                count++;
        }
    }
    float dif = cont.size() / count; /**< ��������� ������ �� ������ */
    cout << "� " << setw(5) << dif << " ��� ���������� ���������, ������� ����������� ������������, ������ ��� ����� ���������� ���������" << endl;/**< ����������� �������� �������� ���������� �� �����*/
    return dif;
}
void  Info_about_lib(map<int, vector<Capabilities>> cont)
{
    for (auto var : cont)
    {
        int size = var.second.size();
        for (int i = 0; i < size; i++)
        {
            cout << endl << "� ����� ��������������� \"";
            cout << var.second[i].getLanguage_programming();
            cout << "\" ������������ ���������� " << var.second[i].getName() << endl;
            cout << "� ������ ���������� ���� ����� �������" << endl;
            cout << "������� - " << var.second[i].getFunction() << endl;
            cout << "����������� ������ ����������" << endl << var.second[i].getCapabilities() << endl;
        }
    }
}
int  Write_file(map<int, vector<Capabilities>> cont, string file_name)
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
        int size = var.second.size();
        for (int i = 0; i < size; i++)
        {
            file << i + 1 << "- " << setw(10) << var.second[i].getID() << setw(13) << var.second[i].getNumber_of_function() << setw(21) << var.second[i].getYear_Creating() << setw(20) << var.second[i].getDynamically() << setw(30) << var.second[i].getName() << setw(26) << var.second[i].getFunction() << setw(24) << var.second[i].getLanguage_programming() << setw(20) << endl << var.second[i].getCapabilities() << endl;
            i++;
        }
    }
    file.close(); /**< �������� �����*/
    return 0;
}
void  Check(map<int, vector<Capabilities>> cont)
{
    regex regular("(([A-Z�-�]+[\\w�-��-�\-|_|:|;|\.]*)+( )+([A-Z�-�]+[\\w�-��-�\-|_|:|;|\.]*))");  /**< ��������� ����������� ������ ��� ���������� ����� � ����� �������*/
    string check;
    stringstream str;
    int k = 0;
    Capabilities obj;
    for (auto var : cont)
    {
        int size = var.second.size();
        for (int i = 0; i < size; i++)
        {
            auto check_res = var.second[i].getName();
            if (regex_match(check_res, regular))  /**< ����������� �� ������ ����� 2 �����*/
            {
                obj = var.second[i];
                Str_return(obj);

                k++;
            }
        }
    }
}
void Criterion(map<int, vector<Capabilities>> cont)
{
    int command, count;
    bool flag = true;
    cout << "������� ����� �������� �� �������� ������ ������ ���������� ���������" << endl << "1 - ��� ���������� ������� �� 2� ����" << endl << "2 - ��� ��������" << endl << "3 - ���� ���������������" << endl << "4 - ���������� ����������� ������������ ���������" << endl << "404 - ���������� ������ ���������� �� ���������" << endl;
    cin >> command;
    while (flag)
    {
        count = 0;
        switch (command)
        {
        case 1:
        {
            regex regular("(([A-Z�-�]+[\\w�-��-�\-|_|:|;|\.]*)+( )+([A-Z�-�]+[\\w�-��-�\-|_|:|;|\.]*))");
            for (auto var : cont)
            {
                int size = var.second.size();
                for (int i = 0; i < size; i++)
                {
                    auto check_res = var.second[i].getName();
                    if (regex_match(check_res, regular))  /**< ����������� �� ������ ����� 2 �����*/
                    {
                        count++;
                    }
                }
            }
            cout << "���������� ����������, � �������� ������� 2 ����� - " << count << endl;
            break;
        }
        case 2:
        {

            int year;
            cout << "������� ��� ��������" << endl;
            cin >> year;
            for (auto var : cont)
            {
                int size = var.second.size();
                for (int i = 0; i < size; i++)
                {
                    if (var.second[i].getYear_Creating() == year)  /**< ����������� �� ������ ����� 2 �����*/
                    {
                        count++;
                    }
                }
            }

            cout << "���������� ����������" << year << " ���� �������� - " << count << endl;
            break;

        }
        case 3:
        {
            cout << "1 - ���� �, 2 - �++" << endl;
            cin >> command;
            if (command == 1)
            {
                for (auto var : cont)
                {
                    int size = var.second.size();
                    for (int i = 0; i < size; i++)
                    {
                        if (var.second[i].getLanguage_programming() == "C")  /**< ����������� �� ������ ����� 2 �����*/
                        {
                            count++;
                        }
                    }
                }
                cout << "���������� ���������, ��������� �� ����� ��������������� � - " << count << endl;
            }
            else
            {
                for (auto var : cont)
                {
                    int size = var.second.size();
                    for (int i = 0; i < size; i++)
                    {
                        if (var.second[i].getLanguage_programming() == "C++")  /**< ����������� �� ������ ����� 2 �����*/
                        {
                            count++;
                        }
                    }
                }
                cout << "���������� ���������, ��������� �� ����� ��������������� �++ - " << count << endl;
            }
            break;

        }
        case 4:
        {

            for (auto var : cont)
            {
                int size = var.second.size();
                for (int i = 0; i < size; i++)
                {
                    if (var.second[i].getDynamically() == "yes") /**< �������� �� �������� ���������� ��������, ���� ��� �������� �������� �����*/
                        count++;
                }
            }

            cout << "���������� ����������� ������������ ��������� - " << count << endl;
            break;

        }
        case 404:
        {
            flag = false;
            break;
        }

        default:
        {
            cout << "�� ������ �������� �� ����������" << endl;
            cout << "������� ����� �������� �� �������� ������ ������ ���������� ���������" << endl << "1 - ��� ���������� ������� �� 2� ����" << endl << "2 - ��� ��������" << endl << "3 - ���� ���������������" << endl << "4 - ���������� ����������� ������������ ���������" << endl << "404 - ���������� ������ ���������� �� ���������" << endl;
            cin >> command;
            break;
        }
        }
        if (flag)
        {
            cout << "������� ����� �������� �� �������� ������ ������ ���������� ���������" << endl << "1 - ��� ���������� ������� �� 2� ����" << endl << "2 - ��� ��������" << endl << "3 - ���� ���������������" << endl << "4 - ���������� ����������� ������������ ���������" << endl << "404 - ���������� ������ ���������� �� ���������" << endl;
            cin >> command;
        }
    }
}
void Search(map<int, vector<Capabilities>> cont)
{
    int command;
    bool flag = true;
    cout << "������� ����� �������� ����� �� �������� ������ �����" << endl << "1 - ��� ����������" << endl << "2 - ID ����������" << endl << "3 - ���������� ����� ����������" << endl;
    cin >> command;
    while (flag)
    {
        switch (command)
        {
        case 1:
        {
            string name;
            cout << "������� ��� �������� �������" << endl;
            cin >> name;
            for (auto var : cont)
            {
                int size = var.second.size();
                for (int i = 0; i < size; i++)
                {
                    if (var.second[i].getName() == name)
                    {
                        cout << "����� ������� �������� �� ������" << endl;
                        Str_return(var.second[i]);
                        flag = false;
                        break;
                    }

                }
            }
            break;
        }
        case 2:
        {
            int id;
            cout << "������� ID �������� �������" << endl;
            cin >> id;
            for (auto var : cont)
            {
                int size = var.second.size();
                for (int i = 0; i < size; i++)
                {
                    if (var.second[i].getID() == id)
                    {
                        cout << "����� ������� �������� �� ������" << endl;
                        Str_return(var.second[i]);
                        flag = false;
                        break;
                    }
                }
            }
            break;

        }
        case 3:
        {
            string exp;
            cout << "������� ���������� �������� �������" << endl;
            cin >> exp;
            for (auto var : cont)
            {
                int size = var.second.size();
                for (int i = 0; i < size; i++)
                {
                    if (var.second[i].getExpansion_file() == exp)
                    {
                        cout << "����� ������� �������� �� ������" << endl;
                        Str_return(var.second[i]);
                        flag = false;
                        break;
                    }
                }
            }
            break;

        }
        default:
        {
            cout << "�� ������ �������� �� ����������" << endl;
            cout << "������� ����� �������� ����� �� �������� ������ �����" << endl << "1 - ��� ����������" << endl << "2 - ID ����������" << endl << "3 - ���������� ����� ����������" << endl;
            cin >> command;
            break;
        }
        }
    }
} 
map<int, vector<Capabilities>> Merger_map(map<int, vector<Capabilities>> cont)
{
    int q, size;
    cout << "������� ������ ������ ���������� m��" << endl;
    cin >> size;
    map<int, vector<Capabilities>> maP;
    for (size_t i = 0; i < size; i++) /**< �� ��������� ����� �������� �� ������ � �����*/
    {
        srand(static_cast<unsigned int>(time(0)));
        if (i % 2 == 0) /**< ������� �� ����� � �������� ����� � ���� �����, � ���� ������ ������� �� ������� ���������� ����������� �������*/
            q = rand() % 1;
        else
            q = 2;
        if (q == 0) /**< ������ 1*/
        {
            string dynamically = "yes"; /**< ��������� ������ � ����������*/
            string name = "math" + i;
            string func = "Default";
            string lang = "default";
            string expansion = ".dll";
            string capabilities = "using this library you can do something";
            C_Expansion new_el_e(expansion, dynamically, name, 3 + i, 1999, 20, func, lang);
            vector<Capabilities> arr;
            arr.emplace_back(Capabilities(capabilities, dynamically, name, 3 + i, 1999, 20, func, lang, new_el_e));
            maP.emplace(i, arr);
        }
        else if (q == 1) /**< ������ 2*/
        {
            string dynamically = "no"; /**< /**< ��������� ������ � ����������*/
            string name = "string" + i;
            string func = "Default";
            string lang = "default";
            string expansion = ".a";
            string capabilities = "using this library you can do something";
            C_Expansion new_el_e(expansion, dynamically, name, 46 + i, 1998, 10, func, lang);
            vector<Capabilities> arr;
            arr.emplace_back(Capabilities(capabilities, dynamically, name, 46 + i, 1998, 10, func, lang, new_el_e));
            maP.emplace(i, arr);
        }
        else if (q == 2) /**< ������ 3*/
        {
            C_Expansion new_el_e;
            int id = new_el_e.getID();
            new_el_e.setID(id + 14);
            Capabilities  new_el_c; /**< ��������� ������ �� ��������� ������������ �� �������������*/
            new_el_c.setID(id + 14); /**< ������� �������� �������������� ��� ���� ��� ���� �� ��������*/
            new_el_c.setExpansion(new_el_e);
            vector<Capabilities> arr;
            arr.emplace_back(new_el_c);
            maP.emplace(i, arr);
        }
    }
    int i = 0, j = 0, check = 0;
    for (auto var1 : cont)
    {
        j = 0;
        for (auto var2 : maP)
        {

            check = 0;
            if (var1.first == var2.first)
            {
                int size = var1.second.size();
                for (int k = 0; k < size; k++)
                {
                    if (var1.second[k].getName() == var2.second[0].getName())
                        check++;
                }
                if (check == 0)
                {
                    vector<Capabilities> new_arr;
                    for (int k = 0; k < size; k++)
                    {
                        new_arr.emplace_back(var1.second[k]);
                    }
                    new_arr.emplace_back(var2.second[0]);
                    cont.at(j) = new_arr;

                }
            }
            j++;
        }
        i++;
    }
    int one = 1, conut = 0;
    j = 0;
    for (auto var1 : maP)
    {

        conut = 0;
        for (auto var2 : cont)
        {
            if (var1.first == var2.first)
                conut++;
        }
        if (conut == 0)
        {
            vector<Capabilities> new_arr;
            new_arr.emplace_back(var1.second[0]);//
            cont.emplace(j, new_arr);//   
        }
        j++;
    }
    maP.clear();
    return cont;
}
map<int, vector<Capabilities>> Sort(map<int, vector<Capabilities>> cont)
{
    Funct functor;
    vector<Capabilities> vec;
    for (auto var : cont)
    {
        int size = var.second.size();
        for (int i = 0; i < size; i++)
        {
            vec.emplace_back(var.second[i]);
        }
    }

    sort(vec.begin(), vec.end(), functor);
    int size = cont.size();
    int i = 0, j = 0;
    for (auto var : cont)
    {
        vector<Capabilities> new_arr;
        int size1 = var.second.size();
        for (int k = 0; k < size1; k++)
        {
            new_arr.emplace_back(vec[j++]);
        } 
        cont.at(i) = new_arr; 
        i++;
    }
    return cont;
}