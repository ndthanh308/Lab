#include "Employee.h"

// Default constructor
Employee::Employee() : _name(""),_email(""), _startDate(Date()), _book(Book()) {}

// Parameterized constructor
Employee::Employee(const string& name, const string& email, const Date& startDate, const Book& book)
    : _name(name), _email(email), _startDate(startDate), _book(book) {}

// Getter methods
string Employee::name() const
{
    return _name;
}

string Employee::email() const
{
    return _email;
}

Date Employee::startDate() const
{
    return _startDate;
}

Book Employee::book() const
{
    return _book;
}

// Setter methods
void Employee::setName(const string& name)
{
    _name = name;
}

void Employee::setEmail(const string& email)
{
    _email = email;
}

void Employee::setStartDate(const Date& startDate)
{
    _startDate = startDate;
}

void Employee::setBook(const Book& book)
{
    _book = book;
}

// Override toString method
string Employee::toString() const { return "Employee"; }

float Employee::yearWork()
{
    time_t now = time(0);
    tm* ltm = localtime(&now);

    int yearNow = ltm->tm_year + 1900;
    int monthNow = ltm->tm_mon + 1;

    if(yearNow - _startDate.year() >= 2) 
    {
        if(monthNow < _startDate.month())
        {
            return 1.5f;
        }
        else 
        {
            return 2.0f;
        }
    }
    else if( yearNow - _startDate.year() == 1)
    {
        if(monthNow < _startDate.month()) 
        {
            return 0.5f;
        }
        else
        {
            return 1.0f;
        }
    }
    else 
    {
        return 0.5f; // the same year like 01/2023 --> 05/2023
    }
}


string Employee::seniority()
{

    if(yearWork() < 1.0) 
    {
        return "Fresher";
    }
    else if (yearWork() >= 1 && yearWork() < 2)
    {
        return "Junior";
    }
    else
    {
        return "Senior";
    }
}

float Employee::percentOfSponsoring()
{
    if(yearWork() < 1.0) 
    {
        return 0.3f;
    }
    else if (yearWork() >= 1 && yearWork() < 2)
    {
        return 0.5f;
    }
    else
    {
        return 1.0f;
    }
}

float Employee::sponsorship()
{
    return (_book.price() * percentOfSponsoring());
}
