#include<bits/stdc++.h>
using namespace std;
long long getFinalAns(long long int *a ,long long int size ,long long int teamSize) //not working for repeated elements.
{
	sort(a,a+size);
	long long numberOfZeros = teamSize - 1;
	long long *diff = new long long[size-1];
	for(long long i=0;i<size-1;i++)
		diff[i] = a[i+1] - a[i];
	/*
	for(long long i =0 ; i<size-1;i++)
		cout<<diff[i]<<" ";
	cout<<endl;
	*/
	long long overAllSum = 0 , sum = 0;
	for(long long i=0;i<numberOfZeros;i++)
		sum = sum + diff[i];
	overAllSum = sum;
	for(long long i=0;i<numberOfZeros;i++)
	{
		overAllSum = overAllSum + (sum - diff[i]);
		sum = sum - diff[i];
	}
	return overAllSum;
}
long long getValue(long long *a , long long start , long long end) //slower
{
	long long maxElement = a[end-1];
	long long sum = 0;
	for(long long i = start ; i < end ;i++)
		sum = sum + (maxElement - a[i]);
	return sum;
}
long long getValueFast(long long *a , long long start , long long end , long long *sum) //fast AF
{
	long long maxElement = a[end-1];
	return (maxElement*(end-start)) -(sum[end-1] - (sum[start] - a[start]));
}
long long getAns(long long *a , long long size , long long teamSize) //works for repeated elemets as well.
{
	long long start = 0;
	long long end = teamSize;
	long long minDiff = INT_MAX;
	long long s = 0;
	long long *sum = new long long[size];
	for(long long i=0;i<size;i++)
	{
		s = s + a[i];
		//cout<<s<<endl;
		sum[i] = s;
	}
	while(1)
	{
		long long final = getValueFast(a,start,end,sum);
		//cout<<start<<" "<<end<<" "<<final<<endl;
		if(final<minDiff)
			minDiff = final;
		start++;
		end++;
		if(end>size)
			break; 
	}
	delete [] sum;
	return minDiff;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int count = 1;
	while(t--)
	{
		long long n,p;
		cin>>n>>p;
		long long *a = new long long[n];
		for(long long i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		cout<<"Case #"<<count<<": "<<getAns(a,n,p)<<endl;
		count++;
		delete [] a;
	}
	return 0;
}