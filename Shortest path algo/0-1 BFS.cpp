



#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e5+5;

vector<pair<ll,ll>>adj[limit];
ll dis[limit];    ///level 
ll n,m;

void bfs01(ll node){


    for(int i=1;i<=n;i++) dis[i]=1e9;

    deque<ll>dq;
    dq.push_back(node);
    dis[node]=0;

    while(dq.size()>0){

        ll node=dq.front();

        dq.pop_front();

        for(pair<ll,ll> ch:adj[node]){

            if(dis[ch.first] > dis[node] + ch.second){

                dis[ch.first]= dis[node]+ch.second;

                if(ch.second == 1) dq.push_back(ch.first);

                else dq.push_front(ch.first);

            }
        }
    }
}


int main(){
    fast;
    cin>>n>>m;

    for(int i=1;i<=m;i++){

        ll x,y>>w;
        cin>>x>>y>>w;

        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
      

    }
    bfs01(1);

    cout<<dis[n]<<endl;


    return 0;
}


