#include "Digit.h"

Digit::Digit() {
    this->base = 10;
    this->isFloat = false;
    this->isNeg = false;
    this->decimalPoint = 0;
}

// ! constructor will accept a string - the number to be stored in base (base) notation
// ! the string will be in the format: "123.456" or "123" - has to be stored as a vector of integers
// ! the constructor will also accept an integer - the base of the number
Digit::Digit(string number, int base)
{
    this->base = base;
    this->isFloat = false;
    this->isNeg = false;
    this->decimalPoint = 0;
    if (number[0] == '-')
    {
        this->isNeg = true;
        number = number.substr(1);
    }
    for (int i = 0; i < number.length(); i++)
    {
        if (number[i] == '.')
        {
            this->isFloat = true;
            this->decimalPoint = number.length() - i - 1;
        }
        else
        {
            this->push_back(number[i] - '0');
        }
    }
}

string Digit::display()
{
    int i = 0;
    int precision = PRECISION;
    string s = "";
    for (auto x : *this)
    {
        if (precision == 0)
        {
            break;
        }
        if (precision < PRECISION)
            precision--;
        if (i == this->size() - this->decimalPoint)
        {
            s += ".";
            precision--;
        }
        s += to_string(x);
        i++;
    }
    
    if(this->isNeg)
        s="-"+s;
    return s;
}

void Digit::padWithZeroes(int count)
{
    int decimalPoint = this->getDecimalPoint();
    for (int i = 0; i < count; i++)
    {
        this->push_back(0);
        decimalPoint++;
    }
    this->setDecimalPoint(decimalPoint);
}