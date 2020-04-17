#pragma once
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#include <iostream>
#include <clocale>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <regex>
#include <Windows.h>
#include <stddef.h>
#include <cstddef> 

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::setw; 
using std::ifstream;
using std::ofstream; 
using std::stringstream;
using std::getline;
using std::istringstream;  
using std::ostream;
using std::istream;
using std::exception;


