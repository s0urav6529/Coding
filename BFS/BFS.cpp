
///BFS er maddhome 0 1 2 print kora
///complexity O(v+e)
#include<bits/stdc++.h>
using namespace std;

void bfs(int srt,vector<int>adj[],bool vis[])
{
    queue<int>q;
    q.push(srt);
    vis[srt]=true;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        cout<<cur<<" ";
        for(int child:adj[cur])
        {
            if(vis[child]==false)
            {
                q.push(child);
                vis[child]=true;
            }
        }
    }
}
int main()
{
    int n,e;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int>adj[100];
    bool vis[100]={false};
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        //adj[y].push_back(x);
    }
    bfs(1,adj,vis);
    return 0;
}
