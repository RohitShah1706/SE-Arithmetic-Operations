#!/bin/bash

# Compile the C++ files
g++ src/Digit.cpp src/Arithmetic/Add/AddArithmetic.cpp src/Operators/Add/AddOperator.cpp main.cpp -o main

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Executable created: main"
else
    echo "Compilation failed."
fi