#include <iostream>
#include <string>
#include <cctype>

#include "Stack.h"

using namespace std;

int calc(string str);

int main()
{
	string str;
	cin>>str;

	str += '#';

	int result;

	try{
		result = calc(str);
	}catch(const char *errorMessage)
	{
		cerr<<errorMessage<<endl;
	}

	cout<<result<<endl;

	return 0;
}

int calc(string::iterator left,string::iterator right);
int calc(char oper,int num1,int num2);

inline
int getInt(string::iterator &iter)
{
	int result = 0;
	while(isdigit(*iter))
	{
		result *= 10;
		result += (int)*iter & 0x0f;
		++iter;
	}
	--iter;

	return result;
}

int calc(string str)
{
	return calc(str.begin(),str.end());
}

bool higher(char left,char right)
{
	bool result = false;
	if(left == '*' || left == '/')
		if(right != '*' && right != '/')
		result = true;

	return result;
}

int calc(char oper,int num1,int num2)
{
	int result = 0;

	switch(oper)
	{
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		result = num1 / num2;
		break;
	default:
		throw "ERROR : calc(char,int,int);Bad operator";
	}

	return result;
}

string::iterator findRight(string::iterator iter)
{
	Stack<char> stack;
	stack.push(*iter);

	while(!stack.isEmpty())
	{
		++iter;
		if(*iter == '(')
			stack.push(*iter);
		if(*iter == ')')
			stack.pop();
	}

	return iter;
}

int calc(string::iterator left,string::iterator right)
{
	Stack<int> numStack;
	Stack<char> operStack;

	int num1 = 0,num2 = 0;

	for(string::iterator i = left;i < right;++i)
	{
		if(isdigit(*i))
		{
			numStack.push(getInt(i));
		}
		else if(ispunct(*i))
		{
			if(*i == '(')
			{
				string::iterator right;
				right = findRight(i);
				numStack.push(calc(i+1,right+1));
				i = right;
			}
			else if(operStack.isEmpty() || higher(*i,operStack.getTop()))
				operStack.push(*i);
			else
			{
				num2 = numStack.pop();
				num1 = numStack.pop();

				num1 = calc(operStack.pop(),num1,num2);
				numStack.push(num1);

				--i;
			}
		}
	}
	return numStack.pop();
}
