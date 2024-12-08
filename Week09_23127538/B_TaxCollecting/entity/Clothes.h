#ifndef CLOTHES_H
#define CLOTHES_H

#include "IStall.h"
#include <string>

using std::string;

class Clothes : public IStall
{
public:
    Clothes(const string& id, int area);
    string toString() const override;
};

#endif // CLOTHES_H