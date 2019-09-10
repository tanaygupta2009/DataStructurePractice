#include<bits/stdc++.h>
using namespace std;
int cycles(bool **a , int v , bool *visited)
{
    int count = 0;
    for(int i=0 ; i<v ; i++)
    {
        vector<int>temp;
        for(int j=0 ; j<v ; j++)
        {
            if(a[i][j] == true)
                temp.push_back(j);
        }
        for(int j=0 ; j<temp.size();j++)
        {
            for(int k=j+1;k<temp.size();k++)
            {
                if(a[temp[j]][temp[k]] == true)
                    count++;
            }
        }
    }
    return count/3;
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
    return cycles(data , n , visited);
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