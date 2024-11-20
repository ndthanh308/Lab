#include "../HeaderFiles/Entity/Square.h"

Square::Square() : _a(0) {}

Square::Square(double a) : _a(a) {}

Square::~Square() {}

double Square::area() const
{
    return _a * _a;
}

double Square::perimeter() const
{
    return 4 * _a;
}

std::string Square::toString() const { return "Square"; }