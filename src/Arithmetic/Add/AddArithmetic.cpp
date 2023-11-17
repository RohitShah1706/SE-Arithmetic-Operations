#include "AddArithmetic.h"

Digit AddArithmetic::apply(Digit &d1, Digit &d2)
{
    Digit c;
    int carry = 0;

    int l1 = d1.size();
    int l2 = d2.size();
    int mine = min(l1, l2);

    while (mine--)
    {
        c.push_back((d1[l1 - 1] + d2[l2 - 1] + carry) % d1.getBase());
        carry = (d1[l1 - 1] + d2[l2 - 1] + carry) / d1.getBase();
        l1--;
        l2--;
    }

    while (l1--)
    {
        c.push_back((d1[l1] + carry) % d1.getBase());
        carry = (d1[l1] + carry) / d1.getBase();
    }
    while (l2--)
    {
        c.push_back((d2[l2] + carry) % d1.getBase());
        carry = (d2[l2] + carry) / d1.getBase();
    }

    if (carry)
        c.push_back(carry);

    reverse(c.begin(), c.end()); // ! Reverse the result to maintain correct order

    return c;
}