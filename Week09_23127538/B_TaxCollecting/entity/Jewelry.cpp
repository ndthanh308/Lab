#include "Jewelry.h"

Jewelry::Jewelry(const string &id, int area, int otherFee)
    : IStall(id, area, otherFee) {}

string Jewelry::toString() const { return "Jewelry"; }
