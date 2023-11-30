#include "GUI.h"

GUI::GUI()
{
    addOperator.setArithmetic(&addArithmetic);
    subOperator.setArithmetic(&subArithmetic);
}

GUI *GUI::instance = NULL;

// ! Static method to get the singleton instance
GUI *GUI::getInstance()
{
    if (instance == NULL)
    {
        instance = new GUI();
    }
    return instance;
}

Operator *GUI::getOperator(string op)
{
    if (strcmp(op.c_str(), "+") == 0)
    {
        return &addOperator;
    }
    else if (strcmp(op.c_str(), "-") == 0)
    {
        return &subOperator;
    }
    return NULL;
}

void GUI::run()
{
    string s1, s2;
    while (1)
    {
        cout << "Enter number 1: ";
        cin >> s1;
        cout << "Enter number 2: ";
        cin >> s2;

        GUI *gui = GUI::getInstance();
        gui->digit1 = Digit(s1, 10);
        gui->digit2 = Digit(s2, 10);

        Operator *myOperator = gui->getOperator("-");
        Digit result = myOperator->operate(gui->digit1, gui->digit2);
        cout << "Result: ";
        result.display();
    }
}