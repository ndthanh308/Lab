#include "StallToTableConverter.h"
#include "../../lib/ui/IntToVND.cpp"



string StallToTableConverter::StallToRowConverter::convert(const shared_ptr<Object>& o) const
{
    stringstream row;
    shared_ptr<IStall> stall = dynamic_pointer_cast<IStall>(o);
    IntToVND vnd;
    
    row << '|' << centerText(stall->ID(), _columnSizes[1]) 
        << '|' << centerText(stall->toString(), _columnSizes[2])
        << '|' << centerText((to_string(stall->area()) + " m2"), _columnSizes[3])
        << '|' << centerText(vnd.convert(stall->feeRentPerM2()), _columnSizes[4])
        << '|' << centerText(vnd.convert(stall->premisesRent()), _columnSizes[5])
        << '|' << centerText(vnd.convert(stall->otherFee()), _columnSizes[6])
        << '|' << centerText(vnd.convert(stall->totalFee()), _columnSizes[7]) << '|';

    return row.str();
}

string StallToTableConverter::convert(const vector<shared_ptr<Object>> &os, string intro)
{
    stringstream table;
    
    table << intro << "\n\n";

    int totalAllFee = 0;
    
    // Convert headers to table header row
    table << '|' << left << setw(_columnSizes[0]) << _headers[0] << '|'
          << centerText(_headers[1], _columnSizes[1]) << '|'
          << centerText(_headers[2], _columnSizes[2]) << '|'
          << centerText(_headers[3], _columnSizes[3])  << '|'
          << centerText(_headers[4], _columnSizes[4])  << '|'
          << centerText(_headers[5], _columnSizes[5]) << '|'
          << centerText(_headers[6], _columnSizes[6]) << '|'
          << centerText(_headers[7], _columnSizes[7]) << "|\n";
    
    // Add a separator row
    int sum = 2; // two is number _comlumnSizes[i] - 
    for(size_t i = 0; i < _headers.size(); i++)
    {
        sum += _columnSizes[i];
    }
    for(size_t i = 0; i < sum; i++) table << '-';
    table << '\n';
    
    // Convert each startup to a row
    StallToRowConverter rowConverter(_columnSizes);
    for (size_t i = 0; i < os.size(); i++)
    {
        table << '|' << left << setw(_columnSizes[0]) << i + 1 << rowConverter.convert(os[i]) << '\n';
        shared_ptr<IStall> stall = dynamic_pointer_cast<IStall>(os[i]);
        totalAllFee += stall->totalFee();
    }

    IntToVND vnd;
    table << "\nTotal premises rental fees collected in May: " << vnd.convert(totalAllFee) << "\n\n";

    return table.str();

}

string centerText(const string &text, int width)
{
    stringstream center;
    int padding = width - text.size();
    int leftPadding = padding / 2;
    int rightPadding = padding - leftPadding;

    center << string(leftPadding, ' ') << text << string(rightPadding, ' ');
    return center.str();
}