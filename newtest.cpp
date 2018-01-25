
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>
#include <math.h>
#include <exception>
#include <time.h>
#include <regex>
using namespace std;



/* Triogmetric Functions */

double sinTrigometric(double a) {

    return sin(a);

}

double cosTrigometric(double a) {

    return cos(a);

}

double tanTrigometric(double a) {

    return tan(a);

}
double sqrtFunction(double a) {

    return sqrt(a);

}





 
class ExpressionElementNode
{
    public:
        virtual double value() = 0; // Return the value of this node.
};
 
class NumericElementNode: public ExpressionElementNode
{
 
    private:
        double number;
        NumericElementNode(const NumericElementNode& n);
        NumericElementNode();
        NumericElementNode&operator=(const NumericElementNode& n);
    public:
 
        NumericElementNode(double val);
        virtual double value();
};
 
inline NumericElementNode::NumericElementNode(double val) :
    number(val)
{
}
 
inline double NumericElementNode::value()
{
    return number;
}
 
class BinaryOperationNode: public ExpressionElementNode
{
 
    private:
 
        char binary_op;
 
        ExpressionElementNode *left;
        ExpressionElementNode *right;
 
        BinaryOperationNode(const BinaryOperationNode& n);
        BinaryOperationNode();
        BinaryOperationNode &operator=(const BinaryOperationNode& n);
 
    public:
        BinaryOperationNode(char op, ExpressionElementNode *l,
                ExpressionElementNode *r);
 
        virtual double value();
};
 
inline BinaryOperationNode::BinaryOperationNode(char op,
        ExpressionElementNode *l, ExpressionElementNode *r) :
    binary_op(op), left(l), right(r)
{
}
double BinaryOperationNode::value()
{
    // To get the value, compute the value of the left and
    // right operands, and combine them with the operator.
    double leftVal = left->value();
 
    double rightVal = right->value();
 
    double result;
 
    switch (binary_op)
    {
 
        case '+':
            result = leftVal + rightVal;
            break;
 
        case '-':
            result = leftVal - rightVal;
            break;
 
        case '*':
            result = leftVal * rightVal;
            break;
 
        case '/':
            result = leftVal / rightVal;
            break;
        case '^':
            result = pow(leftVal,rightVal);
            break;
    }
 
    return result;
}
class ExpressionElementNode;
class BinaryOperationNode;
 
class BinaryExpressionBuilder
{
 
    private:
        // holds either (, +, -, /, or *
        std::stack<char> operatorStack;
 
        // operandStack is made up of BinaryOperationNodes and NumericElementNode
        std::stack<ExpressionElementNode *> operandStack;
 
        void processOperator(char op);
        void processRightParenthesis();
 
        void doBinary(char op);
 
        int precedence(char op);
 
    public:
 
        class NotWellFormed: public std::exception
        {
 
            public:
                virtual const char* what() const throw ()
                {
                    return "The expression is not valid";
                }
        };
 
        BinaryOperationNode *parse(std::string& istr) throw (NotWellFormed);
};
int BinaryExpressionBuilder::precedence(char op)
{
    enum
    {
        lowest, mid, highest
    };
 
    switch (op)
    {
 
        case '+':
        case '-':
            return mid;
 
        case '/':
        case '*':
        case '^':
            return highest;
 
        default:
            return lowest;
    }
}
 
// Input: +, -, /, or *
// creates BinaryOperationNode's from all preceding
BinaryOperationNode *BinaryExpressionBuilder::parse(std::string& str)
        throw (NotWellFormed)
{
    istringstream istr(str);
    char token;
 
    while (istr >> token)
    {
 
        switch (token)
        {
 
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                processOperator(token);
                break;
 
            case ')':
                processRightParenthesis();
                break;
 
            case '(':
                operatorStack.push(token);
                break;
 
            default:
                // If it is not an operator, it must be a number.
                // Since token is only a char in width, we put it back,
                // and get the complete number as a double.
                istr.putback(token);
                double number;
 
                istr >> number;
 
                NumericElementNode *newNode = new NumericElementNode(number);
                operandStack.push(newNode);
 
                continue;
        } // end switch
    } // end while
 
    while (!operatorStack.empty())
    {
 
        doBinary(operatorStack.top());
        operatorStack.pop();
    }
 
    // Invariant: At this point the operandStack should have only one element
    //     operandStack.size() == 1
    // otherwise, the expression is not well formed.
    if (operandStack.size() != 1)
    {
 
        throw NotWellFormed();
    }
 
    ExpressionElementNode *p = operandStack.top();
 
    return static_cast<BinaryOperationNode *> (p);
}
 
void BinaryExpressionBuilder::processOperator(char op)
{
    // pop operators with higher precedence and create their BinaryOperationNode
    int opPrecedence = precedence(op);
 
    while ((!operatorStack.empty()) && (opPrecedence <= precedence(
            operatorStack.top())))
    {
 
        doBinary(operatorStack.top());
        operatorStack.pop();
    }
 
    // lastly push the operator passed onto the operatorStack
    operatorStack.push(op);
}
 
