#include "MultArithmetic.h"
// karatsuba on digits
Digit MultArithmetic::apply(Digit &a, Digit &b) {
    
    int base = a.getBase(); 
    Digit res = Digit("",base);

    // //////////////////////////////////////////////////////
    // cout<<"checkpoint-1"<<endl;
    // cout <<"res base " <<res.getBase()<<endl;
    // cout<<"res "<<res.display()<<endl;
    // cout <<"a base " <<a.getBase()<<endl;
    // cout<<"a "<<a.display()<<endl;
    // cout <<"b base " <<b.getBase()<<endl;
    // cout<<"b "<<b.display()<<endl;
    // //////////////////////////////////////////////////////

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

    // //////////////////////////////////////////////////////
    // cout<<"checkpoint-2"<<endl;
    // cout <<"a_left base " <<a_left.getBase()<<endl;
    // cout<<"a_left "<<a_left.display()<<endl;
    // cout <<"a_right base " <<a_right.getBase()<<endl;
    // cout<<"a_right "<<a_right.display()<<endl;
    // cout <<"b_left base " <<b_left.getBase()<<endl;
    // cout<<"b_left "<<b_left.display()<<endl;
    // cout <<"b_right base " <<b_right.getBase()<<endl;
    // cout<<"b_right "<<b_right.display()<<endl;
    // //////////////////////////////////////////////////////

    Digit P1 = this->apply(a_left,b_left);
    Digit P2 = this->apply(a_right,b_right);

    // //////////////////////////////////////////////////////
    // cout<<"checkpoint-3"<<endl;
    // cout <<"P1 base " <<P1.getBase()<<endl;
    // cout<<"P1 "<<P1.display()<<endl;
    // cout <<"P2 base " <<P2.getBase()<<endl;
    // cout<<"P2 "<<P2.display()<<endl;
    // //////////////////////////////////////////////////////    

    // P3 = (a_left+a_right) * (b_left+b_right) how to add digits here? instantiate an AddArithmetic or operator?? 
    Digit a_sum = this->addArith.apply(a_left,a_right);
    a_sum.setBase(base);
    Digit b_sum = this->addArith.apply(b_left,b_right);
    b_sum.setBase(base);
    Digit P3 = this->apply(a_sum,b_sum);


    // //////////////////////////////////////////////////////
    // cout<<"checkpoint-4"<<endl;
    // cout <<"a_sum base " <<a_sum.getBase()<<endl;
    // cout<<"a_sum "<<a_sum.display()<<endl;
    // cout <<"b_sum base " <<b_sum.getBase()<<endl;
    // cout<<"b-sum "<<b_sum.display()<<endl;
    // cout <<"P3 base " <<P3.getBase()<<endl;
    // cout<<"P3 "<<P3.display()<<endl;
    // ////////////////////////////////////////////////////// 

    //res = P1*(10^(2*second_half)) + (P3 - P1 - P2)*(10^(second_half)) + P2
    // P1 + P2
    Digit x = this->addArith.apply(P1,P2);
    x.setBase(base);
    //P3 - P1 - P2
    Digit y = this->subArith.apply(P3,x);
    y.setBase(base);
    // (P3 - P1 - P2)*(10^(second_half)

    // //////////////////////////////////////////////////////
    // cout<<"checkpoint-5"<<endl;
    // cout <<"x base " <<x.getBase()<<endl;
    // cout<<"x "<<x.display()<<endl;
    // cout <<"y base " <<y.getBase()<<endl;
    // cout<<"y "<<y.display()<<endl;
    // ////////////////////////////////////////////////////// 

    y.padWithZeroes(second_half);
    // P1*(10^(2*second_half))
    P1.padWithZeroes(2*second_half);
    // P1*(10^(2*second_half)) + P2
    res = this->addArith.apply(P1,P2);
    res.setBase(base);
    // ////////////////////////////////////////////////////// 
    // cout<<"checkpoint-6"<<endl;
    // cout <<"res base " <<res.getBase()<<endl;
    // cout<<"res "<<res.display()<<endl;
    // ////////////////////////////////////////////////////// 

    // P1*(10^(2*second_half)) + (P3 - P1 - P2)*(10^(second_half)) + P2
    res = this->addArith.apply(res,y);
    res.setBase(base);
    // ////////////////////////////////////////////////////// 
    // cout<<"checkpoint-7"<<endl;
    // cout <<"res base " <<res.getBase()<<endl;
    // cout<<"res "<<res.display()<<endl;
    // ////////////////////////////////////////////////////// 

    return res; 
}