#include <iostream>
using namespace std;
#include<unordered_map>
void intersection(int input1[], int input2[], int size1, int size2)
{
    unordered_map<int,bool>map;
    for(int i=0;i<size1;i++)
    	map[input1[i]] = true;
  	for(int i=0;i<size2;i++)
  	{
  		if(map.count(input2[i])>0)
  			cout<<input2[i]<<endl;
  	}
  	return;
}
void PairSum(int *input, int n) 
{	 
	unordered_map<int,int>map;
    for(int i=0;i<n;i++)
    {
    	if(map.count(input[i])>0)
    		map[input[i]]++;
    	else
    		map[input[i]]=1;
    }
    for(int i=0;i<n;i++)
    {
    	if(map.count(0-input[i])>0)
    	{
    		for(int j=0;j<(map[input[i]]*map[0-input[i]]);j++)
    			cout<<min(input[i],0-input[i])<<" "<<max(input[i],0-input[i])<<endl;
    		map[input[i]]=0;
    		map[0-input[i]] = 0;
    	}
    }
    return;
}
int main() {

	int size1,size2;

	cin>>size1;
	int *input1=new int[1+size1];	
	
	for(int i=0;i<size1;i++)
		cin>>input1[i];
	PairSum(input1,size1);
	//cin>>size2;
	//int *input2=new int[1+size2];	
	
	//for(int i=0;i<size2;i++)
	//	cin>>input2[i];
	
	
	//intersection(input1,input2,size1,size2);

		
	return 0;}