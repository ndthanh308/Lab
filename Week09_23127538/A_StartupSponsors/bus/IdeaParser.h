#ifndef IDEAPARSER_H
#define IDEAPARSER_H

#include "../../lib/bus/IParsable.h"
#include "../entity/Idea.h"

class IdeaParser : public IParsable
{
    public:
        shared_ptr<Object> parse (const string& data) const override;
        string toString() const override;
};

#endif // IDEAPARSER_H