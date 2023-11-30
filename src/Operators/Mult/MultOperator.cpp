#include "MultOperator.h"

// MultOperator::MultOperator(Arithmetic * arithmetic) : Operator(arithmetic) {}

Digit MultOperator::operate(Digit &d1, Digit &d2) {
    //find result's decimal point
    int resultDecimalPoint = d1.getDecimalPoint() + d2.getDecimalPoint();
    
    // karatsuba to multiply

    Digit res = this->arithmetic->apply(d1,d2);

    //set decimal point of result

    res.setDecimalPoint(resultDecimalPoint);

    int i =  res.size() - (res.getDecimalPoint()+1);
    int start = 0;

    for (auto x: res) {
        if(x != 0) break;
        else if (start == i) break;
        else start++;
    }
    res = res.subDigit(start,res.size()-start);
    return res;}

