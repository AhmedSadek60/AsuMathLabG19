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
#include "prefixevaluator.cpp"
#include "CMatrix.cpp"
using namespace std;

/*
    [ Function Name ] : replaceMatrixOperator()
    [ Returned Type ] : string
    [ Inherited Function ] : - replace from string library
    [ Functionality ] : replace [ .+ , .* , .^ , ...etc ]
 */

string replaceMatrixOperator(string x)
{

    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '.' && x[i + 1] == '+')
        {
            x.replace(i, 2, "@");
        }
        else if (x[i] == '.' && x[i + 1] == '-')
        {
            x.replace(i, 2, "?");
        }
        else if (x[i] == '.' && x[i + 1] == '*')
        {
            x.replace(i, 2, "#");
        }
        else if (x[i] == '.' && x[i + 1] == '/')
        {
            x.replace(i, 2, "$");
        }
        else if (x[i] == '.' && x[i + 1] == '^')
        {
            x.replace(i, 2, "&");
        }
    }

    return x;
}

/* ############################################################################# */

int isInsideMatrixForMatrix(vector<CMatrix> matricesArray, string target)
{
    bool found = false;
    int index = -1;
    for (int i = 0; i < matricesArray.size(); i++)
    {
        if (matricesArray[i].getName() == target)
        {
            found = true;
            index = i;
        }
    }
    return index;
}

/* ############################################################################# */

/* Triogmetric Functions */

// /*
//     [ Function Name ] : sinTrigometric()
//     [ Returned Type ] : double
//     [ Inherited Function ] : - sin From <cmath> Library
//     [ Functionality ] : get the Sin Value of a double number
//  */

// double sinTrigometric(double a) {

//     return sin(a);

// }

// /*
//     [ Function Name ] : cosTrigometric()
//     [ Returned Type ] : double
//     [ Inherited Function ] : - cos From <cmath> Library
//     [ Functionality ] :  get the Cos Value of a double number
//  */

// double cosTrigometric(double a) {

//     return cos(a);

// }

// /*
//     [ Function Name ] : tanTrigometric()
//     [ Returned Type ] : double
//     [ Inherited Function ] : - tan From <cmath> Library
//     [ Functionality ] :  get the tan Value of a double number
//  */

// double tanTrigometric(double a) {

//     return tan(a);

// }

// /*
//     [ Function Name ] : sqrtFunction()
//     [ Returned Type ] : double
//     [ Inherited Function ] : - sqrt From <cmath> Library
//     [ Functionality ] : get the sqrt Value of a double number
//  */
// double sqrtFunction(double a) {

//     return sqrt(a);

// }

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

string replaceNegativeNumbersForMatrix(string expression)
{
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '-' && i != 0)
        {
            smatch negativeCheck;
            string tempExpression = "";
            tempExpression += expression[i - 1];
            bool ifUnary = regex_search(tempExpression, negativeCheck, regex("[\d]+"));        // To Search For Any Number
            bool ifOperator = regex_search(tempExpression, negativeCheck, regex("[*^\/+-]+")); // To Search For +,-,/,*,^,...etc
            if (expression[i - 1] == ')' || ifUnary == 1 || expression[i - 1] == '.')
            { // Subtraction Case
                continue;
            }
            else if (ifOperator == 1 || expression[i - 1] == '(')
            { // Unary Negative Case
                string forNegativePurpose = "(0-";
                int numberOfOperator = -1;
                for (int j = i + 1; j < expression.size(); j++)
                {
                    if (expression[j] == '+' || expression[j] == '-' || expression[j] == '*' || expression[j] == '/' || expression[j] == '^' || expression[j] == '@' || expression[j] == '?' || expression[j] == '#' || expression[j] == '$' || expression[j] == '&' || expression[j] == ')')
                    {
                        numberOfOperator = j; // To be my endpoint that i should replace to
                        break;
                    }
                    else
                    {
                        forNegativePurpose += expression[j];
                    }
                }
                forNegativePurpose += ")";
                expression.replace(i, numberOfOperator - i, forNegativePurpose);
            }
        }
    }

    return expression;
}

void tokenizeForMatrix(string &str, vector<string> &tokens)
{
    int pos;
    string token;
    while ((pos = str.find(" ")) != std::string::npos)
    {
        token = str.substr(0, pos);
        tokens.push_back(token);
        str.erase(0, pos + 1);
    }
    tokens.push_back(str.c_str());
}

