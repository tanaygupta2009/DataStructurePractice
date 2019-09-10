#include<bits/stdc++.h>
using namespace std;
bool findPath(int **a , int size , int x ,int y , int finalX , int finalY)
{
	if(a[x][y] == 1)
		return false;
	if(x == finalX || y == finalY)
	{
		if(x==finalX && y == finalY)
			return true;
		else if(x == finalX)
			return findPath(a,size,x,y+1,finalX,finalY);
		return findPath(a,size,x+1,y,finalX,finalY);
	}
	return findPath(a,size,x+1,y,finalX,finalY) || findPath(a,size,x,y+1,finalX,finalY);
}
bool findWithKey(int **a , int size, int x , int y , int finalX , int finalY , bool key)
{
	//cout<<x<<" "<<y<<" "<<key<<endl;
	if(a[x][y] == 1)
	{
		if(key==true)
		{
			a[x][y] = -1;
			return findWithKey(a,size,x+1,y,finalX,finalY,false) || findWithKey(a,size,x,y+1,finalX,finalY,false);
		}
		//cout<<x<<" "<<y<<endl;
		return false;
	}
	if(x == finalX || y == finalY)
	{
		if(x==finalX && y==finalY)
			return true;
		if(x==finalX)
			return findWithKey(a,size,x,y+1,finalX,finalY,key);
		return findWithKey(a,size,x+1,y,finalX,finalY,key);
	}
	return findWithKey(a,size,x+1,y,finalX,finalY,key) || findWithKey(a,size,x,y+1,finalX,finalY,key);

}
bool findWithKeyValue(int **a , int size, int x , int y , int finalX , int finalY , int *key)
{
	cout<<x<<" "<<y<<" "<<*key<<endl;
	if(a[x][y] == 1)
	{
		if(*(key+0)>0)
		{
			*key = *key - 1;
			return findWithKeyValue(a,size,x+1,y,finalX,finalY,key) || findWithKeyValue(a,size,x,y+1,finalX,finalY,key);
		}
		return false;
	}
	if(x == finalX || y == finalY)
	{
		if(x==finalX && y==finalY)
			return true;
		if(x==finalX)
			return findWithKeyValue(a,size,x,y+1,finalX,finalY,key);
		return findWithKeyValue(a,size,x+1,y,finalX,finalY,key);
	}
	return findWithKeyValue(a,size,x+1,y,finalX,finalY,key) || findWithKeyValue(a,size,x,y+1,finalX,finalY,key);

}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int **a = new int*[n];
	for(int i=0;i<n;i++)
		a[i] = new int[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	int *key;
	int temp = 16;
	key=&temp;
	if(findWithKeyValue(a,n,0,0,n-1,n-1,key))
		cout<<"Path found"<<endl;
	else
		cout<<"Nope, dude"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Key Left: "<<*key<<endl;
	return 0;
}