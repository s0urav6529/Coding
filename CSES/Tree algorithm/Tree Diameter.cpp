#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);

vector<int>adj[200005];
int dis[200005];
int dd[200005];

int dia=0;

void diameter(int node,int parent,int distance){

    for(int ch:adj[node]){

        if(ch!=parent){

            diameter(ch,node,distance+1);
        }
    }
    dis[node]=distance;

}
void solve()
{
    int n,x,y;
    cin>>n;


    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    diameter(1,-1,0);

    int mx=0,node;
    for(int i=1;i<=n;i++) {
        if(mx<dis[i]){
            mx=dis[i];
            node=i;
        }
    }
    diameter(node,-1,0);

    int ans=0;
    for(int i=1;i<=n;i++) {
        ans=max(ans,dis[i]);
    }

    cout<<ans<<endl;
    return;
}
int main()
{
    fast;
    int tc=1;
    while(tc--) solve();
    return 0;
}




