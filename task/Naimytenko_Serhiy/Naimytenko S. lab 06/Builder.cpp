#include "Builder.h"
#include"C_Library.h"

C_Expansion New_Lib(int i) // 2
{
    int a = 0;
    C_Library new_l;
    int x;
    srand(static_cast<unsigned int>(time(0)));
    if (i % 2 == 0)
        x = rand() % 1;
    else
        x = 2;
    if (x == 0)
    {
        string dynamically = "yes";
        string name = "math" + i;
        string func = "Default";
        string lang = "default";
        string expansion = ".dll";
        new_l.setFunction(func);
        new_l.setLanguage_programming(lang);
        C_Library new_lib(dynamically, name, 20 + i, 1998, 40, new_l);
        C_Expansion new_el(expansion, new_lib);
        return new_el;
    }
    else if (x == 1)
    {
        string dynamically = "no";
        string name = "string" + i;
        string func = "Default";
        string lang = "default";
        string expansion = ".dll"; 
        new_l.setFunction(func);
        new_l.setLanguage_programming(lang);;
        C_Library new_lib(dynamically, name, 46 + i, 2000, 20, new_l);
        C_Expansion new_el(expansion, new_lib);
        return new_el;
    }
    else if (x == 2)
    {
        string expansion = ".dll"; 
        C_Library new_lib(new_l);
        int id = new_lib.getID();
        new_lib.setID(id + i);
        C_Expansion new_el(expansion, new_lib);
        return new_el;
    }

}




