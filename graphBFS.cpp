#include<bits/stdc++.h>
using namespace std;
void printLevelWise(bool **a, int v,bool *visited)
{
	queue<int>q;
	q.push(0);
	while(!q.empty())
	{
		for(int i=0;i<q.size();i++)
		{
			int front = q.front();
			q.pop();
			if(visited[front]==false)
			{
				visited[front] = true;
				cout<<front<<" ";
			}
			for(int j=0;j<v;j++)
				if(a[front][j] == true)
				{
					if(visited[j]==false)
					{
						q.push(j);
						visited[j] = true;
						cout<<j<<" ";
					}
				}
		}
	}
}
bool hasPath(bool **v , int e ,bool *visited2,int start , int end)
{
	visited2[start] = true;
	for(int i=0;i<e;i++)
	{
		if(v[start][i] == true)
		{
			if(i == end)
				return true;
			if(visited2[i]==false)
			{
				if(!hasPath(v,e,visited2,i,end))
					continue;
				return true;
			}
		}
	}
	return false;
}
void printPath(bool **a , int v , bool *visited, int start , int end)
{
	//cout<<start<<" "<<end<<endl;
	if(!hasPath(a,v,visited,start,end))
		return;
	unordered_map<int,int>map;
	queue<int>q;
	int flag = 0;
	q.push(start);
	while(!q.empty())
	{
		int front = q.front();
		q.pop();
		for(int i=0;i<v;i++)
		{
			if(a[front][i] == true && visited[i]==false)
			{
				flag++;
				map[i] = front;
				q.push(i);
				visited[i] = true;
				if(i==end)
					break;
			}
		}
	}
	if(flag==0)
		return;
	/*
	unordered_map<int,int>::iterator it = map.begin();
	while(it!=map.end())
	{
		cout<<it->first<<" "<<it->second<<endl;
		it++;
	}
	*/
	int i=end;
	cout<<end<<" ";
	while(map[i]!=start)
	{
		cout<<map[i]<<" ";
		i = map[i];
	}
	cout<<start<<" ";
	return;
}
int main(int argc, char const *argv[])
{
	int v,e;
	cin>>v>>e;
	bool **data = new bool*[v];
	for(int i=0;i<v;i++)
	{
		data[i] = new bool[v];
		for(int j=0;j<v;j++)
			data[i][j] = false;
	}
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		data[a][b] = true;
		data[b][a] = true;
	}
	int p,q;
	cin>>p>>q;
	bool *visited = new bool[v]();
	//printLevelWise(data,v,visited);
	printPath(data,v,visited,p,q);
	return 0;
}