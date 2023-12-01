#!/bin/bash

digitPath="./src/Digit/"
arithmeticPath="./src/Arithmetic/"
operatorsPath="./src/Operators"
guiPath="./src/GUI/"

digitFiles=$(find $digitPath -name "*.cpp")
arithmeticFiles=$(find $arithmeticPath -name "*.cpp")
operatorsFiles=$(find $operatorsPath -name "*.cpp")
guiFiles=$(find $guiPath -name "*.cpp")

# Compile the C++ files and generate one single executable
g++ -fprofile-arcs -ftest-coverage $digitFiles $arithmeticFiles $operatorsFiles $guiFiles tester.cpp -o test

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Executable created: test"
else
    echo "Compilation failed."
    exit 1
fi

# Run the tests to generate the coverage data
./test

# Create the coverage folder if it doesn't exist
if [ ! -d "coverage" ]; then
    mkdir coverage
fi

# Generate the coverage report with lcov
gcovr -r . --html --html-details -o coverage/coverage.html 

# Clean up the binaries generated
./cleanup.sh