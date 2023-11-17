# Compile the C++ files
g++ src/Digit.cpp src/Arithmetic/Add/AddArithmetic.cpp src/Operators/Add/AddOperator.cpp main.cpp -o main
 
# Check if the compilation was successful
if ($LASTEXITCODE -eq 0) {
    Write-Output "Compilation successful. Executable created: main"
} else {
    Write-Output "Compilation failed."
}