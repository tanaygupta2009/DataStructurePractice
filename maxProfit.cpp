#include<bits/stdc++.h>
using namespace std;
int getMaxProfit(int *a , int size)
{
	int small = INT_MAX ;
	int big = -1;
	bool found = false;
	int profit= 0;
	int final = 0;
	for(int i=0;i<size;i++)
	{
		//cout<<big<<" "<<small<<endl;
		if(found == false && a[i+1]>a[i])
		{
			small = a[i];
			big = a[i+1];
			profit = big - small;
			found = true;
		}
		else if(found == true)
		{
			if(a[i]>big)
			{
				big = a[i];
				profit = big - small;
			}
			else if(a[i]<=small)
			{
				small = a[i];
				final = final + profit;
				profit = 0;
				big = a[i];
			}
			//cout<<a[i]<<" "<<big<<" "<<small<<endl;
		}
	}
	final = final + profit;
	return final;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<getMaxProfit(a,n)<<endl;
	return 0;
}