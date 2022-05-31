///Time compliexity O(N+M)///node + edges

///Articulation points guluke set e rakha hoi karon same point multiple times occure kore

#include<bits/stdc++.h>
#include<math.h>
using namespace std;
vector<int>g[100005];
int vis[100005];
int in[100005];///When you enter in a node.
int low[100005];///Lowest time needed to enter a particuler node by its anchester/parent
int timer;
set<int> AP;
void dfs(int node,int par)
{
    vis[node]=true;
    in[node]=low[node]=timer++; ///At first enter and lowest time decler as enter time

    int children=0;///if root has more than one children than it should be an articulation point
    for(int child:g[node])
    {
        if(child==par) continue;
        else if(vis[child])
        {
            ///back edge

            ///update kore nicchi anchester er in time er maddhome
            low[node]=min(low[node],in[child]);
        }
        else
        {
            ///forward edge
            dfs(child,node);

            ///dfs call hower por child low time er maddhome node er low time update kore
            low[node]=min(low[node],low[child]);

            ///This node is an articulation point and not a root because it's parents is not -1
            if(low[child]>=in[node] && par!=-1)
            {
                cout<<node<<" is an articulation point"<<endl;
                AP.insert(node);///insert into set
            }
            children++;
        }
    }
    ///This means If root has more than one children and it must be an articulation point
    if(par==-1&&children>1)
    {
        cout<<node<<" is an articulation point"<<endl;
        AP.insert(node);///insert into set
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n,e;
        cin>>n>>e;
        for(int i=1;i<=e;i++)
        {
            int u,v;
            cin>>u>>v;
            g[v].push_back(u),g[u].push_back(v);
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]) dfs(i,-1);///root and his parents-1
        }
        //for(auto i:AP) cout<<i<<endl;
    }
    return 0;
}

