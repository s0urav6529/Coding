

#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10001];
bool vis[10001]={false};
int col[10001];
bool bfs(int node,int c)
{
    queue<int>q;
    col[node]=c;
    q.push(node);
    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        for(int child:adj[current])
        {
            if(col[current]==col[child]) return false;
            if(col[child]==-1)
            {
                col[child]=1-col[current];
                q.push(child);
            }
        }
    }
}
int main()
{
    memset(col,-1,sizeof(col));
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,e,yes=1;
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
        if(col[i]==-1)
        {
            if(bfs(i,1));
            else yes*=0;
        }
    }
    if(yes) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}


