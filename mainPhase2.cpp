#ifndef STUDENT_H
#define STUDENT_H

#include "CMatrix.h"
#include <iostream>
#include <string>
#include <fstream>
#include "stdarg.h"
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <time.h>
#include <cmath>
#include <regex>
#include "prefixevaluatormatrix.cpp"
#include <assert.h>
#include <math.h>

#endif

using namespace std;




class AssociativeNumber {
        string name;
        double value;
public:
        AssociativeNumber(string a,double b) {
                this->name = a;
                this->value = b;
        }

        string getName() {
                return name;
        }
        double getValue() {
                return value;
        }
        string setName(string a) {
                this->name = a;

        }
        double setValue(double b) {
                this->value = b;

        }

};



/*

[ Function Name ] : isInsideMatrix()
[ Returned Type ] : int*
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

/* ############################################################################# */

/*

[ Function Name ] : isInsideValues()
[ Returned Type ] : int
[ inherited Function from CMatrix Class ] : getName() - [ Inside File : CMatrix.cpp , Line : 167 ]
[ Functionality ] : To Get the Index of Parameter Matrix inside the Matrix vector so we can get the index
                    and use the matrix in this index anywhere else

*/

int isInsideAssociate(vector<AssociativeNumber> associateArray,string target) {
        bool found = false;
        int index = -1;
        for(int i =0;i < associateArray.size();i++) {
                if(associateArray[i].getName() == target) {
                        found = true;
                        index = i;
                }
        }
        return index;
}

/* ############################################################################# */
/*
[ Function Name ] : sinOperation
[ Returned Type ] : CMatrix
[ inherited Function or Operators from CMatrix Class ] :
                                                - setName() - [ Inside File : CMatrix.cpp , Line : 167 ]
                                                - sin Operator - [ Inside File : CMatrix.cpp , Line : 318 ] ==> uses += & add Function in the Same File
[ Functionality ] : To Make sinOperation to one Matrix we just pass the whole matrices vector and indeces of the target matrices,
                    and return a matrix that have the result
*/

CMatrix sinOperation(vector<CMatrix> &matricesArray,int a ,string target) {
  cout << target << endl;
        cout << a << endl;
        cout << matricesArray[0] << endl;
        CMatrix returnedResult = matricesArray[a].sin();
        returnedResult.setName(target);
        return returnedResult;
}

/*
[ Function Name ] : cosOperation
[ Returned Type ] : CMatrix
[ inherited Function or Operators from CMatrix Class ] :
                                                - setName() - [ Inside File : CMatrix.cpp , Line :  ]
                                                - cos Operator - [ Inside File : CMatrix.cpp , Line :  ]
[ Functionality ] : To Make cosOperation to one Matrix we just pass the whole matrices vector and indeces of the target matrices,
                    and return a matrix that have the result
*/

CMatrix cosOperation(vector<CMatrix> matricesArray,int a ,string target) {
        CMatrix returnedResult = matricesArray[a].cos();
        returnedResult.setName(target);
        return returnedResult;

}

/*
[ Function Name ] : tanOperation
[ Returned Type ] : CMatrix
[ inherited Function or Operators from CMatrix Class ] :
                                                - setName() - [ Inside File : CMatrix.cpp , Line :  ]
                                                - tan Operator - [ Inside File : CMatrix.cpp , Line :  ]
[ Functionality ] : To Make tanOperation to Two Matrices we just pass the whole matrices vector and indeces of the  target matrices,
                    and return a matrix that have the result
*/

CMatrix tanOperation(vector<CMatrix> matricesArray,int a ,string target) {
        CMatrix returnedResult = matricesArray[a].tan();
        returnedResult.setName(target);
        return returnedResult;
}


/*

[ Function Name ] : addOperation
[ Returned Type ] : CMatrix
[ inherited Function or Operators from CMatrix Class ] :
                                                - getName() - [ Inside File : CMatrix.cpp , Line : 167 ]
                                                - + Operator - [ Inside File : CMatrix.cpp , Line : 318 ] ==> uses += & add Function in the Same File
[ Functionality ] : To Make addOperation to Two Matrices we just pass the whole matrices vector and indeces of the two target matrices,
                    and return a matrix that have the result

*/

CMatrix addOperation(vector<CMatrix> matricesArray,int a,int b,string target) {
        CMatrix returnedResult = matricesArray[a] + matricesArray[b];
        returnedResult.setName(target);
        return returnedResult;

}
/* ############################################################################# */

