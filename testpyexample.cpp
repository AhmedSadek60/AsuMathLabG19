#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cctype>
#include <time.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <exception> 
using namespace std;




// #################################################### AST Class #########################################
enum TokenType 
{
   Error,
   Plus,
   Minus,
   Mul,
   Div,
   EndOfText,
   OpenParenthesis,
   ClosedParenthesis,
   Number
};

struct Token 
{
	TokenType	Type;
	double		Value;
	char		Symbol;

	Token():Type(Error), Value(0), Symbol(0)
	{}
};

enum ASTNodeType 
{
   Undefined,
   OperatorPlus,
   OperatorMinus,
   OperatorMul,
   OperatorDiv,
   UnaryMinus,
   NumberValue
};

class ASTNode
{
public:
   ASTNodeType Type;
   double      Value;
   ASTNode*    Left;
   ASTNode*    Right;

   ASTNode()
   {
      Type = Undefined;
      Value = 0;
      Left = NULL;
      Right = NULL;
   }

   ~ASTNode()
   {
      delete Left;
      delete Right;
   }
};



// ############################################# Evaluator ########################################


class Evaluator 
{
   double EvaluateSubtree(ASTNode* ast)
   {
      if(ast == NULL) 
         cout << "Incorrect syntax tree!" << endl;

      if(ast->Type == NumberValue)
         return ast->Value;
      else if(ast->Type == UnaryMinus)
         return -EvaluateSubtree(ast->Left);
      else 
      {
         double v1 = EvaluateSubtree(ast->Left);
         double v2 = EvaluateSubtree(ast->Right);
         switch(ast->Type)
         {
         case OperatorPlus:  return v1 + v2;
         case OperatorMinus: return v1 - v2;
         case OperatorMul:   return v1 * v2;
         case OperatorDiv:   return v1 / v2;
         }
      }

      cout << "Incorrect syntax tree!" << endl;
   }

public:
   double Evaluate(ASTNode* ast)
   {
      if(ast == NULL)
         cout << "Incorrect abstract syntax tree" << endl;

      return EvaluateSubtree(ast);
   }
};


// ################################################# Parser Class ##################################


class Parser
{
   Token m_crtToken;
   const char* m_Text;
   size_t m_Index;

private:

   ASTNode* Expression()
   {
      ASTNode* tnode = Term();
      ASTNode* e1node = Expression1();

      return CreateNode(OperatorPlus, tnode, e1node);
   }

   ASTNode* Expression1()
   {
      ASTNode* tnode;
      ASTNode* e1node;

      switch(m_crtToken.Type)
      {
      case Plus:
         GetNextToken();
         tnode = Term();
         e1node = Expression1();

         return CreateNode(OperatorPlus, e1node, tnode);

      case Minus:
         GetNextToken();
         tnode = Term();
         e1node = Expression1();

         return CreateNode(OperatorMinus, e1node, tnode);
      }

      return CreateNodeNumber(0);
   }

   ASTNode* Term()
   {
      ASTNode* fnode = Factor();
      ASTNode* t1node = Term1();

      return CreateNode(OperatorMul, fnode, t1node);
   }

   ASTNode* Term1()
   {
      ASTNode* fnode;
      ASTNode* t1node;

      switch(m_crtToken.Type)
      {
      case Mul: 
         GetNextToken();
         fnode = Factor();
         t1node = Term1();
         return CreateNode(OperatorMul, t1node, fnode);

      case Div:
         GetNextToken();
         fnode = Factor();
         t1node = Term1();
         return CreateNode(OperatorDiv, t1node, fnode);
      }

      return CreateNodeNumber(1);
   }

   ASTNode* Factor()
   {
      ASTNode* node;
      switch(m_crtToken.Type)
      {
      case OpenParenthesis:
         GetNextToken();
         node = Expression();
         Match(')');
         return node;

      case Minus:
         GetNextToken();
		 node = Factor();
         return CreateUnaryNode(node);

      case Number:
         {
            double value = m_crtToken.Value;
            GetNextToken();
            return CreateNodeNumber(value);
         }

      default:
         {
            std::stringstream sstr; 
            sstr << "Unexpected token '" << m_crtToken.Symbol << "' at position " << m_Index;
            
         }
      }
   }

