#ifndef TEXTDAO_H
#define TEXTDAO_H


#include "../bus/EmployeeParser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


using std::stringstream;
using std::fstream;
using std::getline;
using std::vector;
using std::ifstream;
using std::ios;
using std::cout;

class TextDao
{
    public:
        vector<shared_ptr<Object>> getAll();
};

#endif // TEXTDAO_H