#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef unsigned long long int llu;

constexpr ll mod=1e9+7;
const int limit=2e5+5;
const int MaxN=21;

vector<int>g[limit];
int level[limit];
int LCA[limit][MaxN+5];
int ans[limit];

void dfs(int node,int p,int l)
{
    level[node]=l;
    LCA[node][0]=p;
    for(int child:g[node]) {
        if(child!=p) {
            dfs(child,node,l+1);
        }
    }
}


int get_lca(int a,int b){

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

void dfs_ans(int node,int p){

    for(int ch:g[node]){

        if(ch!=p){

            dfs_ans(ch,node);
            ans[node]+=ans[ch];
        }

    }

}

int main(){
    fast;

    int n,q;
    cin>>n>>q;
    for(int i=1;i<n;i++){

        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    memset(LCA,-1,sizeof(LCA));

    dfs(1,-1,0);

    for(int i=1;i<=MaxN;i++) {

        for(int j=1;j<=n;j++) {

            if(LCA[j][i-1]!=-1) {

                int p=LCA[j][i-1];
                LCA[j][i]=LCA[p][i-1];
            }
        }
    }
    memset(ans,0,sizeof ans);

    while(q--){

        int x,y;
        cin>>x>>y;

        int lca=get_lca(x,y);

        ans[x]++;
        ans[y]++;
        ans[lca]--;

        int lca_parent=LCA[lca][0];

        if(lca_parent!=-1)
            ans[lca_parent]--;

    }

    dfs_ans(1,-1);

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}





