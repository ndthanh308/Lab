#include "Date.h"

// Default constructor
Date::Date() : _day(1), _month(1), _year(1970) {}

// Parameterized constructor
Date::Date(int day, int month, int year) : _day(day), _month(month), _year(year) {}

// Getter methods
int Date::day() const 
{
    return _day;
}

int Date::month() const 
{
    return _month;
}

int Date::year() const 
{
    return _year;
}

// Setter methods
void Date::setDay(int day) 
{
    _day = day;
}

void Date::setMonth(int month) 
{
    _month = month;
}

void Date::setYear(int year) 
{
    _year = year;
}

// Override toString method
string Date::toString() const { return "Date"; }