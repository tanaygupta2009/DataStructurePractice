#include <iostream>
using namespace std;
#include <stack>
#include<string.h>
char getOpposite(char x)
{
	if(x=='(')
		return ')';
	else if(x=='{')
		return '}';
	else if(x=='[')
		return ']';
	else
		return '\0';
}
bool checkBalanced(char *exp) 
{
	int size = strlen(exp);
	stack<char>s;
	for(int i=0;i<size;i++)
	{
		//cout<<exp[i]<<endl;
		if(exp[i] == '(' || exp[i]=='{' || exp[i]=='[')
		{
			s.push(exp[i]);
			//cout<<s.top()<<" "<<i<<endl;
		}
		else if(exp[i] == ')' || exp[i]=='}' || exp[i]==']')
		{	
			if(s.size()!=0 && getOpposite(s.top())==exp[i])
				s.pop();
			else
				return false;
		}
		else
			continue;
	}
	if(s.size()==0)
		return true;
	return false;
}
int main() 
{
    char input[100000];
    cin.getline(input, 100000);
    if(checkBalanced(input))
        cout << "true" << endl;
    else 
        cout << "false" << endl;
}