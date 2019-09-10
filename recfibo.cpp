#include<bits/stdc++.h>
using namespace std;
int fibo(int n)
{
	if(n==1 || n==2)
		return 1;
	if(n==0)
		return 0;
	int res = fibo(n-1)%10+fibo(n-2)%10;
	//cout<<res<<" ";
	return res;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		unsigned long long int a[2] = {0,1};
		if(n==0 || n==1)
		{
			if(n==0)
				cout<<"0"<<endl;
			else
				cout<<"1"<<endl;
			return 0;
		}
		cout<<"0 1 ";
		unsigned long long temp = 0;
		unsigned long long k = 1;
		for(long long i=2;i<=n;i++)
		{
			temp = (a[0]  + a[1]);
			a[0] = a[1];
			a[1] = temp;
			if(i == pow(2,k))
			{
				cout<<"i = "<<i<<" "<<temp % 10<<endl;
				k++;
			}
		}
		cout<<endl;
		cout<<temp<<endl;
	}
	return 0;
}