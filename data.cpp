#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const char * expressionToParse = "5+(1.6+202)+2*4";

char peek()
{
    return *expressionToParse;
}

char get()
{
    return *expressionToParse++;
}

int expression();

int number()
{
    
    int result = get() - '0';
    cout << "Result Inside Number : " << endl;
    cout << result << endl;
    int val = 10;
    while ((peek() >= '0' && peek() <= '9') || (peek() == '.'))
    {
        
        if(peek() == '.') {
            result = result + ((get() - '0') / val);
            val += 10;
            cout << result << endl;
        }
        else {
            cout << "Peek ==> " << peek() << endl;
            result = 10*result + get() - '0';
        }
        cout << "Inside While" << endl;
        cout << result << endl;
    }
    cout << "End Of Number Function : " << endl;
    cout << result << endl;
    return result;
}

int factor()
{
    if (peek() >= '0' && peek() <= '9') {
        return number();
    }
    else if (peek() == '(')
    {
        get(); // '('
        int result = expression();
        get(); // ')'
        return result;
    }
    else if (peek() == '-')
    {
        get();
        return -factor();
    }
    return 0; // error
}

int term()
{
    int result = factor();
    while (peek() == '*' || peek() == '/')
        if (get() == '*')
            result *= factor();
        else
            result /= factor();
    return result;
}

int expression()
{
    int result = term();
    while (peek() == '+' || peek() == '-')
        if (get() == '+')
            result += term();
        else
            result -= term();
    return result;
}

int main()
{

    int result = expression();

    cout << result << endl;

    return 0;
}