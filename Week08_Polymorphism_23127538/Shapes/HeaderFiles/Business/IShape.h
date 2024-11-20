#ifndef ISHAPE_H
#define ISHAPE_H


#include "../Entity/Object.h"

class IShape : virtual public Object
{
    public:
        virtual ~IShape() = default;
    public:
        virtual double perimeter() const = 0;
        virtual double area() const = 0;
};

#endif ISHAPE_H

