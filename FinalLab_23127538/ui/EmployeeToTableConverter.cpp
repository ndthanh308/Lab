#include "EmployeeToTableConverter.h"



string EmployeeToTableConverter::EmployeeToRowConverter::convert(const shared_ptr<Object>& o) const
{
    stringstream row;
    shared_ptr<Employee> employee = dynamic_pointer_cast<Employee>(o);
    
    row << infoSuitableForRow(employee->name(), _columnSizes[1])
        << infoSuitableForRow(employee->seniority(), _columnSizes[2])
        << infoSuitableForRow(employee->book().title(), _columnSizes[3])
        << infoSuitableForRow(myFloatToPrice(employee->book().price()), _columnSizes[4])
        << infoSuitableForRow(floatToPercent(employee->percentOfSponsoring()), _columnSizes[5])
        << infoSuitableForRow(myFloatToPrice(employee->sponsorship()), _columnSizes[6]) << '|';


    return row.str();
}

string EmployeeToTableConverter::convert(const vector<shared_ptr<Object>> &os, string intro)
{
    stringstream table;
    
    table << intro << "\n\n";

    float totalSponsorship = 0;
    
    // Convert headers to table header row
    table << '|' << left << _headers[0] << setw(_columnSizes[0])
          << infoSuitableForRow(_headers[1], _columnSizes[1])
          << infoSuitableForRow(_headers[2], _columnSizes[2])
          << infoSuitableForRow(_headers[3], _columnSizes[3])
          << infoSuitableForRow(_headers[4], _columnSizes[4])
          << infoSuitableForRow(_headers[5], _columnSizes[5])
          << infoSuitableForRow(_headers[6], _columnSizes[6]) << "|\n";
    
    // Add a separator row
    int sum = _headers.size() - 5;
    for(size_t i = 0; i < _headers.size(); i++)
    {
        sum += _columnSizes[i];
    }
    for(size_t i = 0; i < sum; i++) table << '-';
    table << '\n'; 
    
    // Convert each startup to a row
    EmployeeToRowConverter rowConverter(_columnSizes);
    for (size_t i = 0; i < os.size(); i++)
    {
        table << '|' << left << setw(_columnSizes[0]) << i + 1 << rowConverter.convert(os[i]) << '\n';
        shared_ptr<Employee> employee = dynamic_pointer_cast<Employee>(os[i]);
        totalSponsorship += employee->sponsorship();
    }

    table << "\nTotal sponsorship: $" << fixed << setprecision(2) << totalSponsorship << '\n';

    return table.str();

}

string infoSuitableForRow(const string &info, int size)
{
    stringstream in4;
    if(info.length() < size - 2)
    {
        in4 << "| " << left << setw(size - 2) << info;
    }
    else
    {
        string info2;
        for(int i = 0; i < size - 2; i++)
        {
            if(i < size - 5)
            {
                info2 += info[i];
            }
            else
            {
                info2 += '.';
            }
        }
        in4 << "| " << left << setw(size - 2) << info2;
    }

    return in4.str();
}

string floatToPercent(float f)
{
    stringstream perS;
    float perF = f * 100;
    perS << perF << '%';
    return perS.str();
}

string myFloatToPrice(float f)
{
    stringstream mF;
    mF << "$" << fixed << setprecision(2) << f;
    return mF.str();
}
