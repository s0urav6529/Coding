#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=2e5+5;


vector<int>adj[limit];
int in[limit],out[limit];

ll val[limit],tr[8*limit],ft[2*limit];

int timer=1;

void Euler_tour(int node,int par){

    in[node]=timer;
    ft[timer]=val[node];
    timer++;

    for(int ch:adj[node])
        if(ch!=par) Euler_tour(ch,node);

    out[node]=timer;
    ft[timer]=val[node];
    timer++;
}

void built_tree(int node,int s,int e){

    if(s==e) {
        tr[node]=ft[s];
        return;
    }

    int mid=(s+e)/2;

    built_tree(2*node,s,mid);
    built_tree(2*node+1,mid+1,e);

    tr[node]=max(tr[2*node],tr[2*node+1]);
}

void update(int node,int s,int e,int idx,ll Val){

    if(s==e && s==idx){
        tr[node]=Val;
        ft[s]=Val;
        return;
    }

    int mid=(s+e)/2;

    if(idx<=mid) update(2*node,s,mid,idx,Val);
    else update(2*node+1,mid+1,e,idx,Val);

    tr[node]=max(tr[2*node],tr[2*node+1]);

}

ll Subtree_sum(int node,int s,int e,int l,int r){

    if(e<l || s>r)
        return 0;

    if(s>=l && e<=r)
        return tr[node];

    int mid=(s+e)/2;

    ll Left=Subtree_sum(2*node,s,mid,l,r);
    ll Right=Subtree_sum(2*node+1,mid+1,e,l,r);

    return max(Left,Right);
}


int main(){
    fast;

    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        cin>>val[i];
    }

    for(int i=1;i<n;i++){

        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    Euler_tour(1,-1);
    built_tree(1,1,2*n);

    while(q--){

        int t;
        cin>>t;

        if(t==1){

            int node,Val;
            cin>>node>>Val;

            int inIdx=in[node];
            int outIdx=out[node];

            update(1,1,2*n,inIdx,Val);
            update(1,1,2*n,outIdx,Val);

        }
        else{

            int node;
            cin>>node;

            int inIdx=in[node];
            int outIdx=out[node];

            cout<<Subtree_sum(1,1,2*n,inIdx,outIdx)<<endl;

        }
    }
    return 0;
}

