

///TIME comlexity o(v+e)

#include<bits/stdc++.h>
#include<math.h>
using namespace std;
vector<int>adj[100005];///store the directed graph
vector<int>ans;///store the sorting path
int degree[100005];///store the in degree of any node
void topsort(int n)
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(degree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int current=q.front();
        ans.push_back(current);
        q.pop();
        for(int child:adj[current])
        {
            degree[child]--; ///Reduce the in degree of this current node's child because we acutually remove the current node from our graph so degree of its adjecnt node should be reduce
            if(degree[child]==0)
            {
                q.push(child);
            }
        }
    }
    cout<<"TOPOLOGICAL SORT IS"<<endl;
    for(auto i:ans) cout<<i<<" ";
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
            adj[u].push_back(v);
            degree[v]++;///increasing the  in degree of node
        }
        topsort(n);
    }
    return 0;
}
///TOPOLOGICAL sort e obossoi number of ans elements==n;
///otherwise there is a deadlock/cycle




