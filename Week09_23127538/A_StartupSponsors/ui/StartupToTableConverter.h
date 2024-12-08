#ifndef STARTUPTOTABLECONVERTER_H
#define STARTUPTOTABLECONVERTER_H

#include "../../lib/ui/ToTableConverter.h"
#include "../entity/Idea.h"
#include "../entity/MVP.h"
#include "../../lib/ui/IntToDollar.h"



class StartupToTableConverter : public ToTableConverter
{
    public:
        StartupToTableConverter(const vector<string>& headers, const vector<int>& columnSizes)
        : ToTableConverter(headers, columnSizes) {}
        string convert(const vector<shared_ptr<Object>>& os, string intro) override;

    protected:
        class StartupToRowConverter : public ToRowConverter
        {
        public:
            using ToRowConverter::ToRowConverter; // Inherit constructors
            string convert(const shared_ptr<Object>& o) const override;
        };
};

#endif // STARTUPTOTABLECONVERTER_H