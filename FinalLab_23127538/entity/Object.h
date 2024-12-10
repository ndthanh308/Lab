#ifndef OBJECT_H
#define OBJECT_H

#include <string>
using std::string;

class Object
{
    public:
        virtual ~Object() = default;
    public:
        virtual string toString() const = 0;
};

#endif // OBJECT_H