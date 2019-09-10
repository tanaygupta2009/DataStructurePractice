#include<bits/stdc++.h>
using namespace std;
void solveTower(int n,char source , char aux , char des)
{
	if(n==1)
	{
		cout<<source<<" "<<des<<endl;
		return;
	}
	solveTower(n-1, source , des , aux);
	cout<<source<<" "<<des<<endl;
	solveTower(n-1 , aux , des , source);
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	solveTower(n,'a','b','c');
	return 0;
}