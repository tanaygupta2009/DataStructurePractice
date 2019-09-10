#include<bits/stdc++.h>
using namespace std;
int getLastIndex(int *a,int size , int n)
{
	if(size==1)
	{
		if(*(a+0)==n)
			return 0;
		else
			return -1;
	}

	//cout<<"size= "<<size<<" "<<*(a+size-1)<<endl;
	if(*(a+size-1)==n)
		return (size-1);
	int ans = getLastIndex((a) , size-1 , n);
	if(ans==-1)
		return -1;
	return ans;
}
int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,3,2,5,6,6,5};
	cout<<getLastIndex(a,9,6)<<endl;
	return 0;
}