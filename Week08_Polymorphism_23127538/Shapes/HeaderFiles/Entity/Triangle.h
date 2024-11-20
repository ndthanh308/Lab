#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "IShape.h"
#include <cmath>

class Triangle : public IShape
{
    private:
        double _a, _b, _c;
    
    public:
        Triangle();
        Triangle(double a, double b, double c);
        ~Triangle();

    public:
        double area() const override;
        double perimeter() const override;
        std::string toString() const override;
};
#endif TRIANGLE_H