#!/bin/bash

# ! Define the paths
digitPath="src/Digit"
arithmeticPath="src/Arithmetic"
operatorsPath="src/Operators"

# ! Get the .cpp files in the directories
digitFiles=$(find $digitPath -name "*.cpp")
arithmeticFiles=$(find $arithmeticPath -name "*.cpp")
operatorsFiles=$(find $operatorsPath -name "*.cpp")

# ! Compile the C++ files and generate one single executable
g++ $digitFiles $arithmeticFiles $operatorsFiles main.cpp -o main

# ! Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Executable created: main"
else
    echo "Compilation failed."
fi