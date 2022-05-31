
///DFS use kore in(discover) and out(finishing) time ber kora;
///Time complexity O(v+e)


#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10001];
bool vis[10001]={false};
int in[10001],out[10001];
int t=1;
bool dfs(int node)
{
    vis[node]=true;
    in[node]=t++;
    for(int child:adj[node])
    {
        if(!vis[child]) dfs(child);
    }
    out[node]=t++;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,e;
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i=1;i<=n;i++) cout<<in[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++) cout<<out[i]<<" ";
    return 0;
}

