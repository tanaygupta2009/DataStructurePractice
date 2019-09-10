#include<bits/stdc++.h>
using namespace std;
int subset(int input[], int n, int output[][20])
{
	for(int i=0 ; i< size ;i++) // fill current element 
		output[size+i][1] = input[0];
	for(int i=0 ; i< size ; i++)
	{
		for(int j=0;j<20;j++)
			output[i][j] = 
	}
}
int main(int argc, char const *argv[])
{
	int input[20],length, output[35000][20];
	cin >> length;
	for(int i=0; i < length; i++)
		cin >> input[i];
	int size = subset(input, length, output);
	for( int i = 0; i < size; i++)
	{ 
		for( int j = 1; j <= output[i][0]; j++)
			cout << output[i][j] << " ";
		cout << endl;
	}
	return 0;
}