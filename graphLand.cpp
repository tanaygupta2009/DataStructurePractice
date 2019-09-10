#include<iostream>
#include<vector>
using namespace std;
void visit(bool **a, int v, bool *visited , int start)
{
    //cout<<start<<endl;
	visited[start] = true;
	for(int i=0;i<v;i++)
		if(a[start][i] == true && visited[i]==false)
			visit(a,v,visited,i);
	return;
}
int components(bool **a , int v, bool *visited)
{
	visit(a,v,visited,0);
    int count = 1;
	for(int i=0;i<v;i++)
    {
        //cout<<i<<endl;
		if(visited[i] == false)
        {
		    visit(a,v,visited,i);
            count++;
        }
    }
	return count;
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
    bool **data = new bool*[n]();
    for(int i=0;i<n;i++)
        data[i] = new bool[n]();
    for(int i=0;i<m;i++)
    {
        data[u[i]-1][v[i]-1] = true;
        data[v[i]-1][u[i]-1] = true;
    }
    bool *visited = new bool[n]();
    return components(data,n,visited);
}
int main()
{
    int n,m;
    vector<int>u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        u.push_back(x);
    }
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<solve(n,m,u,v)<<endl;
}