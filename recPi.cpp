#include<bits/stdc++.h>
using namespace std;
#define pi 3.14
string s;
void replacePi(char input[]) 
{
    if(*(input+0)=='\0')
    {
    	char p[strlen(input)];
    	strcpy(p,s.c_str());
    	input = p;
    	cout<<input<<endl;
        return;
    }
    if(*(input+0)=='p' && *(input+1)=='i')
    {
       	s = s + "3.14";
        replacePi(input+1);
    }
    else
    {
    	if(*(input+0)=='i' && *(input-1)=='p')
    		replacePi(input+1);
    	else
    	{
    		s = s + *(input+0);
    		replacePi(input+1);
    	}
    }
}
int main(int argc, char const *argv[])
{
	char s[] = "xpix";
	//replacePi(s);
	cout<<s<<endl;
	return 0;
}
