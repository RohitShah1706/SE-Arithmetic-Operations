#include "SubOperator.h"

Digit SubOperator::operate(Digit &d1, Digit &d2)
{
    int maxDecimalPoint = max(d1.getDecimalPoint(), d2.getDecimalPoint());
    d1.padWithZeroes(maxDecimalPoint - d1.getDecimalPoint());
    d2.padWithZeroes(maxDecimalPoint - d2.getDecimalPoint());

    Digit c = this->arithmetic->apply(d1, d2);
    c.setDecimalPoint(maxDecimalPoint);
    c.setBase(d1.getBase());

    return c;
}