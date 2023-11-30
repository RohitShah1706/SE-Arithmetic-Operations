#include <iostream>
#include <bits/stdc++.h>
#include "src/GUI/GUI.h"

class DigitTester {
public:
    void addTest(const string& name, const string& op, const Digit& d1, const Digit& d2, const Digit& expected) {
        tests.push_back({name, op, d1, d2, expected});
    }

    void runTests() {
        GUI *gui = GUI::getInstance();
        int passed = 0;
        for (const auto& test : tests) {
            Digit d1 = test.d1;
            Digit d2 = test.d2;
            Digit expected = test.expected;
            Digit result = gui->getOperator(test.op)->operate(d1, d2);
            if (compareDigits(expected, result)) {
                cout << "Test passed: " << test.name << endl;
                passed++;
            } else {
                cout << "Test failed: " << test.name << endl;
            }
        }
        cout << "Total tests: " << tests.size() << ", Passed: " << passed << ", Failed: " << tests.size() - passed << endl;
    }

private:
    struct TestCase {
        string name;
         string op;
        Digit d1;
        Digit d2;
        Digit expected;
    };

    vector<TestCase> tests;

    bool compareDigits(const Digit& d1, const Digit& d2) {
        if (d1 == d2) {
            return true;
        }
        return false;
    }
};

int main() {
    DigitTester tester;

    // ! add tests
    tester.addTest("Test 1", "+", Digit("12", 10), Digit("10", 10), Digit("22", 10));
    tester.addTest("Test 2", "+", Digit("123.456", 10), Digit("21.042353", 10), Digit("144.498353", 10));
    tester.addTest("Test 3", "+", Digit("12", 10), Digit("0.02", 10), Digit("12.02", 10));

    // ! sub tests
    tester.addTest("Test 4", "-", Digit("12", 10), Digit("10", 10), Digit("2", 10));
    tester.addTest("Test 5", "-", Digit("123.456", 10), Digit("21.042353", 10), Digit("102.413647", 10));
    tester.addTest("Test 6", "-", Digit("12", 10), Digit("0.02", 10), Digit("11.98", 10));

    // ! run tests
    tester.runTests();
    return 0;
}