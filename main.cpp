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
#include <ctype.h>
#include "concat.cpp"


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

[ function name] : elementWiseDivOperationNumber
[ return type] : CMatrix
[ inherited function/operation ] : -getnR() [CMatrix.cpp, line: ]
                                   -getnC() [CMatrix.cpp, line: ]
                                   -elementWiseDiv() [CMatrix.cpp, line: ]
                                   -setName() [CMatrix.cpp, line: ]
[ functionality ] : converts the first parameter (that is number) of type string to float and constructs a full matrix with it,
                    then performs element wise division with the second parameter (that is a matrix given by the user)

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
        [ Function Name ] : getEvaluation(string token)
        [ Function Returned Type ] : double
        [ Function Inherited Function ] : - erase
                                          - strToExp() -> Class Exp in testexp.cpp file
                                          - print() -> Class Exp in testexp.cpp file
                                          - tokenize() -> Prefixevaluator.cpp
                                          - evalPrefix() -> Prefixevaluator.cpp
        [ Functionality ] : Get the Evaluation of any Expression
*/

double getEvaluation(string token) {

        token.erase(remove_if(token.begin(), token.end(), ::isspace), token.end());
        token = replaceTriagomtric(token);
        token = replaceNegativeNumbers(token);



        Exp *finalResult = strToExp(token);
        string tempFinal;
        tempFinal += finalResult->print();
        if(tempFinal.find("Expression is Wrong") != std::string::npos) {
                return 184467440737.12345657;
        }
        vector<string> tokens;
        tokens.clear();
        tokenize(tempFinal, tokens);
        if(tokens.size()) {
                return evalPrefix(tokens);
        }


}



/* ################################################################################### */


/*
        [ Function Name ] : tokenizingexpression
        [ Function Returned Type ] : string , Or String with Matrix at the start of it
        [ inherited Function ] : - Regex Search Function from Regex library in the c++11 std
        [ Functionality ] :
 */
string tokenizingexpression(string expression , vector<CMatrix> matrices,vector<AssociativeNumber> associative) {
   smatch m;
    string tempString = expression;
    string secondTempString = expression;
    bool isMatrixOperations = false;
    bool result = regex_search(tempString,m,regex("[A-Za-z]+"));
    if(result == 1) {
        while(regex_search(secondTempString,m,regex("[A-Za-z]+"))) {
            string d = m[0];
            if(d == "sin" || d == "cos" || d == "log" || d == "ln" || d == "sqrt" || d == "tan" || d == "rand" || d == "zeros" || d == "ones" || d == "eye") {
                secondTempString = m.suffix().str();
                continue;
            } else {
                int isMatrix = isInsideMatrix(matrices , d);
                int isAssociative = isInsideAssociate(associative , d);
                if(isAssociative != -1) {
                        string number = std::to_string(associative[isAssociative].getValue());
                        expression.replace(expression.find(m[0]),m.length(0),number);

                } else if(isMatrix != -1) {
                        // Send to Function in PrefixEvaluatorMatrix
                        // TODO ::
                        isMatrixOperations = true;
                }
                secondTempString = m.suffix().str();
            }
        }
    }

    if(expression.find("eye") != std::string::npos || expression.find("rand") != std::string::npos || expression.find("zeros") != std::string::npos || expression.find("ones") != std::string::npos) {
            expression = getExpressionFromMain(expression, matrices);

    }

    if(isMatrixOperations == true) {
            expression = getExpressionFromMain(expression, matrices);
    }


    return expression;


}


