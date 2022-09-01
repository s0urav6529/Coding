

///steps first e finish time ber korte hbe sob gula node er and tader finishing time onushe e list kore nite hbe.

///tarpor maximum finishing time e abar transpose matrix er upor dfs kore connected component ber korte hbe.


#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e5+5;

vector<int>adj[limit];
vector<int>transpose[limit];
vector<int>out,scc;
vector<bool>vis(limit,false);

void dfs_out(int node){   ///dfs for out time of node

    vis[node]=true;

    for(int ch:adj[node]){


        if(vis[ch]==false)
            dfs_out(ch);

    }

    out.push_back(node);

}

void dfs(int node){   ///dfs for scc 

    vis[node]=true;

    for(int ch:transpose[node]){

        if(vis[ch]==false)
            dfs(ch);

    }

    scc.push_back(node);

}

int main(){
    fast;
    ll n,e;
    cin >> n >> e;

    for(int i=1;i<=e;i++){
        ll x,y;

        cin >> x >> y;

        adj[x].push_back(y);

        transpose[y].push_back(x);
    }

    for(int i=1;i<=n;i++){

        if(vis[i]==false)    ///calculate out time of each node
            dfs_out(i);

    }

    for(int i=1;i<=n;i++)
        vis[i]=false;

    for(int i=1;i<=n;i++){

        scc.clear();

        if(vis[out[n-i]]==false){

            dfs(out[n-i]);

            cout<<"SCC are : ";
            for(auto j:scc) cout<<j<<" ";
            cout<<endl;

        }

    }
    return 0;
}





