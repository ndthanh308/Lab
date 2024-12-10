#include "TextDao.h"

vector<shared_ptr<Object>> TextDao::getAll()
{
    vector<shared_ptr<Object>> employees;

    const string filename = "data/May2024Proposals.txt";

    ifstream reader;
    reader.open(filename, ios::in);

    if(!reader.is_open())
    {
        cout << "Cannot open file " << filename << " !!!\n";
        return employees;
    }
    string lineEmployee, lineBook, lineBlank;

    while(getline(reader, lineEmployee))
    {
        getline(reader, lineBook);
        getline(reader, lineBlank);

        EmployeeParser parser;
        shared_ptr<Employee> employee;
        employee = parser.parse(lineEmployee, lineBook);

        employees.push_back(employee);
    }

    reader.close();
    return employees;

}