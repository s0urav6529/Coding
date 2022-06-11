#include<bits/stdc++.h>
using namespace std;
const int limit=100005;
vector<int>adj[limit];
bool vis[limit]={false};
int parent[limit];

int startv,endv;


bool dfs(int node,int par){

    vis[node]=true;
    parent[node]=par;
    for(int child:adj[node]){

        if(child==par) continue;
        if(!vis[child]){
            if(dfs(child,node)==true)
                return true;
        }
        else{
            startv=child;
            endv=node;
            return true;
        }
    }
    return false;
}

void makepath(){

    vector<int>path;
    int x=endv;
    path.push_back(x);
    while(x!=startv){

        path.push_back(parent[x]);
        x=parent[x];
    }
    path.push_back(endv);
    cout<<path.size()<<endl;
    for(auto i:path) cout<<i<<" ";
    cout<<endl;
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,e;
    cin>>n>>e;

    for(int i=1;i<=e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++) vis[i]=false;


    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,-1)){
                makepath();
                return 0;
            }
        }

    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
