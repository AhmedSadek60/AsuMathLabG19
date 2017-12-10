// #include <iostream>
// #include <string>
// #include <vector>
// #include <cstring>
// #include <sstream>
// #include <algorithm>
// #include <iterator>
// #include <time.h>
// #include <cmath>
// using namespace std;

// /*
// [ function name] : split
// [ return type] : vector of type string
// [ inherited function/operation ] : -find() string implemented function
//                                    -push_back() string implemented function
//                                    -length() string implemented function

// [ functionality ] : takes a line of string and split it by a seperator delim, and return a vector of each part of the string,
//                     the deafult separator is space, you can separator by anything you want, just ", " this separates by , and space

// [ example ]   string a = "ahmad, amr ebeid,,ahmad , a";
//               vector<string> res = split(a, ", ");
//             return  {"ahmad","amr","ebeid","ahmad","a"} as vector
// */

// vector<string> split(string line, string delim = " ", string delimAl = ".")
// {
//   string word = "";
//   vector<string> words;
//   for (int i = 0; i < line.length(); i++){
//     char ch = line[i];
//     if (delimAl.find(ch) != string::npos)
//     {
//       if (delim.find(line[i + 1]) != string::npos)
//       {
//         i++;
//         if (word.length())
//         {
//           words.push_back(word);
//           word = "";
//         }
//       }
//       else
//         word.push_back(ch);
//     }
//     else if (delim.find(ch) == string::npos)
//       word.push_back(ch);
//     else
//       if (word.length())
//       {
//         words.push_back(word);
//         word = "";
//       }
//   }
//   if (word.length())
//     words.push_back(word);
//   return words;
// }

// int main(){

//   string a = "1*2*3.2.*4";
//   vector<string> res = split(a, "*");

//   for(string text: res){
//     cout << text << endl;
//   }

// }

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <time.h>
#include <cmath>
using namespace std;

/*
[ function name] : split
[ return type] : vector of type string
[ inherited function/operation ] : -find() string implemented function
                                   -push_back() string implemented function
                                   -length() string implemented function

[ functionality ] : takes a line of string and split it by a seperator delim, and return a vector of each part of the string,
                    the deafult separator is space, you can separator by anything you want, just ", " this separates by , and space

[ example ]   string a = "ahmad, amr ebeid,,ahmad , a";
              vector<string> res = split(a, ", ");
            return  {"ahmad","amr","ebeid","ahmad","a"} as vector
*/

vector<string> split(string line, string delim = " ")
{
  string word = "";
  vector<string> words;
  for (char ch : line)
    if (delim.find(ch) == string::npos)
      word.push_back(ch);
    else if (word.length())
    {
      words.push_back(word);
      word = "";
    }
  if (word.length())
    words.push_back(word);
  return words;
}

int main()
{

  string a = "ahmad, amr ebeid,,ahmad , a";
  vector<string> res = split(a, ", ");

  for (string text : res)
  {
    cout << text << endl;
  }
}
