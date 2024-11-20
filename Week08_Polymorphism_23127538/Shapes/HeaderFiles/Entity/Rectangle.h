#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "IShape.h"
class Rectangle : public IShape
{
    private:
        double _width;
        double _height;

    public:
        Rectangle();
        Rectangle(double w, double h);
        ~Rectangle();

    public:
        double area() const override;
        double perimeter() const override;
        std::string toString() const override;
};

#endif RECTANGLE_H