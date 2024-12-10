#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "entity/Employee.h"
#include "data-access/TextDao.h"
#include "bus/EmployeeParser.h"
#include "ui/EmployeeToTableConverter.h"

#include "entity/Employee.cpp"
#include "data-access/TextDao.cpp"
#include "bus/EmployeeParser.cpp"
#include "entity/Book.cpp"
#include "entity/Date.cpp"
#include "ui/EmployeeToTableConverter.cpp"
#include "ui/ToTableConverter.cpp"

using std::cout;
using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;

#endif // MAIN_H
