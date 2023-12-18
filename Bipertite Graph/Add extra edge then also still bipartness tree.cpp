

///Problem link : 862B Codeforces


///GOD is Allmighty.
///Hore Krisna,Lord Krisna.

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///*************************Keep Coding***********************************

vector<int>adj[100005];
set<int>black,white;

void dfs(int src,int par,int col)
{
    if(col) black.insert(src);
    else white.insert(src);

    for(auto c:adj[src])
    {
        if(c!=par)
            dfs(c,src,1-col);
    }
    return;
}
void solution()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0,1); ///root,parent,color
    
    int ans=0;
    for(auto i:black)
    {
        ans += (white.size()-adj[i].size());
        //cout<<adj[i].size()<<endl;
    }
    cout<<ans<<endl;
    return;
}
int main()
{
    fast;
    int tc=1;
    //in(tc);
    while(tc--) solution();
    return 0;
}




