#ifndef TOTABLECONVERTER_H
#define TOTABLECONVERTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <iomanip>


#include "IConverter.h"

using std::vector;
using std::stringstream;
using std::shared_ptr;
using std::make_shared;
using std::setw;

class ToTableConverter : public IConverter
{
    protected:
        vector<string> _headers;
        vector<int> _columnSizes;

    public:
        ToTableConverter();
        ToTableConverter(vector<string> headers, vector<int> columnSizes);
        virtual ~ToTableConverter() = default;
    
    public:
        vector<string> headers() const;
        vector<int> columnSizes() const;
    
    public:
        string toString() const override;
        virtual string convert(const vector<shared_ptr<Object>>& os, string intro) = 0;
        string convert(const Object& o) override;

    protected:
        class ToRowConverter
        {
            protected:
                vector<int> _columnSizes;

            public:
                ToRowConverter();
                ToRowConverter(vector<int> columnSizes);
                virtual string convert(const shared_ptr<Object>& object) const = 0; // Use a more generic type
        };
};

#endif // TOTABLECONVERTER_H