/*

[ Function Name ] : addOperation
[ Returned Type ] : CMatrix
[ inherited Function or Operators from CMatrix Class ] :
                                                - getName() - [ Inside File : CMatrix.cpp , Line : 167 ]
                                                - + Operator - [ Inside File : CMatrix.cpp , Line : 318 ] ==> uses += & add Function in the Same File
[ Functionality ] : To Make addOperation to Two Matrices we just pass the whole matrices vector and indeces of the two target matrices,
                    and return a matrix that have the result

*/

CMatrix powOperation(vector<CMatrix> matricesArray, int a, string powerValue,string target) {
        CMatrix returnedResult = matricesArray[a] ^ atoi(powerValue.c_str());
        returnedResult.setName(target);
        return returnedResult;

}
/* ############################################################################# */

CMatrix elementWisePower(vector<CMatrix> matricesArray, int a, string powerValue,string target) {
    CMatrix result = matricesArray[a].elementWisePow(atof(powerValue.c_str()));
    result.setName(target);

    return result;



}
/* ############################################################################# */
CMatrix sqrtOperation(vector<CMatrix> matricesArray, int a,string target) {
    CMatrix result = matricesArray[a].sqrt();
    result.setName(target);

    return result;
}



/* ############################################################################# */
/*

[ Function Name ] : subOperation
[ Returned Type ] : CMatrix
[ inherited Function or Operators from CMatrix Class ] :
                                                - getName() - [ Inside File : CMatrix.cpp , Line : 167 ]
                                                - - Operator - [ Inside File : CMatrix.cpp , Line : 318 ] ==> uses += & add Function in the Same File
[ Functionality ] : To Make subOperation to Two Matrices we just pass the whole matrices vector and indeces of the two target matrices,
                    and return a matrix that have the result

*/


CMatrix subOperation(vector<CMatrix> matricesArray,int a,int b,string target) {
        CMatrix returnedResult = matricesArray[a] - matricesArray[b];
        returnedResult.setName(target);
        return returnedResult;

}
/* ############################################################################# */

/*

[ Function Name ] : multiplyOperation
[ Returned Type ] : CMatrix
[ inherited Function or Operators from CMatrix Class ] :
                                                - getName() - [ Inside File : CMatrix.cpp , Line : 167 ]
                                                - * Operator - [ Inside File : CMatrix.cpp , Line : 318 ] ==> uses += & add Function in the Same File
[ Functionality ] : To Make multiplyOperation to Two Matrices we just pass the whole matrices vector and indeces of the two target matrices,
                    and return a matrix that have the result

*/

CMatrix multiplyOperation(vector<CMatrix> matricesArray,int a,int b,string target) {
        CMatrix returnedResult = matricesArray[a] * matricesArray[b];
        returnedResult.setName(target);
        return returnedResult;

}
/* ############################################################################# */

/*

[ Function Name ] : addOperation
[ Returned Type ] : CMatrix
[ inherited Function or Operators from CMatrix Class ] :
                                                - getName() - [ Inside File : CMatrix.cpp , Line : 167 ]
                                                - getInverse() - [ Inside File : CMatrix.cpp , Line : 532 ]
                                                - * Operator - [ Inside File : CMatrix.cpp , Line : 318 ]
[ Functionality ] : To Make divideOperation to Two Matrices we just pass the whole matrices vector and indeces of the two target matrices,
                    and return a matrix that have the result

*/
CMatrix divideOperation(vector<CMatrix> matricesArray,int a,int b,string target) {
        CMatrix aMatrix = matricesArray[a];
        CMatrix bMatrix = matricesArray[b].getInverse();
        CMatrix returnedResult = aMatrix * bMatrix;
        returnedResult.setName(target);
        return returnedResult;

}
/* ############################################################################# */

/*

[ Function Name ] : transposeOperation
[ Returned Type ] : CMatrix
[ inherited Function or Operators from CMatrix Class ] :
                                                - getName() - [ Inside File : CMatrix.cpp , Line : 167 ]
                                                - getTranspose() - [ Inside File : CMatrix.cpp , Line : 522 ]
[ Functionality ] : To Make addOperation to Two Matrices we just pass the whole matrices vector and indeces of the two target matrices,
                    and return a matrix that have the result

*/


