///single source shortest path of a tree using BFS

#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001]={false};
int d[1001];

void bfs(int node,int dis)
{
    queue<int> q;
    q.push(node);
    d[node]=dis;
    vis[node]=true;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(int child:adj[cur])
        {
            if(!vis[child])
            {
                d[child]=d[cur]+1;
                q.push(child);
                vis[child]=true;
            }
        }
    }

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
    bfs(1,0);
    for(int i=1;i<=n;i++) cout<<d[i]<<" ";
    return 0;
}
