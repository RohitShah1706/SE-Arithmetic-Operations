#ifndef SUB_ARITHMETIC_H
#define SUB_ARITHMETIC_H

#include <iostream>
#include "../Arithmetic.h"

class SubArithmetic : public Arithmetic
{
public:
    Digit apply(Digit &a, Digit &b);
};

#endif