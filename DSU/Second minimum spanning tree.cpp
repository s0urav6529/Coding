#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define pb push_back
const int limit=200001;

vector<int>Parent(limit,-1);
vector<int>Rank(limit,1);
vector<int>mst_edge;   /// for storing mst edges

int cost , edges;

void init(int n){       /// initialize parents

    for(int i=0;i<=n;i++) 
        Parent[i] = -1;

}

int Find(int node){

    if(Parent[node] < 0) return node;

    return Parent[node] = Find(Parent[node]);

}

void Union(int u, int v, int w, int ith, int flag){

    u = Find(u);

    v = Find(v);

    if(u != v){

        if(Rank[v] > Rank[u]) swap(u,v);

        Parent[v] = u;
        
        Rank[u] += Rank[v];

        cost += w;

        if(flag){       /// apply during mst_cost
            mst_edge.push_back(ith);
        }
        else{   /// apply during second mst_cost
            edges++;
        }
    }

}

void solution(){

    int n , e;
    cin >> n >> e;

    vector<pair<int,pair<int,int>>>tree(e);

    for(int i=0;i<e;i++){
       
       cin >> tree[i].second.first >> tree[i].second.second >> tree[i].first;
    }

    sort(tree.begin(),tree.end());

    cost = 0;

    for(int i=0;i<e;i++){

        /// sending i & 1 because we need to identify mst edges
        Union(tree[i].second.first, tree[i].second.second, tree[i].first, i , 1);
    
    }

    int mst_cost = cost , s_mst_cost = 1e8;


    for(int j=0;j<mst_edge.size();j++){

        init(n); cost = 0 , edges = 0;

        for(int i=0;i<e;i++){

            if(i != mst_edge[j]){ 

                Union(tree[i].second.first, tree[i].second.second, tree[i].first, i , 0);
            
            }
        
        }

        if(edges == n-1){

            s_mst_cost = min(s_mst_cost , cost);

        }

    }

    cout << mst_cost <<" "<<s_mst_cost<<endl;


    return;
}
int main(){

    fast; 
    solution();
    return 0;
}
