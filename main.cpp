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

*/

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
void programLoopFromFile(char* fileName){

          vector<CMatrix> matrices;

        // string content = getFileContents(fileName);
        // string::size_type pos = 0; // Must initialize
        // while ( ( pos = content.find ("\r\n",pos) ) != string::npos )
        // {
        //         content.replace(pos, 2 , "<");
        // }
        //
        // vector<string>fileData;
        // for(int i = 0; i < content.length() ; i++) {
        //         if(content.find("<") != std::string::npos) {
        //                 if(content[content.find("<") - 1] == ']') {
        //                 int findTag = content.find("<");
        //                 int anotherTag = content.find("<" , findTag + 1);
        //                 if(content.substr(0 , anotherTag).length() >= 1) {
        //                         fileData.push_back(content.substr(0 , anotherTag));
        //                 }
        //                 content.erase(0 , anotherTag);
        //
        //                 } else {
        //
        //                 if(content.substr(0 , "<").length() >= 1) {
        //                         fileData.push_back(content.substr(0 , content.find("<")));
        //                 }
        //                 content.erase(0 , content.find("<") + 1);
        //
        //                 }
        //         }
        //
        //
        // }
        //
        //
        // for(int i = 0; i < fileData.size();i++) {
        //         if(fileData[i].length() == 0) {
        //                 fileData[i] = "Empty Line";
        //         }
        //         cout << fileData[i] << endl;
        //         cout << "#########################"<<endl;
        // }


// ---------------------------

std::ifstream ifs( fileName );
std::string content( (std::istreambuf_iterator<char>(ifs) ), (std::istreambuf_iterator<char>()  ) );
// std::istringstream f(content);
std::string operationLine;

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

for (int i = 0; i < content.length(); ++i){
cout<<content[i];
}
cout<<endl;












        //   content.erase(std::remove(content.begin(), content.end(), '\n'), content.end());
// string fileData = content;
// string tempString = "";
// for(int i = 0 ; i < 15 ; i++) {
//         int fooundNewLine = fileData.find('\n');
//         if(fooundNewLine != -1) {
//                 // cout << fooundNewLine << endl;
//                 if(fileData[fooundNewLine - 1] == ']' || fileData[fooundNewLine - 1] == ';') {
//                         fooundNewLine = fileData.find('\n' , fooundNewLine + 2);
//                         tempString += fileData.substr(0 ,fooundNewLine + 1 );
//                         // cout << tempString << endl;
//                 } else {
//                         tempString += fileData.substr(0,fooundNewLine + 1);
//                         // cout << tempString << endl;
//                         fileData.erase(0,fileData.find('\n') + 1);
//                         // cout << fileData << endl;

//                 }

//         }
//         // cout << fooundNewLine << endl;
//         // fileData[fooundNewLine] = '@';
//         // cout << fileData << endl;
// }
//   std::istringstream f(content);
//   std::string operationLine;


        // cout << endl;

//   cout << content << endl;

// cout << fileData << endl;

//   size_t countSqaures = std::count(content.begin(),content.end() , ']');
//   bool flag = false;

//   for(int i = 0 ;i < countSqaures + 1;i++) {

//           size_t found = content.find('[');
//           if(found != std::string::npos) {
//           string matrixData,matrixName;
//           matrixData = content.substr(0,content.find(']') + 1);
//           matrixName = matrixData.substr(0,content.find('='));
//           matrixName.erase(std::remove(matrixName.begin(),matrixName.end(),' '),matrixName.end());
//           matrixName.erase(std::remove(matrixName.begin(), matrixName.end(), '\n'), matrixName.end());
//           matrixData.erase(0,matrixData.find('['));
//           matrixData.erase(std::remove(matrixData.begin(), matrixData.end(), '\n'), matrixData.end());


//           CMatrix temp(matrixName,matrixData);
//           matrices.push_back(temp);
//           int indexOfSemicolon = content.find(']') + 1;
//           if(content[indexOfSemicolon] != ';') {
//                   cout << temp.getName() << " = " << endl;
//                   cout << temp;
//                   cout << "######################################################" << endl;
//           }
//           content.erase(0,content.find('=',content.find(']')) - 2);

//           } else {
//                   flag = true;
//           }

//   }



//   std::istringstream f(content);
//   std::string operationLine;
//   int countMe = 0;
//   while(getline(f,operationLine)) {
//           if(operationLine.find('+') != std::string::npos) {
//               operationLine.erase(std::remove(operationLine.begin(), operationLine.end(), ' '), operationLine.end());
//               string firstParameter = operationLine.substr(operationLine.find('=') + 1, operationLine.find('+') - (operationLine.find('=') + 1));
//               string secondParameter = operationLine.substr(operationLine.find('+') + 1,1);
//               string result = operationLine.substr(0,operationLine.find('='));


//              int firstParameterIndex = isInsideMatrix(matrices,firstParameter);
//              CMatrix firstParameterTemp = matrices[firstParameterIndex];



//               int secondParameterIndex = isInsideMatrix(matrices,secondParameter);
//               CMatrix secondParameterTemp = matrices[secondParameterIndex];


//               if(firstParameterTemp.getnR() != secondParameterTemp.getnR() || firstParameterTemp.getnC() != secondParameterTemp.getnC()) {
//                 cout << "This Operation Can't be Made Because Matrices is not in Compatible Shape." << endl;
//                 cout << "######################################################" << endl;



//               } else {

//                         CMatrix resultMatrix = addOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
//                         matrices.push_back(resultMatrix);

//                         if(operationLine.find(';') == std::string::npos) {
//                                 cout << resultMatrix.getName() << " = " << endl;
//                                 cout << resultMatrix;
//                                 cout << "######################################################" << endl;

//                         }


//               }




//           }
//           else if(operationLine.find('-') != std::string::npos) {
//           operationLine.erase(std::remove(operationLine.begin(), operationLine.end(), ' '), operationLine.end());

//               string firstParameter = operationLine.substr(operationLine.find('=') + 1, operationLine.find('-') - (operationLine.find('=') + 1));
//               string secondParameter = operationLine.substr(operationLine.find('-') + 1,1);
//               string result = operationLine.substr(0,operationLine.find('='));


//              int firstParameterIndex = isInsideMatrix(matrices,firstParameter);
//              CMatrix firstParameterTemp = matrices[firstParameterIndex];



//               int secondParameterIndex = isInsideMatrix(matrices,secondParameter);
//               CMatrix secondParameterTemp = matrices[secondParameterIndex];


//               if(firstParameterTemp.getnR() != secondParameterTemp.getnR() || firstParameterTemp.getnC() != secondParameterTemp.getnC()) {
//                         cout << "This Operation Can't be Made Because Matrices is not in Compatible Shape." << endl;
//                         cout << "######################################################" << endl;

//               } else {


//                         CMatrix resultMatrix = subOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
//                         matrices.push_back(resultMatrix);

//                         if(operationLine.find(';') == std::string::npos) {
//                                 cout << resultMatrix.getName() << " = " << endl;
//                                 cout << resultMatrix;
//                                 cout << "######################################################" << endl;

//                         }



//               }




//           }
//           else if(operationLine.find('*') != std::string::npos) {
//           operationLine.erase(std::remove(operationLine.begin(), operationLine.end(), ' '), operationLine.end());

//               string firstParameter = operationLine.substr(operationLine.find('=') + 1, operationLine.find('*') - (operationLine.find('=') + 1));
//               string secondParameter = operationLine.substr(operationLine.find('*') + 1,1);
//               string result = operationLine.substr(0,operationLine.find('='));


//              int firstParameterIndex = isInsideMatrix(matrices,firstParameter);
//              CMatrix firstParameterTemp = matrices[firstParameterIndex];



//               int secondParameterIndex = isInsideMatrix(matrices,secondParameter);
//               CMatrix secondParameterTemp = matrices[secondParameterIndex];

//               if(firstParameterTemp.getnC() != secondParameterTemp.getnR()) {

//                 cout << "This Operation Can't be Made Because Matrices is not in Compatible Shape." << endl;
//                 cout << "######################################################" << endl;

//               } else {
//                 CMatrix resultMatrix = multiplyOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
//                 matrices.push_back(resultMatrix);

//                 if(operationLine.find(';') == std::string::npos) {
//                         cout << resultMatrix.getName() << " = " << endl;
//                         cout << resultMatrix;
//                         cout << "######################################################" << endl;

//                 }

//               }



//           }

//           else if(operationLine.find("./") != std::string::npos) {
//             operationLine.erase(std::remove(operationLine.begin(), operationLine.end(), ' '), operationLine.end());

//             string firstParameter = operationLine.substr(operationLine.find('=') + 1, operationLine.find("./") - (operationLine.find('=') + 1));
//             string secondParameter = operationLine.substr(operationLine.find("./") + 2,1);
//             string result = operationLine.substr(0,operationLine.find('='));

//             if(checkNumeric(firstParameter)) {

//               CMatrix resultMatrix = elmentWiseDivOperationNumber(matrices,isInsideMatrix(matrices,secondParameter),firstParameter,result);
//               matrices.push_back(resultMatrix);

//               if(operationLine.find(';') == std::string::npos) {
//                       cout << resultMatrix.getName() << " = " << endl;
//                       cout << resultMatrix;
//                       cout << "######################################################" << endl;

//               }

//             } else {
//               CMatrix resultMatrix = elmentWiseDivOperationNormal(matrices,isInsideMatrix(matrices,secondParameter),isInsideMatrix(matrices,firstParameter),result);
//               matrices.push_back(resultMatrix);

//               if(operationLine.find(';') == std::string::npos) {
//                       cout << resultMatrix.getName() << " = " << endl;
//                       cout << resultMatrix;
//                       cout << "######################################################" << endl;

//               }

//             }


//           }

//           else if(operationLine.find('/') != std::string::npos && operationLine.find('.') == std::string::npos) {
//           operationLine.erase(std::remove(operationLine.begin(), operationLine.end(), ' '), operationLine.end());

//               string firstParameter = operationLine.substr(operationLine.find('=') + 1, operationLine.find('/') - (operationLine.find('=') + 1));
//               string secondParameter = operationLine.substr(operationLine.find('/') + 1,1);
//               string result = operationLine.substr(0,operationLine.find('='));

//              int firstParameterIndex = isInsideMatrix(matrices,firstParameter);
//              CMatrix firstParameterTemp = matrices[firstParameterIndex];
              // else if(s.find("rand") != std::string::npos)
              //                   {
              //                       s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
              //                       string result = s.substr(0,s.find('='));
              //                       string rowsNumber = s.substr(s.find('(') + 1, s.find(',') - (s.find('(') + 1));
              //                       string columnsNumber = s.substr(s.find(',') + 1, s.find(')') - (s.find(',') + 1));
              //
              //
              //                       if(s.find(';') == std::string::npos)
              //                       {
              //                              CMatrix resultMatrix = randFunction(rowsNumber, columnsNumber, result);
              //                              matrices.push_back(resultMatrix);
              //                               cout << resultMatrix.getName() << " = " << endl;
              //                               cout << resultMatrix;
              //                               cout << "######################################################" << endl;
              //                       }
              //                       else
              //                       {
              //                               CMatrix resultMatrix = randFunction(rowsNumber, columnsNumber, result);
              //                               matrices.push_back(resultMatrix);
              //                       }
              //                   }
              //
              //                   else if(s.find("eye") != std::string::npos)
              //                   {
              //                       s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
              //                       string result = s.substr(0,s.find('='));
              //                       string rowsNumber = s.substr(s.find('(') + 1, s.find(',') - (s.find('(') + 1));
              //                       string columnsNumber = s.substr(s.find(',') + 1, s.find(')') - (s.find(',') + 1));
              //
              //
              //                       if(s.find(';') == std::string::npos)
              //                       {
              //                              CMatrix resultMatrix = eyeFunction(rowsNumber, columnsNumber, result);
              //                              matrices.push_back(resultMatrix);
              //                               cout << resultMatrix.getName() << " = " << endl;
              //                               cout << resultMatrix;
              //                               cout << "######################################################" << endl;
              //                       }
              //                       else
              //                       {
              //                               CMatrix resultMatrix = eyeFunction(rowsNumber, columnsNumber, result);
              //                               matrices.push_back(resultMatrix);
              //                       }
              //                   }




//               int secondParameterIndex = isInsideMatrix(matrices,secondParameter);
//               CMatrix secondParameterTemp = matrices[secondParameterIndex].getInverse();
//               if(secondParameterTemp.getName() == "Invert") {
//                       cout << "This Operation Can't Be Made Because [ " << secondParameter << " ] Can't Be Inverted" << endl;
//                       cout << "######################################################" << endl;

//               } else if( secondParameterTemp.getnC() != secondParameterTemp.getnR()) {
//                       cout << "This Operation Can't Be Made Because [ " << secondParameter << " ] not a Sqaure Matrix" << endl;
//                       cout << "######################################################" << endl;


//               } else if(firstParameterTemp.getnC() != secondParameterTemp.getnR()) {
//                       cout << "This Operation Can't be Made Because Matrices is not in Compatible Shape." << endl;
//                       cout << "######################################################" << endl;
//               } else {
//                 CMatrix resultMatrix = divideOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
//                 matrices.push_back(resultMatrix);
//                 if(operationLine.find(';') == std::string::npos) {
//                         cout << resultMatrix.getName() << " = " << endl;
//                         cout << resultMatrix;
//                         cout << "######################################################" << endl;

//                 }
//               }
//         //1.9582e+21



//           }
//           else if(operationLine.find("'") != std::string::npos) {
//                   operationLine.erase(std::remove(operationLine.begin(), operationLine.end(), ' '), operationLine.end());
//                   string firstParameter = operationLine.substr(operationLine.find('=') + 1,1);
//                   string result = operationLine.substr(0,operationLine.find('='));

//                   CMatrix resultMatrix = transposeOperation(matrices,isInsideMatrix(matrices,firstParameter),result);
//                   matrices.push_back(resultMatrix);

//                   if(operationLine.find(';') == std::string::npos) {
//                       cout << resultMatrix.getName() << " = " << endl;
//                       cout << resultMatrix;
//                       cout << "######################################################" << endl;

//               }

//           }



//   } // End Of While

} // End of Program Function




