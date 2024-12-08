#ifndef JEWELRY_H
#define JEWELRY_H

#include "IStall.h"
#include <string>

using std::string;

class Jewelry : public IStall
{
public:
    Jewelry(const string& id, int area, int otherFee);
    string toString() const override;
};

#endif // JEWELRY_H