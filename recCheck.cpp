#include<bits/stdc++.h>
using namespace std;
bool stepTwo(char*);
bool stepThree(char *input)
{
	if(input[0]=='\0' || input[0]=='a')
	{
		if(input[0]=='\0')
			return true;
		else
			return stepTwo(input+1);
	}
	return false;
}
bool stepTwo(char *input)
{
	if(input[0]=='\0' || (input[0]=='a') || (input[0]=='b' && input[1]=='b'))
	{
		if(input[0]=='\0' || (input[0]=='a'))
		{
			if(input[0]=='\0')
				return true;
			else
				return stepTwo(input+1);
		}
		else
			return stepThree(input+2);
	}
	return false;
}
bool checkAB(char *input) 
{
    if(*(input+0)=='a')
    	return stepTwo(input+1);
    else
    	return false;
}
int main(int argc, char const *argv[])
{
	char input[1000];
	scanf("%s",&input);
	cout<<checkAB(input)<<endl;
	return 0;
}