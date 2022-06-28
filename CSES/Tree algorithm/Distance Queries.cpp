#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define MaxN 17
const int limit=2e5+5;

vector<int>g[limit];
int level[limit];
int LCA[limit][MaxN+5];

void dfs(int node,int p,int l)
{
    level[node]=l;
    LCA[node][0]=p;
    for(int child:g[node])
    {
        if(child!=p)
        {
            dfs(child,node,l+1);
        }
    }
}


int get_lca(int a,int b)
{
    if(level[a]>level[b]) swap(a,b);
    int d=level[b]-level[a];
    while(d>0)
    {
        int i=log2(d);
        b=LCA[b][i];
        d-=(1<<i);
    }
    if(a==b) return a;

    for(int i=MaxN;i>-1;i--)
    {
        if(LCA[a][i]!=-1 && (LCA[a][i]!=LCA[b][i]))
        {
            a=LCA[a][i],b=LCA[b][i];
        }
    }
    return LCA[a][0];
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[v].push_back(u),g[u].push_back(v);
        }
        memset(LCA,-1,sizeof(LCA));


        dfs(1,-1,0);
        for(int i=1;i<=MaxN;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(LCA[j][i-1]!=-1)
                {
                    int p=LCA[j][i-1];
                    LCA[j][i]=LCA[p][i-1];
                }
            }
        }
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            int lca=get_lca(x,y);///finding the lca;
            cout<<level[x]+level[y]-2*level[lca]<<endl;
        }
    }
    return 0;
}


