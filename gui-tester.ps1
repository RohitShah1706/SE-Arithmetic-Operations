# ! Define the paths
$digitPath = "src/Digit"
$arithmeticPath = "src/Arithmetic"
$operatorsPath = "src/Operators"
$guiPath = "src/GUI"

$digitFiles = Get-ChildItem $digitPath -Recurse -Include *.cpp
$arithmeticFiles = Get-ChildItem $arithmeticPath -Recurse -Include *.cpp
$operatorsFiles = Get-ChildItem $operatorsPath -Recurse -Include *.cpp
$guiFiles = Get-ChildItem $guiPath -Recurse -Include *.cpp

# ! Compile the C++ files and generate one single executable
# g++ -fprofile-arcs -ftest-coverage $digitFiles $arithmeticFiles $operatorsFiles $guiFiles runtester.cpp -o runtester
g++ $digitFiles $arithmeticFiles $operatorsFiles $guiFiles runtester.cpp -o runtester
 
# ! Check if the compilation was successful
if ($LASTEXITCODE -eq 0) {
    Write-Output "Compilation successful. Executable created: runtester"
} else {
    Write-Output "Compilation failed."
    exit
}

# # ! Run the tests to generate the coverage data
# ./runtester

# # ! create the coverage folder if it doesn't exist
# if (!(Test-Path -Path coverage)) {
#     New-Item -ItemType Directory -Path coverage
# }

# # ! Generate the coverage report with lcov
# gcovr -r . --html --html-details -o coverage/coverage.html 