#ifndef IPARSABLE_H
#define IPARSABLE_H

#include "../Object.h"
#include <memory>
#include <iostream>
#include <regex>

using std::string;
using std::shared_ptr;
using std::make_shared;

class IParsable : public Object
{
    public:
        virtual ~IParsable() = default;
        virtual shared_ptr<Object> parse(const string& data) const = 0;
};

#endif // IPASARBLE_H