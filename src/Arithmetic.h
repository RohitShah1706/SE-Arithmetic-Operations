#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <iostream>
#include "Digit.h"

class Arithmetic
{
public:
    virtual Digit apply(Digit &a, Digit &b);
};

#endif