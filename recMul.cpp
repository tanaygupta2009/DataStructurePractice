#include<bits/stdc++.h>
using namespace std;
int multiplyNumbers(int m, int n) 
{
	if(n==1)
		return m;
	return m + multiplyNumbers(m,n-1);
}
int main(int argc, char const *argv[])
{
	cout<<multiplyNumbers(3,5)<<endl;
	return 0;
}