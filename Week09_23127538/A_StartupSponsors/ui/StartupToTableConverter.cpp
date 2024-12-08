#include "StartupToTableConverter.h"
#include "../../lib/ui/IntToDollar.cpp"


string StartupToTableConverter::StartupToRowConverter::convert(const shared_ptr<Object>& o) const
{
    stringstream row;
    shared_ptr<IStartup> startup = dynamic_pointer_cast<IStartup>(o);
    IntToDollar dollar;
    
    row << '|' << ' ' << startup->toString() << setw(_columnSizes[1] - 1 - startup->toString().length()) << setfill(' ') << '|'
        << ' ' << startup->name() <<  setw(_columnSizes[2] - 1 - startup->name().length()) << setfill(' ') << '|'
        << ' ' << startup->info() <<  setw(_columnSizes[3] - 1 - startup->info().length()) << setfill(' ') << '|'
        << ' ' << dollar.convert(startup->budget()) <<  setw(_columnSizes[4] - 1 - dollar.convert(startup->budget()).length()) << setfill(' ') << '|';

    return row.str();
}

string StartupToTableConverter::convert(const vector<shared_ptr<Object>> &os, string intro)
{
    stringstream table;
    
    table << intro << "\n\n";

    int totalBuget = 0;
    
    // Convert headers to table header row
    table << '|' << left << setw(_columnSizes[0]) << _headers[0] << '|'
          << ' ' << setw(_columnSizes[1] - 2) << _headers[1] << '|'
          << ' ' << setw(_columnSizes[2] - 2) << _headers[2] << '|'
          << ' ' << setw(_columnSizes[3] - 2) << _headers[3] << '|'
          << ' ' << setw(_columnSizes[4] - 2) << _headers[4] << "|\n";
    // Add a separator row
    int sum = 2; // 2 is _columnSize[i] -
    for(size_t i = 0; i < _headers.size(); i++)
    {
        sum += _columnSizes[i];
    }
    for(size_t i = 0; i < sum; i++) table << '-';
    table << '\n';
    
    // Convert each startup to a row
    StartupToRowConverter rowConverter(_columnSizes);
    for (size_t i = 0; i < os.size(); i++)
    {
        table << '|' << left << setw(_columnSizes[0]) << i + 1 << rowConverter.convert(os[i]) << '\n';
        shared_ptr<IStartup> startup = dynamic_pointer_cast<IStartup>(os[i]);
        totalBuget += startup->budget();
    }

    IntToDollar dollar;
    table << "\nTotal funding buget: " << dollar.convert(totalBuget) << "\n\n";

    return table.str();

}
