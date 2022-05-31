#include<bits/stdc++.h>
#include<math.h>
using namespace std;
vector<int>adj[100005];
bool vis[100005]={false};
int in[100005];///When you enter in a node.
int low[100005];///Lowest time needed to enter a particuler node by its anchester/parent
int timer;
void dfs(int node,int par)
{
    vis[node]=true;
    in[node]=low[node]=timer++;///At first enter and lowest time decler as enter time
    for(int child:adj[node])
    {
        if(child==par) continue;
        else if(vis[child])
        {
            ///back edge
            ///update kore nicchi anchester er in time er maddhome
            low[node]=min(in[child],low[node]);
        }
        else
        {
            ///forword  edge
            dfs(child,node);

            ///dfs call hower por child low time er maddhome node er low time update kore
            low[node]=min(low[node],low[child]);

            ///johkon dekbe node er in time child er low time theke besi tokhon seta bridge hbe.
            if(low[child]>in[node])
            {
                cout<<node<<"-"<<child<<" is a bridge\n";
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n,e;
        cin>>n>>e;
        for(int i=1;i<=e;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[v].push_back(u),adj[u].push_back(v);
        }
        dfs(1,-1);

    }
    return 0;
}
