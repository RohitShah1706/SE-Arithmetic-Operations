#ifndef ADD_OPERATOR_H
#define ADD_OPERATOR_H

#include "../Operator.h"

class AddOperator : public Operator
{
public:
    AddOperator(Arithmetic *arithmetic);

    Digit operate(Digit &d1, Digit &d2);
};

#endif