bool isOperatorForMatrix(string str)
{
    if ((str == "+") || (str == "-") || (str == "*") || (str == "/") || (str == "^") || (str == "@") || (str == "?") || (str == "#") || (str == "$") || (str == "&"))
        return true;
    else
        return false;
}

CMatrix computeForMatrix(string oper, CMatrix val1, CMatrix val2)
{

    if (oper == "+" || oper == "@")
    {
        if (val2.getName() == "Number")
        {
            CMatrix tempMatrix = val1 + val2.getOneValue();
            return tempMatrix;
        }
        else
        {
            CMatrix tempMatrix = val1 + val2;
            return tempMatrix;
        }
    }
    else if (oper == "*" || oper == "#")
    {
        if (val2.getName() == "Number")
        {
            CMatrix tempMatrix = val1 * val2.getOneValue();
            return tempMatrix;
        }
        else
        {
            CMatrix tempMatrix = val1 * val2;
            return tempMatrix;
        }
    }
    else if (oper == "-" || oper == "?")
    {
        if (val2.getName() == "Number")
        {
            CMatrix tempMatrix = val1 - val2.getOneValue();
            return tempMatrix;
        }
        else
        {
            CMatrix tempMatrix = val1 - val2;
            return tempMatrix;
        }
    }
    else if (oper == "/")
    {
        CMatrix invertedMatrix = val2.getInverse();
        CMatrix tempMatrix = val1 * invertedMatrix;
        return tempMatrix;
    }
    else if (oper == "^")
    {
        if (val2.getName() == "Number")
        {
            CMatrix tempMatrix = val1 ^ val2.getOneValue();
            return tempMatrix;
        }
        
    } else if(oper == "&") {
        CMatrix tempMatrix = val1.elementWisePow(val2.getOneValue());
        return tempMatrix;
    } else if(oper == "$") {
        if(val1.getName() == "Number") {
            CMatrix dMatrix(val2.getnR(),val2.getnC(),CMatrix::MI_VALUE,val1.getOneValue());
            CMatrix tempMatrix = dMatrix.elementWiseDiv(val2);
            return tempMatrix;

        } else if(val2.getName() == "Number") {
            CMatrix dMatrix(val1.getnR(),val1.getnC(),CMatrix::MI_VALUE,val2.getOneValue());
            CMatrix tempMatrix = val1.elementWiseDiv(dMatrix);
            return tempMatrix;

        } else {
            CMatrix tempMatrix = val1.elementWiseDiv(val2);
            return tempMatrix;
        }
    }
    else
        return 0;
}

