#ifndef SUB_OPERATOR_H
#define SUB_OPERATOR_H

#include "../Operator.h"

class SubOperator : public Operator
{
public:
    SubOperator() : Operator() {};

    Digit operate(Digit &d1, Digit &d2);
};

#endif