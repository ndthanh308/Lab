#ifndef INTTODOLLAR_H
#define INTTODOLLAR_H

#include "IntToCurrency.h"


using std::stringstream;

class IntToDollar : public IntToCurrency
{
    private:
        const char _symbol = '$';
        const char _decimalSeparator = ',';

    public:
        const char symbol();
        const char decimalSeparator();
    public:
        string convert(int num) const override;
};

#endif  // INTTODOLLAR_H