/* ############################################################################# */
/*
        [ Function Name ] : tokenizingMatrix(string data,vector<CMatrix> matricesArray,vector<AssociativeNumber> associateValuesArray)
        [ Function Return Type ] : string
        [ Function Inherited Function ] : - erase
                                          - remove
                                          - substr
                                          - regex_search
                                          - to_string
                                          - IsInsideAssociateArray
        [ Functionality ] : tokenize Matrix if it has any Matrix inside it or any variables or any operations or expressions ==> and Return a string containing the result matrix
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
                        finalMatrixString += matrixForm;

                } else { // Not Found

                }

            }


            content.erase(0, pos + 1);

        }
        finalMatrixString += ";";


    }


        finalMatrixString.erase(finalMatrixString.length() - 1);

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
        [ Functionality ] : Concatenate the Matrices ==> Depends on the ExpConcat Matrix
*/

CMatrix concatMatrices(string content,string name,vector<CMatrix> matricesArray,vector<AssociativeNumber> associateValuesArray) {

    vector<CMatrix> matrixConcat;
    vector<string> matricesConcatStrings;
    for(int i = 0 ;i < content.size();i++) {
        if(content[i] == ']' && content[i + 1] == ' ') {
            content[i + 1] = ',';
        }
        else if(isalpha(content[i]) && content[i + 1] == ' ' && content[i + 2] == '[') {
                content[i + 1] = ',';
        }
    }

    ExpConcat* tree = strToExpConcat(content);
    content = "";
    content += tree->print();
        regex re3("[$]+");
        sregex_token_iterator it3(content.begin(), content.end(), re3, -1);
        sregex_token_iterator reg_end3;
        for(;it3 != reg_end3;++it3) {
                string tempString = it3->str();
                matricesConcatStrings.push_back(tempString);
        }
        for(int i = 0; i < matricesConcatStrings.size();i++) {
                if(matricesConcatStrings[i].length() == 0) {
                        matricesConcatStrings.erase(matricesConcatStrings.begin() + i);
                        i--;
                } else {
                        if(matricesConcatStrings[i] == ";") {
                                continue;
                        } else {
                                if(matricesConcatStrings[i][0] == ';' || matricesConcatStrings[i][matricesConcatStrings[i].length() - 1] == ';') {
                                        matricesConcatStrings[i] = tokenizingMatrix(matricesConcatStrings[i] , matricesArray,associateValuesArray);
                                        matricesConcatStrings[i] += ";";
                                } else {
                                        matricesConcatStrings[i] = tokenizingMatrix(matricesConcatStrings[i] , matricesArray,associateValuesArray);
                                }
                        }
                }
        }


        // LOGIC
        for(int i = 0 ; i < matricesConcatStrings.size();i++) {
                string matrixTemp = matricesConcatStrings[i];
                if(matrixTemp[0] == ';' || matrixTemp[matrixTemp.length() - 1] == ';') {
                        if(matrixTemp == ";") {
                                matricesConcatStrings.erase(matricesConcatStrings.begin() + i);
                                i--;
                        }
                        continue;

                } else {
                        int countEraseElements = 0;
                        for(int j = i; j < matricesConcatStrings.size() - i;j++) {
                                string matrixTemp2 = matricesConcatStrings[j];
                                string matrixTemp3;
                                if(j + 1 < matricesConcatStrings.size()) {
                                        matrixTemp3 = matricesConcatStrings[j + 1];
                                }
                                if(matricesConcatStrings.size() == 1) {
                                        break;
                                }
                                if(matrixTemp2[0] == ';' || matrixTemp2[matrixTemp2.length() - 1] == ';' || matrixTemp3[0] == ';' || matrixTemp3[matrixTemp3.length() - 1] == ';') {
                                        j = matricesConcatStrings.size() - i;
                                } else {
                                        CMatrix first(matrixTemp2);
                                        CMatrix second(matrixTemp3);
                                        first.addColumn(second);
                                        matricesConcatStrings[j] = first.getMatrixForm();
                                        matricesConcatStrings.erase(matricesConcatStrings.begin() + j + 1);
                                        countEraseElements++;
                                        j = i - 1;
                                }
                        }
                }
        }

        if(matricesConcatStrings.size() > 1) {
                for(int i = (matricesConcatStrings.size() - 1);i > 0;i--) {
                                CMatrix first(matricesConcatStrings.back());
                                matricesConcatStrings.pop_back();
                                CMatrix second(matricesConcatStrings.back());
                                matricesConcatStrings.pop_back();
                                second.addRow(first);
                                string tempConcat = second.getMatrixForm();
                                matricesConcatStrings.push_back(tempConcat);
                }

                CMatrix matrixConcatFinal(matricesConcatStrings[0]);
                matrixConcatFinal.setName(name);
                return matrixConcatFinal;

        } else {
                CMatrix matrixConcatFinal(matricesConcatStrings[0]);
                matrixConcatFinal.setName(name);
                return matrixConcatFinal;
        }





}
/* ############################################################################# */

