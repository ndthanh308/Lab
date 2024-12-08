#include "MVP.h"
#include <sstream>

// Default Constructor
MVP::MVP() : _runMonths(0), _marketingMonths(0)
{
    _name = "Unnamed MVP";
}

// Parameterized Constructor
MVP::MVP(const string &name, int runMonths, int marketingMonths)
    : _runMonths(runMonths), _marketingMonths(marketingMonths)
{
    _name = name;
}

// Getter for runMonths
int MVP::runMonths() const
{
    return _runMonths;
}

// Setter for runMonths
void MVP::setRunMonths(int runMonths)
{
    _runMonths = runMonths;
}

// Getter for marketingMonths
int MVP::marketingMonths() const
{
    return _marketingMonths;
}

// Setter for marketingMonths
void MVP::setMarketingMonths(int marketingMonths)
{
    _marketingMonths = marketingMonths;
}

// Getter for name
string MVP::name() const
{
    return _name;
}

// Setter for name
void MVP::setName(const string &name)
{
    _name = name;
}

// Overridden toString method
string MVP::toString() const { return "MVP"; }

string MVP::info() const
{
    stringstream info;
    info << "Run months: " << runMonths() << " month";
    if(runMonths() > 1) info << 's';
    info << ". Marketing: " << marketingMonths() << " month";
    if(marketingMonths() > 1) info << 's';
    return info.str();
}

// Overridden budget method
int MVP::budget() const
{
    return (_runMonths * _supportEachMonthForRun) + 
           (_marketingMonths * _supportEachMonthForMarketing);
}
