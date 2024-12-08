#include "IntToDollar.h"

const char IntToDollar::symbol()
{
    return _symbol;
}

const char IntToDollar::decimalSeparator()
{
    return _decimalSeparator;
}

string IntToDollar::convert(int num) const
{
    stringstream dollar;
    string numStr = to_string(num);
    int insertPos = numStr.length() - 3;
    while (insertPos > 0)
    {
        numStr.insert(insertPos, 1, _decimalSeparator);
        insertPos -= 3;
    }

    dollar << _symbol << numStr;
    return dollar.str();
}
