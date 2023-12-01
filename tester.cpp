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
                cout << result.display() << " " << expected.display() << endl;
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
               << test.op << "\n"
               << test.d1.getBase() << "\n";
        }
        ss << "exit" << "\n"
           << "" << "\n"
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
                cout<<results[i]<<" "<< tests[i].expected.display()<<endl;
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

    // ! add tests(base-10)
    tester.addTest("Test 1", "+", Digit("12", 10), Digit("10", 10), Digit("22", 10));
    tester.addTest("Test 2", "+", Digit("12.22", 10), Digit("10", 10), Digit("22.22", 10));
    tester.addTest("Test 3", "+", Digit("123.456", 10), Digit("21.042353", 10), Digit("144.498353", 10));
    tester.addTest("Test 4", "+", Digit("1.232", 10), Digit("12.22", 10), Digit("13.452", 10));

    // ! add tests(base-2)
    tester.addTest("Test 5", "+", Digit("1101", 2), Digit("101", 2), Digit("10010", 2));
    tester.addTest("Test 6", "+", Digit("101.001", 2), Digit("1101", 2), Digit("10010.001", 2));
    tester.addTest("Test 7", "+", Digit("0.101", 2), Digit("0.1101", 2), Digit("1.0111", 2));
    tester.addTest("Test 8", "+", Digit("0.001", 2), Digit("0.1101", 2), Digit("0.1111", 2));

    // ! sub tests(base-10)
    tester.addTest("Test 9", "-", Digit("12", 10), Digit("10", 10), Digit("2", 10));
    tester.addTest("Test 10", "-", Digit("123.456", 10), Digit("21.042353", 10), Digit("102.413647", 10));
    tester.addTest("Test 11", "-", Digit("12", 10), Digit("0.02", 10), Digit("11.98", 10));
    tester.addTest("Test 12", "-", Digit("10", 10), Digit("123.02", 10), Digit("-113.02", 10));
    tester.addTest("Test 13", "-", Digit("99.64", 10), Digit("100.324", 10), Digit("-.684", 10));

    // ! sub tests(base-2)
    tester.addTest("Test 14", "-", Digit("1101", 2), Digit("101", 2), Digit("1000", 2));
    tester.addTest("Test 15", "-", Digit("101", 2), Digit("1101", 2), Digit("-1000", 2));

    // ! failed
    tester.addTest("Test 16", "-", Digit("101.101", 2), Digit("1101.1101", 2), Digit("-1000.0001", 2));
    tester.addTest("Test 17", "-", Digit("1101.1111", 2), Digit("101.111", 2), Digit("1000.0001", 2));
    tester.addTest("Test 18", "+", Digit("1101.1111", 2), Digit("11011", 2), Digit("0.0001", 2));


    // ! mult test()
    tester.addTest("Test 19","*",Digit("23",10), Digit("3",10), Digit("69",10));
    tester.addTest("Test 20","*",Digit("2.3",10), Digit("3",10), Digit("6.9",10));
    tester.addTest("Test 21","*",Digit("2.3",10), Digit("300",10), Digit("690.0",10));
    tester.addTest("Test 22","*",Digit("2.3",10), Digit("30",10), Digit("69.0",10));

    // ! mult tests
    tester.addTest("Test 23","*",Digit("0.3",10),Digit("230",10),Digit("69.0",10));
    tester.addTest("Test 24","*",Digit("23",10),Digit("3",10),Digit("69",10));
    tester.addTest("Test 25","*",Digit("0.23",10),Digit("0.3",10),Digit("0.069",10));
    
    // ! run tests
    // cout << "Running tests without GUI" << endl;
    // tester.runTestsWithoutGUI();
    // cout << endl;

    cout << "Running tests with GUI" << endl;
    tester.runTestsWithGUI();
    return 0;
}