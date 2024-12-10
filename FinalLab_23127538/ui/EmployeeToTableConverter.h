#ifndef EMPLOYEETOTABLECONVERTER_H
#define EMPLOYEETOTABLECONVERTER_H

#include "ToTableConverter.h"
#include "../entity/Employee.h"

using std::dynamic_pointer_cast;
using std::setprecision;
using std::fixed;
using std::to_string;

class EmployeeToTableConverter : public ToTableConverter
{
    public:
        EmployeeToTableConverter(const vector<string>& headers, const vector<int>& columnSizes)
        : ToTableConverter(headers, columnSizes) {}
        string convert(const vector<shared_ptr<Object>>& os, string intro) override;

    protected:
        class EmployeeToRowConverter : public ToRowConverter
        {
        public:
            using ToRowConverter::ToRowConverter; // Inherit constructors
            string convert(const shared_ptr<Object>& o) const override;
        };
};

/// @brief return info suitable for size of column
/// @param info 
/// @param size 
/// @return return info suitable for size of column
string infoSuitableForRow(const string& info, int size);

string floatToPercent(float f);

string myFloatToPrice(float f);

#endif // EMPLOYEETOTABLECONVERTER_H