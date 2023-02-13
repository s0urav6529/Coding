#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=2e5+5;
const int MaxN=21;

vector<int>adj[limit];

int level[limit];
int LCA[limit][MaxN+5];



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

int main(){
    fast;

    int n,q;
    cin>>n>>q;

    for(int i=1;i<n;i++){

        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    memset(LCA,-1,sizeof(LCA));

    for(int i=1;i<=MaxN;i++) {

        for(int j=1;j<=n;j++) {

            if(LCA[j][i-1]!=-1) {

                int p=LCA[j][i-1];
                LCA[j][i]=LCA[p][i-1];
            }
        }
    }

    while(q--){

        int a,b,k;
        cin>>a>>b>>k;

        int lca=get_lca(a,b);

        int a_level=level[a];

        int b_level=level[b];

        int lca_level=level[lca];

        int dis=a_level-lca_level;

        if(dis>=k){   ///kth node at path a to lca

            int msb=(int)log2(k);

            int node=a;

            for(int i=msb;i>=0;i--){

                if((k&(1<<i)))
                    node=LCA[node][i];

            }
            cout<<node<<endl;

        }
        else{  ///kth node at  path  b to before lca


            dis=(b_level-lca_level)-(k-dis);


            int msb=(int)log2(dis);

            int node=b;

            for(int i=msb;i>=0;i--){

                if((dis&(1<<i)))
                    node=LCA[node][i];

            }
            cout<<node<<endl;

        }


    }
    return 0;
}