CMatrix transposeOperation(vector<CMatrix> &matricesArray,int a,string target) {
        CMatrix returnedResult = matricesArray[a].getTranspose();
        returnedResult.setName(target);
        return returnedResult;

}

/* ############################################################################# */

/*

[ function name] : randFunction
[ return type] : CMatrix
[ inherited function/operation ] : -CMatrix Constructor [CMatrix.cpp, line: 22]
[ functionality ] : Initializes a matrix of Random-value elements with given number of rows & columns  User input ex: rand(4, 4)

*/

CMatrix randFunction(string rowsNumber, string columnsNumber, string target)
{
        int numR= atof(rowsNumber.c_str());
        int numC = atof(columnsNumber.c_str());
        CMatrix returnedResult = CMatrix(target, numR, numC, CMatrix::MI_RAND, 0.0);
        return returnedResult;
}

/* ############################################################################# */

/*

[ function name] : eyeFunction
[ return type] : CMatrix
[ inherited function/operation ] : -CMatrix Constructor [CMatrix.cpp, line: 22]
[ functionality ] : Initializes a matrix of UNITY with given number of rows & columns  User input ex: eye(4, 4)

*/

CMatrix eyeFunction(string rowsNumber, string columnsNumber, string target)
{
        int numR= atof(rowsNumber.c_str());
        int numC = atof(columnsNumber.c_str());
        CMatrix returnedResult = CMatrix(target, numR, numC, CMatrix::MI_EYE, 0.0);
        return returnedResult;
}


/* ############################################################################# */

/*

[ function name] : elementWiseDivOperationNumber
[ return type] : CMatrix
[ inherited function/operation ] : -getnR() [CMatrix.cpp, line: ]
                                   -getnC() [CMatrix.cpp, line: ]
                                   -elementWiseDiv() [CMatrix.cpp, line: ]
                                   -setName() [CMatrix.cpp, line: ]
[ functionality ] : converts the first parameter (that is number) of type string to float and constructs a full matrix with it,
                    then performs element wise division with the second parameter (that is a matrix given by the user)

/*#################################################################################*/

CMatrix ZEROSFunction(string rowsNumber, string columnsNumber, string target)
{
        int numR= atof(rowsNumber.c_str());
        int numC = atof(columnsNumber.c_str());
        CMatrix returnedResult = CMatrix(target, numR, numC, CMatrix::MI_ZEROS, 0.0);
        return returnedResult;
}
/*#################################################################################*/

CMatrix ONESFunction(string rowsNumber, string columnsNumber, string target)
{
        CMatrix temp;
        CMatrix returnedResult(target,atof(rowsNumber.c_str()),atof(columnsNumber.c_str()),CMatrix::MI_ONES, 0.0);
        return returnedResult;
}
/*#################################################################################*/


CMatrix elmentWiseDivOperationNumber(vector<CMatrix> &matricesArray,int a,string number,string target) {

        int num = atof(number.c_str());
        CMatrix aMatrix = matricesArray[a];
        CMatrix dMatrix(aMatrix.getnR(),aMatrix.getnC(),CMatrix::MI_VALUE,num);
        CMatrix returnedResult = dMatrix.elementWiseDiv(aMatrix);
        returnedResult.setName(target);
        return returnedResult;

}

/* ############################################################################# */

/*

[ function name] : elementWiseDivOperationNormal
[ return type] : CMatrix
[ inherited function/operation ] : -elementWiseDiv() [CMatrix.cpp, line: ]
                                                      -setName() [CMatrix.cpp, line: ]
[ functionality ] : performs element wise division with the first and second parameters (that are matrices given by the user)

*/

CMatrix elmentWiseDivOperationNormal(vector<CMatrix> &matricesArray,int a,int b,string target) {

        CMatrix aMatrix = matricesArray[a];
        CMatrix bMatrix = matricesArray[b];
        CMatrix returnedResult = bMatrix.elementWiseDiv(aMatrix);
        returnedResult.setName(target);
        return returnedResult;

}

/* ############################################################################# */

/*
[ function name] : logOperation
[ return type] : CMatrix
[ inherited function/operation ] : getLog() [CMatrix.cpp, line: ]
[ functionality ] : Performs Log operation on Matrices
*/

CMatrix logOperation(vector<CMatrix> &matricesArray,int a,string target)
{
        CMatrix returnedResult = matricesArray[a].getLog();
        returnedResult.setName(target);
        return returnedResult;
}

