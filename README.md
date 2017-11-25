# Matrix C++ Project
  a c++ program for carrying out matrix operations.

## Environment
coded with c++ and compiled with g++.
works on linux os, tested on ubuntu 16.04 LTS

## Project phases
- [x] creating the C/C++ matrix class, and support basic operations
- adding more complex operations, and supporting concatenation
- ???


## Installation & Setup

- To Run the Program You can use Command Line(CMD) For Windows or Linux Users :
```
make 
```
- Previous Command Will Generate a Binary File or exe file in windows
- You can run the executable file :
- For Linux 
```
./matrix
```
- For Windows
```
matrix.exe
```

- If you want to pass a file to the program :
- For Linux : 
```
./matrix [filename]
```
- For Windows :
```
matrix.exe [filename]
```


## Code example

creating a 2 x 3 matrix without displaying it:
```c++
a = [1 2 3; 4 5 6];
```

if you want to display it, leave out the semicolon:
```c++
b = [ 1 2 1; 1 4 4]
```

doing some operations:

```c++
c // Uninitialized Matrix
c = b[transpose]; // Make it Like That c = b' because of single qoute escape doesn't work here
c    // displays c
d = a * b    //error, invalid dimensions
d = c * a
e = c / a
f = 1 ./ a
g = [ 1 1 2; 1 1 1];
h = c / g   //error, g is not invertible (not a square matrix)
g = [ 1 1 1 ; 1 1 1; 1 1 1];
h = [1 2 3; 4 5 6; 7 8 9]
i = h / g   //error, g is not invertible (determinant of g is zero)
```

.or you can use an input file with operations stored in it:
```
./matrix example.m
```
### supported operations
- add ( + )
- sub ( - )
- mult ( * )
- div ( / )
- elementWiseDiv ( ./ )

## debugging and enhancements

### Profiling 
- For Profiling We Use The <a href="http://gnuwin32.sourceforge.net/packages/gprof.htm"><b>Gprof Profiler</b></a> <br />
- You Will Find profiling results for the Two Files [ example.m , bigexample.m ] :
```code
- profilingexamplefile.txt
- profilingbigexamplefile.txt
```

### Outputs Form Files
- You can Find the Output of the Two Files :
```code
- outputexamplefile.txt
- outputbigexamplefile.txt
```