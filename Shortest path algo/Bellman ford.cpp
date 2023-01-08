
/// https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html

#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=2505;

struct edges{
    int src,des;
    ll w;
};

int main(){
    fast;
    int n,m;
    cin >> n >> m;

    vector<edges> adj(m);
    vector<int> Parent(n+1,-1);
    vector<ll> dis(n+1,1e15);

    for(int i=0;i<m;i++){

        int a, b;
        ll  c;
        cin >> a >> b >> c;
        adj[i].src = a;
        adj[i].des = b;
        adj[i].w = c;

    }

    dis[1] = 0;
    int neg_node = -1;

    for(int i=1;i<=n;i++){

        neg_node = -1;

        for(int j=0;j<m;j++){

            int src = adj[j].src;
            int des = adj[j].des;
            ll w = adj[j].w;

            if(dis[src] + w < dis[des]){

                neg_node = des;
                dis[des] = dis[src] + w;
                Parent[des] = src;
            }
        }
    }
    
    
    
    
    if(neg_node == -1){  /// since updated node is not found during n'th or n-1,n-2... iteration. so no negative cycle is found
        cout<< "NO"<<endl;
    }
    else{   ///negative cycle found & print any negative cycle 
        
        for(int i = 1 ; i <= n; i++){
            neg_node = Parent[neg_node];
        }

        vector<int>cycle;

        for(int i = neg_node ;; i = Parent[i] ){

            cycle.push_back(i);

            if(i == neg_node && cycle.size() > 1) break;

        }

        reverse(cycle.begin(),cycle.end());
        cout<<"YES"<<endl;
        for(int i = 0; i < cycle.size(); i++){
            cout<< cycle[i] <<" ";
        }
        cout<<endl;

    }
    return 0;
}

