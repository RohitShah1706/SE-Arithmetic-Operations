# ! Define the paths
$digitPath = "src/Digit"
$arithmeticPath = "src/Arithmetic"
$operatorsPath = "src/Operators"

$digitFiles = Get-ChildItem $digitPath -Recurse -Include *.cpp
$arithmeticFiles = Get-ChildItem $arithmeticPath -Recurse -Include *.cpp
$operatorsFiles = Get-ChildItem $operatorsPath -Recurse -Include *.cpp

# ! Compile the C++ files and generate one single executable
g++ $digitFiles $arithmeticFiles $operatorsFiles main.cpp -o main
 
# ! Check if the compilation was successful
if ($LASTEXITCODE -eq 0) {
    Write-Output "Compilation successful. Executable created: main"
} else {
    Write-Output "Compilation failed."
}