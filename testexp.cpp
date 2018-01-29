#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cctype>
#include <iterator>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <regex>
using namespace std;










class Exp{
public:
//  Exp(){}
    virtual string print(){}
    virtual void release(){}
    virtual string valueData(){}
    virtual double value(){}
};
class Term: public Exp {
    string val;
public:
    Term(string v):val(v){}
    string print(){
        string te = val;
        return te;
    }
    double value() {
        double result = atof(val.c_str());

        return result;
    }
    string valueData() {
        return val;
    }
    void release(){}
};

class Node: public Exp{
    Exp *l_exp;
    Exp *r_exp;
    char op; // +, -, *, /,^ ==> [ .^ , .+ , ./ ] ==> Element Wise Operators // Convert op to string to valid the +. , .^ , ./
public:
    Node(char op, Exp* left, Exp* right):op(op),l_exp(left), r_exp(right){}
    ~Node(){
    }
    string print(){
        string l_expValue = l_exp->print();
        string r_expValue = r_exp->print();
        if(l_expValue == "Wrong" || r_expValue == "Wrong") {
            string errorString = "Expression is Wrong";
            return errorString;
        }
        string operationName = "";
        operationName += op;
        string ta = operationName + " " +  l_exp->print() + " " + r_exp->print();
        return ta;
    }
    void release(){
        l_exp->release();
        r_exp->release();
        delete l_exp;
        delete r_exp;
    }
};

Exp* strToExp(string &str){
    int level = 0;//inside parentheses check
    //case + or -
    //most right '+' or '-' (but not inside '()') search and split
    for(int i=str.size()-1;i>=0;--i){
        char c = str[i];
        if(c == ')'){
            ++level;
            continue;
        }
        if(c == '('){
            --level;
            continue;
        }
        if(level>0) continue;
        if((c == '+' || c == '-' || c == '@' || c == '?') && i!=0 ){//if i==0 then s[0] is sign
            string left(str.substr(0,i));
            string right(str.substr(i+1));
            return new Node(c, strToExp(left), strToExp(right));
        }
    }
    //case * or /
    //most right '*' or '/' (but not inside '()') search and split
    for(int i=str.size()-1;i>=0;--i){
        char c = str[i];
        if(c == ')'){
            ++level;
            continue;
        }
        if(c == '('){
            --level;
            continue;
        }
        if(level>0) continue;
        if(c == '*' || c == '/' || c == '#' || c == '$'){
            string left(str.substr(0,i));
            string right(str.substr(i+1));
            return new Node(c, strToExp(left), strToExp(right));
        }
    }
    // Case ==> ^
    for(int i=str.size()-1;i>=0;--i){
        char c = str[i];
        if(c == ')'){
            ++level;
            continue;
        }
        if(c == '('){
            --level;
            continue;
        }
        if(level>0) continue;
        if(c == '^' || c == '&'){
            string left(str.substr(0,i));
            string right(str.substr(i+1));
            return new Node(c, strToExp(left), strToExp(right));
        }
    }
    if(str[0]=='('){
    //case ()
    //pull out inside and to strToExp
        for(int i=0;i<str.size();++i){
            if(str[i]=='('){
                ++level;
                continue;
            }
            if(str[i]==')'){
                --level;
                if(level==0){
                    string exp(str.substr(1, i-1));
                    return strToExp(exp);
                }
                continue;
            }
        }
    } else
    //case value
        return new Term(str);
// cerr << "Error: Expression is Wrong" << endl;
    return new Term("Wrong");//never
}

