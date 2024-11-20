#include "../HeaderFiles/Entity/Triangle.h"


Triangle::Triangle() : _a(0), _b(0), _c(0) {}

Triangle::Triangle(double a, double b, double c) : _a(a), _b(b), _c(c) {}

Triangle::~Triangle() {}

double Triangle::area() const {
    double s = (_a + _b + _c) / 2;
    return std::sqrt(s * (s - _a) * (s - _b) * (s - _c));
}

double Triangle::perimeter() const {
    return _a + _b + _c;
}

std::string Triangle::toString() const { return "Triangle"; }