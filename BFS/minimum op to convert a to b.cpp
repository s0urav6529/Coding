#include<bits/stdc++.h>
#include<math.h>
using namespace std;
vector<int>adj[100005];
bool vis[100005]={false};
int in[100005],update[100005];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int timer;
int n,m;
int minop()
{
    set<int>vis;
    queue<pair<int,int>>q;
    q.push({n,0});
    while(!q.empty())
    {
        int node=q.front().first;
        int level=q.front().second;
        q.pop();
        vis.insert(node);
        if(node==m) return level;
        if(node*2==m||node-1==m) return level+1;
        if(vis.find(node*2)==vis.end())
        {
            q.push({node*2,level+1});
        }
        if(node-1>=0&&vis.find(node-1)==vis.end())
        {
            q.push({node-1,level+1});
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
        cin>>n>>m;
        cout<<minop()<<endl;
    }
    return 0;
}

