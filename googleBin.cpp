#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b;
		cin>>a>>b;
		long long n;
		cin>>n;
		while(n--)
		{
			long long mid = (a+b)/2;
			long long temp = mid;
			if(mid==a)
				cout<<b<<endl;
			else
				cout<<temp<<endl;
			string s;
			cin>>s;
			if(s=="CORRECT")
				break;
			else if(s=="TOO_SMALL")
				a = mid;
			else if(s=="TOO_BIG")
				b = mid;
			else
			{
				cout<<s<<endl;
				break;
			}
		}
	}
}