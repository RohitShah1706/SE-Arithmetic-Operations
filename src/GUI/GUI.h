#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <string>

#include "../Digit/Digit.h"
#include "../Operators/Operator.h"
#include "../Arithmetic/Add/AddArithmetic.h"
#include "../Operators/Add/AddOperator.h"

class GUI
{
private:
    static GUI *instance; // ! Static field for the singleton instance
    Digit digit1;
    Digit digit2;

    AddArithmetic addArithmetic;
    AddOperator addOperator;

    // ! Private constructor for GUI
    GUI();

public:
    // ! Static method to get the singleton instance
    static GUI *getInstance();

    Operator *getOperator(string op);

    static void run();
};

#endif