   ASTNode* CreateNode(ASTNodeType type, ASTNode* left, ASTNode* right)
   {
      ASTNode* node = new ASTNode;
      node->Type = type;
      node->Left = left;
      node->Right = right;

      return node;
   }

   ASTNode* CreateUnaryNode(ASTNode* left)
   {
      ASTNode* node = new ASTNode;
      node->Type = UnaryMinus;
      node->Left = left;
      node->Right = NULL;

      return node;
   }

   ASTNode* CreateNodeNumber(double value)
   {
      ASTNode* node = new ASTNode;
      node->Type = NumberValue;
      node->Value = value;

      return node;
   }

   void Match(char expected)
   {
      if(m_Text[m_Index-1] == expected)
         GetNextToken();
      else
      {
         std::stringstream sstr;
         sstr << "Expected token '" << expected << "' at position " << m_Index;
      }
   }

   void SkipWhitespaces()
   {
      while(isspace(m_Text[m_Index])) m_Index++;
   }

   void GetNextToken()
   {
      SkipWhitespaces();

	  m_crtToken.Value = 0;
	  m_crtToken.Symbol = 0;

      if(m_Text[m_Index] == 0)
      {
         m_crtToken.Type = EndOfText;
         return;
      }

      if(isdigit(m_Text[m_Index]))
      {
         m_crtToken.Type = Number;
		 m_crtToken.Value = GetNumber();
         return;
      }

      m_crtToken.Type = Error;

      switch(m_Text[m_Index])
      {
      case '+': m_crtToken.Type = Plus; break;
      case '-': m_crtToken.Type = Minus; break;
      case '*': m_crtToken.Type = Mul; break;
      case '/': m_crtToken.Type = Div; break;
      case '(': m_crtToken.Type = OpenParenthesis; break;
      case ')': m_crtToken.Type = ClosedParenthesis; break;
      }

      if(m_crtToken.Type != Error)
	  {
         m_crtToken.Symbol = m_Text[m_Index];
         m_Index++;
	  }
      else
      {
         std::stringstream sstr; 
         sstr << "Unexpected token '" << m_Text[m_Index] << "' at position " << m_Index;
      }
   }

   double GetNumber()
   {
      SkipWhitespaces();

      int index = m_Index;
      while(isdigit(m_Text[m_Index])) m_Index++;
      if(m_Text[m_Index] == '.') m_Index++;
      while(isdigit(m_Text[m_Index])) m_Index++;

      if(m_Index - index == 0)
         cout << "Number expected but not found!" << endl;

      char buffer[32] = {0};
      memcpy(buffer, &m_Text[index], m_Index - index);

      return atof(buffer);
   }

public:
   ASTNode* Parse(const char* text)
   {
      m_Text = text;
      m_Index = 0;
      GetNextToken();

      return Expression();
   }
};







/// ########################################## Test Class #######################################
void Test(const char* text)
{
   Parser parser;

      ASTNode* ast = parser.Parse(text);

         Evaluator eval;
         double val = eval.Evaluate(ast);

         std::cout << text << " = " << val << std::endl;
   
      delete ast;
      
}


int main() {

cout << "Hello Parser" << endl;

   Test("1+2+3+4.2");
   Test("1*2*3*4");
   Test("1-2-3-4");
   Test("1/2/3/4");
   Test("1*2+3*4");
   Test("1+2*3+4");
   Test("(1+2)*(3+4)");
   Test("1+(2*3)*(4+5)");
   Test("1+(2*3)/4+5");
   Test("5/(4+3)/2");
   Test("1 + 2.5");
   Test("125");
   Test("-1");
   Test("-1+(-2)");
   Test("-1+(-2.0)");

   cout << "#######################################################" << endl;
   cout << "Result : From ( advexamplefile )" << endl;
   Test("(1.2 + 3.4 - 5.6)/(2.1*3.2 + 4.6) - 12.1*3.1 + (1.2 + 5.2)^(4/(3.2+5.6))");




    return 0;
}