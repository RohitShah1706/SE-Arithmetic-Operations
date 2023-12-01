#include "GUI.h"

GUI::GUI()
{
    addOperator.setArithmetic(&addArithmetic);
    subOperator.setArithmetic(&subArithmetic);
    multOperator.setArithmetic(&multArithmetic);
}

bool GUI::isValidNumber(const string &num)
{
    return all_of(num.begin(), num.end(), [](char c) { return isdigit(c) || c == '.'; });
}

bool GUI::isValidOperator(const string &op)
{
    return op == "+" || op == "-" || op == "*";
}

bool GUI::isValidBase(int base)
{
    return base>1;
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
    else if (strcmp(op.c_str(), "*") == 0) {
        return &multOperator;
    }
    return NULL;
}

void GUI::run()
{
    string s1, s2, op;
    int base;
    while (1)
    {
        // cout << "Enter number 1: ";
        cin >> s1;
        if (strcmp(s1.c_str(), "exit") == 0)
        {
            break;
        }
        // cout << "Enter number 2: ";
        cin >> s2;
        // cout << "Enter operator: ";
        cin >> op;
        // cout << "Enter base: ";
        cin >> base;

        GUI *gui = GUI::getInstance();
        gui->digit1 = Digit(s1, base);
        gui->digit2 = Digit(s2, base);

        // ! Handling exception cases

        if(!GUI::isValidOperator(op))
            cout<<"ERROR:Invalid operator"<<endl;
        else if(!GUI::isValidNumber(s1) || !GUI::isValidNumber(s2))
            cout<<"ERROR:Invalid number"<<endl;
        else if(!GUI::isValidBase(base))
            cout<<"ERROR:Invalid base"<<endl;
        else
        {
            Operator *myOperator = gui->getOperator(op);
            Digit result = myOperator->operate(gui->digit1, gui->digit2);
            cout << result.display() << endl;
        }

        Operator *myOperator = gui->getOperator(op);
        Digit result = myOperator->operate(gui->digit1, gui->digit2);
        cout << result.display() << endl;
    }

    cout.flush();
}