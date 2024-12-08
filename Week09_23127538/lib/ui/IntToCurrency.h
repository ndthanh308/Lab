#ifndef INTTOCURRENCY_H
#define INTTOCURRENCY_H

#include "IConverter.h"
#include <sstream>

using std::stringstream;
using std::to_string;

class IntToCurrency : public IConverter
{
    public:
        string toString() const override;
        string convert(const Object& o) override;
        virtual string convert(int num) const = 0;
};

#endif  // INTTOCURRENCY_H