#ifndef CLOTHESPARSER_H
#define CLOTHESPARSER_H

#include "../../lib/bus/IParsable.h"
#include "../entity/Clothes.h"

class ClothesParser : public IParsable
{
    public:
        shared_ptr<Object> parse(const string& data) const override;
        string toString() const override;
};

#endif // MVPPARSER_H
