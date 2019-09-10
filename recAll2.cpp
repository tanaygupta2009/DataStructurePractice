#include<bits/stdc++.h>
using namespace std;
int getSizeOutput(int *a , int size , int n , int *output, int &finalSize , int i)
{
	if(size==1)
	{
		if(*(a+size-1)==n)
		{
			*(output+finalSize)=i;
			finalSize++;
			return 1;
		}
		return 0;
	}
	if(*(a+size-1)==n)
	{
		*(output+finalSize)=i;
		finalSize++;
		i++;
		return 1 + getSizeOutput(a , size-1 , n , output,finalSize,i);
	}
	i++;
	return getSizeOutput(a,size-1,n,output,finalSize,i);
}
void getOutput(int *a, int size , int n , int *output , int &finalSize , int i)
{
	if(i==size)
		return;
	if(*(a+i)==n)
	{
		*(output+finalSize)=i;
		finalSize++;
	}
	i++;
	getOutput(a,size,n,output,finalSize,i);
}
int allIndexes(int *input, int size ,int x ,int *output)
{
	int index=0;
	getOutput(input,size,x,output,index,0);
	return index;
}
int main(int argc, char const *argv[])
{
	int a[] = {3,4,5,1,2,4,2,2};
	int *output = new int[8];
	int size = allIndexes(a, size , 2 ,output);
	cout<<"size = "<<size<<endl;
	for(int i=0;i<size;i++)
		cout<<*(output+i)<<" ";
	cout<<endl;
	return 0;
}