/* ############################################################################# */

/*
[ function name] : lnOperation
[ return type] : CMatrix
[ inherited function/operation ] : getLn() [CMatrix.cpp, line: ]
[ functionality ] : Performs Log operation on Matrices
*/

CMatrix lnOperation(vector<CMatrix> &matricesArray,int a,string target)
{
        CMatrix returnedResult = matricesArray[a].getLn();
        returnedResult.setName(target);
        return returnedResult;
}

/* ############################################################################# */

/*

[ function name] : checkAlpha
[ return type] : bool
[ inherited function/operation ] : none
[ functionality ] : checks if the string parameter is a number

*/

bool checkNumeric(const string &str) {
    bool allDigits = true;
    for (int i = 0; i < str.size(); i++)
        if (!isdigit(str[i]) && str[i] != '.')
                allDigits = false;
    return allDigits;
}

/* ############################################################################# */




/*
        [ Function Name ] : replaceMatrixOperator(string x)
        [ Function Return Type ] : string
        [ Function Inherited Function ] :
                                        - size() from <string>
                                        - replace() from <string>
        [ Functionality ] : Replace Matrix Operators [ .+ , .- , .* , ./ , .^ ] to [ @ , ? , # , $ , & ]
*/

string replaceMatrixOperator(string x) {


for(int i = 0 ; i < x.size();i++) {
        if(x[i] == '.' && x[i + 1] == '+') {
                x.replace(i,2,"@");
        } else if(x[i] == '.' && x[i + 1] == '-') {
                x.replace(i,2,"?");
        } else if(x[i] == '.' && x[i + 1] == '*') {
                x.replace(i,2,"#");
        } else if(x[i] == '.' && x[i + 1] == '/') {
                x.replace(i,2,"$");
        } else if(x[i] == '.' && x[i + 1] == '^') {
                x.replace(i,2,"&");
        }

}


        return x;
}


CMatrix getEvaluationForMatrix(string token,vector<CMatrix> matricesArray) {

        token.erase(remove_if(token.begin(), token.end(), ::isspace), token.end());
        // token = replaceTriagomtric(token);
        token = replaceNegativeNumbersForMatrix(token);

        Exp *finalResult = strToExp(token);
        string tempFinal;
        tempFinal += finalResult->print();
            cout << tempFinal << endl;
        vector<string> tokens;
        tokens.clear();
        tokenizeForMatrix(tempFinal, tokens);
        if(tokens.size()) {
                CMatrix resultFromEval = evalPrefixForMatrix(tokens,matricesArray);
                return resultFromEval;
        }


}




/*
        [ Function Name ] :
        [ Function Returned Type ] :
        [ Function Inherited Function ] :
        [ Functionality ] :
*/

double getEvaluation(string token) {

        token.erase(remove_if(token.begin(), token.end(), ::isspace), token.end());
        token = replaceTriagomtric(token);
        token = replaceNegativeNumbers(token);


        Exp *finalResult = strToExp(token);
        string tempFinal;
        tempFinal += finalResult->print();
        vector<string> tokens;
        tokens.clear();
        tokenize(tempFinal, tokens);
        if(tokens.size()) {
                return evalPrefix(tokens);
        }

}

/* ############################################################################# */
/*
        [ Function Name ] :
        [ Function Return Type ] :
        [ Function Inherited Function ] :
        [ Functionality ] :
*/

