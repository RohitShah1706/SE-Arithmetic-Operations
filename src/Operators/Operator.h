#ifndef OPERATOR_H
#define OPERATOR_H

#include "../Arithmetic/Arithmetic.h"

class Operator {
protected: 
   Arithmetic *arithmetic;

public:
    Operator(Arithmetic *arithmetic) {
        this->arithmetic = arithmetic;
    }

    virtual Digit operate(Digit &d1, Digit &d2) = 0;
};

#endif