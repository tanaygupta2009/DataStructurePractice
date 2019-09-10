#include<bits/stdc++.h>
using namespace std;
bool isSorted(int *a , int size)
{
	if(size==1 || size==0)
		return true;
	cout<<"size= "<<size<<*(a+0)<<" "<<*(a+1)<<endl;
	if(*(a+0)<=*(a+1))
		if(isSorted((a+1),size-1))
			return true;
	return false;
}
int getSum(int *a, int size)
{
	if(size==1)
		return *(a+0);
	int sum = *(a+0) + getSum((a+1),size-1);
	return sum;
}
bool isPresent(int *a , int size , int n)
{
	if(size==1)
	{
		if(*(a+0)==n)
			return true;
		else
			return false;
	}
	if(*(a+0)==n)
		return true;
	else
		return isPresent((a+1),size-1,n);
}
int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,5,4,10};
	cout<<isPresent(a,6,2)<<endl;
	return 0;
}