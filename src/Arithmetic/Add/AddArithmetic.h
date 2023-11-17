#ifndef ADD_ARITHMETIC_H
#define ADD_ARITHMETIC_H

#include <iostream>
#include "../Arithmetic.h"

class AddArithmetic : public Arithmetic
{
public:
    Digit apply(Digit &a, Digit &b);
};

#endif