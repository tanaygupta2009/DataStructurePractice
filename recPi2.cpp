#include<bits/stdc++.h>
using namespace std;
#include<string.h>
void convert(char* d, char* src)
{
	if(!*src) 
	{
		*d = '\0';
		return;
	}
	if(*src == 'p' && *(src + 1) == 'i') 
	{
		*(d++) = '3';*(d++) = '.';*(d++) = '1';*(d++) = '4';
		src += 2;
	} 
	else 
		*(d++) = *(src++);
	convert(d, src);
}
void replacepi(char *input)
{	
	int size = (sizeof(input)/sizeof(input[0]));
	char *d = new char[10000];
	convert(d,input);
	for(int i=0;i<size;i++)
		input[i]='\0';
	int i=0;
	while(d[i]!='\0')
	{
		input[i]=d[i];
		i++;
	}
	input[i]='\0';
}
int main()
{
	char input[] = "xpipipixpisip";
	//char input[] = "xpix";
	replacepi(input);
	cout<<input<<endl;
}