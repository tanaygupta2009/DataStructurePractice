#include<bits/stdc++.h>
using namespace std;
void print(bool **v ,int size, bool *visited , int start)
{
	if(visited[start]==false)
	{
		cout<<start<<" ";
		visited[start] = true;
	}
	for(int i = 0 ; i< size ;i++)
	{
		if(i==start)
			continue;
		if(visited[i] == false)
			print(v,size,visited,i);
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
vector<int>final;
void getPath(bool **v , int e , bool *visited , int start , int end)
{
	visited[start] = true;
    if(start == end)
    {
        final.push_back(end);
        return;
    }
    for(int i=0;i<e;i++)
    {
    	//cout<<i<<endl;
        if(v[start][i] == true)
        {
            bool *visited2 = new bool[e]();
            if(visited[i]==false)
            {
            	if(hasPath(v,e,visited2,i,end))
	           	{
	                final.push_back(start);
	                getPath(v,e,visited,i,end);
	                return;
	            }
	        }
        }
    }
}
vector<int>paths;
vector<int> visit(bool **a, int v, bool *visited , int start)
{
	visited[start] = true;
	paths.push_back(start);
	for(int i=0;i<v;i++)
		if(a[start][i] == true && visited[i]==false)
			visit(a,v,visited,i);
	return paths;
}
vector<vector<int>> components(bool **a , int v, bool *visited)
{
	vector<vector<int>>res;
	vector<int>temp = visit(a,v,visited,0);
	sort(temp.begin(),temp.end());
	res.push_back(temp);
	for(int i=0;i<v;i++)
		if(visited[i] == false)
		{
			paths.clear();
			temp = visit(a,v,visited,i);
			sort(temp.begin(),temp.end());
			res.push_back(temp);
		}
	return res;
}
bool isConnected(bool **a , int v , bool *visited)
{
	visit(a,v,visited,0);
	for(int i=0;i<v;i++)
		if(visited[i]==false)
			return false;
	return true;
}
int main(int argc, char const *argv[])
{
	int v;
	cin>>v;
	int e;
	cin>>e;
	bool **data = new bool*[v]();
	for(int i=0;i<v;i++)
		data[i] = new bool[v]();
	for(int i=0;i<e;i++)
	{
		int temp1,temp2;
		cin>>temp1>>temp2;
		data[temp1][temp2] = true;
		data[temp2][temp1] = true;
	}
	int a,b;
	//cin>>a>>b;
	bool *visited = new bool[v];
	for(int i=0;i<v;i++)
		visited[i] = false;
	std::vector<vector<int>> result = components(data,v,visited);
	for(int i=0;i<result.size();i++)
	{
		for(int j=0;j<result[i].size();j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}