CMatrix evalPrefixForMatrix(vector<string> &expression, vector<CMatrix> matricesArray)
{
    vector<CMatrix> numStack;
    CMatrix num1;
    CMatrix num2;

    for (int i = (expression.size() - 1); i >= 0; i--)
    {

        if (isOperatorForMatrix(expression[i]))
        {
            num1 = numStack.back();
            numStack.pop_back();
            num2 = numStack.back();
            numStack.pop_back();
            CMatrix resultMatrixFromCompute = computeForMatrix(expression[i], num1, num2);
            numStack.push_back(resultMatrixFromCompute);
        }
        else
        {
            smatch s;
            bool isNumber = regex_search(expression[i], s, regex("[A-Za-z]+"));
            if (isNumber == 0)
            {
                double num = atof(expression[i].c_str());
                CMatrix dMatrix(1, 1, CMatrix::MI_VALUE, num);
                dMatrix.setName("Number");
                numStack.push_back(dMatrix);
            }
            else
            {
                int getMatrix = isInsideMatrixForMatrix(matricesArray, expression[i]);
                if (getMatrix != -1)
                {
                    CMatrix aMatrix = matricesArray[getMatrix];
                    numStack.push_back(aMatrix);
                }
            }
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

string replaceTriagomtricForMatrix(string &expression, vector<CMatrix> &matrices)
{
    // For Trigrometric Function COnversion
    smatch m;
    string testString = expression;
    bool result = regex_search(testString, m, regex("(sin|cos|sqrt|tan|ln|log).{1,10}.[)]"));
    string tempString = expression;
    double count = (rand() % 1000000) / 1000000.0;
    if (result == 1)
    {
        while (regex_search(tempString, m, regex("(sin|cos|sqrt|tan|ln|log).{1,10}.[)]")))
        {
            string d = m[0];
            if (d.find("sin") != string::npos)
            {
                bool additionPar = false;
                size_t countLeftPar = std::count(d.begin(), d.end(), '(');
                size_t countRightPar = std::count(d.begin(), d.end(), ')');
                if (countLeftPar != countRightPar)
                {
                    additionPar = true;
                }
                d.erase(d.length() - 1);
                d.erase(0, d.find('(') + 1);
                smatch checkOp;
                bool checkOperation = regex_search(d, checkOp, regex("[\/*^+$&@#-]+"));
                CMatrix tempResult;
                if (checkOperation == 1)
                {
                    d = replaceMatrixOperator(d);
                    d = replaceNegativeNumbersForMatrix(d);
                    d = replaceTriagomtricForMatrix(d, matrices);
                    Exp *tree = strToExp(d);
                    string temp;
                    temp += tree->print();
                    vector<string> tokens;
                    tokens.clear();
                    tokenize(temp, tokens);
                    if (tokens.size())
                    {
                        tempResult = evalPrefixForMatrix(tokens, matrices);
                    }
                    tempResult = tempResult.sin();
                    tempResult.setName("S" + std::to_string(count));
                    matrices.push_back(tempResult);
                    count++;
                }
                else
                {
                    int isMatrix = isInsideMatrixForMatrix(matrices, d);
                    if (isMatrix != -1)
                    {
                        tempResult = matrices[isMatrix].sin();
                        tempResult.setName("S" + std::to_string(count));
                        matrices.push_back(tempResult);
                        count++;
                    }
                }

                if (additionPar == true)
                {
                    string tempForAdditionPar = tempResult.getName();
                    for (int o = 0; o < countRightPar - countLeftPar; o++)
                    {
                        tempForAdditionPar += ")";
                    }
                    expression.replace(expression.find(m[0]), m.length(0), tempForAdditionPar);
                }
                else
                {
                    expression.replace(expression.find(m[0]), m.length(0), tempResult.getName());
                }
            }
            else if (d.find("cos") != string::npos)
            {
                bool additionPar = false;
                size_t countLeftPar = std::count(d.begin(), d.end(), '(');
                size_t countRightPar = std::count(d.begin(), d.end(), ')');
                if (countLeftPar != countRightPar)
                {
                    additionPar = true;
                }
                d.erase(d.length() - 1);
                d.erase(0, d.find('(') + 1);
                smatch checkOp;
                bool checkOperation = regex_search(d, checkOp, regex("[\/*^+$&@#-]+"));
                CMatrix tempResult;
                if (checkOperation == 1)
                {
                    d = replaceMatrixOperator(d);
                    d = replaceNegativeNumbersForMatrix(d);
                    d = replaceTriagomtricForMatrix(d, matrices);
                    Exp *tree = strToExp(d);
                    string temp;
                    temp += tree->print();
                    vector<string> tokens;
                    tokens.clear();
                    tokenize(temp, tokens);
                    if (tokens.size())
                    {
                        tempResult = evalPrefixForMatrix(tokens, matrices);
                    }
                    tempResult = tempResult.cos();
                    tempResult.setName("S" + std::to_string(count));
                    matrices.push_back(tempResult);
                    count++;
                }
                else
                {
                    int isMatrix = isInsideMatrixForMatrix(matrices, d);
                    if (isMatrix != -1)
                    {
                        tempResult = matrices[isMatrix].cos();
                        tempResult.setName("S" + std::to_string(count));
                        matrices.push_back(tempResult);
                        count++;
                    }
                }

                if (additionPar == true)
                {
                    string tempForAdditionPar = tempResult.getName();
                    for (int o = 0; o < countRightPar - countLeftPar; o++)
                    {
                        tempForAdditionPar += ")";
                    }
                    expression.replace(expression.find(m[0]), m.length(0), tempForAdditionPar);
                }
                else
                {
                    expression.replace(expression.find(m[0]), m.length(0), tempResult.getName());
                }
            }
            else if (d.find("tan") != string::npos)
            {
                bool additionPar = false;
                size_t countLeftPar = std::count(d.begin(), d.end(), '(');
                size_t countRightPar = std::count(d.begin(), d.end(), ')');
                if (countLeftPar != countRightPar)
                {
                    additionPar = true;
                }
                d.erase(d.length() - 1);
                d.erase(0, d.find('(') + 1);
                smatch checkOp;
                bool checkOperation = regex_search(d, checkOp, regex("[\/*^+$&@#-]+"));
                CMatrix tempResult;
                if (checkOperation == 1)
                {
                    d = replaceMatrixOperator(d);
                    d = replaceNegativeNumbersForMatrix(d);
                    d = replaceTriagomtricForMatrix(d, matrices);
                    Exp *tree = strToExp(d);
                    string temp;
                    temp += tree->print();
                    vector<string> tokens;
                    tokens.clear();
                    tokenize(temp, tokens);
                    if (tokens.size())
                    {
                        tempResult = evalPrefixForMatrix(tokens, matrices);
                    }
                    tempResult = tempResult.tan();
                    tempResult.setName("S" + std::to_string(count));
                    matrices.push_back(tempResult);
                    count++;
                }
                else
                {
                    int isMatrix = isInsideMatrixForMatrix(matrices, d);
                    if (isMatrix != -1)
                    {
                        tempResult = matrices[isMatrix].tan();
                        tempResult.setName("S" + std::to_string(count));
                        matrices.push_back(tempResult);
                        count++;
                    }
                }

                if (additionPar == true)
                {
                    string tempForAdditionPar = tempResult.getName();
                    for (int o = 0; o < countRightPar - countLeftPar; o++)
                    {
                        tempForAdditionPar += ")";
                    }
                    expression.replace(expression.find(m[0]), m.length(0), tempForAdditionPar);
                }
                else
                {
                    expression.replace(expression.find(m[0]), m.length(0), tempResult.getName());
                }
            }
            else if (d.find("sqrt") != string::npos)
            {
                bool additionPar = false;
                size_t countLeftPar = std::count(d.begin(), d.end(), '(');
                size_t countRightPar = std::count(d.begin(), d.end(), ')');
                if (countLeftPar != countRightPar)
                {
                    additionPar = true;
                }
                d.erase(d.length() - 1);
                d.erase(0, d.find('(') + 1);
                smatch checkOp;
                bool checkOperation = regex_search(d, checkOp, regex("[\/*^+$&@#-]+"));
                CMatrix tempResult;
                if (checkOperation == 1)
                {
                    d = replaceMatrixOperator(d);
                    d = replaceNegativeNumbersForMatrix(d);
                    d = replaceTriagomtricForMatrix(d, matrices);
                    Exp *tree = strToExp(d);
                    string temp;
                    temp += tree->print();
                    vector<string> tokens;
                    tokens.clear();
                    tokenize(temp, tokens);
                    if (tokens.size())
                    {
                        tempResult = evalPrefixForMatrix(tokens, matrices);
                    }
                    tempResult = tempResult.sqrt();
                    tempResult.setName("S" + std::to_string(count));
                    matrices.push_back(tempResult);
                    count++;
                }
                else
                {
                    d.erase(std::remove(d.begin(), d.end(), ')'), d.end());
                    d.erase(std::remove(d.begin(), d.end(), '('), d.end());
                    int isMatrix = isInsideMatrixForMatrix(matrices, d);
                    if (isMatrix != -1)
                    {

                        tempResult = matrices[isMatrix].sqrt();
                        tempResult.setName("S" + std::to_string(count));
                        matrices.push_back(tempResult);
                        count++;
                    }
                }

                if (additionPar == true)
                {
                    string tempForAdditionPar = tempResult.getName();
                    for (int o = 0; o < countRightPar - countLeftPar; o++)
                    {
                        tempForAdditionPar += ")";
                    }
                    expression.replace(expression.find(m[0]), m.length(0), tempForAdditionPar);
                }
                else
                {
                    expression.replace(expression.find(m[0]), m.length(0), tempResult.getName());
                }
            }
            else if (d.find("log") != string::npos)
            {
                bool additionPar = false;
                size_t countLeftPar = std::count(d.begin(), d.end(), '(');
                size_t countRightPar = std::count(d.begin(), d.end(), ')');
                if (countLeftPar != countRightPar)
                {
                    additionPar = true;
                }
                d.erase(d.length() - 1);
                d.erase(0, d.find('(') + 1);
                smatch checkOp;
                bool checkOperation = regex_search(d, checkOp, regex("[\/*^+$&@#-]+"));
                CMatrix tempResult;
                if (checkOperation == 1)
                {
                    d = replaceMatrixOperator(d);
                    d = replaceNegativeNumbersForMatrix(d);
                    d = replaceTriagomtricForMatrix(d, matrices);
                    Exp *tree = strToExp(d);
                    string temp;
                    temp += tree->print();
                    vector<string> tokens;
                    tokens.clear();
                    tokenize(temp, tokens);
                    if (tokens.size())
                    {
                        tempResult = evalPrefixForMatrix(tokens, matrices);
                    }
                    tempResult = tempResult.getLog();
                    tempResult.setName("S" + std::to_string(count));
                    matrices.push_back(tempResult);
                    count++;
                }
                else
                {
                    int isMatrix = isInsideMatrixForMatrix(matrices, d);
                    if (isMatrix != -1)
                    {
                        tempResult = matrices[isMatrix].getLog();
                        tempResult.setName("S" + std::to_string(count));
                        matrices.push_back(tempResult);
                        count++;
                    }
                }

                if (additionPar == true)
                {
                    string tempForAdditionPar = tempResult.getName();
                    for (int o = 0; o < countRightPar - countLeftPar; o++)
                    {
                        tempForAdditionPar += ")";
                    }
                    expression.replace(expression.find(m[0]), m.length(0), tempForAdditionPar);
                }
                else
                {
                    expression.replace(expression.find(m[0]), m.length(0), tempResult.getName());
                }
            }
            else if (d.find("ln") != string::npos)
            {
                bool additionPar = false;
                size_t countLeftPar = std::count(d.begin(), d.end(), '(');
                size_t countRightPar = std::count(d.begin(), d.end(), ')');
                if (countLeftPar != countRightPar)
                {
                    additionPar = true;
                }
                d.erase(d.length() - 1);
                d.erase(0, d.find('(') + 1);
                smatch checkOp;
                bool checkOperation = regex_search(d, checkOp, regex("[\/*^+$&@#-]+"));
                CMatrix tempResult;
                if (checkOperation == 1)
                {
                    d = replaceMatrixOperator(d);
                    d = replaceNegativeNumbersForMatrix(d);
                    d = replaceTriagomtricForMatrix(d, matrices);
                    Exp *tree = strToExp(d);
                    string temp;
                    temp += tree->print();
                    vector<string> tokens;
                    tokens.clear();
                    tokenize(temp, tokens);
                    if (tokens.size())
                    {
                        tempResult = evalPrefixForMatrix(tokens, matrices);
                    }
                    tempResult = tempResult.getLn();
                    tempResult.setName("S" + std::to_string(count));
                    matrices.push_back(tempResult);
                    count++;
                }
                else
                {
                    int isMatrix = isInsideMatrixForMatrix(matrices, d);
                    if (isMatrix != -1)
                    {
                        tempResult = matrices[isMatrix].getLn();
                        tempResult.setName("S" + std::to_string(count));
                        matrices.push_back(tempResult);
                        count++;
                    }
                }

                if (additionPar == true)
                {
                    string tempForAdditionPar = tempResult.getName();
                    for (int o = 0; o < countRightPar - countLeftPar; o++)
                    {
                        tempForAdditionPar += ")";
                    }
                    expression.replace(expression.find(m[0]), m.length(0), tempForAdditionPar);
                }
                else
                {
                    expression.replace(expression.find(m[0]), m.length(0), tempResult.getName());
                }
            }
            tempString = m.suffix().str();
        }
    }

    return expression;
}

string getExpressionFromMain(string content, vector<CMatrix> matrices)
{
    if(content.find("rand") != std::string::npos){
        content.erase(std::remove(content.begin(), content.end(), ' '), content.end());
        string rowsNumber = content.substr(content.find('(') + 1, content.find(',') - (content.find('(') + 1));
        string columnsNumber = content.substr(content.find(',') + 1, content.find(')') - (content.find(',') + 1));

        int numR = atof(rowsNumber.c_str());
        int numC = atof(columnsNumber.c_str());
        CMatrix result = CMatrix(numR, numC, CMatrix::MI_RAND, 0.0);
        result.setName(result.getMatrixForm());

        return result.getName();

    }
    else if(content.find("eye") != std::string::npos)
    {
        content.erase(std::remove(content.begin(), content.end(), ' '), content.end());
        string rowsNumber = content.substr(content.find('(') + 1, content.find(',') - (content.find('(') + 1));
        string columnsNumber = content.substr(content.find(',') + 1, content.find(')') - (content.find(',') + 1));

        int numR = atof(rowsNumber.c_str());
        int numC = atof(columnsNumber.c_str());
        CMatrix result = CMatrix(numR,numC,CMatrix::MI_EYE, 0.0);
        result.setName(result.getMatrixForm());

        return result.getName();

    } else if(content.find("ones") != std::string::npos) {
        content.erase(std::remove(content.begin(), content.end(), ' '), content.end());
        string rowsNumber = content.substr(content.find('(') + 1, content.find(',') - (content.find('(') + 1));
        string columnsNumber = content.substr(content.find(',') + 1, content.find(')') - (content.find(',') + 1));

        int numR = atof(rowsNumber.c_str());
        int numC = atof(columnsNumber.c_str());
        CMatrix result = CMatrix(numR,numC,CMatrix::MI_ONES, 0.0);
        result.setName(result.getMatrixForm());

        return result.getName();
    } else if(content.find("zeros") != std::string::npos) {
        content.erase(std::remove(content.begin(), content.end(), ' '), content.end());
        string rowsNumber = content.substr(content.find('(') + 1, content.find(',') - (content.find('(') + 1));
        string columnsNumber = content.substr(content.find(',') + 1, content.find(')') - (content.find(',') + 1));

        int numR = atof(rowsNumber.c_str());
        int numC = atof(columnsNumber.c_str());
        CMatrix result = CMatrix(numR, numC, CMatrix::MI_ZEROS, 0.0);
        result.setName(result.getMatrixForm());

        return result.getName();

    } else {
        CMatrix result;
        content.erase(remove_if(content.begin(), content.end(), ::isspace), content.end());
        content = replaceNegativeNumbersForMatrix(content);
        content = replaceTriagomtricForMatrix(content, matrices);

        string temp;
        Exp *tree = strToExp(content);
        temp += tree->print();
        vector<string> tokens;
        tokens.clear();
        tokenize(temp, tokens);
        if (tokens.size())
        {
            result = evalPrefixForMatrix(tokens, matrices);
        }

        result.setName(result.getMatrixForm());

        return result.getName();

    }

}



/* End  */

// int main()
// {

//     clock_t tStart = clock();
//     string token;
//     string testcases[] = {
//         "5.5 + 12 * sin(0.4) + 2.2^4",
//         "(1.2 + 3.4 - 5.6)/(2.1*3.2 + 4.6) - 12.1*3.1 + (1.2 + 5.2)^(4/(3.2+5.6))",
//         "12 * -0.255 + 2.5689 - 5.6 + sin(-3 + 1)",
//         "5.5 + 12 * sin(-4 + 1) - 2.2^4",
//         "5.5 + 12 * sin(-4 + 1) - 2.2^4 + -2.6",
//         "15/(2.1+10*sin(0.12))",
//         "1.2 + cos(0.6) + tan(0.8) + -2.5",
//         "1.5 + 15 * sin(0.4 - 0.2) + sqrt(3 + 6)",
//         "1.2^3",
//         "3+1.2"
//     };
//     for(int f = 0 ; f < 10;f++) {
//     // string expression = "12 * -0.255 + 2.5689 - 5.6 + sin(-3 + 1)";
//     // string expression = "5.5 + 12 * sin(-4 + 1) - 2.2^4";
//     string expression = testcases[f];
//     expression.erase(remove_if(expression.begin(), expression.end(), ::isspace), expression.end());

//     cout << "###### Test Case : (" << f + 1 << ") ########" << endl;

//     cout << "Expression : " << endl;
//     cout << expression << endl;

//     // Replace Triagrometric
//     expression = replaceTriagomtric(expression);

//     // Replace Negative
//     expression = replaceNegativeNumbers(expression);

//     cout << "Check For Negative Numbers ..." << endl;
//     cout << "After Conversion of Negative Numbers : " << endl;
//     cout << expression << endl;

//         Exp *finalResult = strToExp(expression);
//         string tempFinal;
//         tempFinal += finalResult->print();
//         cout << tempFinal << endl;
//         vector<string> tokens;

//         cout << "Result =  ( ";
//                 tokens.clear();
//                 tokenize(tempFinal, tokens);
//                 if(tokens.size()) {
//                     cout << evalPrefix(tokens);
//                 }
//                 cout << " )" << endl;

//     cout << "#########################################################################" << endl;

//     }

//                 cout << "Execution Time : " << endl;
//                 cout << ((double)(clock() - tStart) / CLOCKS_PER_SEC ) * 1000 << "ms" << endl;
//     return 0;
// }