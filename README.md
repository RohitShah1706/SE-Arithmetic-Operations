## Installation:
1. Clone the repository:  
`git clone https://github.com/RohitShah1706/SE-Arithmetic-Operations.git`

2. Change directory:  
`cd SE-Arithmetic-Operations`

3. Compile the program:
- For Linux: 
```bash
    chmod +x install.sh
    ./install.sh
```
- For Windows:  
```bash
    ./install.ps1
```

4. Run the program:  
`./main.out` for Linux  
`./main.exe` for Windows


## Testing:
1. Install CMake: https://cmake.org/download/
2. Possible error faced: https://stackoverflow.com/questions/45150172/cmake-error-cmake-was-unable-to-find-a-build-program-corresponding-to-mingw-ma 
3. Install google test on windows: https://www.youtube.com/watch?v=3zUqJEilhnM
4. Install make on windows: https://leangaurav.medium.com/how-to-setup-install-gnu-make-on-windows-324480f1da69

Command:
```bash
    cmake -G "MinGW Makefiles" -S . -B build
```