#include "IStall.h"

IStall::IStall(const string& id, int area, int otherFee)
    : _ID(id), _area(area), _otherFee(otherFee) {}

int IStall::premisesRent() const 
{
    return _area * _feeRentPerM2;
}

int IStall::totalFee() const 
{
    return premisesRent() + _otherFee;
}

string IStall::ID() const
{
    return _ID;
}

int IStall::area() const
{
    return _area;
}

int IStall::otherFee() const
{
    return _otherFee;
}

const int IStall::feeRentPerM2()
{
    return _feeRentPerM2;
}

string IStall::toString() const 
{
    return "IStall";
}