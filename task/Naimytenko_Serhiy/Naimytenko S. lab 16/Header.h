#pragma once
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>



using std::stringstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::ostream;
using std::getline;
 
 