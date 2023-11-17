#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <iostream>
#include "../Digit/Digit.h"

class Arithmetic
{
public:
    virtual Digit apply(Digit &d1, Digit &d2) = 0;
};

#endif