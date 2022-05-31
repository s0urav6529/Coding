///sssp means single source shortest path(only tree te use hoi)
///DFS er maddhome tree er single source hote prottec node er shortest distance ber kora
///Time complexity O(v+e)

#include<bits/stdc++.h>
using namespace std;
int d[100];
void dfs(int s,int dis,vector<int>adj[],bool vis[])
{
   vis[s]=true;
   for(int i=0;i<adj[s].size();i++)
   {
       int c=adj[s][i];
       if(!vis[c])
       {
          d[c]=d[s]+1;
          dfs(c,d[c],adj,vis);
       }
   }
}
int main()
{
    int n,e,cnt=0;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int>adj[100];
    bool vis[100]={false};
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    dfs(1,d[1],adj,vis);
    for(int i=1;i<=n;i++) cout<<d[i]<<" ";
    return 0;
}
