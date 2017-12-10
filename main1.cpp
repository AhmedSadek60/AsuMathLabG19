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

string insert(string s, int index, string insertS)
{
  return s.substr(0, index) + insertS + s.substr(index, s.length());
}


string insertInAllString(string line, string func[] ={0}, int size = 0, string beforeAndAfter = "()+-*/", string delima2 = ".")
{
  for (int i = 0; i < size; i++)
  {
    if (line.find(func[i]) != string::npos)
    {
      int index = line.find(func[i]);
      int index1 = line.find("(", index);
      int index2 = line.find(")", index);
      line[index1] = '[';
      line[index2] = ']';
    }
  }

  for (int i = 0; i < line.length(); i++)
  {
    char ch = line[i];
    if (beforeAndAfter.find(ch) != string::npos)
    {
      if (i > 0 && line[i - 1] != ' ')
      {
        if (line[i - 1] == '.'){
          if(line[i-2] != ' '){
            line = insert(line, i - 1, " ");
            i++;
          } 
        }else{
          line = insert(line, i, " ");
          
        }
          
      }
      if (i < line.length() && line[i + 1] != ' ')
      {
        line = insert(line, i + 1, " ");
        i++;
      }
    }
  }
  return line;
}

vector<string> split2(string line, string delim = " ", string delimAl = ".", string delimA2 = "()+-*/")
{
  string word = "";
  vector<string> words;
  for (int i = 0; i < line.length(); i++){
    char ch = line[i];
    if (delimAl.find(ch) != string::npos)
    {
      if (delim.find(line[i + 1]) != string::npos)
      {
        i++;
        if (word.length())
        {
          words.push_back(word);
          word = "";
        }
      }
      else
        word.push_back(ch);
    }
    else if (delim.find(ch) == string::npos)
      word.push_back(ch);
    else
      if (word.length())
      {
        words.push_back(word);
        word = "";
      }
  }
  if (word.length())
    words.push_back(word);
  return words;
}

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

int main(){

  string a = "(1.2 + sin(3.4) - sqrt(5.6))./(2.1*3.2 + cos(4.6)) - 12.1.*3.1 + (1.2 + 5.2)^(4/(3.2+5.6))";
  string func[] = {"sqrt","sin","cos","tan"};

  a = insertInAllString(a, func, 4);
  vector<string> res = split(a, "()");
  
  vector<vector<string>> ress;
  for(string text: res){
    cout << text << endl;
    ress.push_back(split(text));
  }
  for(vector<string> re: ress){
    for (string text : re)
    {
      cout << text << " , ";
    }
    cout << endl;
  }
  // for (string text : res2)
  // {
  //   cout << text << endl;
  // }
}