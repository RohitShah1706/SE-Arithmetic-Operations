#include "MultArithmetic.h"
// karatsuba on digits
Digit MultArithmetic::apply(Digit &a, Digit &b) {
    
    int base = a.getBase(); 
    Digit res = Digit("",base);
    //making both of equal lengths
    int len1 = a.size();
    int len2 = b.size();
    int len;
    if(len2>len1) {
        a.padZeroesFront(len2-len1);
        len = len2;
    }
    else if(len1>len2) {
        b.padZeroesFront(len1-len2);
        len = len1;
    }
    else len = len1;
    // base cases
    if (len == 0) { res.push_back(0) ; return res; }

    if (len == 1) {
        int product = a[0]*b[0];
        res.push_back(product/base);
        res.push_back(product%base);
        return res;
    }

    // splitting input digits
    int first_half = len/2;
    int second_half = len-first_half;

    Digit a_left = a.subDigit(0,first_half);
    Digit a_right = a.subDigit(first_half,second_half);

    Digit b_left = b.subDigit(0,first_half);
    Digit b_right = b.subDigit(first_half,second_half);

    Digit P1 = this->apply(a_left,b_left);
    Digit P2 = this->apply(a_right,b_right);

    // P3 = (a_left+a_right) * (b_left+b_right) how to add digits here? instantiate an AddArithmetic or operator?? 
    Digit a_sum = this->addArith.apply(a_left,a_right);
    Digit b_sum = this->addArith.apply(b_left,b_right);
    Digit P3 = this->apply(a_sum,b_sum);

    //res = P1*(10^(2*second_half)) + (P3 - P1 - P2)*(10^(second_half)) + P2
    // P1 + P2
    Digit x = this->addArith.apply(P1,P2);
    //P3 - P1 - P2
    Digit y = this->subArith.apply(P3,x);
    // (P3 - P1 - P2)*(10^(second_half)
    y.padWithZeroes(second_half);
    // P1*(10^(2*second_half))
    P1.padWithZeroes(2*second_half);
    // P1*(10^(2*second_half)) + P2
    res = this->addArith.apply(P1,P2);
    // P1*(10^(2*second_half)) + (P3 - P1 - P2)*(10^(second_half)) + P2
    res = this->addArith.apply(res,y);

    return res; 
}