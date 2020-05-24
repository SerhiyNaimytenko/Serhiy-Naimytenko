#pragma once
#pragma once
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#include <iostream>
#include <clocale>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream> 
#include <Windows.h>
#include <stddef.h>
#include <cstddef>  
#include <vector>  
#include<algorithm>
#include<memory>

using std::vector; 
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::setw;
using std::setprecision;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::stringstream; 
using std::istringstream; 
using std::ostream;
using std::istream; 
using std::for_each;
using std::auto_ptr;
using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;