string tokenizingMatrix(string data,vector<CMatrix> matricesArray,vector<AssociativeNumber> associateValuesArray) {

        data.erase(remove(data.begin(), data.end(), '['), data.end());
        data.erase(remove(data.begin(), data.end(), ']'), data.end());
        int pos;
        string token;
        string finalMatrixString = "";
           regex re("[;%]+");
    sregex_token_iterator it(data.begin(), data.end(), re, -1);
    sregex_token_iterator reg_end;
    for (; it != reg_end; ++it) {
            string content = it->str();
            content += " ";

while ((pos = content.find(" ")) != std::string::npos )
        {
            token = content.substr(0,pos);
            smatch s;
            string tempRegx = token;
        //     bool isNumber = regex_search(tempRegx,s,regex("[\d.]+"));
            bool isChar = regex_search(tempRegx,s,regex("[A-Za-z]+"));
            bool isOperation = regex_search(tempRegx,s,regex("[+\/*^-]+"));
            if(isOperation == 0 && isChar == 0) { // is Number
                token.erase(std::remove(token.begin(), token.end(), ';'), token.end());
                token.erase(remove_if(token.begin(), token.end(), ::isspace), token.end());
                    finalMatrixString += token + " ";
            } else if(isOperation == 1) { // is Operation
                // Replace Operation
                finalMatrixString += std::to_string(getEvaluation(token)) + " ";


            } else if(isChar == 1) {
                    // Check Arrays Then Replace
                token.erase(std::remove(token.begin(), token.end(), ';'), token.end());
                token.erase(remove_if(token.begin(), token.end(), ::isspace), token.end());
                int isInMatrix = isInsideMatrix(matricesArray,token);
                int isInAssociate = isInsideAssociate(associateValuesArray,token);

                if(isInMatrix == -1 && isInAssociate != -1) { // Inside Values
                        double charValue = associateValuesArray[isInAssociate].getValue();
                        finalMatrixString += std::to_string(charValue) + " ";


                } else if(isInAssociate == -1 && isInMatrix != -1) { // Inside Matrix
                        string matrixForm = matricesArray[isInMatrix].getMatrixForm();
                        return matrixForm;

                } else { // Not Found

                }

            }


            content.erase(0, pos + 1);

        }

        finalMatrixString += ";";


    }

        return finalMatrixString;
}







/* ############################################################################# */
/*
        [ Function Name ] : concatMatrices(string content,string name)
        [ Function Return Type ] : CMatrix
        [ Function Inherited Function ] :
                                        - Regular Expression From <regex>
                                        - iterator From <iterator> & <regex>
                                        - size() from <vector>
                                        - push_back() from <vector>
                                        - back() from <vector>
                                        - pop_back() from <vector>
                                        - getnC() , getnR() , setName() From CMatrix.cpp File
        [ Functionality ] : Concatenate the Matrices
*/

CMatrix concatMatrices(string content,string name,vector<CMatrix> matricesArray,vector<AssociativeNumber> associateValuesArray) {
        CMatrix matrixConcat;
//     content.erase(0,1);
//     content.erase(content.length() - 1);
    for(int i = 0 ; i < content.length() - 1;i++) {
        if(content[i] == '[' && i != 0) {
            for(int j = i + 1;j < i - content.find(']',i);j++) {
                if(content[j] == ']') {
                    break;
                }
                if(content[j] == ';') {
                    content[j] = '%';
                }

            }
        }

    }

    // Start the Concatentation



    regex re("[;\\n]+");
    string tempTest = content;
    sregex_token_iterator it(tempTest.begin(), tempTest.end(), re, -1);
    sregex_token_iterator reg_end;
    for (; it != reg_end; ++it) {
            string tempTokenizing = it->str();
            if(std::count(tempTokenizing.begin() , tempTokenizing.end() , '[') > 1) {
                vector<CMatrix> matrixConcatCols;
                regex re2("[\\[\\],]+");
                sregex_token_iterator it2(tempTokenizing.begin(), tempTokenizing.end(), re2, -1);
                sregex_token_iterator reg_end2;
                for(;it2 != reg_end2;++it2) {
                    string testString = it2->str();
                    string secondTempString = testString;
                    secondTempString = tokenizingMatrix(secondTempString,matricesArray,associateValuesArray);
                    CMatrix temp(secondTempString);
                    if(temp.getnC() != 0 && temp.getnR() != 0) {
                        matrixConcatCols.push_back(temp);
                    }
                }
                for(int i = 0; i < matrixConcatCols.size();i++) {
                        CMatrix first = matrixConcatCols.back();
                        matrixConcatCols.pop_back();
                        CMatrix second = matrixConcatCols.back();
                        matrixConcatCols.pop_back();
                        second.addColumn(first);
                        matrixConcatCols.push_back(second);
                }
                matrixConcat.addRow(matrixConcatCols[0]);
                matrixConcatCols.pop_back();

            } else {
                    tempTokenizing = tokenizingMatrix(tempTokenizing,matricesArray,associateValuesArray);
                    CMatrix temp(tempTokenizing);
                    matrixConcat.addRow(temp);
            }

    }


    matrixConcat.setName(name);
    return matrixConcat;





}
/* ############################################################################# */
string replaceStrChar(string str, const string& replace, char ch) {

  // set our locator equal to the first appearance of any character in replace
  size_t found = str.find_first_of(replace);

  while (found != string::npos) { // While our position in the sting is in range.
    str[found] = ch; // Change the character at position.
    found = str.find_first_of(replace, found+1); // Relocate again.
  }

  return str; // return our new string.
}



