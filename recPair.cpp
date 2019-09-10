#include<bits/stdc++.h>
using namespace std;
void getString(char *input, char *c)
{
	if(*(input+0)=='\0')
	{
		*(c+0)='\0';
		return;
	}
	if(input[0]==input[1])
	{
		c[0]=input[0];
		c[1]='*';
		getString(input+1,c+2);
	}
	else
	{	
		*(c+0)=*(input+0);
		getString(input+1,c+1);
	}
}
void pairStar(char *input)
{
	int size = sizeof(input)/sizeof(input[0]);
	char *c = new char[size];
	getString(input,c);
	for(int i=0;i<size;i++)
		input[i]='\0';
	int i=0;
	while(c[i]!='\0')
	{
		*(input+i)=*(c+i);
		i++;
	}
	*(input+i)='\0';
}
int main(int argc, char const *argv[])
{
	char input[100];
   	cin.getline(input, 100);
   	pairStar(input);
   	cout << input << endl;
}