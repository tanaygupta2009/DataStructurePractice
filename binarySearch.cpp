#include<bits/stdc++.h>
using namespace std;
int binarySearch(int input[], int size, int element)
{
	if(size<=0)
		return -1;
	int mid = (size-1)/2;
	if(input[mid]<element)
	{
		int small = binarySearch( input+mid+1 , size - (mid+1) , element);
		if(small == -1)
			return -1;
		return mid + small + 1;
	}
	else
		if(input[mid]>element)
		{
			int small = binarySearch(input , mid ,element);
			if(small == -1)
				return -1;
			return small;
		}
		else
			return mid;
}
int main(int argc, char const *argv[])
{
	int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
        cin >> input[i];
	cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
	return 0;
}