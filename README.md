# Matrix C++ Project
  a c++ program for carrying out matrix operations.

## Environment
coded with c++ and compiled with g++.
working on linux os, tested on ubuntu 16.04 LTS

## Project phases
- [x] creating the C/C++ matrix class, and support basic operations
- []  adding more complex operations, and supporting concatenation
- [] ???


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
c = b'\ ';
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
