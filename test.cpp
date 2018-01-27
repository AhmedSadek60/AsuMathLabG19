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



int main() {
    // string n;

    // test For Concatenation
    
   // Full Command : g++ test.cpp -o test -w -fpermissive -std=c++0x -std=c++11 -std=gnu++11 
//   std::ifstream ifs("bigexample2.m");
//   std::string content( (std::istreambuf_iterator<char>(ifs) ),
//   (std::istreambuf_iterator<char>()    ) );
    // cout << "############################################# C Matrix ######################" << endl;
    // cout << "C = [[B [3.4; 2.1; 3.5+9.1]]\n 1.2^3 3+1.2 15/(2.1+10*sin(0.12))  1.2]" << endl;
    // cout << "# After Parsing" << endl;
    // // string content = "[1.1 1.2 1.3;[1.4 1.5;1.6 1.7],[1.8;1.9];[2.0 2.1;2.2 2.3],[2.4;2.5]]";
    // // string content = "[1 2 3 4;[1 2;1 2],[1;2] [3;4];[1 2 3;1 2 3],[1;5];[1 3 5 9]]";
    // string content = "1.2 3.5 5.8;[1.2 1.3;1.2 1.3],[1.2;1.5];[1.2;1.2],[1.2;1.2],[1.3;1.3;1.5;1.6]";
    // int rightSquareBrackets = 0;
    // int leftSquareBrackets = 0;
    // for(int i = 0 ; i < content.length() -1;i++) {
    //     if(content[i] == '[' && i!=0) {
    //         for(int j = i + 1;j < i - content.find(']',i);j++) {
    //             if(content[j] == ']') {
    //                 break;
    //             }
    //             if(content[j] == ';') {
    //                 content[j] = '%';
    //             }
                
    //         }
    //     } 

    // }
    // cout << "Count % : " << std::count(content.begin(), content.end(),'%') << endl;
    // cout << "After Conversion : " << endl;
    // cout << content << endl;


    // Start the Concatentation

    // regex re("[;\\n]+");
    // string tempTest = content;
    // sregex_token_iterator it(tempTest.begin(), tempTest.end(), re, -1);
    // sregex_token_iterator reg_end;
    // for (; it != reg_end; ++it) {
    //         string tempTokenizing = it->str();
    //         cout << "After First Tokenizing : " << endl;
    //         cout << tempTokenizing << endl;
    //         cout << "######################" << endl;
    //         if(std::count(tempTokenizing.begin() , tempTokenizing.end() , '[') > 1) {
    //             regex re2("[\\[\\],]+");
    //             sregex_token_iterator it2(tempTokenizing.begin(), tempTokenizing.end(), re2, -1);
    //             sregex_token_iterator reg_end2;
    //             for(;it2 != reg_end2;++it2) {
    //                 cout << "After Second Regex : " << endl;
    //                 cout << it2->str() << endl;
    //             }

    //         }

    // }







    // cout << "After Regex" << endl;
    // regex re("[;\\n]+");
    // sregex_token_iterator it(content.begin(), content.end(), re, -1);
    // sregex_token_iterator reg_end;
    // for (; it != reg_end; ++it) {
    //         cout << it->str() << endl;
    // }
    // cout << endl;
    // cout << "################################## Operation A #############################" << endl;
    // cout << "A = 5.5 + 12 * sin(0.4) + 2.2^4" << endl;
    // cout << "# After Parsing" << endl;
    // string content2 = "5.5 + 12 * sin(0.4) + 2.2^4";
    // regex re2("[\\s+*^-]+");
    // sregex_token_iterator it2(content2.begin(), content2.end(), re2, -1);
    // sregex_token_iterator reg_end2;
    // for (; it2 != reg_end2; ++it2) {
    //     cout << it2->str() << endl;
    // }

    // cout << "#################################################" << endl;
// >>>>>>> 11211c72799a4b3f6e5b918f6bce7363362216a1

    // Make the Concatentation For the Matrix For Columns

    // vector<string> data;
    // data.push_back("3");
    // data.push_back("1");
    // data.push_back("2");
    // cout << data.back() << endl;
    // data.pop_back();
    // cout << data.back() << endl;
    // data.pop_back();
    // cout << data.back() << endl;
    // data.pop_back();
    // string expression = "( 2.5 * (1.2 + 4.4 / (2.4 + 3.3)) + 12 * sin(0.4) + 2.2^4 / (M.^3 + M.^2 - 5) ).^(-1.4 + 5)";
    string expression = "((C*D .+ 4)./2.1 + sqrt(D))./C.^2";
    smatch m;
    string tempString = expression;
    string secondTempString = expression;
    bool result = regex_search(tempString,m,regex("[A-Za-z]+"));
    if(result == 1) {
        while(regex_search(secondTempString,m,regex("[A-Za-z]+"))) {
            string d = m[0];
            if(d == "sin" || d == "cos" || d == "log" || d == "ln" || d == "sqrt" || d == "tan") {
                secondTempString = m.suffix().str();
                continue;
            } else {
                expression.replace(expression.find(m[0]),m.length(0),"Shorbagy");
                secondTempString = m.suffix().str();
            }
        }
    }


    cout << "After Conversion" << endl;
    cout << expression << endl;


                    // expression.replace(expression.find(m[0]),m.length(0),tempForAdditionPar);
                    // expression.replace(expression.find(m[0]),m.length(0),std::to_string(tempResult));




    return 0;
}