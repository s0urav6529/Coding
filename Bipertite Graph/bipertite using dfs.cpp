

///Time complexity O(v*(v+e))

#include<bits/stdc++.h>
using namespace std;
int col[100];
bool dfs(int node,int c,vector<int>adj[],bool vis[])
{
   vis[node]=1;
   col[node]=c;
   for(int child:adj[node])
   {
       if(!vis[child])
       {
           if(dfs(child,c^1,adj,vis)==false)
            return false;
       }
       else
        if(col[node]==col[child]) return false;
   }
   return true;
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
    if(dfs(1,1,adj,vis)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

