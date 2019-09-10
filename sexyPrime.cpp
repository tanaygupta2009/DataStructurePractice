#include<bits/stdc++.h>
using namespace std;
bool isPrime(long long int n)
{
	if(n==1)
		return false;
	if(n==2)
		return true;
	for(long long i=2;i<=n/2;i=i+2)
		if(n%i==0)
			return false;
	return true;
}
int main(int argc, char const *argv[])
{
	long long n,k;
	cin>>n>>k;
	vector<long long >v;
	unordered_map<long long , bool>map;
	for(long long i=n;i<=k;i++)
	{
		if(isPrime(i))
		{
			v.push_back(i);
			map[i] = true;
		}
	}
	long long int count = 0;
	for(long long int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
		if(map.count(v[i] + 6) > 0)
			count++;
	}
	cout<<endl;
	cout<<count<<endl;
	return 0;	
}