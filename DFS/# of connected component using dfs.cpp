
///DFS er maddhome Graph er number of connected component ber kora
///complexity O(v*(v+e))

#include<bits/stdc++.h>
using namespace std;

void dfs(int s,vector<int>adj[],bool vis[])
{
   vis[s]=true;
   for(int i=0;i<adj[s].size();i++)
   {
       int c=adj[s][i];
       if(!vis[c])
       {
          dfs(c,adj,vis);
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
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i,adj,vis);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
