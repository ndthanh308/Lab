#include "Food.h"


Food::Food(const string& id, int area, int otherFee)
    : IStall(id, area, otherFee) {}
string Food::toString() const { return "Food"; }