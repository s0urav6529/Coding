

#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e5+5;

vector<int>adj[limit];   ///for main graph
vector<int>transpose[limit];   ///for transpose graph
vector<int>condense[limit];   /// for condense graph
vector<int>out;
vector<bool>vis(limit,false);
vector<int>con_group(limit);   ///condense graph group

int c;

void dfs_out(int node){         ///out time calculation

    vis[node]=true;

    for(int ch:adj[node]){

        if(vis[ch]==false)
            dfs_out(ch);
    }
    out.push_back(node);
}

void dfs(int node){     ///Transepose graph dfs

    vis[node]=true;

    for(int ch:transpose[node]){

        if(vis[ch]==false)
            dfs(ch);
    }
    con_group[node]=c;
}

int main(){
    fast;
    int n,e;
    cin >> n >> e;

    for(int i=1;i<=e;i++){
        int x,y;

        cin >> x >> y;

        if(x==y) continue;

        adj[x].push_back(y);

        transpose[y].push_back(x);
    }

    for(int i=1;i<=n;i++){

        if(vis[i]==false)
            dfs_out(i);
    }

    for(int i=1;i<=n;i++)
        vis[i]=false;

    c=1;
    for(int i=1;i<=n;i++){

        if(vis[out[n-i]]==false){

            dfs(out[n-i]);
            c++;
        }
    }

    map<pair<int,int>,bool>mp;

    for(int i=1;i<=n;i++){       ///Making condense graph

        for(int ch:adj[i]){

            int par=i,child=ch;

            if(par<child) swap(par,child);

            if(con_group[par]!=con_group[child] && mp.find({par,child})==mp.end()) {

                condense[con_group[i]].push_back(con_group[ch]);

                mp[{par,child}]=true;

            }
        }
    }
    
   
   return 0;
}







