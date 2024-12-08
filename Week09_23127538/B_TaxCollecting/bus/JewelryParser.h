#ifndef JEWELRYPARSER_H
#define JEWELRYPARSER_H

#include "../../lib/bus/IParsable.h"
#include "../entity/Jewelry.h"


class JewelryParser : public IParsable
{
    public:
        shared_ptr<Object> parse (const string& data) const override;
        string toString() const override;
};

#endif // JEWELRYPARSER_H