#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
bool isPrime[1000001];
bool isPrime2[1000001];
void generatePrimesFirst()
{
	memset(isPrime,1, sizeof(isPrime));
	isPrime[0] = false; 
	isPrime[1] = false;
	for(long long i=2;i*i<=1000000;i++)
	{
		if(isPrime[i]==true)
		{
			//cout<<i<<" ";
			for(int j=i+i;j<=1000000;j+=i)
				isPrime[j] = false;
		}
	}
}
void generatePrimesSecond()
{
	memset(isPrime2,1, sizeof(isPrime2));
	
}
int main(int argc, char const *argv[])
{
	clock_t start, end; 
	start = clock(); 
	generatePrimesFirst();
	generatePrimesSecond();
	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by program is : " << fixed<< time_taken << setprecision(5); 
    cout << " sec " << endl;
	/*
	for(long long i=0;i<=1000000;i++)
	{
		//cout<<isPrime[i]<<" ";
		if(isPrime[i]==true)
			cout<<i<<" ";
	}
	cout<<endl;
	*/
	return 0;
}