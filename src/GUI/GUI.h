#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <string>

#include "../Digit/Digit.h"
#include "../Operators/Operator.h"
#include "../Arithmetic/Add/AddArithmetic.h"
#include "../Operators/Add/AddOperator.h"
#include "../Arithmetic/Subtract/SubArithmetic.h"
#include "../Operators/Subtract/SubOperator.h"
#include "../Operators/Mult/MultOperator.h"
#include "../Arithmetic/Mult/MultArithmetic.h"

class GUI
{
private:
    static GUI *instance; // ! Static field for the singleton instance
    Digit digit1;
    Digit digit2;

    AddArithmetic addArithmetic;
    AddOperator addOperator;

    SubArithmetic subArithmetic;
    SubOperator subOperator;

    MultOperator multOperator;
    MultArithmetic multArithmetic;


    // ! Private constructor for GUI
    GUI();

public:
    // ! Static method to get the singleton instance
    static GUI *getInstance();

    Operator *getOperator(string op);

    static void run();
};

#endif