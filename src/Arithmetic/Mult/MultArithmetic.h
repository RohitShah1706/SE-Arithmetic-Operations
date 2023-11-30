#ifndef MULT_ARITHMETIC_H
#define MULT_ARITHMETIC_H

#include <iostream>
#include "../Arithmetic.h"
#include "../Add/AddArithmetic.h"
#include "../Subtract/SubArithmetic.h"

class MultArithmetic : public Arithmetic {

    protected:
        AddArithmetic addArith;
        
         SubArithmetic subArith;
    public:
        Digit apply(Digit &a, Digit &b);
};


#endif  