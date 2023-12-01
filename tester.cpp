#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "src/GUI/GUI.h"

class DigitTester
{
public:
    void addTest(const string &name, const string &op, int base, const string &d1, const string &d2, const string &expected)
    {
        tests.push_back({name, op, base, d1, d2, expected});
    }

    void runTestsWithGUI()
    {
        // ! Prepare the input
        std::stringstream ss;
        for (auto test : tests)
        {
            string s1 = test.d1;
            string s2 = test.d2;

            ss << s1 << "\n"
               << s2 << "\n"
               << test.op << "\n"
               << test.base << "\n";
        }
        ss << "exit"
           << "\n"
           << ""
           << "\n"
           << ""
           << "\n"
           << ""
           << "\n";

        // ! Redirect cin to read from the stringstream
        std::streambuf *origCin = std::cin.rdbuf(ss.rdbuf());

        // ! Redirect cout to write to a stringstream
        std::stringstream out;
        std::streambuf *origCout = std::cout.rdbuf(out.rdbuf());

        // ! Run the GUI
        GUI *gui = GUI::getInstance();
        gui->run();

        // ! Restore cin and cout to the original buffers
        std::cin.rdbuf(origCin);
        std::cout.rdbuf(origCout);

        // ! Get the output
        string output = out.str();
        // ! vector<string> results = separate output by \n as delimiter
        vector<string> results;
        stringstream ss2(output);
        string temp;
        while (getline(ss2, temp, '\n'))
        {
            results.push_back(temp);
        }

        if (results.size() != tests.size())
        {
            cout << "Tests failed" << endl;
            return;
        }

        int passed = 0;
        for (int i = 0; i < results.size(); i++)
        {
            if (results[i] == tests[i].expected)
            {
                passed++;
                cout << "Test passed: " << tests[i].name << endl;
            }
            else
            {
                cout << "Test failed: " << tests[i].name << endl;
                cout << results[i] << " " << tests[i].expected << endl;
            }
        }
        cout << "Total tests: " << results.size() << ", Passed: " << passed << ", Failed: " << results.size() - passed << endl;
    }

private:
    struct TestCase
    {
        string name;
        string op;
        int base;
        string d1;
        string d2;
        string expected;
    };

    vector<TestCase> tests;

    bool compareDigits(Digit &d1, Digit &d2)
    {
        if (d1.getBase() != d2.getBase())
            return false;
        if (d1.getDecimalPoint() != d2.getDecimalPoint())
            return false;
        if (d1.size() != d2.size())
            return false;
        for (size_t i = 0; i < d2.size(); i++)
        {
            if (d1[i] != d2[i])
                return false;
        }
        return true;
    }
};

int main()
{
    DigitTester tester;

    // ! add tests(base-10)
    tester.addTest("Test 1", "+", 10, "12", "10", "22");
    tester.addTest("Test 2", "+", 10, "12.22", "10", "22.22");
    tester.addTest("Test 3", "+", 10, "123.456", "21.042353", "144.498353");
    tester.addTest("Test 4", "+", 10, "1.232", "12.22", "13.452");

    // ! add tests(base-2)
    tester.addTest("Test 5", "+", 2, "1101", "101", "10010");
    tester.addTest("Test 6", "+", 2, "101.001", "1101", "10010.001");
    tester.addTest("Test 7", "+", 2, "0.101", "0.1101", "1.0111");
    tester.addTest("Test 8", "+", 2, "0.001", "0.1101", "0.1111");

    // ! sub tests(base-10)
    tester.addTest("Test 9", "-", 10, "12", "10", "2");
    tester.addTest("Test 10", "-", 10, "123.456", "21.042353", "102.413647");
    tester.addTest("Test 11", "-", 10, "12", "0.02", "11.98");
    tester.addTest("Test 12", "-", 10, "10", "123.02", "-113.02");
    tester.addTest("Test 13", "-", 10, "98.64", "99.324", "-.684");

    // ! sub tests(base-2)
    tester.addTest("Test 14", "-", 2, "1101", "101", "1000");
    tester.addTest("Test 15", "-", 2, "101", "1101", "-1000");
    
    // ! failed
    tester.addTest("Test 16", "-", 2, "101.101", "1101.1101", "-1000.0001");
    tester.addTest("Test 17", "-", 2, "1101.1101", "101.101", "1000.0001");

    // ! mult tests(base-10)
    tester.addTest("Test 18", "*", 10, "23", "3", "69");
    tester.addTest("Test 19", "*", 10, "2.3", "3", "6.9");
    tester.addTest("Test 20", "*", 10, "2.3", "300", "690.0");
    tester.addTest("Test 21", "*", 10, "2.3", "30", "69.0");

    // ! mult tests(base-10)
    tester.addTest("Test 23", "*", 10, "0.3", "230", "69.0");
    tester.addTest("Test 24", "*", 10, "23", "3", "69");
    tester.addTest("Test 25", "*", 10, "0.23", "0.3", "0.069");

    // ! exception tests
    tester.addTest("Test 26", "%", 10, "0.3", "230", "ERROR:Invalid operator");
    tester.addTest("Test 27", "/", 10, "23", "3", "ERROR:Invalid operator");
    tester.addTest("Test 28", "+", 10, "0.2.3", "0.3", "ERROR:Invalid number");
    tester.addTest("Test 29", "*", 10, "0.3", "0.3.2", "ERROR:Invalid number");
    tester.addTest("Test 30", "+", 10, "$", "0.2", "ERROR:Invalid number");
    tester.addTest("Test 31", "*", 1, "0.3", "0.32", "ERROR:Invalid base");
    tester.addTest("Test 32", "+", -2, "0.2", "0.2", "ERROR:Invalid base");

    // ! run tests

    cout << "Running tests with GUI" << endl;
    tester.runTestsWithGUI();
    cout << endl;
    return 0;
}