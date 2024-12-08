#include "IntToVND.h"

const char IntToVND::symbol()
{
    return _symbol;
}

const char IntToVND::decimalSeparator()
{
    return _decimalSeparator;
}

string IntToVND::convert(int num) const
{
    stringstream VND;
    string numStr = to_string(num);
    int insertPos = numStr.length() - 3;
    while (insertPos > 0)
    {
        numStr.insert(insertPos, 1, _decimalSeparator);
        insertPos -= 3;
    }

    VND << numStr << ' ' << _symbol;
    return VND.str();
}
