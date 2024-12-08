#ifndef STALLTOTABLECONVERTER_H
#define STALLTOTABLECONVERTER_H

#include "../../lib/ui/ToTableConverter.h"
#include "../entity/Food.h"
#include "../entity/Clothes.h"
#include "../entity/Jewelry.h"
#include "../../lib/ui/IntToVND.h"

using std::shared_ptr;
using std::make_shared;
using std::dynamic_pointer_cast;
using std::left;

class StallToTableConverter : public ToTableConverter
{
    public:
        StallToTableConverter(const vector<string>& headers, const vector<int>& columnSizes)
        : ToTableConverter(headers, columnSizes) {}
        string convert(const vector<shared_ptr<Object>>& os, string intro) override;

    protected:
        class StallToRowConverter : public ToRowConverter
        {
        public:
            using ToRowConverter::ToRowConverter; // Inherit constructors
            string convert(const shared_ptr<Object>& o) const override;
        };
};

string centerText(const string &text, int width);
#endif // STALLTOTABLECONVERTER_H