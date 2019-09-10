#include<bits/stdc++.h>
using namespace std;
int allIndexes(int input[], int size, int x, int output[]) 
{
	if(size==1)
	{
        if(*(input+0)==x)
            return 0;
        else
            return -1;
    }
   	if(*(input+0)==x)
    {

        int ans = allIndexes(input+1 , size-1 , x , output+1);
        //cout<<ans<<endl;
        if(ans==-1)
        {
            *(output+0)=-1;
            return -1;
        }
        *(output+0)=1+ans;
        return 1+ans;
    }
   	int ans = allIndexes(input+1 , size-1 , x , output);
    if(ans==-1)
    {
        *(output+0)=-1;
        return -1;
    }
    return 1 + ans;
}
int main(int argc, char const *argv[])
{
	int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++)
        cin >> input[i];
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    //cout<<size<<endl;
    for(int i = 0; i < size; i++) 
        cout << output[i] << " ";
    
}
