#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e5+5;


vector<ll>adj[limit];
ll a[limit];
set<ll>s;
ll mex=0;

void dfs(int node,int par){

    bool nichi=false;

    if(s.count(a[node])>0){
        s.erase(a[node]);
        nichi=true;
    }

    mex=max(mex,*s.begin());

    for(int ch:adj[node]){

        if(ch!=par) dfs(ch,node);

    }

    if(nichi) s.insert(a[node]);

}


int main(){
    fast;

    ll n; cin >> n;

    for(int i=1; i<=n ;i++) cin >> a[i];

    for(int i=0;i<=n;i++) s.insert(i);

    for(int i=1;i<n;i++){

        ll u,v; cin >> u >>v;

        adj[u].push_back(v); adj[v].push_back(u);

    }

    dfs(1,-1);

    cout<<mex<<endl;


    return 0;
}