string getFileContents(char * fileName) {

        std::ifstream ifs( fileName );
        std::string content( (std::istreambuf_iterator<char>(ifs) ),
        (std::istreambuf_iterator<char>()    ) );


        return content;
}



/* ############################################################################# */


// --------------------------- parsingPhase2 -----------------------------------------------

/*

input: char* filename
funcion: reassigns '\n' where needed, avoiding (handling) the concatenation case.
return: string content

*/

string readjustingNewLines(char* fileName){
  std::ifstream ifs( fileName );
  std::string content( (std::istreambuf_iterator<char>(ifs) ), (std::istreambuf_iterator<char>()  ) );

  for (int i = 0; i < content.length(); ++i){
    if(content[i] == '\n'){
      int k = i;
      while( isspace(content[k+1]) )   // skipping spaces
        ++k;
      assert( isspace(content[k+1]) == 0 );
      if ( isdigit(content[k+1]) == 1 || content[k+1]  == '[' )
        content[i] = ';';
    }
  }

  return content;
}

/*

input: string line, string &variableName, string &operationLine, bool &verbose
funcion: parses the variable name on the lhs of the = sign, and the operation line on the rhs of the = sign.
         checks if the variable value needs printing afterwards.
return: void

*/
void parse( string line, string &variableName, string &operationLine, bool &verbose ){

  if(line[line.length() - 1] == ';'){ // if last char is a semicolon, then we're not printing the variable value
    verbose = false;
    line = line.substr( 0, line.length() - 1 ); // removing the semicolon
  }
  else
    verbose = true;

  if( line.find("=") == string::npos){  // no operation in the line, just the variable name
    variableName = line.substr(0);
    operationLine = "";
  }
  else{
    variableName = line.substr( 0, line.find('=') ); // paring lhs of the = sign
    operationLine = line.substr(line.find('=') + 1); // parsing rhs of the = sign
  }

    variableName.erase(std::remove(variableName.begin(),variableName.end(),' '),variableName.end()); // removing spaces
    // operationLine.erase(std::remove(operationLine.begin(),operationLine.end(),' '),operationLine.end()); // removing spaces

    int i = 0;
    while(operationLine[i] == ' '){ // removing spaces from the beginning of the line
      operationLine = operationLine.substr(i + 1);
      ++i;
    }

}

