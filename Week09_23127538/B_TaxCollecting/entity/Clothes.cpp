#include "Clothes.h"

Clothes::Clothes(const string &id, int area)
    : IStall(id, area, 0) {}

string Clothes::toString() const { return "Clothes"; }
