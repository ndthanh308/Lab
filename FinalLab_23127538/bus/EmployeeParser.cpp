#include "EmployeeParser.h"
#include <regex>
#include <stdexcept>

using std::regex;
using std::smatch;
using std::invalid_argument;
using std::make_shared;
using std::stoi;

shared_ptr<Employee> EmployeeParser::parse(const string &line1, const string& line2) const
{
    // Employee: Name=Do Minh Long, Email=dmlong@gmail.com, StartDate=05/07/2023
    // => Book: Title=Clean architecture with .Net Core, Price=$60.69, Link=www.amazon.com?id=11512
    shared_ptr<Employee> employee = make_shared<Employee>();

    regex pattern1("Employee: Name=(.+?), Email=(.+?), StartDate=(0?\\d{1,2})/(0?\\d{1,2})/(\\d{4})");
    smatch matches1;
    if (regex_match(line1, matches1, pattern1))
    {
        employee->setName(matches1[1]);
        // Assuming you have a setEmail method in Employee class
        // employee->setEmail(matches1[2]);

        int day = stoi(matches1[3]);
        int month = stoi(matches1[4]);
        int year = stoi(matches1[5]);

        employee->setStartDate(Date(day, month, year));
    }
    else
    {
        throw invalid_argument("Invalid employee data format: " + line1);
    }

    regex pattern2("=> Book: Title=(.+?), Price=\\$(.+?), Link=(.+)");
    smatch matches2;

    if (regex_match(line2, matches2, pattern2))
    {
        string title = matches2[1];
        float price = stof(matches2[2]);
        string link = matches2[3];

        Book book(title, price, link);
        employee->setBook(book);
    }
    else
    {
        throw invalid_argument("Invalid book data format: " + line2);
    }

    return employee;
}