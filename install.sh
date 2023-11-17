#!/bin/bash

# ! Define the paths
digitPath="src/Digit"
arithmeticPath="src/Arithmetic"
operatorsPath="src/Operators"
guiPath="src/GUI"

# ! Get the .cpp files in the directories
digitFiles=$(find $digitPath -name "*.cpp")
arithmeticFiles=$(find $arithmeticPath -name "*.cpp")
operatorsFiles=$(find $operatorsPath -name "*.cpp")
guiFiles=$(find $guiPath -name "*.cpp")

# ! Compile the C++ files and generate one single executable
g++ $digitFiles $arithmeticFiles $operatorsFiles $guiFiles main.cpp -o main.out

# ! Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Executable created: main.out"
else
    echo "Compilation failed."
fi