// --------------------------- parsingPhase2 -----------------------------------------------//

/*

        [ Function Name ] : readjustingNewLines(char* fileName)
        [ Function Return Type ] : string
        [ Inherited Function ] : - length
                                 - isspace
                                 - isdigit
                                 - length
        [ Functionality ] : - For Case C in advExample File

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

        [ Function Name ] : parse( string line, string &variableName, string &operationLine, bool &verbose )
        [ Function Return Type ] : Void Function [ None ]
        [ Inherited Function ] : - erase
                                 - remove
                                 - substr
                                 - length
        [ Functionality ] : - Parse the input string if it ( Expression , Matrix , Matrix Concatenation )

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
    size_t countBracketsForConcatenation = std::count(line.begin(),line.end(),'[');
    if(countBracketsForConcatenation == 0) {
      line.erase(0,line.find("=") + 1);
    } else {
      line.erase(0,line.find("["));
    }
    operationLine = line;// parsing rhs of the = sign
  }

    variableName.erase(std::remove(variableName.begin(),variableName.end(),' '),variableName.end()); // removing spaces

}

/*

        [ Function Name ] : execute(vector<CMatrix>& matrices, vector<AssociativeNumber>& associateValues, string variableName, string operationLine, bool verbose)
        [ Function Return Type ] : Void Function [ None ]
        [ Inherited Function ] : - isInsideMatrix
                                 - isInsideAssociate
                                 - replaceMatrixOperator
                                 - concatMatrices
        [ Functionality ] : - Executes Every Line in the File ( Expression , Matrix , Concatenated Matrix )

*/
void execute(  vector<CMatrix>& matrices, vector<AssociativeNumber>& associateValues, string variableName, string operationLine, bool verbose ){

  int matrixIndex = isInsideMatrix(matrices, variableName);
  int associativeNumberIndex = isInsideAssociate(associateValues, variableName);

  if(operationLine == ""){ // no operation
    if(verbose)  // printing the variable value
      if( matrixIndex != -1 ){
        cout<<variableName<<" ="<<endl;
        cout<<matrices[matrixIndex]<<endl;
        cout << "###################################################################" << endl;
      }
      else if( associativeNumberIndex != -1 ){
        cout<<variableName<<" ="<<endl;
        cout<<associateValues[associativeNumberIndex].getValue()<<endl;
        cout << "###################################################################" << endl;
      }
  }
  else{ // operation lines

    operationLine = replaceMatrixOperator(operationLine); // replacing unary operations with binary ones

    size_t countBracketsForConcatenation = std::count(operationLine.begin(),operationLine.end(),'[');

    if(countBracketsForConcatenation > 1) { // case of concatenation concatenation
        CMatrix finalMatrix = concatMatrices(operationLine, variableName, matrices, associateValues);
        matrices.push_back(finalMatrix);
        if(verbose){
          cout << finalMatrix.getName() << " = " << endl;
          cout << finalMatrix;
          cout << "###################################################################" << endl;
        }
    }
    else if(countBracketsForConcatenation == 1) {  // case of constructing a matrix
        operationLine  = tokenizingMatrix(operationLine, matrices,associateValues);
        CMatrix normalMatrix(operationLine);
        if(normalMatrix.getName() == "Error Dimension") {
                cout << "Error Dimension" << endl;
                cout << "###################################################################" << endl;
        } else {
                normalMatrix.setName(variableName);
                matrices.push_back(normalMatrix);
                if(verbose){
                cout << normalMatrix.getName() << " = " << endl;
                cout << normalMatrix;
                cout << "###################################################################" << endl;
                }
        }
    }
    else if(countBracketsForConcatenation == 0) { // case of operations

      operationLine = tokenizingexpression(operationLine , matrices , associateValues);
      if(operationLine[0] == '[') { // Case of Matrix Operation
        CMatrix temp(operationLine);
        temp.setName(variableName);
        matrices.push_back(temp);
        if(verbose){
          cout << temp.getName() << " = " << endl;
          cout << temp;
          cout << "###################################################################" << endl;
        }
      } else {
        double answer = getEvaluation(operationLine);
        if(answer == 184467440737.12345657) {
                cout << "Expression is Wrong!" << endl;
                cout << "###################################################################" << endl;
        } else {
                AssociativeNumber temp(variableName, getEvaluation(operationLine));
                associateValues.push_back(temp);
                if(verbose)
                        cout << temp.getName() << " = " << temp.getValue() << endl;
                        cout << "###################################################################" << endl;

        }
      }

    }
  }

  } // end of execute


