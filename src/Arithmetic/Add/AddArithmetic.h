#ifndef ADD_ARITHMETIC_H
#define ADD_ARITHMETIC_H

#include <iostream>
#include "../Arithmetic.h"

class AddArithmetic: public Arithmetic
{
public:
    AddArithmetic();
    virtual ~AddArithmetic();
    Digit apply(Digit &a, Digit &b);
};

#endif