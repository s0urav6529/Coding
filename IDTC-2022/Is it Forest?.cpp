

#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Fin freopen ("in.txt","r",stdin);
#define Fout freopen ("out1.txt","w",stdout);
typedef long long int ll;
constexpr ll MOD=1000000007;
const int limit=2e5+5;


vector<int>adj[limit];
vector<int>vis(limit);
bool ok=true;

void dfs(int node,int par){

    vis[node]=true;

    for(int ch:adj[node]){

        if(vis[ch]==true && ch!=par){
            ok=false;
            return;
        }
        else if(vis[ch]==false) dfs(ch,node);

    }
    return;

}

int main(){
    fast;
    int tc=1;
    //cin>>tc;
    while(tc--){

        int n,m;
        cin>>n>>m;

        map<pair<int,int>,int>mp;

        for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;

            if(x>y) swap(x,y);

            if((mp.find({x,y})!=mp.end()) || (x==y)) continue;

            adj[x].push_back(y);
            adj[y].push_back(x);

            mp[{x,y}]++;
        }

        ok=true;
        for(int i=1;i<=n;i++){

            if(vis[i]==false){
                dfs(i,-1);
            }
        }

        if(ok) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;


    }

    return 0;
}

