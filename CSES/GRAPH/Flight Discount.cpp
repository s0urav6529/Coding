#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define pb push_back
const int limit=100005;

vector<pair<int,int>>adj1[limit],adj2[limit];
vector<ll>dis1(limit,1e17),dis2(limit,1e17);
vector<bool>vis(limit);
int n,e;

void dij1(){

    for(int i=1;i<=n;i++) vis[i]=false;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;

    dis1[1]=0;
    pq.push({0,1});
    while(!pq.empty())
    {
        ll weight=pq.top().ff;
        int node=pq.top().ss;
        pq.pop();

        if(vis[node]) continue;
        vis[node]=1;

        for(pair<int,int>child:adj1[node]){

            if(weight+child.ss<dis1[child.ff]) {
                dis1[child.ff]=weight+child.ss;
                pq.push({dis1[child.ff],child.ff});
            }
        }
    }
}

void dij2(){

    for(int i=1;i<=n;i++) vis[i]=false;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;

    dis2[n]=0;
    pq.push({0,n});
    while(!pq.empty())
    {
        ll weight=pq.top().ff;
        int node=pq.top().ss;
        pq.pop();

        if(vis[node]) continue;
        vis[node]=1;

        for(pair<int,int>child:adj2[node]){

            if(weight+child.ss<dis2[child.ff]) {
                dis2[child.ff]=weight+child.ss;
                pq.push({dis2[child.ff],child.ff});
            }
        }
    }
}

int main()
{
    fast;

    cin>>n>>e;
    vector<tuple<int,int,int>>edges;

    for(int i=1;i<=e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj1[x].pb({y,w});
        adj2[y].pb({x,w});
        edges.pb({x,y,w});
    }

    dij1();
    dij2();


    ll ans=1e17;

    for(auto [x,y,w]:edges){
        ans=min(ans,dis1[x]+dis2[y]+w/2);
    }
    cout<<ans<<endl;


    return 0;
}
