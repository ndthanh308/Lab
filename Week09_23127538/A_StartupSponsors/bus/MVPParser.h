#ifndef MVPPARSER_H
#define MVPPARSER_H

#include "../../lib/bus/IParsable.h"
#include "../entity/MVP.h"

class MVPParser : public IParsable
{
    public:
        shared_ptr<Object> parse(const string& data) const override;
        string toString() const override;
};

#endif // MVPPARSER_H
