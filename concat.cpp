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



// int main() {
//     string n;

//     // test For Concatenation
    
//    // Full Command : g++ test.cpp -o test -w -fpermissive -std=c++0x -std=c++11 -std=gnu++11 
// //   std::ifstream ifs("bigexample2.m");
// //   std::string content( (std::istreambuf_iterator<char>(ifs) ),
// //   (std::istreambuf_iterator<char>()    ) );
//     // cout << "############################################# C Matrix ######################" << endl;
//     // cout << "C = [[B [3.4; 2.1; 3.5+9.1]]\n 1.2^3 3+1.2 15/(2.1+10*sin(0.12))  1.2]" << endl;
//     // cout << "# After Parsing" << endl;
//     // string content = "[1.1 1.2 1.3;[1.4 1.5;1.6 1.7],[1.8;1.9];[2.0 2.1;2.2 2.3],[2.4;2.5]]";
//     string content2 = "[1 2 3 4;[1 2;1 2],[1;2] [3;4];[1 2 3;1 2 3],[1;5];[1 3 5 9]]";

//     for(int i = 0 ;i < content2.size();i++) {
//         if(content2[i] == ']' && content2[i + 1] == ' ') {
//             content2[i + 1] = ',';
//         }
//     }
//     // string content = "[[[1 2 3;2 3 4];6 7 8],[6;7;5]]";
//     // string content2 = "[1 2 3;[[1;1],[1;2]],[1;3];[4 5 6]]";
//     // [[1 2 3;2 3 4];6 7 8],[6;7;5]
//     int rightSquareBrackets = 0;
//     int leftSquareBrackets = 0;
//     // for(int i = 0 ; i < content.length() -1;i++) {
//     //     if(content[i] == '[' && i!=0) {
//     //         for(int j = i + 1;j < i - content.find(']',i);j++) {
//     //             if(content[j] == ']') {
//     //                 break;
//     //             }
//     //             if(content[j] == ';') {
//     //                 content[j] = '%';
//     //             }
                
//     //         }
//     //     } else if(content[i] == ']' && content[i + 1] == ';') {
//     //             content[i + 1] = '%';
//     //     } 

//     // }
//     // cout << "Count % : " << std::count(content.begin(), content.end(),'%') << endl;
//     // cout << "After Conversion : " << endl;
//     // cout << content << endl;

//     // cout << strToExpConcat(content) << endl;

//     ExpConcat* tree = strToExpConcat(content2);
//     content2 = "";content2 += tree->print();
//     // content.erase(0,1);
//     // content.erase(content.length() - 1);
//     // Start the Concatentation

//     // regex re("[;\\n]+");
//     // string tempTest = content;
//     // sregex_token_iterator it(tempTest.begin(), tempTest.end(), re, -1);
//     // sregex_token_iterator reg_end;
//     // for (; it != reg_end; ++it) {
//     //         string tempTokenizing = it->str();
//     //         cout << "After First Tokenizing : " << endl;
//     //         cout << tempTokenizing << endl;
//     //         cout << "######################" << endl;
//     //         if(std::count(tempTokenizing.begin() , tempTokenizing.end() , '[') > 1) {
//     //             regex re2("[,]+");    
//     //             sregex_token_iterator it2(tempTokenizing.begin(), tempTokenizing.end(), re2, -1);
//     //             sregex_token_iterator reg_end2;
//     //             for(;it2 != reg_end2;++it2) {
//     //                 cout << "After Second Regex : " << endl;
//     //                 cout << it2->str() << endl;
//     //                 string secondStringTemp = it2->str();
//     //                 regex re3("[\\[\\]]+");    
//     //                 sregex_token_iterator it3(secondStringTemp.begin(), secondStringTemp.end(), re3, -1);
//     //                 sregex_token_iterator reg_end3;
//     //                 for(;it3 != reg_end3;++it3) {
//     //                     cout << "After Third Regex : " << endl;
//     //                     cout << it3->str() << endl;
//     //                 }
                    
//     //             }

//     //         }

//     // }







//     // cout << "After Regex" << endl;
//     // regex re("[;\\n]+");
//     // sregex_token_iterator it(content.begin(), content.end(), re, -1);
//     // sregex_token_iterator reg_end;
//     // for (; it != reg_end; ++it) {
//     //         cout << it->str() << endl;
//     // }
//     // cout << endl;
//     // cout << "################################## Operation A #############################" << endl;
//     // cout << "A = 5.5 + 12 * sin(0.4) + 2.2^4" << endl;
//     // cout << "# After Parsing" << endl;
//     // string content2 = "5.5 + 12 * sin(0.4) + 2.2^4";
//     // regex re2("[\\s+*^-]+");
//     // sregex_token_iterator it2(content2.begin(), content2.end(), re2, -1);
//     // sregex_token_iterator reg_end2;
//     // for (; it2 != reg_end2; ++it2) {
//     //     cout << it2->str() << endl;
//     // }

//     // cout << "#################################################" << endl;
// // >>>>>>> 11211c72799a4b3f6e5b918f6bce7363362216a1

//     // Make the Concatentation For the Matrix For Columns

//     // vector<string> data;
//     // data.push_back("3");
//     // data.push_back("1");
//     // data.push_back("2");
//     // cout << data.back() << endl;
//     // data.pop_back();
//     // cout << data.back() << endl;
//     // data.pop_back();
//     // cout << data.back() << endl;
//     // data.pop_back();

//                     cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
//                     // string s = "[1 2;1 2],[1;2] [3;4]";
//                     regex re3("[$]+");    
//                     sregex_token_iterator it3(content2.begin(), content2.end(), re3, -1);
//                     sregex_token_iterator reg_end3;
//                     for(;it3 != reg_end3;++it3) {
//                         cout << it3->str() << endl;
//                     }




//     return 0;
// }