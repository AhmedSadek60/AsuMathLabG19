# Matrix C++ Project
  a c++ program for carrying out matrix operations.

## Environment
coded with c++ and compiled with g++.
works on linux os, tested on ubuntu 16.04 LTS

## Project phases
- [x] creating the C/C++ matrix class, and support basic operations
- [x] adding more complex operations, and supporting concatenation
- [x] adding Concatenation for Matrices
- [x] adding Expression Evaluation For Both only Numbers and Matrix operations


## Installation & Setup

- Firstly you need to have g++ or gcc or g++-gcc compiler in your local machine

- If you have it, you can skip this part if not please follow it even if you are windows or linux.

### For Windows Users :
- You can download and use both g++ or gcc compilers and use it from CMD like linux by insatalling :
- <a href="https://cygwin.com/install.html"><b>Cygwin</b></a>
- <a href="http://www.mingw.org/category/wiki/download"><b>MinGW</b></a>

- for tutorials to setup cygwin or mingw in your local machine you can also follow the docs in thier website or follow this youtube tutorial :
        - <a href="https://www.youtube.com/watch?v=DAlS4hF_PbY">https://www.youtube.com/watch?v=DAlS4hF_PbY</a>

### For Linux Users :
- You can just open your terminal and put the following command : 
```
sudo apt-get install g++
```
- if you have any errors so write the following commands : 
```
sudo apt-get update
sudo apt-get install g++  // or you can type gcc iif you want
```


### Cloning Project : 
- To get the porject you can just get the winrar from "Clone or Download" Button at the top
- Or you can clone it by terminal in linux but you must have it to install it follow the following commands :
```
sudo apt-get update
sudo apt-get install git
``` 

- then you can clone it in your local machine by typing in terminal :
```
git clone https://github.com/AhmedSadek60/AsuMathLabG19
```

- If you are a Windows User don't worry git provides tool called git bash you can download it from here : 
        - <a href="https://git-scm.com/downloads">https://git-scm.com/downloads</a>

- Then type in the git bash command : 
```
git clone https://github.com/AhmedSadek60/AsuMathLabG19
```

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
- You will Find the Outputs Seprated by Some Hashtags for both ( Command Line , Files ) Like this : 
```
B = 
1.2	5.7	4.2	1.4	

6.3	2.5	8.1	3.1	

6.4	2.8	7.1	8.1	

3.2	5.1	7.2	8.9	

######################################################
C = 
10.1	13	8.2	3.8	

8.6	9	17	6.2	

11.3	6.6	9.1	15.6	

13	8.5	8.2	17.8	
```


### supported operations
- add ( + )
- sub ( - )
- mult ( * )
- div ( / )
- elementWiseDiv ( ./ )
- elmentWisePow  ( .^ )
- elmentWiseAdd  ( .+ )
- elmentWiseSubtract  ( .- )
- elmentWiseMultiply  ( .* )

## debugging and enhancements

### Profiling 
- For Profiling We Use The <a href="http://gnuwin32.sourceforge.net/packages/gprof.htm"><b>Gprof Profiler</b></a> <br />
- You Will Find profiling results for the Two Files [ example.m , bigexample.m ] :
```code
- profilingexamplefile.txt
- profilingbigexamplefile.txt
- profilingbigexample2file.txt
- profilingadvexamplefile.txt
- profilingtrickyexamplefile.txt
- profilingerrorexamplefile.txt
```

### Outputs Form Files
- You can Find the Output of the Two Files :
```code
- outputexamplefile.txt
- outputbigexamplefile.txt
- outputbigexample2file.txt
- outputadvexamplefile.txt
- outputtrickyexamplefile.txt
- outputerrorexamplefile.txt
```

### Code Style 
- if you want to be a contributer to our code please follow the same styling here the commenting styling that all contributers follow :
- Commenting Style :
```c++
/*

[ Function Name ] : isInsideMatrix()
[ Returned Type ] : int
[ inherited Function from CMatrix Class ] : getName() - [ Inside File : CMatrix.cpp , Line : 167 ]
[ Functionality ] : To Get the Index of Parameter Matrix inside the Matrix vector so we can get the index
                    and use the matrix in this index anywhere else

*/

int isInsideMatrix(vector<CMatrix> matricesArray,string target) {
        bool found = false;
        int index = -1;
        for(int i =0;i < matricesArray.size();i++) {
                if(matricesArray[i].getName() == target) {
                        found = true;
                        index = i;
                }
        }
        return index;

}

```