/*

input: vector<CMatrix>& matrices, vector<AssociativeNumber>& associateValues,
       string variableName, string operationLine, bool verbose
funcion: executes the operations on the rhs of the = sign, and stores the value in the corresponding vector
return: void

*/
void execute(  vector<CMatrix>& matrices, vector<AssociativeNumber>& associateValues, string variableName, string operationLine, bool verbose ){

  int matrixIndex = isInsideMatrix(matrices, variableName);
  int associativeNumberIndex = isInsideAssociate(associateValues, variableName);

  if(operationLine == ""){ // no operation
    if(verbose)  // printing the variable value
      if( matrixIndex != -1 ){
        cout<<variableName<<" ="<<endl;
        cout<<matrices[matrixIndex]<<endl;
      }
      else if( associativeNumberIndex != -1 ){
        cout<<variableName<<" ="<<endl;
        cout<<associateValues[associativeNumberIndex].getValue()<<endl;
      }
  }
  else{ // operation lines

    operationLine = replaceMatrixOperator(operationLine); // replacing unary operations with binary ones

    size_t countBracketsForConcatenation = std::count(operationLine.begin(),operationLine.end(),'[');

    if(countBracketsForConcatenation > 1) { // case of concatenation concatenation
        cout << "Concatenated Matrix : " << endl;
        CMatrix finalMatrix = concatMatrices(operationLine, variableName, matrices, associateValues);
        matrices.push_back(finalMatrix);
        if(verbose){
          cout << finalMatrix.getName() << " = " << endl;
          cout << finalMatrix;
        }
    }
    else if(countBracketsForConcatenation == 1) {  // case of constructing a matrix
        operationLine  = tokenizingMatrix(operationLine, matrices,associateValues);
        CMatrix normalMatrix(operationLine) ;
        normalMatrix.setName(variableName);
        matrices.push_back(normalMatrix);
        if(verbose){
          cout << normalMatrix.getName() << " = " << endl;
          cout << normalMatrix;
        }
    }
    else if(countBracketsForConcatenation == 0) { // case of operations with numbers and/or matrices!

      // three cases: - special functions: ones, zeros, rand, eye
      //              - operations with numbers only
      //              - operations with matrices

      // if (special function) {}
      // else{
      //       if ( numbers only) {}
      //       else {}
      //     }

      if(operationLine.find("ones") != std::string::npos) {
        operationLine.erase(std::remove(operationLine.begin(), operationLine.end(), ' '), operationLine.end());
        string rowsNumber = operationLine.substr(operationLine.find('(') + 1, operationLine.find(',') - (operationLine.find('(') + 1));
        string columnsNumber = operationLine.substr(operationLine.find(',') + 1, operationLine.find(')') - (operationLine.find(',') + 1));

        CMatrix resultMatrix = ONESFunction(rowsNumber, columnsNumber, variableName);
        matrices.push_back(resultMatrix);

        if(verbose){
          cout << resultMatrix.getName() << " = " << endl;
          cout << resultMatrix<<endl;
        }
      }
      else if(operationLine.find("zeros") != std::string::npos) {
        operationLine.erase(std::remove(operationLine.begin(), operationLine.end(), ' '), operationLine.end());
        string rowsNumber = operationLine.substr(operationLine.find('(') + 1, operationLine.find(',') - (operationLine.find('(') + 1));
        string columnsNumber = operationLine.substr(operationLine.find(',') + 1, operationLine.find(')') - (operationLine.find(',') + 1));

        CMatrix resultMatrix = ZEROSFunction(rowsNumber, columnsNumber, variableName);
        matrices.push_back(resultMatrix);

        if(verbose){
          cout << resultMatrix.getName() << " = " << endl;
          cout << resultMatrix<<endl;
        }
      }
      else if(operationLine.find("rand") != std::string::npos) {
        operationLine.erase(std::remove(operationLine.begin(), operationLine.end(), ' '), operationLine.end());
        string rowsNumber = operationLine.substr(operationLine.find('(') + 1, operationLine.find(',') - (operationLine.find('(') + 1));
        string columnsNumber = operationLine.substr(operationLine.find(',') + 1, operationLine.find(')') - (operationLine.find(',') + 1));

        CMatrix resultMatrix = randFunction(rowsNumber, columnsNumber, variableName);
        matrices.push_back(resultMatrix);

        if(verbose){
          cout << resultMatrix.getName() << " = " << endl;
          cout << resultMatrix<<endl;
        }
      }
      else if(operationLine.find("eye") != std::string::npos) {
        operationLine.erase(std::remove(operationLine.begin(), operationLine.end(), ' '), operationLine.end());
        string rowsNumber = operationLine.substr(operationLine.find('(') + 1, operationLine.find(',') - (operationLine.find('(') + 1));
        string columnsNumber = operationLine.substr(operationLine.find(',') + 1, operationLine.find(')') - (operationLine.find(',') + 1));

        CMatrix resultMatrix = eyeFunction(rowsNumber, columnsNumber, variableName);
        matrices.push_back(resultMatrix);

        if(verbose){
          cout << resultMatrix.getName() << " = " << endl;
          cout << resultMatrix<<endl;
        }
      }
      else{
        // if numbers only

        AssociativeNumber temp(variableName,getEvaluation(operationLine) );
        associateValues.push_back(temp);
        if(verbose)
          cout << temp.getName() << " = " << temp.getValue() << endl;

        // else (matrices (and numbers))

      }
    }


   //     else if(content.find("log") != std::string::npos)
   //     {
   //         content.erase(std::remove(content.begin(), content.end(), ' '), content.end());
   //         string firstParameter = content.substr( content.find('log(') + 1, content.find(')') -  content.find('log(') - 1 ) ;
   //         if(isdigit(firstParameter[0])) {
   //           continue;
   //         } else {
   //             CMatrix resultMatrix = logOperation(matrices, isInsideMatrix(matrices, firstParameter), name);
   //             matrices.push_back(resultMatrix);
   //
   //             if(content.find(';') == std::string::npos) {
   //                 cout << resultMatrix.getName() << " = " << endl;
   //                 cout << resultMatrix;
   //                 cout << "######################################################" << endl;
   //             }
   //
   //         }
   //
   //   }
   //
   //   else if (content.find("^") != std::string::npos){
   //     content.erase(std::remove(content.begin(), content.end(), ' '), content.end());
   //     string firstParameter = content.substr( 0, content.find('^'));
   //     string secondParameter = content.substr(content.find('^') + 1);
   //
   //     cout<<firstParameter<<endl;
   //     cout<<secondParameter<<endl;
   //     cout<<name<<endl;
   //
   //     CMatrix resultMatrix = powOperation(matrices, isInsideMatrix(matrices, firstParameter), secondParameter, name );
   //     matrices.push_back(resultMatrix);
   //
   //     if(content.find(';') == std::string::npos) {
   //         cout << resultMatrix.getName() << " = " << endl;
   //         cout << resultMatrix;
   //         cout << "######################################################" << endl;
   //     }
   //
   //
   //
   //   }
   //
   //         else if (content.find("&") != std::string::npos){
   //           content.erase(std::remove(content.begin(), content.end(), ' '), content.end());
   //           string firstParameter = content.substr( 0, content.find('&'));
   //           string secondParameter = content.substr(content.find('&') + 1);
   //           //
   //           // cout<<firstParameter<<endl;
   //           // cout<<secondParameter<<endl;
   //           // cout<<name<<endl;
   //
   //           CMatrix resultMatrix = elementWisePower(matrices, isInsideMatrix(matrices, firstParameter), secondParameter, name );
   //           matrices.push_back(resultMatrix);
   //
   //           if(content.find(';') == std::string::npos) {
   //               cout << resultMatrix.getName() << " = " << endl;
   //               cout << resultMatrix;
   //               cout << "######################################################" << endl;
   //           }
   //
   //
   //
   //         }
   //         else if (content.find("sqrt") != std::string::npos){
   //           content.erase(std::remove(content.begin(), content.end(), ' '), content.end());
   //           string firstParameter = content.substr( content.find('sqrt(') + 1, content.find(')') -  content.find('log(') - 1 ) ;
   //           if(isdigit(firstParameter[0])) {
   //             continue;
   //           } else {
   //               CMatrix resultMatrix = sqrtOperation(matrices, isInsideMatrix(matrices, firstParameter), name);
   //               matrices.push_back(resultMatrix);
   //
   //               if(content.find(';') == std::string::npos) {
   //                   cout << resultMatrix.getName() << " = " << endl;
   //                   cout << resultMatrix;
   //                   cout << "######################################################" << endl;
   //               }
   //           }
   //         }


  }

}



