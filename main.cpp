#include "src/Digit.h"
#include "src/Arithmetic/Add/AddArithmetic.h"
#include "src/Operators/Add/AddOperator.h"

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    Digit a(s1, 10);
    Digit b(s2, 10);

    AddArithmetic addArithmetic = AddArithmetic();
    AddOperator addOperator(&addArithmetic);

    a.display();
    b.display();

    Digit c = addOperator.operate(a, b);
    c.display();
    return 0;
}