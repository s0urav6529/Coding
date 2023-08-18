#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define pb push_back
const int limit=200001;


vector<int>parent(limit,-1);

int find(int a){

    if(parent[a]<0) return a;

    return parent[a]=find(parent[a]);
}

void Union(int a,int b){

    a=find(a);
    b=find(b);

    if(a!=b){

        parent[a]+=parent[b];  ///adding all child of b to a;
        parent[b]=a;   ///refenecing parent as a;
    }
}

void solution(){

    int n,m;
    cin>>n>>m;

    while(m--){
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }

    ll ans=1;
    for(int i=1;i<=n;i++){
        cout<<parent[i]<<" ";

        if(parent[i]<0){
            ans=(ans*abs(parent[i]))%MOD;
        }
    }

    //cout<<ans<<endl;
    return;
}
int main()
{
    fast;
    solution();
    return 0;
}


