#include "../HeaderFiles/Entity/Circle.h"


Circle::Circle()
{
    _radius = 0;
}
Circle::Circle(double rad)
{
    _radius = rad;
}
Circle::~Circle()
{
    // do nothing
}

double Circle::area() const
{
    return _radius * Pi;
}

double Circle::perimeter() const
{
    return 2 * _radius * Pi;
}

std::string Circle::toString() const { return "Circle"; }

