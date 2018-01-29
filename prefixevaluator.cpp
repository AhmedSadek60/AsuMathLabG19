#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <cctype>
#include <iterator>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <regex>
#include "testexp.cpp"
using namespace std;


/* Triogmetric Functions */

/*
    [ Function Name ] : sinTrigometric()
    [ Returned Type ] : double
    [ Inherited Function ] : - sin From <cmath> Library
    [ Functionality ] : get the Sin Value of a double number
 */

double sinTrigometric(double a) {

    return sin(a);

}

/*
    [ Function Name ] : cosTrigometric()
    [ Returned Type ] : double
    [ Inherited Function ] : - cos From <cmath> Library
    [ Functionality ] :  get the Cos Value of a double number
 */

double cosTrigometric(double a) {

    return cos(a);

}

/*
    [ Function Name ] : tanTrigometric()
    [ Returned Type ] : double
    [ Inherited Function ] : - tan From <cmath> Library
    [ Functionality ] :  get the tan Value of a double number 
 */

double tanTrigometric(double a) {

    return tan(a);

}

/*
    [ Function Name ] : sqrtFunction()
    [ Returned Type ] : double
    [ Inherited Function ] : - sqrt From <cmath> Library
    [ Functionality ] : get the sqrt Value of a double number  
 */
double sqrtFunction(double a) {

    return sqrt(a);

}



/* Check For Negative */
/*
    [ Function Name ] : replacenegativeNumbers( string expression )
    [ Returned Type ] : string
    [ Inherited Function ] : 
                        - replace function - from <string> library
                        - regex_search - from <regex> library
    [ Functionality ] : It looks for the negattive number in the expression string parameter that you pass to it then it converts all of them to be like that
                    - if 12 + -2.5 ===> 12 + (0 - 2.5)

 */



string replaceNegativeNumbers(string expression) {
    for(int i = 0 ;i < expression.size();i++) {
            if(expression[i] == '-' && i != 0) {
                smatch negativeCheck;
                string tempExpression = "";
                tempExpression += expression[i - 1];
                bool ifUnary = regex_search(tempExpression,negativeCheck,regex("[\d]+")); // To Search For Any Number
                bool ifOperator = regex_search(tempExpression,negativeCheck,regex("[*^\/+-]+")); // To Search For +,-,/,*,^,...etc
                if(expression[i - 1] == ')' || ifUnary == 1) { // Subtraction Case
                    continue;
                } else if(ifOperator == 1 || expression[i-1] == '(') { // Unary Negative Case
                    string forNegativePurpose = "(0-";
                    int numberOfOperator = -1;
                    for(int j = i + 1; j < expression.size();j++) {
                        if(expression[j] == '+' || expression[j] == '-' || expression[j] == '*' || expression[j] == '/' || expression[j] == '^' || expression[j] == ')') {
                            numberOfOperator = j; // To be my endpoint that i should replace to
                            break;
                        } else {
                            forNegativePurpose += expression[j];
                        }
                    }
                    forNegativePurpose += ")";
                    expression.replace(i,numberOfOperator - i,forNegativePurpose);
                }
            }


        }

    return expression;
}





    void tokenize(string& str, vector<string>& tokens)
    {
        int pos;
        string token;
        while ((pos = str.find(" ")) != std::string::npos )
        {
            token = str.substr(0,pos);
            tokens.push_back(token); 
            str.erase(0, pos + 1);  
        }
        tokens.push_back(str.c_str());  
    }

    bool isOperator(string str)
    {
        if((str == "+") || (str == "-") || (str == "*") || (str == "/") || (str == "^") || (str == "&") || (str == "$") || (str == "#") || (str == "?") || (str == "@"))
            return true;
        else
            return false;
    }

    double compute(string oper, double val1, double val2)
    {
        
        if(oper == "+" || oper == "@") {
            return (val1 + val2);
        }
        else if(oper == "*" || oper == "#") {
            return (val1 * val2);
        }
        else if(oper == "-" || oper == "?") {
            return (val1 - val2);
        }
        else if(oper == "/" || oper == "$") {
            return (val1 / val2); 
        }
        else if(oper == "^" || oper == "&") {
            return pow(val1,val2);
        }
        else {
            return 0;
        }
    }

    double evalPrefix(vector<string>& expression)
    {
        vector<double> numStack;
        double num1;
        double num2;

        for (int i = (expression.size() - 1); i >=0; i--)
        {
            
            if(isOperator(expression[i]))
            {
                num1 = numStack.back();
                numStack.pop_back();
                num2 = numStack.back();
                numStack.pop_back();
                numStack.push_back(compute(expression[i], num1, num2));
            }
            else
            {
                numStack.push_back(atof(expression[i].c_str()));
            }
        }

        return numStack[0];
    }


/*
    [ Function Name ] : replaceTriagomtric(string expression)
    [ Function return Type ] : string
    [ Function Inherited Functions ] : 
    [ Functionality ] : 


*/


