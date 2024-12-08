#ifndef ISTALL_H
#define ISTALL_H

#include "../../lib/Object.h"
#include <iostream>
#include <string>

using std::string;

class IStall : public Object
{
protected:
    string _ID;
    int _area;
    int _otherFee;
    const int _feeRentPerM2 = 560000;

public:
    IStall(const string& id, int area, int otherFee);

    virtual int premisesRent() const;
    virtual int totalFee() const;

    string ID() const;        // Getter for _ID
    int area() const;         // Getter for _area
    int otherFee() const;     // Getter for otherFee
    const int feeRentPerM2();

    string toString() const override;
};

#endif // ISTALL_H