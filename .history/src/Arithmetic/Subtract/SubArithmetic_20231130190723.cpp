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
        for (int i = 0; i < maxLen; ++i)
        {
            int digit1 = (i < l1) ? d1[l1 - 1 - i] : 0;
            int digit2 = (i < l2) ? d2[l2 - 1 - i] : 0;

            int currentDigit = digit1 - digit2 - borrow;

            if (currentDigit < 0)
            {
                currentDigit += d1.getBase();
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result.push_back(currentDigit);
    }
    }

    for (int i = 0; i < maxLen; ++i)
    {
        int digit1 = (i < l1) ? d1[l1 - 1 - i] : 0;
        int digit2 = (i < l2) ? d2[l2 - 1 - i] : 0;

        int currentDigit = digit1 - digit2 - borrow;

        if (currentDigit < 0)
        {
            currentDigit += d1.getBase();
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result.push_back(currentDigit);
    }

    // Remove leading zeros
    while (!result.empty() && result.back() == 0)
        result.pop_back();

    reverse(result.begin(), result.end()); // Reverse the result to maintain correct order

    return result;
}
