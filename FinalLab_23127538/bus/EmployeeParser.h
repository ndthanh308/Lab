#ifndef EMPLOYEEPARSER_H
#define EMPLOYEEPARSER_H

#include "../entity/Employee.h"

#include <regex>

using std::regex;
using std::smatch;


class EmployeeParser
{
    public:
        shared_ptr<Employee> parse(const string& line1, const string& line2) const;
};

#endif // EMPLOYEEPARSER_H