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
g++ $digitFiles $arithmeticFiles $operatorsFiles $guiFiles main.cpp -o main
 
# ! Check if the compilation was successful
if ($LASTEXITCODE -eq 0) {
    Write-Output "Compilation successful. Executable created: main"
} else {
    Write-Output "Compilation failed."
}