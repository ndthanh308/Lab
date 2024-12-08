#ifndef INTTOVND_H
#define INTTOVND_H

#include "IntToCurrency.h"


using std::stringstream;

class IntToVND : public IntToCurrency
{
    private:
        const char _symbol = 'd';
        const char _decimalSeparator = '.';

    public:
        const char symbol();
        const char decimalSeparator();
    public:
        string convert(int num) const override;
};

#endif  // INTTOVND_H