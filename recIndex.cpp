#include<bits/stdc++.h>
using namespace std;
int getIndex(int *a , int size , int n)
{
	if(size==1)
	{
		if(*(a+0)==n)
			return 0;
		else
			return -1;
	}
	if(*(a+0)==n)
		return 0;
	int ans = getIndex(a+1 , size-1 , n);
	if(ans==-1)
		return -1;
	return 1+ans;
}
int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,3,2,5,6,5};
	cout<<getIndex(a,8,5)<<endl;
	return 0;
}