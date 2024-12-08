#include "Idea.h"

// Default Constructor
Idea::Idea() : _devMonths(0)
{
    _name = "Unnamed Idea";
}

// Parameterized Constructor
Idea::Idea(const string &name, int devMonths)
    : _devMonths(devMonths)
{
    _name = name;
}

// Getter for devMonths
int Idea::devMonths() const
{
    return _devMonths;
}

// Setter for devMonths
void Idea::setDevMonths(int devMonths)
{
    _devMonths = devMonths;
}

// Getter for name
string Idea::name() const
{
    return _name;
}

// Setter for name
void Idea::setName(const string &name)
{
    _name = name;
}

// Overridden toString method
string Idea::toString() const { return "Idea"; }

string Idea::info() const
{
    stringstream info;
    info << "Dev months: " << devMonths() << " month";
    if(devMonths() > 1) info << 's';
    return info.str();
}

// Overridden budget method
int Idea::budget() const
{
    return _devMonths * _supportEachMonth;
}
