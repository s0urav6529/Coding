#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=2e5+5;
const int MaxN=21;

vector<int>adj[limit];
int in[limit],out[limit];

ll val[limit],tr[8*limit],ft[2*limit];
int level[limit];
int LCA[limit][MaxN+5];

int timer=1;

void Euler_tour(int node,int par,int l){


    level[node]=l;
    LCA[node][0]=par;

    in[node]=timer;
    ft[timer]=val[node];
    timer++;

    for(int ch:adj[node])
        if(ch!=par) Euler_tour(ch,node,l+1);

    out[node]=timer;
    ft[timer]=-val[node];
    timer++;
}

int get_lca(int a,int b)
{
    if(level[a]>level[b]) swap(a,b);
    int d=level[b]-level[a];
    while(d>0){

        int i=log2(d);
        b=LCA[b][i];
        d-=(1<<i);
    }
    if(a==b) return a;

    for(int i=MaxN;i>-1;i--) {

        if(LCA[a][i]!=-1 && (LCA[a][i]!=LCA[b][i])) {

            a=LCA[a][i],b=LCA[b][i];
        }
    }
    return LCA[a][0];
}


void built_tree(int node,int s,int e){

    if(s==e) {
        tr[node]=ft[s];
        return;
    }

    int mid=(s+e)/2;

    built_tree(2*node,s,mid);
    built_tree(2*node+1,mid+1,e);
    tr[node]=tr[2*node]+tr[2*node+1];
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

    tr[node]=tr[2*node]+tr[2*node+1];

}

ll Subtree_sum(int node,int s,int e,int l,int r){

    if(e<l || s>r)
        return 0;

    if(s>=l && e<=r)
        return tr[node];

    int mid=(s+e)/2;

    ll Left=Subtree_sum(2*node,s,mid,l,r);
    ll Right=Subtree_sum(2*node+1,mid+1,e,l,r);

    return Left+Right;
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
    memset(LCA,-1,sizeof(LCA));
    Euler_tour(1,-1,0);

    for(int i=1;i<=MaxN;i++) {

        for(int j=1;j<=n;j++) {

            if(LCA[j][i-1]!=-1) {

                int p=LCA[j][i-1];
                LCA[j][i]=LCA[p][i-1];
            }
        }
    }


    built_tree(1,1,2*n);

    while(q--){

        int t;
        cin>>t;

        if(t==1){

            int node,Val;
            cin>>node>>Val;

            int inIdx=in[node];
            int outIdx=out[node];

            val[node]=Val;

            update(1,1,2*n,inIdx,Val);
            update(1,1,2*n,outIdx,-Val);

        }
        else{

            int a,b;
            cin>>a>>b;
            int inA=in[a];
            int inB=in[b];
            int inRoot=in[1];

            int lca=get_lca(a,b);

            ll root_to_lca=0,lcaVal=0;

            if(lca!=-1){

                int inLca=in[lca];

                root_to_lca=Subtree_sum(1,1,2*n,inRoot,inLca);

                lcaVal=val[lca];
            }



            ll root_to_a = Subtree_sum(1,1,2*n,inRoot,inA);
            ll root_to_b = Subtree_sum(1,1,2*n,inRoot,inB);


            ll ans=root_to_a + root_to_b-(2*root_to_lca)+lcaVal;

            cout<<ans<<endl;


//            cout<<Subtree_sum(1,1,2*n,inRoot,inA)<<endl;
//            cout<<Subtree_sum(1,1,2*n,inRoot,inB)<<endl;
//            cout<<Subtree_sum(1,1,2*n,inRoot,inLca)<<endl;

        }
    }
    return 0;
}