int main(int argc, char* argv[]){

  vector<CMatrix> matrices;
  vector<AssociativeNumber> associateValues;

  string content, // carries the whole file
         line,    // carries one Line
         variableName, // carries the variable name (lhs of the = sign if it exists)
         operationLine; // carries the rhs of the = sign if it exists

  bool verbose; // for (not) showing variable value

  if (argc > 1) {

    content = readjustingNewLines(argv[1]); // no '\n' after last line
    std::istringstream fileStream(content);
    while(getline(fileStream, line)){
      parse(line, variableName, operationLine, verbose);
      if(variableName == "" && operationLine == "") // skipping empty lines in the file
        continue;

      execute(matrices, associateValues, variableName, operationLine, verbose);
    }

  }

  else {
    while(1){
      while(getline(cin, line)){


        if( std::count(line.begin(),line.end(),'[') == std::count(line.begin(),line.end(),']') ){ // one line operation/instantiation
          // cout<< line<<"end of line."<<endl;

          parse(line, variableName, operationLine, verbose);
          if(variableName == "" && operationLine == "") // skipping empty lines in the file
            continue;

          execute(matrices, associateValues, variableName, operationLine, verbose);

          continue; // skipping the next while loop
        }


        string subLine; // stores multilines for concatenation and multiline-matrix instantiation

        while( std::count(line.begin(),line.end(),'[') != std::count(line.begin(),line.end(),']') ){ // one bracket was opened but not closed,
                                                                                                    // keep getting the rest of the line
          getline(cin, subLine);

          while( subLine[0] == ' ' ){
            subLine = subLine.substr(1, subLine.length() - 1);
          }

          line += subLine;
        }
        // cout<< line<<"end of line."<<endl;

        parse(line, variableName, operationLine, verbose);
        if(variableName == "" && operationLine == "") // skipping empty lines in the file
          continue;

        execute(matrices, associateValues, variableName, operationLine, verbose);
      }


    } // end of while(1)












                   /* Test regex in the Matrix Class */
                   clock_t tStart = clock();
    string testcases[] = {
        //     "A = 5.5 + 12 * sin(0.4) + 2.2^4",
        //     "B = [1.2 2.3 A;[1.3 2.4;4.6 1.3],[3.2;7.8]]",
        //     "C = [[B [3.4; 2.1; 3.5+9.1]];1.2^3 3+1.2 15/(2.1+10*sin(0.12)) 1.2]",
        //     "D = rand(4,4)",
        //     "E = [1 2 3 3; 1 2 3 3; 1 2 3 3;1 2 3 3]",
        //     "F = sqrt(E)",
        //     "M = 4",
        //     "I = [[1.2 2.3; 3 2.3;[1.3 2.4;4.6 1.3]], [3.2;-7.8;-3.2; 1.2]]",
        //     "N = [[B,[3.4; 2.1; 3.5+9.1]];1.2^3 3+1.2 15/(2.1+10*sin(0.12)) 1.2]",
        //     "K = ( 2.5 * (1.2 + 4.4 / (2.4 + 3.3)) + 12 * sin(0.4) + 2.2^4 / (M.^3 + M.^2 - 5) ).^(-1.4 + 5)",
        //     "Y = C^3 * sin(E)",
        //     "U = eye(4,4)",
        //     "O = ones(4,4)",
        //     "W = zeros(4,4)"
        //     "D = [1.2^3 3+1.2 15/(2.1+10*sin(0.12)) 1.2;1.4 1.2 1.6 1.1]",
        //     "E = [1.2 1.5;1.6 1.8]",
        //     "F = [1.2+1;1.9*2]",
        //     "G = [1.6+2]",
        //     "H = [1.2 5.7 4.2 1.4+2; 6.3 2.5 8.1 3.1; 6.4 2.8 7.1 8.1; 3.2 5.1 7.2 8.9+2]",
        //     "L = (1.2 + 3.4 - 5.6)/(2.1*3.2 + 4.6) - 12.1*3.1 + (1.2 + 5.2)^(4/(3.2+5.6))",
        //     "N = -3 + 1",
        //     "M = 1 + 20 + -25"
                "A = 5.5 + 12 * sin(0.4) + 2.2^4",
                "B = [1.2 2.3 A;[1.3 2.4;4.6 1.3],[3.2;7.8]]",
                "C = [[B [3.4; 2.1; 3.5+9.1]];1.2^3 3+1.2 15/(2.1+10*sin(0.12))  1.2]",
                "D = rand(4,4)",
                "E = eye(4, 4)",
                "F = zeros(2, 3)",
                "G = ones(3, 6)",
                "L = (1.2 + 3.4 - 5.6)/(2.1*3.2 + 4.6) - 12.1*3.1 + (1.2 + 5.2)^(4/(3.2+5.6))",
                "X = ((C*D .+ 4)./2.1 + sqrt(D))./C.^2",
                "Y = C^3 * sin(1./D)",
                "M = 4",
                "A = ( 2.5 * (1.2 + 4.4 / (2.4 + 3.3)) + 12 * sin(0.4) + 2.2^4 / (M.^3 + M.^2 - 5) ).^(-1.4 + 5)",
                "B = [1.3 2.4;4.6 1.3]",
                "B = [[1.2 2.3; A 2.3; B], [3.2;-7.8;-3.2; 1.2]]"
    };

    vector<CMatrix> matrices;
    vector<AssociativeNumber> associateValues;

    for(int i = 0;i < sizeof(testcases) / sizeof(testcases[0]);i++) {

    cout << "############## Test Case : (" << i + 1 << ")" << " ##################" << endl;
    cout << "Matrix Form : " << endl;
    cout << testcases[i] << endl;
    string content = replaceMatrixOperator(testcases[i]);
    string name = content.substr(0,content.find("="));
    size_t countBracketsForConcatenation = std::count(content.begin(),content.end(),'[');
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
    content = tokenizingexpression(content , matrices , associateValues);
        if(content[0] == '[') { // Case of Matrix Operation
                cout << "case" << endl;
                CMatrix temp(content);
                temp.setName(name);
                matrices.push_back(temp);
                cout << temp.getName() << " = " << endl;
                cout << temp;
        } else {
                AssociativeNumber temp(name,getEvaluation(content));
                associateValues.push_back(temp);
                cout << temp.getName() << " = " << temp.getValue() << endl;
        }
    }


} // End of For Loop





} // End of Else

  return 0;
}
