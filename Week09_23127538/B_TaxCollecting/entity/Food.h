#ifndef FOOD_H
#define FOOD_H

#include "IStall.h"
#include <string>

using std::string;

class Food : public IStall
{
public:
    Food(const string& id, int area, int otherFee);
    string toString() const override;
};

#endif // FOOD_H