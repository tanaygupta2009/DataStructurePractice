#include<bits/stdc++.h>
#include<sys/time.h>
using namespace std;
long long getTimeinMicroSeconds()
{
	struct timeval start;
	gettimeofday(&start,NULL);
	return start.tv_sec*1000000+start.tv_usec;
}
void mergeArray(long long *a , long long si, long long mid,long long ei)
{
	if(si==mid || mid==ei)
	{
		long long temp = a[si];
		long long temp2 = a[ei];
		a[si] = min(temp,temp2);
		a[ei] = max(temp,temp2);
	}
	else
	{	
		long long k=0;
		long long *temp = new long long[ei-si+1];
		for(long long i=si;i<(ei+1);i++)
		{
			temp[k] = 0;
			k++;
		}
		k=0;
		long long index1 = si , index2 = mid+1 , pivot;
		while(k<(ei-si+1))
		{	
			if(index1>=(mid+1) || index2>=(ei+1))
			{
				if(index1>=(mid+1) && index2>=(ei+1))
					break;
				else
				{
					if(index1>=(mid+1))
					{
						pivot = a[index2];
						index2++;
					}
					else
					{
						pivot = a[index1];
						index1++;
					}
				}
			}
			else
			{
				if(a[index1]<=a[index2])
				{
					if(index1<(mid+1))
					{
						pivot = a[index1];
						index1++;
					}
				}
				else
				{
					if(index2<(ei+1))
					{
						pivot = a[index2];
						index2++;
					}
				}
			}
			temp[k] = pivot;
			k++;
		}
		k=0;
		for(long long i=si;i<(ei+1);i++)
		{
			a[i] = temp[k];
			k++;
		}
	}
}
void mergeSortIndex(long long *a,long long si,long long ei)
{
	if(si>=ei)
		return;
	else
	{
		long long mid = (si+ei)/2;
		mergeSortIndex(a,si,mid);
		mergeSortIndex(a,mid+1,ei);
		mergeArray(a,si,mid,ei);
	}
}
void mergeSort(long long *a , long long size)
{
	mergeSortIndex(a,0,size-1);
}
int main(int argc, char const *argv[])
{
	/*long long a[] = {83,45,12,4,5,64};
	mergeSort(a,6);
	for(long long i=0;i<6;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	*/
	for(long long n=10;n<=1000000;n=n*10)
	{
		long long *arr = new long long[n];
		long long startTime , endTime;
		for(long long i=0;i<n;i++)
			arr[i] = n-i;
		startTime = getTimeinMicroSeconds();
		mergeSort(arr,n);
		endTime = getTimeinMicroSeconds();
		cout<<"Merge Sort n = "<<n<<" time = "<<(float)(endTime-startTime)/(float)1000000<<" sec"<<endl;
	}
	return 0;
}