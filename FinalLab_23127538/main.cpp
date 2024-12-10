#include "main.h"

int main()
{
    cout << "\n\n";
    TextDao dao;
    vector<shared_ptr<Object>> employees = dao.getAll();
    vector<string> headers = {"Num", "Employee", "Seniority", "Book's title", "Price", "Percent", "Sponsorship"};
    vector<int> columnSizes = {3, 15, 12, 24, 12, 10, 15};
    
    EmployeeToTableConverter converter(headers, columnSizes);

    string intro = "UltraUs Employee Sponsorship Program for May 2024\nReading proposals from the file May2024Proposals.txt\nFound";
    stringstream intro2;
    intro2 << intro << ' ' << employees.size() << " book purchase proposals\n";

    cout << converter.convert(employees, intro2.str());

    


    cout << "\n\n";
    return 0;
}