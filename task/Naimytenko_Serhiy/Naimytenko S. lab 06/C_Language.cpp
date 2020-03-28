#include"C_Library.h"
#include"C_Language.h"

void C_Language::setLanguage_programming(string name)
{
	language = name;
}

string C_Language::Which_language_programming()
{
	return language;
}

C_Language::C_Language() :language("Default")
{
}
C_Language::C_Language(string language) : language(language)
{
}
C_Language::C_Language(const C_Language& lang) : language(lang.language)
{
}
C_Language::~C_Language()
{
}