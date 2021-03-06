#include "Builder.h"
#include "C_Library.h"

C_Library New_Lib(int i) // 2
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
        static char dynamically[] = "no";
        C_Library new_lib(dynamically, 20 + i, 1998, 40);
        return new_lib;
    }
    else if (x == 1)
    {
        static char dynamically[] = "yes";
        C_Library new_lib(dynamically, 46 + i, 2000, 20);
        return new_lib;
    }
    else if (x == 2)
    {
        C_Library new_lib(new_l);
        int id = new_lib.getID();
        new_lib.setID(id + i);
        return new_lib;
    }

}




