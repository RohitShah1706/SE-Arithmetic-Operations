#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "src/GUI/GUI.h"

class DigitTester
{
public:
    void addTest(const string &name, const string &op, const Digit &d1, const Digit &d2, const Digit &expected)
    {
        tests.push_back({name, op, d1, d2, expected});
    }

    void runTestsWithoutGUI()
    {
        GUI *gui = GUI::getInstance();
        int passed = 0;
        for (const auto &test : tests)
        {
            Digit d1 = test.d1;
            Digit d2 = test.d2;
            Digit expected = test.expected;
            Digit result = gui->getOperator(test.op)->operate(d1, d2);
            if (compareDigits(expected, result))
            {
                cout << "Test passed: " << test.name << endl;
                passed++;
            }
            else
            {
                cout << "Test failed: " << test.name << endl;
            }
        }
        cout << "Total tests: " << tests.size() << ", Passed: " << passed << ", Failed: " << tests.size() - passed << endl;
    }

    void runTestsWithGUI()
    {
        // ! Prepare the input
        std::stringstream ss;
        for (auto test : tests)
        {
            string s1 = test.d1.display();
            string s2 = test.d2.display();

            ss << s1 << "\n"
               << s2 << "\n"
               << test.op << "\n";
        }
        ss << "exit" << "\n"
           << "" << "\n"
           << "" << "\n";

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
            if (results[i] == tests[i].expected.display())
            {
                passed++;
                cout << "Test passed: " << tests[i].name << endl;
            }
            else
            {
                cout << "Test failed: " << tests[i].name << endl;
            }
        }
        cout << "Total tests: " << results.size() << ", Passed: " << passed << ", Failed: " << results.size() - passed << endl;
    }

private:
    struct TestCase
    {
        string name;
        string op;
        Digit d1;
        Digit d2;
        Digit expected;
    };

    vector<TestCase> tests;

    bool compareDigits(const Digit &d1, const Digit &d2)
    {
        if (d1 == d2)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    DigitTester tester;

    // ! add tests
    tester.addTest("Test 1", "+", Digit("12", 10), Digit("10", 10), Digit("22", 10));
<<<<<<< HEAD
    tester.addTest("Test 2", "+", Digit("123.456", 10), Digit("21.042353", 10), Digit("144.498353", 10));
    tester.addTest("Test 3", "+", Digit("12", 10), Digit("0.02", 10), Digit("12.02", 10));
=======
    tester.addTest("Test 2", "+", Digit("12.22", 10), Digit("10", 10), Digit("22", 10));
    tester.addTest("Test 3", "+", Digit("123.456", 10), Digit("21.042353", 10), Digit("144.498353", 10));
    tester.addTest("Test 4", "+", Digit("1.232", 10), Digit("12.22", 10), Digit("13.452", 10));
>>>>>>> f0a71ec012f1eb04fa2fec50b1f3af501b97378d

    // ! sub tests
    tester.addTest("Test 4", "-", Digit("12", 10), Digit("10", 10), Digit("2", 10));
    tester.addTest("Test 5", "-", Digit("123.456", 10), Digit("21.042353", 10), Digit("102.413647", 10));
    tester.addTest("Test 6", "-", Digit("12", 10), Digit("0.02", 10), Digit("11.98", 10));

    // ! run tests
    // cout << "Running tests without GUI" << endl;
    // tester.runTestsWithoutGUI();
    // cout << endl;

    cout << "Running tests with GUI" << endl;
    tester.runTestsWithGUI();
    return 0;
}