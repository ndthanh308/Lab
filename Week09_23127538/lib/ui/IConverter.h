#ifndef ICONVERTER_H
#define ICONVERTER_H

#include "../Object.h"


// TODO:convert Object to Object, but to do it we need to wrapper
class IConverter : public Object 
{
    public:
        virtual ~IConverter() = default;
        
    public:
        virtual string convert(const Object& o) = 0;
};

#endif // ICONVERTER_H
