#ifndef MULT_OPERATOR_H
#define MULT_OPERATOR_H

#include "../Operator.h"

class MultOperator : public Operator {

    public:
        MultOperator() : Operator() {}

        // MultOperator(Arithmetic * arithmetic);




        Digit operate(Digit &d1, Digit &d2);

};

#endif