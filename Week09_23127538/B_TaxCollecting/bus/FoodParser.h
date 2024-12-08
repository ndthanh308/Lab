#ifndef FOODPARSER_H
#define FOODPARSER_H

#include "../../lib/bus/IParsable.h"
#include "../entity/Food.h"

class FoodParser : public IParsable
{
    public:
        shared_ptr<Object> parse (const string& data) const override;
        string toString() const override;
};

#endif // FOODPARSER_H