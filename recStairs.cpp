#include<bits/stdc++.h>
using namespace std;
int staircase(int n)
{
	//cout<<n<<" ";
	if(n>=3)
	{
		int num = staircase(n-1);
		num = num + staircase(n-2);
		num = num + staircase(n-3);
		//cout<<num<<" ";
		return num;
	}
	else
	{
		if(n==1)
			return 1;
		else
		{
			if(n==2)
			{
				int num = staircase(n-1);
				num = num + staircase(n-2);
				//cout<<num<<" ";
				return num;
			}
			else
				return 1;
		}
	}
}
int main() 
{
    int n, output;
    cin >> n;
    output=staircase(n);
    //cout<<endl;
    cout<< output <<endl;
}
