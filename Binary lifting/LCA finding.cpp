#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
const int limit=1e5+5;
#define MaxN 17

int n;
vector<int>adj[limit];
int LCA[MaxN+5][limit];
int level[limit];


int get_lca(int a,int b){

    if(level[a] > level[b]) swap(a,b);

    int d = level[b]-level[a];

    while(d > 0){    /// make them equal level first
      
        int j = log2(d);
        b = LCA[j][b];
        d -= (1<<j);
      
    }

    if(a == b) return a; 

    for(int j=MaxN;j>=0;j--){

        if(LCA[j][a] != -1 && (LCA[j][a] != LCA[j][b])){
            a = LCA[j][a];
            b = LCA[j][b];
        }
    }
    return LCA[0][a];

}

void dfs(int node,int par,int l){

    level[node] = l;
    LCA[0][node] = par; /// 2^0 th parent

    for(int ch : adj[node]){

        if(ch != par) {
          dfs(ch,node,l+1);
        }
    }
}

int main(){
    fast;

    cin >> n;

    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(LCA,-1,sizeof LCA);

    dfs(1,-1,0);

    /// LCA filling code
    for(int j=1;j<=MaxN;j++){

        for(int i=1;i<=n;i++){

            if(LCA[j-1][i] == -1) continue;

            int par = LCA[j-1][i];

            LCA[j][i] = LCA[j-1][par];
        }
    }

    int q;
    cin>>q;
    while(q--){

        int u,v;
        cin>>u>>v;
        cout<<get_lca(u,v)<<endl;;

    }
}
