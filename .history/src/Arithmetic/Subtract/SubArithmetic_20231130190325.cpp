#include "SubArithmetic.h"


Digit SubArithmetic::apply(Digit &d1, Digit &d2)
{
    Digit result;
    int borrow = 0;
    int l1 = d1.size();
    int l2 = d2.size();
    int maxLen = max(l1, l2);
    if(l1<l2)
    {
        Digit temp;
        temp=d1;
        d1=d2;
        d2=temp;
        int temp2;
        temp2=l1;
        l1=l2;
        l2=temp2;
        d2.setNeg();
    }
    cout<<l1<<" "<<l2<<endl;
    // for (int i = 0; i < maxLen; ++i)
    // {
    //     int digit1 = (i < l1) ? d1[l1 - 1 - i] : 0;
    //     int digit2 = (i < l2) ? d2[l2 - 1 - i] : 0;

    //     int currentDigit = digit1 - digit2 - borrow;

    //     if (currentDigit < 0)
    //     {
    //         currentDigit += d1.getBase();
    //         borrow = 1;
    //     }
    //     else
    //     {
    //         borrow = 0;
    //     }

    //     result.push_back(currentDigit);
    // }

    // for (int i = 0; i < l1; ++i)
    // {
    //     int digit1 = d1[l1 - 1 - i];
    //     int digit2 = (i < l2) ? d2[l2 - 1 - i] : 0;

    //     int currentDigit = digit1 - digit2 - borrow;

    //     if (currentDigit < 0)
    //     {
    //         currentDigit += d1.getBase();
    //         borrow = 1;
    //     }
    //     else
    //     {
    //         borrow = 0;
    //     }

    //     result.push_back(currentDigit);
    // }

    // Remove leading zeros
    // while (!result.empty() && result.back() == 0)
    //     result.pop_back();

    // reverse(result.begin(), result.end()); // Reverse the result to maintain correct order

    // return result;
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