void BinaryExpressionBuilder::processRightParenthesis()
{
    while (!operatorStack.empty() && operatorStack.top() != '(')
    {
 
        doBinary(operatorStack.top());
        operatorStack.pop();
    }
 
    operatorStack.pop(); // remove '('
}
 
// Creates a BinaryOperationNode from the top two operands on operandStack
// These top two operands are removed (poped), and the new BinaryOperation
// takes their place on the top of the stack.
void BinaryExpressionBuilder::doBinary(char op)
{
    ExpressionElementNode *right = operandStack.top();
 
    operandStack.pop();
 
    ExpressionElementNode *left = operandStack.top();
 
    operandStack.pop();
 
    BinaryOperationNode *p = new BinaryOperationNode(operatorStack.top(), left,
            right);
 
    operandStack.push(p);
}
int main(int argc, char** argv)
{
 
    clock_t tStart = clock();

    string expression;
    cout << "Please Insert an Expression : ( You can Add [sin,cos,sqrt,tan] functions but pass to it just only Numbers ) : " << endl;
    cout << "Example : 1.2 + sin(5.6) + cos(1 + 2) + sqrt((1 + 4) + 4)" << endl;
    cout << "After reading Instruction , Insert Now : " << endl;
    // getline(cin , expression);
    expression = "5.5 + 12 * sin(5) + 2.2^4";
    expression.erase(remove_if(expression.begin(), expression.end(), ::isspace), expression.end());
    smatch m;
    bool result = regex_search(expression,m,regex("(sin|cos|sqrt|tan).{1,10}.[)]"));
    string tempString = expression;
    if(result == 1) {
        while(regex_search(tempString,m,regex("(sin|cos|sqrt|tan).{1,10}.[)]"))) {
            string d = m[0];
            if(d.find("sin") != string::npos) {
                d.erase(d.length() - 1);
                d.erase(0,d.find('(') + 1);
                smatch checkOp;
                bool checkOperation = regex_search(d,checkOp,regex("[/*^+-]+"));
                double temp;
                if(checkOperation == 1) {
                    BinaryExpressionBuilder tempOperation;
                    BinaryOperationNode *root = tempOperation.parse(d);
                    temp = root->value();
                    temp = sinTrigometric(temp);
                } else {
                    temp = sinTrigometric(atof(d.c_str()));
                }
                expression.replace(expression.find(m[0]),m.length(0),std::to_string(temp));
            }
            else if(d.find("cos") != string::npos) {
                d.erase(d.length() - 1);
                d.erase(0,d.find('(') + 1);
                smatch checkOp;
                bool checkOperation = regex_search(d,checkOp,regex("[/*^+-]+"));
                double temp;
                if(checkOperation == 1) {
                 BinaryExpressionBuilder tempOperation;
                 BinaryOperationNode *root = tempOperation.parse(d);
                 temp = root->value();
                 temp = cosTrigometric(temp);

                } else {
                 temp = cosTrigometric(atof(d.c_str()));
                }
                expression.replace(expression.find(m[0]),m.length(0),std::to_string(temp));
                
            }
            else if(d.find("tan") != string::npos) {
                d.erase(d.length() - 1);
                d.erase(0,d.find('(') + 1);
                smatch checkOp;
                bool checkOperation = regex_search(d,checkOp,regex("[/*^+-]+"));
                double temp;
                if(checkOperation == 1) {
                 BinaryExpressionBuilder tempOperation;
                 BinaryOperationNode *root = tempOperation.parse(d);
                 temp = root->value();
                 temp = tanTrigometric(temp);
                 
                } else {
                 temp = tanTrigometric(atof(d.c_str()));
                }
                expression.replace(expression.find(m[0]),m.length(0),std::to_string(temp));
                
            }
            else if(d.find("sqrt") != string::npos) {
                d.erase(d.length() - 1);
                d.erase(0,d.find('(') + 1);
                smatch checkOp;
                bool checkOperation = regex_search(d,checkOp,regex("[/*^+-]+"));
                double temp;
                if(checkOperation == 1) {
                 BinaryExpressionBuilder tempOperation;
                 BinaryOperationNode *root = tempOperation.parse(d);
                 temp = root->value();
                 temp = sqrtFunction(temp);
                 
                } else {
                 temp = sqrtFunction(atof(d.c_str()));
                }
                expression.replace(expression.find(m[0]),m.length(0),std::to_string(temp));
                
            }
            tempString = m.suffix().str();
        }

    }


    cout << "Wait for Conversion of trigrometric functions and sqrt function ..." << endl;
    cout << endl;
    cout << expression << endl;
    cout << endl;
    cout << "***********************************************" << endl;
    BinaryExpressionBuilder b;
    BinaryOperationNode *operationResult = b.parse(expression);
    cout << endl;
    cout << "Result = " << operationResult->value()  << endl;   








    cout << "Execution Time Of The Program: " << endl;
    cout << ((double)(clock() - tStart)/CLOCKS_PER_SEC) * 1000 << "ms" << endl;
    return 0;
}