#include<bits/stdc++.h>
using namespace std;
int getLength(string *subs)
{
	int i=0;
	while(subs[i]!="\0")
		++i;
	return i;
}
void subString(string s, string *subs)
{
	if(s.empty())
	{
		*(subs+0) = " ";
		return;
	}
	string smallString = s.substr(1);
	subString(smallString,subs);
	int limit = getLength(subs);
	cout<<limit<<endl;
	for(int i=0;i<limit;i++)
		subs[i+limit] = s[0] + subs[i];
}
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	int size = pow(2,s.size());
	string *subs = new string[size];
	subString(s,subs);
	for(int i=0;i<size;i++)
		cout<<subs[i]<<" ";
	cout<<endl;
	return 0;
}