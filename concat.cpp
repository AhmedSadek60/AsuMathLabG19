#include <iostream>
#include <regex>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iterator>
#include <vector>
#include <stack>
using namespace std;


/*
   ===================================== Hint =================================================
   To Remember ===> Execute the test.cpp and see the result
   = We Trace in the semicolon at the first or the end of the matrix ==> Keep ==> ;1 2 3 also for single (;)
   = Else ===> Add Col and Push the Result in this place ==> 1;2

 */

class ExpConcat{
public:
//  ExpConcat(){}
    virtual string print(){}
    virtual void release(){}
    virtual string valueData(){}
    virtual double value(){}
};
class TermConcat: public ExpConcat {
    string val;
public:
    TermConcat(string v):val(v){}
    string print(){
        string te = val;
        return te;  
    }
    string valueData() {
        return val;
    }
    void release(){}
};

class NodeConcat: public ExpConcat{
    ExpConcat *l_exp;
    ExpConcat *r_exp;
    char op;
public:
    NodeConcat(char op,ExpConcat* left, ExpConcat* right):op(op),l_exp(left), r_exp(right){}
    ~NodeConcat(){
    }
    string print(){
        string operationName = "";
        string ta;
        if(op == ',') {
        ta = "$" + l_exp->print() + "$" + r_exp->print() + "$";

        } else {
            ta = l_exp->print() + ";" + r_exp->print();
        }
        return ta;  
    }
    void release(){
        l_exp->release();
        r_exp->release();
        delete l_exp;
        delete r_exp;
    }
};




ExpConcat* strToExpConcat(string &str){
    int level = 0;//inside parentheses check
    for(int i=str.size()-1;i>=0;--i){
        char c = str[i];
        if(c == ']'){
            ++level;
            continue;
        }
        if(c == '['){
            --level;
            continue;
        }
        if(level>0) continue;
        if(c == ';'){
            string left(str.substr(0,i));
            string right(str.substr(i+1));
            return new NodeConcat(c,strToExpConcat(left), strToExpConcat(right));
        }
    }

    for(int i=str.size()-1;i>=0;--i){
        char c = str[i];
        if(c == ']'){
            ++level;
            continue;
        }
        if(c == '['){
            --level;
            continue;
        }
        if(level>0) continue;
        if(c == ','){
            string left(str.substr(0,i));
            string right(str.substr(i+1));
            return new NodeConcat(c,strToExpConcat(left), strToExpConcat(right));
        }
    }

    
    
    if(str[0]=='['){
    //case ()
    //pull out inside and to strToExpConcat
        for(int i=0;i<str.size();++i){
            if(str[i]=='['){
                ++level;
                continue;
            }
            if(str[i]==']'){
                --level;
                if(level==0){
                    string exp(str.substr(1, i-1));
                    return strToExpConcat(exp);
                }
                continue;
            }
        }
    } else {
        return new TermConcat(str);
    } 
}

