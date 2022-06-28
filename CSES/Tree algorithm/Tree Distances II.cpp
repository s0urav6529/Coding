#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef unsigned long long int llu;

constexpr ll mod=1e9+7;
const int limit=2e5+5;

vector<int>adj[limit];
ll subtreenode[limit];
ll subtreeans[limit];
ll ans[limit];
ll n;


void dfs(int src,int par){

    subtreenode[src]=1;
    subtreeans[src]=0;

    for(int ch:adj[src]){

        if(ch!=par){
            dfs(ch,src);

            subtreenode[src]+=subtreenode[ch];

            subtreeans[src]+=subtreeans[ch]+subtreenode[ch];
        }
    }
}

void dfsans(int src,int par,ll par_contb){

    ans[src]=subtreeans[src]+par_contb;

    for(int ch:adj[src]){

        if(ch!=par){

            ll p_contb=(ans[src]-(subtreeans[ch]+subtreenode[ch]));

            p_contb+=(n-subtreenode[ch]);

            dfsans(ch,src,p_contb);
        }

    }

}

int main(){
    fast;

    cin>>n;

    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,-1);
    dfsans(1,-1,0);

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}





