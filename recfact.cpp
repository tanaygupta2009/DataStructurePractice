#include<bits/stdc++.h>
using namespace std;
int facto(int n)
{
	if(n==1)
		return 1;
	else
		return (n*facto(n-1));
}
int power(int x, int n) 
{
    if(n==1) //base case
        return x;
    if(n==0)
    	return 1;
    return x*power(x,(n-1));
}
void print(int n)
{
	if(n==1)
	{
		cout<<n<<" ";
		return;
	}
	print(n-1);
	cout<<n<<" ";
}
int count(int n)
{
	if(n/10==0)
		return 1;
	return 1+count(n/10);
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<facto(n)<<endl;
	print(6);
	cout<<endl<<count(124002)<<endl;
	return 0;
}