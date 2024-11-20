#ifndef CIRCLE_H
#define CIRCLE_H

double const Pi = 3.14;

#include "IShape.h"

class Circle : public IShape
{
    private:
        double _radius;
    
    public:
        Circle();
        Circle(double rad);
        ~Circle() override;

    public:
        double area() const override;
        double perimeter() const override;
        std::string toString() const override;
};


#endif CIRCLE_H