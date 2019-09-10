#include<bits/stdc++.h>
using namespace std;
void printSubs(string input , string output)
{
	if(input.size()==0)
	{
		cout<<output<<endl;
		return;
	}
	printSubs(input.substr(1) , output);
	printSubs(input.substr(1) , output+input[0]);
}
void generateAllSub(string s)
{
	printSubs(s,"");
}
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	generateAllSub(s);
	return 0;
}