string replaceTriagomtric(string expression) {
        // For Trigrometric Function COnversion
    smatch m;
    bool result = regex_search(expression,m,regex("(sin|cos|sqrt|tan).{1,10}.[)]"));
    string tempString = expression;
    if(result == 1) {
        while(regex_search(tempString,m,regex("(sin|cos|sqrt|tan).{1,10}.[)]"))) {
            string d = m[0];
            if(d.find("sin") != string::npos) {
                bool additionPar = false;
                size_t countLeftPar = std::count(d.begin(),d.end(),'(');
                size_t countRightPar = std::count(d.begin(),d.end(),')');
                if(countLeftPar != countRightPar) {
                    additionPar = true;
                }
                d.erase(d.length() - 1);
                d.erase(0,d.find('(') + 1);
                smatch checkOp;
                bool checkOperation = regex_search(d,checkOp,regex("[/*^+-]+"));
                double tempResult;
                if(checkOperation == 1) {
                        d = replaceNegativeNumbers(d);
                        Exp *tree = strToExp(d);
                        string temp;
                        temp += tree->print();
                        vector<string> tokens; 
                        tokens.clear();
                        tokenize(temp, tokens);
                        if(tokens.size()) {
                            tempResult = evalPrefix(tokens);
                        }
                    tempResult = sinTrigometric(tempResult);
                } else {
                    tempResult = sinTrigometric(atof(d.c_str()));
                }

                if(additionPar == true) {
                    string tempForAdditionPar = std::to_string(tempResult);
                    for(int o = 0;o < countRightPar - countLeftPar;o++) {
                        tempForAdditionPar += ")";
                    }
                    expression.replace(expression.find(m[0]),m.length(0),tempForAdditionPar);
                } else {
                    expression.replace(expression.find(m[0]),m.length(0),std::to_string(tempResult));
                }


            }
            else if(d.find("cos") != string::npos) {
                bool additionPar = false;
                size_t countLeftPar = std::count(d.begin(),d.end(),'(');
                size_t countRightPar = std::count(d.begin(),d.end(),')');
                if(countLeftPar != countRightPar) {
                    additionPar = true;
                }
                d.erase(d.length() - 1);
                d.erase(0,d.find('(') + 1);
                smatch checkOp;
                bool checkOperation = regex_search(d,checkOp,regex("[/*^+-]+"));
                double tempResult;
                if(checkOperation == 1) {
                        d = replaceNegativeNumbers(d);                    
                        Exp *tree = strToExp(d);
                        string temp;
                        temp += tree->print();
                        vector<string> tokens; 
                        tokens.clear();
                        tokenize(temp, tokens);
                        if(tokens.size()) {
                            tempResult = evalPrefix(tokens);
                        }
                        tempResult = cosTrigometric(tempResult);

                } else {
                 tempResult = cosTrigometric(atof(d.c_str()));
                }
                if(additionPar == true) {
                    string tempForAdditionPar = std::to_string(tempResult);
                    for(int o = 0;o < countRightPar - countLeftPar;o++) {
                        tempForAdditionPar += ")";
                    }
                    expression.replace(expression.find(m[0]),m.length(0),tempForAdditionPar);
                } else {
                    expression.replace(expression.find(m[0]),m.length(0),std::to_string(tempResult));
                }
                
            }
            else if(d.find("tan") != string::npos) {
                bool additionPar = false;
                size_t countLeftPar = std::count(d.begin(),d.end(),'(');
                size_t countRightPar = std::count(d.begin(),d.end(),')');
                if(countLeftPar != countRightPar) {
                    additionPar = true;
                }
                d.erase(d.length() - 1);
                d.erase(0,d.find('(') + 1);
                smatch checkOp;
                bool checkOperation = regex_search(d,checkOp,regex("[/*^+-]+"));
                double tempResult;
                if(checkOperation == 1) {
                        d = replaceNegativeNumbers(d);                    
                        Exp *tree = strToExp(d);
                        string temp;
                        temp += tree->print();
                        vector<string> tokens; 
                        tokens.clear();
                        tokenize(temp, tokens);
                        if(tokens.size()) {
                            tempResult = evalPrefix(tokens);
                        }
                        tempResult = tanTrigometric(tempResult);
                 
                } else {
                 tempResult = tanTrigometric(atof(d.c_str()));
                }
                if(additionPar == true) {
                    string tempForAdditionPar = std::to_string(tempResult);
                    for(int o = 0;o < countRightPar - countLeftPar;o++) {
                        tempForAdditionPar += ")";
                    }
                    expression.replace(expression.find(m[0]),m.length(0),tempForAdditionPar);
                } else {
                    expression.replace(expression.find(m[0]),m.length(0),std::to_string(tempResult));
                }
                
            }
            else if(d.find("sqrt") != string::npos) {
                bool additionPar = false;
                size_t countLeftPar = std::count(d.begin(),d.end(),'(');
                size_t countRightPar = std::count(d.begin(),d.end(),')');
                if(countLeftPar != countRightPar) {
                    additionPar = true;
                }
                d.erase(d.length() - 1);
                d.erase(0,d.find('(') + 1);
                smatch checkOp;
                bool checkOperation = regex_search(d,checkOp,regex("[/*^+-]+"));
                double tempResult;
                if(checkOperation == 1) {
                        d = replaceNegativeNumbers(d);                    
                        Exp *tree = strToExp(d);
                        string temp;
                        temp += tree->print();
                        vector<string> tokens; 
                        tokens.clear();
                        tokenize(temp, tokens);
                        if(tokens.size()) {
                            tempResult = evalPrefix(tokens);
                        }
                        tempResult = sqrtFunction(tempResult);
                 
                } else {
                 tempResult = sqrtFunction(atof(d.c_str()));
                }
                if(additionPar == true) {
                    string tempForAdditionPar = std::to_string(tempResult);
                    for(int o = 0;o < countRightPar - countLeftPar;o++) {
                        tempForAdditionPar += ")";
                    }
                    expression.replace(expression.find(m[0]),m.length(0),tempForAdditionPar);
                } else {
                    expression.replace(expression.find(m[0]),m.length(0),std::to_string(tempResult));
                }

                
            }
            tempString = m.suffix().str();
        }

    }

     
    return expression;

}


/* End  */
