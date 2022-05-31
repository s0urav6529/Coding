
///DFS er maddhome 0 1 2 print kora
///complexity O(v+e)
#include<bits/stdc++.h>
using namespace std;
vector<int>v[100];
bool vis[100];
void dfs(int p)
{
    vis[p]=true;
    cout<<p<<" ";
    for(int i=0;i<v[p].size();i++)
    {
        int child=v[p][i];
        if(!vis[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int n,e;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(vis,0,sizeof(vis));
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    return 0;
}