int main(int argc, char* argv[]){

  vector<CMatrix> matrices;
  vector<AssociativeNumber> associateValues;

  string content, // carries the whole file
         line,    // carries one Line
         variableName, // carries the variable name (lhs of the = sign if it exists)
         operationLine; // carries the rhs of the = sign if it exists

  bool verbose; // for (not) showing variable value


  if(argc > 1) { // reading from file

    content = readjustingNewLines(argv[1]); // no '\n' after last line
    // cout<< content;
    std::istringstream fileStream(content);
    while(getline(fileStream, line)){
      parse(line, variableName, operationLine, verbose);
      // cout<<"variable name:"<<variableName<<endl;
      // cout<<"operation line:"<<operationLine<<endl;
      // cout<<"verbose: "<<verbose<<endl;
      // cout<<"------------------------------------"<<endl;
      if(variableName == "" && operationLine == "") // skipping empty lines in the file
        continue;

      execute(matrices, associateValues, variableName, operationLine, verbose);
    }

  }
  // else{ // working from cmd line
  //
  //   string s;
  //   string line;
  //
  //   while(1) {
  //     getline(cin, s);
  //
  //     if(s.find('[') != string::npos && s.find(']') == string::npos ) {
  //         getline(cin,line, ']');
  //         string name = "";
  //         name += s[0];
  //         CMatrix temp(name, line);
  //         matrices.push_back(temp);
  //
  //
  //           getline(cin ,semicolonCheck);
  //           if(semicolonCheck == "") {
  //                   cout << temp.getName() << " = " << endl;
  //                   cout << temp;
  //                   cout << "######################################################" << endl;
  //
  //           } else if(semicolonCheck == ";"){
  //                   semicolonCheck = "";
  //           }
  //
  //     }
  //
  //
  //
  // }



  return 0;
}
