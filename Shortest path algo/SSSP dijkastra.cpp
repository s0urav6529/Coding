

///single source shortest path from a root node using dijkastra algorithm
///Time complexity O(v logv+e) ///logv for sorting the priority queue

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main()
{
    fast;
    int n,e;
    cin>>n>>e;

    vector<pair<int,int>>adj[n+1];

    vector<int>dis(n+1,1e9),vis(n+1,0);

    for(int i=1;i<=e;i++){
        
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    dis[1]=0;
    pq.push({0,1});
    while(!pq.empty()) {
        
        int weight=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        if(vis[node]) continue;
        vis[node]=1;

        for(pair<int,int>child:adj[node]){

            if(weight+child.second<dis[child.first]) { ///(dis of src + adjecent dis src to child) < dis of child stored before

                dis[child.first]=weight+child.second;
                pq.push({dis[child.first],child.first});
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
    cout<<endl;
    return 0;
}

/*

6 9
1 2 4
1 6 2
2 3 5
2 6 1
6 3 8
6 5 10
3 4 6
3 5 3
5 4 5
*/



