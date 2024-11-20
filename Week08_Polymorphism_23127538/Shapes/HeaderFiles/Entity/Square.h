#ifndef SQUARE_H
#define SQUARE_H

#include "IShape.h"

class Square : public IShape
{
    private:
        double _a;
    
    public:
        Square();
        Square(double a);
        ~Square();

    public:
        double area() const override;
        double perimeter() const override;
        std::string toString() const override;

};

#endif SQUARE_H