#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main()
{
    fast;
    int n,e;
    cin>>n>>e;

    vector<pair<int,ll>>adj[n+1];

    vector<ll>dis(n+1,1e18),vis(n+1,0);

    for(int i=1;i<=e;i++)
    {
        int x,y;
        ll w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
    }

    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;

    dis[1]=0;
    pq.push({0,1});
    while(!pq.empty())
    {
        ll weight=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        if(vis[node]) continue;
        vis[node]=1;

        for(pair<ll,int>child:adj[node]){

            if(weight+child.second<dis[child.first]) {

                dis[child.first]=weight+child.second;
                pq.push({dis[child.first],child.first});
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
    cout<<endl;
    return 0;
}





