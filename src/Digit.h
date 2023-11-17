#ifndef DIGIT_H
#define DIGIT_H 

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define PRECISION 100

class Digit: public std::vector<int> 
{
private:
    int base;
    bool isFloat;
    int decimalPoint;

public:
    Digit();
    Digit(string number, int base);
    void padWithZeroes(int count);
    void display();

    // ! getters & setters
    int getBase() { return this->base; }
    bool getIsFloat() { return this->isFloat; }
    int getDecimalPoint() { return this->decimalPoint; }
    void setBase(int base) { this->base = base; }
    void setIsFloat(bool isFloat) { this->isFloat = isFloat; }
    void setDecimalPoint(int decimalPoint) { this->decimalPoint = decimalPoint; }

};

#endif