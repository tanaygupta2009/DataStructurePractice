#include<bits/stdc++.h>
using namespace std;
vector<string>v;
string generateStrings(string a , int n)
{
	//cout<<a.length()<<" "<<a<<endl;
	int length = a.size()-1;
	if(a[length]=='a')
	{
		if(a.size()==n)
			return a;	
		string temp1 = generateStrings(a+"e" , n);
		if(temp1.size()==n)
			v.push_back(temp1);
	}
	else
	{
		if(a[length]=='e')
		{
			if(a.size()==n)
				return a;
			string temp1 = generateStrings(a+"a",n);
			if(temp1.size()==n)
				v.push_back(temp1);
			string temp2 = generateStrings(a+"i",n);
			if(temp2.size()==n)
				v.push_back(temp2);
		}
		else
		{
			if(a[length]=='i')
			{
				if(a.size()==n)
					return a;
				string temp1 = generateStrings(a+"e",n);
				if(temp1.size()==n)
					v.push_back(temp1);
				string temp2 = generateStrings(a+"o" , n);
				if(temp2.size()==n)
					v.push_back(temp2);
				string temp3 = generateStrings(a+"u",n);
				if(temp3.size()==n)
					v.push_back(temp3);
				string temp4 = generateStrings(a+"a",n);
				if(temp4.size()==n)
					v.push_back(temp4);
			}
			else
			{	
				if(a[length]=='o')
				{
					if(a.size()==n)
						return a;
					string temp1 = generateStrings(a+"i",n);
					if(temp1.size()==n)
						v.push_back(temp1);
					string temp2 = generateStrings(a+"u",n);
					if(temp2.size()==n)
						v.push_back(temp2);
				}
				else 
				{
					if(a.size()==n)
						return a;
					string temp1 = generateStrings(a+"a",n);
					if(temp1.size()==n)
						v.push_back(temp1);	
				}
			}
		}
	}
	return a;
}
string getString(char x) 
{ 
    string s(1, x); 
    return s;    
} 
int countPerms(int n)
{	
	if(n==1)
		return 5;
	v.clear();
	string s = "aeiou";
	for(int i=0;i<s.size();i++)
	{
		string temp = generateStrings(getString(s[i]),n);
	}
	/*
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
	*/
	return v.size() % 1000000007;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<countPerms(n)<<endl;
	return 0;
}