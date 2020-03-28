#pragma once
#include "C_Library.h"
using std::string;
class C_Language
{
private:
    string language;
public:
    void setLanguage_programming(string);
    string Which_language_programming();

    C_Language();

    C_Language(string);

    C_Language(const C_Language&);

    ~C_Language();
};