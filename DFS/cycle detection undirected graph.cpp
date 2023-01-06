
///DFS use kore kono tree te cycle ase kina ta jachai;
///Time complexity O(v+e)


#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10001];
bool vis[10001]={false};
int col[10001];


bool dfs(int node,int par)
{
    vis[node]=true;
    for(int child:adj[node])
    {
        if(!vis[child])
        {
            if(dfs(child,node)==true) return true;
        }
        else if(child!=par) return true; ///find a back edge
    }
    return false;
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
    if(dfs(1,-1)) cout<<"yes"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
