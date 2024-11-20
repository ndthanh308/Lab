#include "../HeaderFiles/Entity/Rectangle.h"

Rectangle::Rectangle() : _width(0), _height(0) {}

Rectangle::Rectangle(double w, double h) : _width(w), _height(h) {}

Rectangle::~Rectangle() {}

double Rectangle::area() const
{
    return _width * _height;
}

double Rectangle::perimeter() const
{
    return 2 * (_width + _height);
}

std::string Rectangle::toString() const { return "Rectangle"; }