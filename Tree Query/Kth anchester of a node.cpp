#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define MaxN 17
vector<int>g[100005];
int level[100005];
int LCA[100005][MaxN+5];

void dfs(int node,int p,int l){

    level[node]=l;
    LCA[node][0]=p;

    for(int child:g[node]){

        if(child!=p){

            dfs(child,node,l+1);
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n;
        for(int i=1;i<n;i++) {
            int u,v;
            cin>>u>>v;
            g[v].push_back(u);
            g[u].push_back(v);
        }

        memset(LCA,-1,sizeof(LCA));

        dfs(1,-1,0);

        for(int i=1;i<=MaxN;i++) {

            for(int j=1;j<=n;j++){

                if(LCA[j][i-1]!=-1){

                    int p=LCA[j][i-1];

                    LCA[j][i]=LCA[p][i-1];
                }
            }
        }

        cin>>q;
        while(q--) {

            int node,k;
            cin>>node>>k;

            int msb=31-__builtin_clz(k);

            for(int i=msb;i>=0;i--){

                if((k&(1<<i))){

                    node=LCA[node][i];

                }

            }
            cout<<node<<endl;


        }
    }
    return 0;
}


