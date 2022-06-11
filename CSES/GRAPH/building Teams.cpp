
///Time complexity O(v*(v+e))

#include<bits/stdc++.h>
using namespace std;

const int limit=100005;

int col[limit];
bool vis[limit]={false};
vector<int>adj[limit];
bool dfs(int node,int c) {

   vis[node]=true;
   col[node]=c;

   for(int child:adj[node]){
       if(!vis[child]){
           if(dfs(child,c^1)==false)
            return false;
       }
       else
        if(col[node]==col[child]) return false;
   }
   return true;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,e;
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,1)==false) {
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<col[i]+1<<" ";
    cout<<endl;

    return 0;
}


