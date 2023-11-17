#include "src/Digit.h"
#include "src/Arithmetic.h"

Digit padWithZeroes(Digit num, int count)
{
    int decimalPoint = num.getDecimalPoint();
    for (int i = 0; i < count; i++)
    {
        num.push_back(0);
        decimalPoint++;
    }
    num.setDecimalPoint(decimalPoint);
    return num;
}

Digit addition(Digit a, Digit b, int B) // performs the addition of two given vectors in base B
{
    Digit c;
    int carry = 0;

    int maxDecimalPoint = max(a.getDecimalPoint(), b.getDecimalPoint());
    a = padWithZeroes(a, maxDecimalPoint - a.getDecimalPoint());
    b = padWithZeroes(b, maxDecimalPoint - b.getDecimalPoint());

    int l1 = a.size();
    int l2 = b.size();
    int mine = min(l1, l2);

    while (mine--)
    {
        c.push_back((a[l1 - 1] + b[l2 - 1] + carry) % B);
        carry = (a[l1 - 1] + b[l2 - 1] + carry) / B;
        l1--;
        l2--;
    }

    while (l1--)
    {
        c.push_back((a[l1] + carry) % B);
        carry = (a[l1] + carry) / B;
    }
    while (l2--)
    {
        c.push_back((b[l2] + carry) % B);
        carry = (b[l2] + carry) / B;
    }

    if (carry)
        c.push_back(carry);

    reverse(c.begin(), c.end()); // Reverse the result to maintain correct order

    c.setDecimalPoint(maxDecimalPoint);

    return c;
}

int main()
{
    // string s1 = "12.333", s2 = "1.1";
    string s1, s2;
    cin >> s1 >> s2;

    Digit a(s1, 10);
    Digit b(s2, 10);

    a.display();
    b.display();

    cout << a.getDecimalPoint() << " " << b.getDecimalPoint() << endl;
    Digit c = addition(a, b, 10);
    c.display();
    return 0;
}