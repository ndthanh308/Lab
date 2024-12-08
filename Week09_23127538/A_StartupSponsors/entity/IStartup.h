#ifndef ISTARTUP_H
#define ISTARTUP_H

#include "../../lib/Object.h"
#include <iostream>
#include <string>

using std::string;  

class IStartup : public Object
{
    protected:
        string _name;
    
    public:
        string name() const;

    public:
        virtual int budget() const = 0;
        virtual string info() const = 0;
        string toString() const override;
};
#endif // ISTARTUP_H