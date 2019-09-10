#include<bits/stdc++.h>
using namespace std;
void FindTriplet(int arr[], int size, int x) 
{
int left, right; 
sort(arr, arr + size); 
for (int i = 0; i < size - 2; i++) 
{ 
        left = i + 1; 
        right = size - 1; // index of the last element 
        while (left < right) 
        { 
            if (arr[i] + arr[left] + arr[right] == x) 
            { 
                printf("%d %d %d\n", arr[i], 
                       arr[left], arr[right]);  
                left++;
                right--;
            } 
            else if (arr[i] + arr[left] + arr[right] < x) 
                left++; 
            else // arr[i] + arr[left] + arr[right] > sum 
                right--; 
        } 
    } 
return;
}
int main(int argc, char const *argv[])
{
    int size;
    int x;
    cin>>size;
    int *input=new int[1+size]; 
    for(int i=0;i<size;i++)
        cin>>input[i];
    cin>>x;
    FindTriplet(input,size,x);
    return 0;
}