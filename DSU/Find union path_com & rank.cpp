#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define pb push_back
const int limit=200001;

vector<int>Parent(limit,-1);
vector<int>Rank(limit,1); ///Rank means size of this conected componemt

int Find(int node){

    if(Parent[node] < 0) return node;

    return Parent[node] = Find(Parent[node]);

}

void Union(int u, int v, int w){

    u = Find(u);

    v = Find(v);

    if(u != v){

        if(Rank[v] > Rank[u]) swap(u,v);

        Parent[v] = u;
        
        Rank[u] += Rank[v];

        cost += w;
    }

}

void solution(){

    int n,m;
    cin >> n >> m;
//    vector<pair<int,pair<int,int>>>tree(n-1);
//
//    for(int i=0;i<n-1;i++){
//        int a,b,w;
//        cin>>tree[i].ss.ff>>tree[i].ss.ss>>tree[i].ff;
//    }
//    sort(tree.begin(),tree.end());
//
//    for(int i=0;i<n-1;i++){
//
//        Union(tree[i].ss.ff,tree[i].ss.ss,tree[i].ff);
//    }
    while(m--){
        int a,b;
        cin >> a >> b;
        Union(a,b);
    }

    return;
}
int main()
{
    fast; 
    solution();
    return 0;
}


