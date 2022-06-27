#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef unsigned long long int llu;

constexpr ll mod=1e9+7;
const int limit=2e5+5;

int  subsize[limit];
vector<int>adj[limit];

void dfs(int node,int parent) {
    subsize[node]=1;

    for(int child:adj[node])
    {
        if(child!=parent)
        {
            dfs(child,node);
            subsize[node]+=subsize[child];
        }
    }
}


int main(){
    fast;
    int n;
    cin>>n;
    memset(subsize,0,sizeof subsize);
    for(int i=2;i<=n;i++) {
        int x;
        cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    dfs(1,0);

    for(int i=1;i<=n;i++) cout<<subsize[i]-1<<" ";
    cout<<endl;

    return 0;
}




