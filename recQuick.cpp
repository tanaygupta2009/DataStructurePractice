#include<bits/stdc++.h>
#include<sys/time.h>
using namespace std;
long getTimeinMicroSeconds()
{
	struct timeval start;
	gettimeofday(&start,NULL);
	return start.tv_sec*1000000+start.tv_usec;
}
long partition(long *a, long si , long ei)
{
	long pivot = a[si] , count = 0;
	for(long i=(si+1);i<(ei+1);i++)
		if(a[i]<=pivot)
			count++;
	long left =si , right=ei;
	long temp = a[si+count];
	a[si+count] = a[si];
	a[si] = temp;
	while(left<(si+count))
	{
		if(a[left]>pivot)
		{
			if(a[right]<=pivot)
			{
				temp = a[right];
				a[right] = a[left];
				a[left] = temp;
				left++;
				right--;
			}
			else
				right--;
		}
		else
			left++;
	}
	return si+count;
}
void quickSortIndex(long *a,long si, long ei)
{
	if(si>=ei)
		return;
	long c = partition(a,si,ei);
	quickSortIndex(a,si,c-1);
	quickSortIndex(a,c+1,ei);
}
void quickSort(long *a,long size)
{
	quickSortIndex(a,0,size-1);
}
int main(int argc, char const *argv[])
{
	/*long a[] = {7,5,4,6,2};
	quickSort(a,5);
	for(long i=0;i<5;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	*/
	for(long n=10;n<=1000000;n=n*10)
	{
		long *arr = new long[n];
		long startTime , endTime;
		for(long i=0;i<n;i++)
			arr[i] = n-i;
		startTime = getTimeinMicroSeconds();
		quickSort(arr,n);
		//sort(arr , arr+n);
		endTime = getTimeinMicroSeconds();
		cout<<"Sort n = "<<n<<" time = "<<(float)(endTime-startTime)/(float)1000000<<" sec"<<endl;
	}
	return 0;
}