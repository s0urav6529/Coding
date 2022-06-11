

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
const int limit=100005;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


vector<int>adj[limit];
bool vis[limit]={false};

void dfs(int node){

    vis[node]=true;

    for(auto ch:adj[node]){

        if(!vis[ch]) dfs(ch);
    }
}
int main(){
    fast;
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>link;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            link.push_back(i);
            dfs(i);
            cnt++;
        }
    }
    if(link.size()>1){
        cout<<cnt-1<<endl;

        for(int i=1;i<(int)link.size();i++){
            cout<<link[i-1]<<" "<<link[i]<<endl;
        }

    }
    else cout<<0<<endl;
    return 0;
}
