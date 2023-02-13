


///steps first e finish time ber korte hbe sob gula node er and tader finishing time onushe e list kore nite hbe.

///tarpor maximum finishing time e abar transpose matrix er upor dfs kore connected component ber korte hbe.

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define output freopen ("out.txt","w",stdout);

vector<int>v[20005];  ///main graph
vector<int>t[20005];  ///transpose graph
vector<int>out;   ///storing node increasing of outtime
vector<int>scc;   ///list of scc
bool vis[20005];
void dfs_out(int node)
{
    vis[node]=1;
    for(int child:v[node])  ///making dfs on main graph
    {
        if(vis[child]==0)
        {
            dfs_out(child);
        }
    }
    out.push_back(node);  ///storing node increasing of outtime
}
void dfs(int node)  ///for scc
{
    vis[node]=1;
    for(int child:t[node])  ///making dfs on transpose graph
    {
        if(vis[child]==0)
        {
            dfs(child);
        }
    }
    scc.push_back(node);
}
void solution()
{
    int n,e;
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        t[y].push_back(x);
    }
    for(int i=1;i<=n;i++)  ///out time measure dfs
    {
        if(vis[i]==0)
        {
            dfs_out(i);
        }
    }
    for(int i=1;i<=n;i++) vis[i]=0;

    for(int i=1;i<=n;i++)  ///scc dfs
    {
        scc.clear();
        if(vis[out[n-i]]==0)  ///orderwise traverse
        {
            dfs(out[n-i]);
            cout<<"SCC are : ";
            for(auto j:scc) cout<<j<<" ";
            cout<<endl;
        }
    }

    return;
}
int main()
{
    fast;
    solution();
    return 0;
}

