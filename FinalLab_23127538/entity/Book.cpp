#include "Book.h"

// Default constructor
Book::Book() : _title(""), _price(0.0), _link("") {}

// Parameterized constructor
Book::Book(const string& title, float price, const string& link)
    : _title(title), _price(price), _link(link) {}

// Getter methods
string Book::title() const
{
    return _title;
}

float Book::price() const
{
    return _price;
}

string Book::link() const
{
    return _link;
}

// Setter methods
void Book::setTitle(const string& title)
{
    _title = title;
}

void Book::setPrice(float price)
{
    _price = price;
}

void Book::setLink(const string& link)
{
    _link = link;
}

// Override toString method
string Book::toString() const { return "Book"; }