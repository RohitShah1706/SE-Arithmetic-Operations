#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <iostream>
#include "../Digit.h"

class Arithmetic
{
public:
    Arithmetic() {};
    virtual ~Arithmetic() {};
    virtual Digit apply(Digit &d1, Digit &d2) = 0;
};

#endif