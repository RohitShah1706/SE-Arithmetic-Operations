#ifndef DIGIT_H
#define DIGIT_H 

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;

#define PRECISION 100

class Digit: public std::vector<int> 
{
private:
    int base;
    bool isFloat;
    bool isNeg;
    int decimalPoint;

public:
    Digit();
    Digit(string number, int base);
    void padWithZeroes(int count);

    string display();

    void padZeroesFront(int n);
    Digit subDigit(int start,int length);
    


    // ! getters & setters
    int getBase() { return this->base; }
    bool getIsFloat() { return this->isFloat; }
    int getDecimalPoint() { return this->decimalPoint; }
    bool getNeg() {return this->isNeg;}
    void setNeg() {this->isNeg=true;}
    void setBase(int base) { this->base = base; }
    void setIsFloat(bool isFloat) { this->isFloat = isFloat; }
    void setDecimalPoint(int decimalPoint) { this->decimalPoint = decimalPoint; }
};

#endif