int main(int argc, char* argv[]){

                      if (argc > 1) {

                        programLoopFromFile(argv[1]);
                      }
                //       else {
                //       vector<CMatrix> matrices;

                //         string s;
                //         string line;
                //         string semicolonCheck;
                //         while(1) {
                //           getline(cin, s);

                //           if(s.find('[') != string::npos && s.find(']') == string::npos ) {
                //               getline(cin,line, ']');
                //               string name = "";
                //               name += s[0];
                //               CMatrix temp(name, line);
                //               matrices.push_back(temp);


                //                 getline(cin ,semicolonCheck);
                //                 if(semicolonCheck == "") {
                //                         cout << temp.getName() << " = " << endl;
                //                         cout << temp;
                //                         cout << "######################################################" << endl;

                //                 } else if(semicolonCheck == ";"){
                //                         semicolonCheck = "";
                //                 }

                //           } else if(s.find('[') != string::npos && s.find(']') != string::npos){
                //               string name = s.substr(0 , s.find('='));
                //               name.erase(std::remove(name.begin(),name.end(),' '),name.end());
                //               size_t found = s.find('[');
                //               string matrixData,matrixName;
                //               if(found != std::string::npos) {
                //                 matrixData = s.substr(0,s.find(']') + 1);
                //                 matrixData.erase(0,matrixData.find('['));
                //                 matrixData.erase(std::remove(matrixData.begin(), matrixData.end(), '\n'), matrixData.end());
                //               }
                //               CMatrix temp(name , matrixData);
                //               matrices.push_back(temp);

                //                 if(s.find(';' , s.find(']')) != std::string::npos) {
                //                         semicolonCheck = "";
                //               } else {
                //                       cout << temp.getName() << " = " << endl;
                //                       cout << temp;
                //                       cout << "######################################################" << endl;

                //               }




                //           } else if(s.find('[') == string::npos && s.find(']') == string::npos && s.find("=") != string::npos) {
                //             if(s.find('+') != std::string::npos) {
                //                 s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
                //                 string firstParameter = s.substr(s.find('=') + 1, s.find('+') - (s.find('=') + 1));
                //                 string secondParameter = s.substr(s.find('+') + 1);
                //                 string result = s.substr(0,s.find('='));

                //                 int firstParameterIndex = isInsideMatrix(matrices,firstParameter);
                //                 CMatrix firstParameterTemp = matrices[firstParameterIndex];

                //                 int secondParameterIndex = isInsideMatrix(matrices,secondParameter);
                //                 CMatrix secondParameterTemp = matrices[secondParameterIndex];


                //                 if(firstParameterTemp.getnR() != secondParameterTemp.getnR() || firstParameterTemp.getnC() != secondParameterTemp.getnC()) {
                //                                 cout << "This Operation Can't be Made Because Matrices is not in Compatible Shape." << endl;
                //                                 cout << "######################################################" << endl;

                //                 } else {

                //                         if(s.find(';') == std::string::npos) {
                //                                 CMatrix resultMatrix = addOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
                //                                 matrices.push_back(resultMatrix);
                //                                 cout << resultMatrix.getName() << " = " << endl;
                //                                 cout << resultMatrix;
                //                                 cout << "######################################################" << endl;


                //                         } else {
                //                                 CMatrix resultMatrix = addOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
                //                                 matrices.push_back(resultMatrix);
                //                         }

                //                 }




                //             }
                //             else if(s.find('-') != std::string::npos) {
                //             s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

                //                 string firstParameter = s.substr(s.find('=') + 1, s.find('-') - (s.find('=') + 1));
                //                 string secondParameter = s.substr(s.find('-') + 1);
                //                 string result = s.substr(0,s.find('='));

                //                 int firstParameterIndex = isInsideMatrix(matrices,firstParameter);
                //                 CMatrix firstParameterTemp = matrices[firstParameterIndex];

                //                 int secondParameterIndex = isInsideMatrix(matrices,secondParameter);
                //                 CMatrix secondParameterTemp = matrices[secondParameterIndex];

                //                 if(firstParameterTemp.getnR() != secondParameterTemp.getnR() || firstParameterTemp.getnC() != secondParameterTemp.getnC()) {
                //                                 cout << "This Operation Can't be Made Because Matrices is not in Compatible Shape." << endl;
                //                                 cout << "######################################################" << endl;

                //                 } else {

                //                         if(s.find(';') == std::string::npos) {
                //                                 CMatrix resultMatrix = subOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
                //                                 matrices.push_back(resultMatrix);
                //                                 cout << resultMatrix.getName() << " = " << endl;
                //                                 cout << resultMatrix;
                //                                 cout << "######################################################" << endl;

                //                         } else {
                //                                 CMatrix resultMatrix = subOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
                //                                 matrices.push_back(resultMatrix);

                //                         }
                //                 }




                //             }
                //             else if(s.find('*') != std::string::npos) {
                //             s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

                //                 string firstParameter = s.substr(s.find('=') + 1, s.find('*') - (s.find('=') + 1));
                //                 string secondParameter = s.substr(s.find('*') + 1);
                //                 string result = s.substr(0,s.find('='));

                //                 int firstParameterIndex = isInsideMatrix(matrices,firstParameter);
                //                 CMatrix firstParameterTemp = matrices[firstParameterIndex];

                //                 int secondParameterIndex = isInsideMatrix(matrices,secondParameter);
                //                 CMatrix secondParameterTemp = matrices[secondParameterIndex];

                //                 if( firstParameterTemp.getnC() != secondParameterTemp.getnR() ){
                //                                 cout << "This Operation Can't be Made Because Matrices is not in Compatible Shape." << endl;
                //                                 cout << "######################################################" << endl;
                //                 }else{
                //                         if(s.find(';') == std::string::npos) {
                //                                 CMatrix resultMatrix = multiplyOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
                //                                 matrices.push_back(resultMatrix);
                //                                 cout << resultMatrix.getName() << " = " << endl;
                //                                 cout << resultMatrix;
                //                                 cout << "######################################################" << endl;

                //                         } else {
                //                                 CMatrix resultMatrix = multiplyOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
                //                                 matrices.push_back(resultMatrix);

                //                         }

                //                       }

                //             }

                //             else if(s.find("./") != std::string::npos) {
                //               s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

                //               string firstParameter = s.substr(s.find('=') + 1, s.find("./") - (s.find('=') + 1));
                //               string secondParameter = s.substr(s.find("./") + 2);
                //               string result = s.substr(0,s.find('='));

                //               if(checkNumeric(firstParameter)) {

                //                 CMatrix resultMatrix = elmentWiseDivOperationNumber(matrices,isInsideMatrix(matrices,secondParameter),firstParameter,result);
                //                 matrices.push_back(resultMatrix);

                //                 if(s.find(';') == std::string::npos) {
                //                         cout << resultMatrix.getName() << " = " << endl;
                //                         cout << resultMatrix;
                //                         cout << "######################################################" << endl;

                //                 }

                //               } else {
                //                 CMatrix resultMatrix = elmentWiseDivOperationNormal(matrices,isInsideMatrix(matrices,secondParameter),isInsideMatrix(matrices,firstParameter),result);
                //                 matrices.push_back(resultMatrix);

                //                 if(s.find(';') == std::string::npos) {
                //                         cout << resultMatrix.getName() << " = " << endl;
                //                         cout << resultMatrix;
                //                         cout << "######################################################" << endl;

                //                 }

                //               }


                //             }

                //             else if(s.find('/') != std::string::npos && s.find('.') == std::string::npos) {
                //                 s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

                //                 string firstParameter = s.substr(s.find('=') + 1, s.find('/') - (s.find('=') + 1));
                //                 string secondParameter = s.substr(s.find('/') + 1);
                //                 string result = s.substr(0,s.find('='));

                //                 int firstParameterIndex = isInsideMatrix(matrices,firstParameter);
                //                 CMatrix firstParameterTemp = matrices[firstParameterIndex];

                //                 int secondParameterIndex = isInsideMatrix(matrices,secondParameter);
                //                 CMatrix secondParameterTemp = matrices[secondParameterIndex].getInverse();
                //                 if(secondParameterTemp.getName() == "Invert") {
                //                         cout << "This Operation Can't Be Made Because [ " << secondParameter << " ] Can't Be Inverted" << endl;
                //                         cout << "######################################################" << endl;

                //                 } else if(secondParameterTemp.getnC() != secondParameterTemp.getnR()) {
                //                         cout << "This Operation Can't Be Made Because [ " << secondParameter << " ] not a Square Matrix" << endl;
                //                         cout << "######################################################" << endl;

                //                 } else if(firstParameterTemp.getnC() != secondParameterTemp.getnR()) {
                //                         cout << "This Operation Can't be Made Because Matrices is not in Compatible Shape." << endl;
                //                         cout << "######################################################" << endl;

                //                 } else {
                //                         if(s.find(';') == std::string::npos) {
                //                                 CMatrix resultMatrix = divideOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
                //                                 matrices.push_back(resultMatrix);
                //                                 cout << resultMatrix.getName() << " = " << endl;
                //                                 cout << resultMatrix;
                //                                 cout << "######################################################" << endl;

                //                         } else {
                //                                 CMatrix resultMatrix = divideOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
                //                                 matrices.push_back(resultMatrix);
                //                         }
                //                 }

                //             }
                //             else if(s.find("'") != std::string::npos) {
                //                 s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
                //                 string firstParameter = s.substr(s.find('=') + 1,1);
                //                 string result = s.substr(0,s.find('='));

                //                 if(s.find(';') == std::string::npos) {
                //                         CMatrix resultMatrix = transposeOperation(matrices,isInsideMatrix(matrices,firstParameter),result);
                //                         matrices.push_back(resultMatrix);
                //                         cout << resultMatrix.getName() << " = " << endl;
                //                         cout << resultMatrix;
                //                         cout << "######################################################" << endl;

                //                 } else {
                //                         CMatrix resultMatrix = transposeOperation(matrices,isInsideMatrix(matrices,firstParameter),result);
                //                         matrices.push_back(resultMatrix);
                //                 }



                //             }

                            // else if(s.find("rand") != std::string::npos)
                            // {
                            //     s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
                            //     string result = s.substr(0,s.find('='));
                            //     string rowsNumber = s.substr(s.find('(') + 1, s.find(',') - (s.find('(') + 1));
                            //     string columnsNumber = s.substr(s.find(',') + 1, s.find(')') - (s.find(',') + 1));
                            //
                            //
                            //     if(s.find(';') == std::string::npos)
                            //     {
                            //            CMatrix resultMatrix = randFunction(rowsNumber, columnsNumber, result);
                            //            matrices.push_back(resultMatrix);
                            //             cout << resultMatrix.getName() << " = " << endl;
                            //             cout << resultMatrix;
                            //             cout << "######################################################" << endl;
                            //     }
                            //     else
                            //     {
                            //             CMatrix resultMatrix = randFunction(rowsNumber, columnsNumber, result);
                            //             matrices.push_back(resultMatrix);
                            //     }
                            // }
                            //
                            // else if(s.find("eye") != std::string::npos)
                            // {
                            //     s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
                            //     string result = s.substr(0,s.find('='));
                            //     string rowsNumber = s.substr(s.find('(') + 1, s.find(',') - (s.find('(') + 1));
                            //     string columnsNumber = s.substr(s.find(',') + 1, s.find(')') - (s.find(',') + 1));
                            //
                            //
                            //     if(s.find(';') == std::string::npos)
                            //     {
                            //            CMatrix resultMatrix = eyeFunction(rowsNumber, columnsNumber, result);
                            //            matrices.push_back(resultMatrix);
                            //             cout << resultMatrix.getName() << " = " << endl;
                            //             cout << resultMatrix;
                            //             cout << "######################################################" << endl;
                            //     }
                            //     else
                            //     {
                            //             CMatrix resultMatrix = eyeFunction(rowsNumber, columnsNumber, result);
                            //             matrices.push_back(resultMatrix);
                            //     }
                            // }

                //           } else if(s.find("=") == string::npos && s != "") {
                //             int matrixIndex = isInsideMatrix(matrices,s);
                //             if(matrixIndex == -1) {
                //               cout << "Uninitialized Matrix" << endl;

                //             } else {
                //               cout << matrices[matrixIndex];
                //               cout << "###################################" << endl;

                //             }

                //           }          // conflict
                          // }          // conflict

                //         }


                // }

                /* ########################################## */
                /* Test Cases */
                //       string s = "[8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 8.6 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.6 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.8 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.8;];";
                // string s2 = "[1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;]";
                // clock_t tStart = clock();
                // string s3 = "8.9 7.3 4.0 2.4; 2.3 6.5 8.9 3.1; 4.9 3.8 2 7.5; 9.8 3.4 1 8.9]";
                // if(s3.find(';',s3.length() - 1) != std::string::npos) {
                //         cout << "Found" << endl;
                // } else {
                //         cout << "Not Found" << endl;
                // }
                // string s4 = "[1.2 5.7 4.2 1.4; 6.3 2.5 8.1 3.1; 6.4 2.8 7.1 8.1; 3.2 5.1 7.2 8.9]";
                //       CMatrix n("D",s3);
                //       CMatrix t("T",s4);

                //       CMatrix temp = t.getInverse();

                //       cout << "Division in Exampel.m File" << endl;

                //       if(temp.getName() == "Invert") {
                //               cout << "Matrix Can't Be Invertable" << endl;
                //       } else {
                //               cout << "Matrix is invertable" << endl;
                //               CMatrix result = n * temp;
                //               result.setName("A");
                //               cout << "Result of Division of A and B in Example.m : " << endl;
                //               cout << result;

                //       }


                //       cout << "**************************************" << endl;
                //       cout << "Matrix in bigexample.m" << endl;
                //       CMatrix y("K",s);
                //       cout << "Number of Rows : " << y.getnR() << endl;
                //       cout << "Number of Columns : " << y.getnC() << endl;
                //       cout << "Value of Determinant : " << y.getDeterminant() << endl;

                //       CMatrix temp2 = y.getInverse();

                //       if(temp2.getName() == "Invert") {
                //               cout << "Matrix is Not Invertable" << endl;
                //       } else {

                //               cout << "Matrix is Invertable" << endl;

                //               cout << temp << endl;
                //       }



                //       cout << "#################### Execution Time ###################" << endl;
                //       cout << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;

                  //
                  // string m1 = "[ 1 2 3 4; 1 2 2 2; 3 3 3 4; 12 3 4 6]";
                  // CMatrix a("a",m1);
                  // cout<< "det of"<<endl<< m1<<endl<<a.getDeterminant()<<endl;
                  //
                  // string m2 = "[8.9 7.3 4.0 2.4; 2.3 6.5 8.9 3.1; 4.9 3.8 2 7.5; 9.8 3.4 1 8.9]";
                  // CMatrix b("b",m2);
                  // cout<< "det of"<<endl<< m2<<endl<<b.getDeterminant()<<endl;
                  //
                  //
                  // string m3 = "[8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9]";
                  // CMatrix c("c",m3);
                  // cout<< "det of"<<endl<< m3<<endl<<c.getDeterminant()<<endl;
                  //
                  //
                  //
                //   string m4 = "1.2 3.4 5.6 7.8 1.0 3.2 2.1 2.3 1.4 2.6 2.7 2.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 3.7 1.2 3.4 5.6 7.8 9.0 1.2 2.1 2.3 2.4 1.6; 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4; 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 7.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 4.1 2.3; 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 1.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1; 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2; 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 17.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0; 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8; 9.0 2.2 2.1 2.3 2.4 1.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 2.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6; 7.4 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4; 5.6 7.8 9.0 2.2 4.4 2.3 2.4 2.6 2.7 1.2 3.4 5.6 2.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2; 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 1.8 9.0 1.2 2.1 2.3 2.4 8.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7; 1.2 3.4 5.6 7.8 9.0 2.2 5.1 4.3 12.4 2.6 2.7 1.2 3.4 5.6 97.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 3.4 2.6; 2.7 1.2 3.4 5.6 7.5 9.0 2.2 2.1 3.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 5.1 2.3 2.4 5.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4; 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 8.2 2.1 2.3; 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 6.6 2.7 1.2 3.4 5.6 2.8 9.0 1.2 2.1; 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 5.1 2.3 2.4 0.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 0.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2; 0.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0; 4.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 5.2 2.1 2.3 2.4 9.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8; 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 5.3 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.3; 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 3.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 3.4 2.6 3.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 8.4 2.6 2.7 1.2 3.4; 5.6 7.8 9.0 2.2 2.1 2.3 3.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 1.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2; 3.4 1.6 7.8 9.0 2.2 3.1 6.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7; 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 4.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 1.6; 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 1.4 2.6 2.7 1.2 3.4 9.6 7.8 9.0 2.2 2.1 2.3 2.4; 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 1.4 2.6 2.7 2.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3; 2.4 2.6 2.7 1.2 3.4 5.6 7.8 1.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 8.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 2.6 7.8 9.0 2.2 2.1; 7.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 3.6 1.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2; 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 7.2 3.4 5.6 7.8 9.0; 2.2 2.1 2.3 2.4 2.6 7.7 9.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.9 2.4 2.6 2.7 1.2 3.4 5.6 7.8; 9.0 2.2 2.1 2.3 2.4 2.6 7.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6; 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4; 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 2.7 1.2 3.4 5.6 7.8 9.0 2.2 2.1 2.3 2.4 2.6 5.7 9.3 3.4 5.6 3.8 9.0 2.2 5.1 2.3 2.4 2.6 2.7 1.2";
                //   CMatrix d("d",s3);
                //   cout << d.getName() << " = " << endl;
                //   cout << d;

                  // CMatrix i = d.getInverse();
                  // cout<< "det of"<<endl<< m4<<endl<<d.getDeterminant()<<endl;
                  //
                  // cout<< "inverse is"<<endl<<i<<endl;

                  /* Test For Parsing New File */
                  /*
                    string s5 = "[1.2 2.3 4.7;[1.3 2.4;4.6 1.3],[3.2;7.8]]";
                int countSquareBracket = count(s5.begin() , s5.end() , '[');
                string firstMatrix = s5.substr(0,s5.find(';')) + "]";
                string secondMatrix = s5.substr(s5.find('[' , s5.find(';')),s5.find(']') + 1 - s5.find('[' , s5.find(';')));
                s5.erase(0,s5.find(']') + 2);
                s5.erase(s5.length() - 1);
                string thirdMatrix = s5;
                CMatrix A("A",firstMatrix);
                CMatrix B("B",secondMatrix);
                CMatrix C("C",thirdMatrix);
                B.addColumn(C);
                A.addRow(B);



                // String Parsing Next Level ==> Done
                // Must Be A New Line to make the Concatentation of the Row
                string s7 = "[[A [3.4; 2.1; 2]]\n 1 2 10  1.2]";
                int countBrackets = std::count(s7.begin(),s7.end(),'[');
                int countCommas = std::count(s7.begin(),s7.end(),',');
                if(countCommas == 0) {
                        string firstMatrix = s7.substr(s7.find('[',1) , s7.find(' ',s7.find('[',1)));
                        string rowMatrix = "[" + s7.substr(s7.find('\n') + 1);
                        CMatrix B("rowTemp",rowMatrix);
                        string thirdMatrix = s7.substr(s7.find(' ') + 1,s7.find(']') - s7.find(' '));
                        CMatrix C("temp2",thirdMatrix);
                        A.addColumn(C);
                        A.addRow(rowMatrix);
                        cout << A;
                } else {
                        string firstMatrix = s7.substr(s7.find('[',1) , s7.find(',',s7.find('[',1)));
                        cout << firstMatrix << endl;
                        string rowMatrix = "[" + s7.substr(s7.find('\n') + 1);
                        cout << rowMatrix << endl;
                        string thirdMatrix = s7.substr(s7.find(',') + 1,s7.find(']') - 1);
                        cout << thirdMatrix << endl;
                }





                   */


                   /* Test regex in the Matrix Class */
                   clock_t tStart = clock();
    string testcases[] = {
            "A = 5.5 + 12 * sin(0.4) + 2.2^4",
            "B = [1.2 2.3 A;[1.3 2.4;4.6 1.3],[3.2;7.8]]",
            "C = [[B [3.4; 2.1; 3.5+9.1]];    1.2^3 3+1.2 15/(2.1+10*sin(0.12)) 1.2]",
            "D = rand(4,4)",
            "E = eye(3,3)",
            "F = tan(E)",
        //     "D = [1.2^3 3+1.2 15/(2.1+10*sin(0.12)) 1.2;1.4 1.2 1.6 1.1]",
        //     "E = [1.2 1.5;1.6 1.8]",
        //     "F = [1.2+1;1.9*2]",
        //     "G = [1.6+2]",
        //     "H = [1.2 5.7 4.2 1.4+2; 6.3 2.5 8.1 3.1; 6.4 2.8 7.1 8.1; 3.2 5.1 7.2 8.9+2]",
        //     "L = (1.2 + 3.4 - 5.6)/(2.1*3.2 + 4.6) - 12.1*3.1 + (1.2 + 5.2)^(4/(3.2+5.6))",
        //     "N = -3 + 1",
        //     "M = 1 + 20 + -25"
    };

    cout << sin(0) << endl;
    cout << sin(1) << endl;
    vector<CMatrix> matrices;
    vector<AssociativeNumber> associateValues;

    for(int i = 0;i < sizeof(testcases) / sizeof(testcases[0]);i++) {

    cout << "############## Test Case : (" << i + 1 << ")" << " ##################" << endl;
    cout << "Matrix Form : " << endl;
    cout << testcases[i] << endl;
    string content = replaceMatrixOperator(testcases[i]);
    size_t countBracketsForConcatenation = std::count(content.begin(),content.end(),'[');
    string name = content.substr(0,content.find("="));
    if(countBracketsForConcatenation == 0) {
            content.erase(0,content.find("=") + 1);
    } else {
        content.erase(0,content.find("["));
    }
    name.erase(std::remove(name.begin(),name.end(),' '),name.end());
    name.erase(std::remove(name.begin(),name.end(),'\n'),name.end());
    name.erase(std::remove(name.begin(),name.end(),'='),name.end());

    if(countBracketsForConcatenation > 1) {
        // Case of Concatenation
        cout << "Concatenated Matrix : " << endl;
        CMatrix finalMatrix = concatMatrices(content,name,matrices,associateValues);
        matrices.push_back(finalMatrix);
        cout << finalMatrix.getName() << " = " << endl;
        cout << finalMatrix;
    } else if(countBracketsForConcatenation == 1) {
            // Normal Case Like Phase 1
        content = tokenizingMatrix(content,matrices,associateValues);
        CMatrix normalMatrix(content);
        normalMatrix.setName(name);
        matrices.push_back(normalMatrix);
        cout << normalMatrix.getName() << " = " << endl;
        cout << normalMatrix;
    } else if(countBracketsForConcatenation == 0) { // Case Of Operation
        AssociativeNumber temp(name,getEvaluation(content));
        associateValues.push_back(temp);
        cout << temp.getName() << " = " << temp.getValue() << endl;
    }

     if(content.find("rand") != std::string::npos)
    {
        content.erase(std::remove(content.begin(), content.end(), ' '), content.end());
        string rowsNumber = content.substr(content.find('(') + 1, content.find(',') - (content.find('(') + 1));
        string columnsNumber = content.substr(content.find(',') + 1, content.find(')') - (content.find(',') + 1));


        if(content.find(';') == std::string::npos)
        {
               CMatrix resultMatrix = randFunction(rowsNumber, columnsNumber, name);
               matrices.push_back(resultMatrix);
                cout << resultMatrix.getName() << " = " << endl;
                cout << resultMatrix;
                cout << "######################################################" << endl;
        }
        else
        {
                CMatrix resultMatrix = randFunction(rowsNumber, columnsNumber, name);
                matrices.push_back(resultMatrix);
        }
    }
    else if(content.find("eye") != std::string::npos)
    {
        content.erase(std::remove(content.begin(), content.end(), ' '), content.end());
        string rowsNumber = content.substr(content.find('(') + 1, content.find(',') - (content.find('(') + 1));
        string columnsNumber = content.substr(content.find(',') + 1, content.find(')') - (content.find(',') + 1));


        if(content.find(';') == std::string::npos)
        {
               CMatrix resultMatrix = eyeFunction(rowsNumber, columnsNumber, name);
               matrices.push_back(resultMatrix);
               cout << resultMatrix.getName() << " = " << endl;
               cout << resultMatrix;
               cout << "######################################################" << endl;
        }
        else
        {
                CMatrix resultMatrix = eyeFunction(rowsNumber, columnsNumber, name);
                matrices.push_back(resultMatrix);
        }
    }
        else if(content.find("tan") != std::string::npos)
        {
            content.erase(std::remove(content.begin(), content.end(), ' '), content.end());
            string firstParameter = content.substr( content.find('tan(') + 1, content.find(')') -  content.find('tan(') - 1 ) ;
            if(isdigit(firstParameter[0])) {
              continue;
            } else {
                CMatrix resultMatrix = tanOperation(matrices, isInsideMatrix(matrices, firstParameter), name);
                matrices.push_back(resultMatrix);

                if(content.find(';') == std::string::npos) {
                    cout << resultMatrix.getName() << " = " << endl;
                    cout << resultMatrix;
                    cout << "######################################################" << endl;
                }

            }
            // cout<<name<<endl;
            // cout<<firstParameter<<endl;
            // cout<<isInsideMatrix(matrices, firstParameter)<<endl;

            // cout<<matrices[0]<<endl;
      }

}

        cout << endl;
        cout << endl;
        cout << endl;

//         cout << "##########################################################" << endl;


//         cout << "Test Case For Prefix Matrix File" << endl;

//         string x = "C*H + 4";
//         x = replaceMatrixOperator(x);
//         CMatrix tempMatrixValue = getEvaluationForMatrix(x,matrices);
//         tempMatrixValue.setName("X");
//         cout << tempMatrixValue.getName() << " = " << endl;
//         cout << tempMatrixValue;



        // string content = "[1 2 3;1 2 3]";


        // CMatrix c(content);
        // cout << c << endl;
        // cout << c.getnC() << endl;
        // cout << c.getnR() << endl;


        // CMatrix d("[1 3 5 9]]");
        // cout << d << endl;
        // cout << d.getnC() << endl;
        // cout << d.getnR() << endl;


        // CMatrix data;
        // cout << data.getnR() << endl;
        // cout << data.getnC() << endl;
        // data.addRow(d);
        // cout << data;

        // string content = "[1 2 3 4;[1 2;1 2],[1;2],[3;4];[1 2 3;1 2 3],[1;5];[1 3 5 9]]";
        // CMatrix finalMatrix = concatMatrices(content,"I",matrices,associateValues);
        // cout << finalMatrix.getName() << endl;
        // cout << finalMatrix;


        cout << "Execution Program Time :" << endl;
        cout << ((double)(clock() - tStart) / CLOCKS_PER_SEC) * 1000 << "ms" << endl;



  return 0;
}
